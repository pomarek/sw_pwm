#include <linux/kernel.h> /* printk() */
#include <linux/ioport.h>
#include <linux/io.h>

#include "pwm_drv_hw.h"
#include "pru.h"
#include "pru_pwm_sw_bin.h"

/***********************************    MACROS   ******************************************/
#define _BIT(X) (1<<X)
#define _BIT_EMPTY 0


/***********************************    CONSTS   ******************************************/
#define GPIO0_BASE 0x44E07000
#define GPIO1_BASE 0x4804C000
#define GPIO2_BASE 0x481AC000
#define GPIO3_BASE 0x481AE000


#define GPIO_CLEARDATAOUT 0x190
#define GPIO_SETDATAOUT 0x194

#define GPIO0_CLEARDATAOUT 	(GPIO0_BASE + GPIO_CLEARDATAOUT)
#define GPIO1_CLEARDATAOUT 	(GPIO1_BASE + GPIO_CLEARDATAOUT)
#define GPIO2_CLEARDATAOUT 	(GPIO2_BASE + GPIO_CLEARDATAOUT)
#define GPIO3_CLEARDATAOUT 	(GPIO3_BASE + GPIO_CLEARDATAOUT)


#define PWM_PRU PRU_ID_PRU0

#define GPIO_NAME "PWM_GPIOS"

#define PWM_CHANNELS			32
#define PWM_STEPS				8 /* always 8 */
#define PWM_OUTPUT_PER_STEP 	((PWM_CHANNELS+PWM_STEPS-1)/PWM_STEPS)

/***********************************   DATA DEF  ******************************************/
typedef struct
{
	unsigned int gpio_clear_set_reg;
	unsigned int bit_mask;
}pwm_output_t;

typedef struct
{
	pwm_output_t pwm_output[PWM_OUTPUT_PER_STEP];
	unsigned char pwm_pos[PWM_OUTPUT_PER_STEP];
}pwm_step_t;

typedef struct
{
	unsigned char servo_per_step;
	unsigned char pad[3];
	pwm_step_t pwm_step[PWM_STEPS];
}pwm_pru_mem_desc_t;


/***********************************  GPIO DESC  ******************************************/
const pwm_output_t gpio_desc[PWM_CHANNELS] =
{
		{GPIO1_CLEARDATAOUT, _BIT(21)},
		{GPIO1_CLEARDATAOUT, _BIT(22)},
		{GPIO1_CLEARDATAOUT, _BIT(23)},
		{GPIO1_CLEARDATAOUT, _BIT(24)},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},

		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
		{GPIO1_CLEARDATAOUT, _BIT_EMPTY},
};
/***********************************  VARIABLES  ******************************************/
static pwm_pru_mem_desc_t * pru_servo_desc = NULL;

/***********************************     CODE    ******************************************/
int s_hw_init_muxing(void)
{
	return 0;
}

static  pwm_pru_mem_desc_t * s_init_pru_data_space(pru_id_t id)
{
	int i;
	pwm_pru_mem_desc_t * result;
	result = (pwm_pru_mem_desc_t *)pru_get_memory_space()->PRU_data_ram[id];
	if(result == NULL)
	{
		return NULL;
	}
	result->servo_per_step = PWM_OUTPUT_PER_STEP;
	for(i=0; i< PWM_CHANNELS; i++)
	{
		result->pwm_step[i/PWM_OUTPUT_PER_STEP].pwm_pos[i%PWM_OUTPUT_PER_STEP] = SERVO_DEF_POS;
		result->pwm_step[i/PWM_OUTPUT_PER_STEP].pwm_output[i%PWM_OUTPUT_PER_STEP].gpio_clear_set_reg = gpio_desc[i].gpio_clear_set_reg;
		result->pwm_step[i/PWM_OUTPUT_PER_STEP].pwm_output[i%PWM_OUTPUT_PER_STEP].bit_mask = gpio_desc[i].bit_mask;
	}
	return result;
}

int hw_init_pwm_device(void)
{
	s_hw_init_muxing();
	if(pru_init() != PRU_ERROR_NO_ERROR)
	{
		printk(KERN_ERR "Pru initialization failed\r\n");
		return -1;
	}
	if(pru_upload(PWM_PRU, PRUCode, sizeof(PRUCode)) != PRU_ERROR_NO_ERROR)
    {
		printk(KERN_ERR "Can not upload pru software\r\n");
        return -1;
    }
	pru_servo_desc = s_init_pru_data_space(PWM_PRU);

   	if(pru_run(PWM_PRU) != PRU_ERROR_NO_ERROR)
	{
   		printk(KERN_ERR "Unable to start pru\r\n");
		return -1;
	}

	return 0;
}

int hw_enable_bank(int pwm_bank)
{	
	return 0;
}

int hw_disable_bank(int pwm_bank)
{
	return 0;
}

int hw_set_pos(int pwm_num, unsigned char pos)
{
	if(pwm_num >= PWM_CHANNELS || pru_servo_desc == NULL)
	{
		return -1;
	}
	pru_servo_desc->pwm_step[pwm_num/PWM_OUTPUT_PER_STEP].pwm_pos[pwm_num%PWM_OUTPUT_PER_STEP] = pos;
	return 0;
}	

unsigned char hw_get_position(int pwm_num)
{
	if(pwm_num >= PWM_CHANNELS || pru_servo_desc == NULL)
	{
		return 0;
	}
	return pru_servo_desc->pwm_step[pwm_num/PWM_OUTPUT_PER_STEP].pwm_pos[pwm_num%PWM_OUTPUT_PER_STEP];
}

void hw_close_pwm_device(void)
{
	pru_halt(PWM_PRU);
	pru_close();
}





