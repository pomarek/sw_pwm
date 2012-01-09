/*
 * driver_main.c
 *
 *  Created on: 2011-11-28
 *      Author: szakal
 */

/* Necessary includes for device drivers */
#include <linux/init.h>
//#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h> /* printk() */
#include <linux/slab.h> /* kmalloc() */
#include <linux/fs.h> /* everything... */
#include <linux/errno.h> /* error codes */
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h> /* O_ACCMODE */
#include <asm/system.h> /* cli(), *_flags */
#include <asm/uaccess.h> /* copy_from/to_user */
#include <linux/miscdevice.h>


MODULE_LICENSE("Dual BSD/GPL");

#define SERVO_NUM 32
#define DEF_STR 256
#define DEF_DEV_NAME 50

#define DEV_NAME "soft_pwm"

int pwm_open(struct inode *inode, struct file *file);
int pwm_release(struct inode *inode, struct file *file);
ssize_t pwm_read (struct file* file, char *buf, size_t count, loff_t * f_pos);
ssize_t pwm_write(struct file* file, const char *buf, size_t count, loff_t * f_pos);


/* Major number */
const int pwm_major = 125;

static struct miscdevice pwm_dev[SERVO_NUM];
static char names[SERVO_NUM][DEF_DEV_NAME];
/* Structure that declares the usual file */
/* access functions */
static struct file_operations pwm_fops = {
  owner: THIS_MODULE,
  read: pwm_read,
  write: pwm_write,
  open: pwm_open,
  release: pwm_release
};

static unsigned char * positions=NULL;


int pwm_create_device(int minor)
{
	int ret;
	snprintf(names[minor], DEF_DEV_NAME, "pwm/pwm%03d", minor);
	pwm_dev[minor].minor=minor;
	pwm_dev[minor].name=names[minor];
	pwm_dev[minor].fops=&pwm_fops;
	ret = misc_register(&pwm_dev[minor]);
        if (ret)
                printk(KERN_ERR "Unable to register pwm driver misc device %s error %d\n", names[minor], ret);
	return ret;
}


int pwm_init(void)
{
	int i;
	printk("<1> PWM for servo motors driver init\r\n");

	/* Allocating memory for the buffer */
	positions = kmalloc(SERVO_NUM, GFP_KERNEL);
	if (!positions)
	{
		return -ENOMEM;
	}
	memset(positions, 0, SERVO_NUM);
	for(i=0; i<SERVO_NUM; i++)
	{
		pwm_create_device(i);
	}
	return 0;
}



void pwm_exit(void)
{
	int i;
	for(i=0; i<SERVO_NUM; i++)
		misc_deregister(&pwm_dev[i]);
	/* Registering device */
	//unregister_chrdev(pwm_major, DEV_NAME);
	
	/* Freeing buffer memory */
	if (positions)
	{
	    kfree(positions);
	}
	printk("<1> PWM for servo motors driver close\r\n");
}

module_init(pwm_init);
module_exit(pwm_exit);



int pwm_open(struct inode *inode, struct file *file)
{
	int minor=MINOR(inode->i_rdev);
	if(minor>=SERVO_NUM)
	{
		printk("<1> incorrect id: %d \r\n", minor);
		return -1;
	}
	
	file->private_data = &positions[minor];
	return 0;
}

int pwm_release(struct inode *inode, struct file *file)
{
	return 0;
}

ssize_t pwm_read(struct file* file, char *buf, size_t count, loff_t * f_pos)
{
	char tmpbuf[6];
	int j;
	snprintf(tmpbuf, 6, "%03d\n", *(unsigned char*)file->private_data);
	for(j=0; *f_pos<5 && j<count; (*f_pos)++, j++)
	{
		buf[j]=tmpbuf[*f_pos];
	}
	return j;
}

ssize_t pwm_write( struct file *file, const char *buf, size_t count, loff_t *f_pos)
{
	char tmpbuf[6];
	int err, res=0;
	if(count>5)
		return -1;

	strncpy(tmpbuf, buf, count);
	tmpbuf[count]='\0';
	
	printk("<1> number %s\n", tmpbuf);
	err = kstrtoint(tmpbuf, 10, &res);
	if(res>=0 && res<256 &&err ==0)
	{
		*((unsigned char*) file->private_data)=res;
		return count;
	}
	printk("<1> incorrect number %s\r\n", tmpbuf);
	return -1;
}
