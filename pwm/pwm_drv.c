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
#include <linux/delay.h>

#include "pwm_drv_hw.h"


MODULE_LICENSE("Dual BSD/GPL");

#define ARRAY_LEN(X) (sizeof(X)/sizeof(X[0]))





#define MINOR_SHIFT 2

#define SERVO_NUM 	32
#define DEV_NAME 	"pwm_drv/pwm%02ddev"
#define SERVO_MIN	50
#define SERVO_MAX	250
#define SERVO_DEF	150

#define DEF_STR 256
#define DEF_DEV_NAME 50



int pwm_open(struct inode *inode, struct file *file);
int pwm_release(struct inode *inode, struct file *file);
ssize_t pwm_read (struct file* file, char *buf, size_t count, loff_t * f_pos);
ssize_t pwm_write(struct file* file, const char *buf, size_t count, loff_t * f_pos);

typedef struct
{
	char 			name[DEF_DEV_NAME];
	unsigned char 		position;
	unsigned char 		id;
	struct miscdevice 	dev;	
}dev_channel_t;



/* Major number */
const int pwm_major = 125;


/* Structure that declares the usual file */
/* access functions */
static struct file_operations pwm_fops = {
  owner: THIS_MODULE,
  read: pwm_read,
  write: pwm_write,
  open: pwm_open,
  release: pwm_release
};

dev_channel_t * servo[SERVO_NUM];



dev_channel_t * pwm_create_device(int id)
{
	int ret;
	dev_channel_t * device;

	device=kmalloc(sizeof(dev_channel_t), GFP_KERNEL);
	memset(device, 0, sizeof(dev_channel_t));

	snprintf(device->name, ARRAY_LEN(device->name), DEV_NAME, id);
	device->dev.minor 	= id + MINOR_SHIFT;
	device->dev.name 	= device->name;
	device->dev.fops 	= &pwm_fops;
	device->position	= SERVO_DEF;
	device->id			= id;

	ret = misc_register(&(device->dev));
        if (ret)
	{
	        printk(KERN_ERR "Unable to register pwm driver misc device %s error %d\n", device->name, ret);
		kfree(device);
		device = NULL;
	}
	return device;
}


int pwm_init(void)
{
	int i;
	printk(KERN_INFO "PWM for servo motors driver init\r\n");

	/* Allocating memory for the buffer */
	for(i=0; i<SERVO_NUM; i++)
	{
		servo[i] = pwm_create_device(i);
	}
	if(hw_init_pwm_device()!=0)
	{
		return -1;
	}
	return 0;
}



void pwm_exit(void)
{
	int i;
	hw_close_pwm_device();
	for(i=0; i<SERVO_NUM; i++)
	{
		if(servo[i] != NULL)
		{
			misc_deregister(&(servo[i]->dev));
			kfree(servo[i]);
			servo[i] = NULL;
		}
	}
	printk(KERN_INFO "PWM for servo motors driver close\r\n");
}

module_init(pwm_init);
module_exit(pwm_exit);



int pwm_open(struct inode *inode, struct file *file)
{
	int id = MINOR(inode->i_rdev) - MINOR_SHIFT;

	if(id >= SERVO_NUM)
	{
		printk(KERN_ERR "incorrect id: %d \r\n", id);
		return -1;
	}
	
	file->private_data = servo[id];
	return 0;
}

int pwm_release(struct inode *inode, struct file *file)
{
	return 0;
}

ssize_t pwm_read(struct file* file, char *buf, size_t count, loff_t * f_pos)
{
	char tmpbuf[6];
	dev_channel_t * device;
	int j;
	
	device = (dev_channel_t*)(file->private_data);
	if(device == NULL)
	{
		printk(KERN_ERR "device not initialized\r\n");
		return -1;
	}
	snprintf(tmpbuf, 6, "%03d\n", device->position);
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
	dev_channel_t * device;

	if(count>5)
		return -1;

	strncpy(tmpbuf, buf, count);
	tmpbuf[count]='\0';
	
	err = kstrtoint(tmpbuf, 10, &res);
	if(res >= SERVO_MIN && res <= SERVO_MAX && err == 0)
	{
		device = (dev_channel_t*)(file->private_data);
		device->position = res;
		hw_set_pos(device->id, device->position);
		return count;
	}
	printk(KERN_WARNING "incorrect number %s\r\n", tmpbuf);
	return -1;
}
