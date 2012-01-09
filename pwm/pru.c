#include <linux/kernel.h> /* printk() */
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/string.h>
#include "pru.h"

#define PRUSS_BASE 	0x4A300000
#define PRUSS_END 	0x4A37FFFF

#define CM_PER_BASE				0x44E00000
#define CM_PER_PRUSS_CLKCTRL 	CM_PER_BASE + 0xE8

#define PRM_PER_BASE			0x44E00C00
#define RM_PER_RSTCTRL 			PRM_PER_BASE
#define PM_PER_PWRSTST			PRM_PER_BASE + 0x08
#define PM_PER_PWRSTCTRL		PRM_PER_BASE + 0x0C


#define DRV_NAME	"pru_pwm_driver"
#define PDEV_NAME	"PRUSSv2"

#define PRU_CONTROL_INITIAL 0x00000008l /* 0x0000 base address, no step, instruction ctr, no sleep, halted, reset */

typedef enum
{
	PRU_FLAGS_PRU0_UPLOADED		=0x01,
	PRU_FLAGS_PRU1_UPLOADED		=0x02
}pru_flags_t;

typedef enum
{
	PRU_CTRL_PRU_RESET		= 0x01,
	PRU_CTRL_PRU_ENABLE		= 0x02
}pru_ctrl_t;

static pruss_mem_t * pruss_data = NULL;
static int pru_flags=0;


static PRUSS_PRU_CTRL_t * s_pru_get_control_block(pru_id_t id)
{
	switch(id)
	{
		case PRU_ID_PRU0:
			return &(pruss_data->PRU0_control);
		case PRU_ID_PRU1:
			return &(pruss_data->PRU1_control);
		default:
			return NULL;
	}
}


static pru_error_t s_pru_enable_clocking_and_power(void)
{
	unsigned int * reg, * reset;

	/* not requesting any of the memory below, because we want be using it after exit */

	reset = (unsigned int *) ioremap_nocache(RM_PER_RSTCTRL, sizeof(unsigned int));
	printk(KERN_INFO "Entering PRUSS reset state.\n");
	*reset=(1<<1);

	reg = (unsigned int *) ioremap_nocache(CM_PER_PRUSS_CLKCTRL, sizeof(unsigned int));
	if(reg == NULL)
	{
		return PRU_ERROR_ALLOCATION_ERROR;
	}
	*reg = 2;
	iounmap(reg);

	/* those registers should already have all the bits we need set correctly, however */
	/* to make sure nothing goes wrong we set them again. */
	reg = (unsigned int *) ioremap_nocache(PM_PER_PWRSTST, sizeof(unsigned int));
	if(reg == NULL)
	{
		return PRU_ERROR_ALLOCATION_ERROR;
	}
	*reg = ((3<<23) | (*reg)) ;
	iounmap(reg);

	reg = (unsigned int *) ioremap_nocache(PM_PER_PWRSTCTRL, sizeof(unsigned int));
	if(reg == NULL)
	{
		return PRU_ERROR_ALLOCATION_ERROR;
	}
	*reg = ((3<<5)|(1<<7)|(*reg));
	iounmap(reg);

	printk(KERN_INFO "Exiting PRUSS reset state.\n");
	*reset=*reset & (~(1<<1));
	iounmap(reset);

	return PRU_ERROR_NO_ERROR;
}

static pruss_mem_t* s_pru_init_memory_space(void)
{
    if( request_mem_region(PRUSS_BASE,  sizeof(pruss_mem_t), DRV_NAME) == NULL )
    {
	    return NULL;
    }

	return (pruss_mem_t*) ioremap_nocache(PRUSS_BASE, sizeof(pruss_mem_t));
}


pru_error_t pru_init(void)
{
	if(pruss_data != NULL)
	{
		return PRU_ERROR_ALREADY_INITIALIZED;
	}
	if(s_pru_enable_clocking_and_power() != PRU_ERROR_NO_ERROR)
	{
			return PRU_ERROR_CLOCKING;
	}

	pruss_data = s_pru_init_memory_space();
	if(pruss_data == NULL)
	{
		return PRU_ERROR_ALLOCATION_ERROR;
	}
	pruss_data->CFG.SYSCFG &= ~ (1<<4);

	return PRU_ERROR_NO_ERROR;
}


pruss_mem_t * pru_get_memory_space(void)
{
	return pruss_data;
}

pru_error_t pru_close(void)
{
	if(pruss_data == NULL)
	{
		return PRU_ERROR_NOT_INITIALIZED;
	}
    iounmap(pruss_data);
    release_mem_region(PRUSS_BASE, sizeof(pruss_mem_t));
	pruss_data = NULL;
	return PRU_ERROR_NO_ERROR;
}

pru_error_t pru_upload(pru_id_t id, const unsigned int * data, unsigned int len)
{
	PRUSS_PRU_CTRL_t * ctrl_data;
	unsigned int * iram;
	unsigned int temp_flag, i;

	if(data == NULL || len > PRU_INTERNAL_RAM_SIZE/4)
	{
		return PRU_ERROR_DATA_ERROR;
	}
	if(pruss_data == NULL)
	{
		return PRU_ERROR_NOT_INITIALIZED;
	}
    ctrl_data = s_pru_get_control_block(id);
	if(ctrl_data == NULL)
	{
		return PRU_ERROR_INVALID_ID;
	}
	if(ctrl_data->CONTROL & PRU_CTRL_PRU_ENABLE)
	{
		return PRU_ERROR_PRU_NOT_HALTED;
	}
	ctrl_data->CONTROL = PRU_CONTROL_INITIAL;
	switch(id)
	{
		case PRU_ID_PRU0:
			iram = pruss_data->PRU0_iram;
			temp_flag = PRU_FLAGS_PRU0_UPLOADED;
			break;
		case PRU_ID_PRU1:
			iram = pruss_data->PRU1_iram;
			temp_flag = PRU_FLAGS_PRU1_UPLOADED;
			break;
		default:
			return PRU_ERROR_INVALID_ID;
	}
	for(i=0; i<len; i++)
	{
		iram[i] = data[i];
	}

	pru_flags |= temp_flag;
	return PRU_ERROR_NO_ERROR;
}



pru_error_t pru_run(pru_id_t id)
{
	PRUSS_PRU_CTRL_t * ctrl_data;
	int temp_flag = 0;
	if(pruss_data == NULL)
	{
		return PRU_ERROR_NOT_INITIALIZED;
	}
	
	ctrl_data = s_pru_get_control_block(id);
	if(ctrl_data == NULL)
	{
		return PRU_ERROR_INVALID_ID;
	}
	
	switch(id)
	{
		case PRU_ID_PRU0:
			temp_flag = PRU_FLAGS_PRU0_UPLOADED;
			break;
        case PRU_ID_PRU1:
            temp_flag = PRU_FLAGS_PRU1_UPLOADED;
            break;
		default:
			return PRU_ERROR_INVALID_ID;
	}

	if((temp_flag & pru_flags) == 0)
	{
		return PRU_ERROR_DATA_ERROR;
	}

	if(ctrl_data->CONTROL & PRU_CTRL_PRU_ENABLE)
	{
		return PRU_ERROR_PRU_NOT_HALTED;
	}
	ctrl_data->CONTROL |= PRU_CTRL_PRU_ENABLE;
	return PRU_ERROR_NO_ERROR;
}

pru_error_t pru_halt(pru_id_t id)
{
    PRUSS_PRU_CTRL_t * ctrl_data;
	if(pruss_data == NULL)
	{
		return PRU_ERROR_NOT_INITIALIZED;
	}

	ctrl_data = s_pru_get_control_block(id);
	if(ctrl_data == NULL)
	{
		return PRU_ERROR_INVALID_ID;
	}

	if(!(ctrl_data->CONTROL & PRU_CTRL_PRU_ENABLE))
	{
		return PRU_ERROR_PRU_NOT_RUNNING;
	}
	ctrl_data->CONTROL&= ~PRU_CTRL_PRU_ENABLE;
	return PRU_ERROR_NO_ERROR;
}

pru_error_t pru_reset(pru_id_t id)
{
    PRUSS_PRU_CTRL_t * ctrl_data;
	if(pruss_data == NULL)
	{
		return PRU_ERROR_NOT_INITIALIZED;
	}

	ctrl_data = s_pru_get_control_block(id);
	if(ctrl_data == NULL)
	{
		return PRU_ERROR_INVALID_ID;
	}
    ctrl_data->CONTROL &= ~PRU_CTRL_PRU_RESET;
	return PRU_ERROR_NO_ERROR;
}
