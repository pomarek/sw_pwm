/*
 * timer.c
 *
 *  Created on: 2012-01-14
 *      Author: pomarek
 */
#include <linux/kernel.h> /* printk() */
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/string.h>

#include "timer.h"

#define DRV_NAME	"pru_pwm_driver_timers"

dmtimer_mem_t * timer_init(unsigned int timer_base)
{
	if(timer_base == NULL)
	{
		return NULL;
	}
    if( request_mem_region(timer_base,  sizeof(dmtimer_mem_t), DRV_NAME) == NULL )
    {
	    return NULL;
    }

	return (dmtimer_mem_t*) ioremap_nocache(timer_base, sizeof(dmtimer_mem_t));
}

int timer_setup(dmtimer_mem_t * timer)
{

}
