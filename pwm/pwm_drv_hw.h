#ifndef PWM_DRV_HW_H
	#define PWM_DRV_HW_H

#define SERVO_DEF_POS 150

int hw_init_pwm_device(void);
int hw_enable_bank(int pwm_bank);
int hw_disable_bank(int pwm_bank);
int hw_set_pos(int pwm_num, unsigned char pos);
unsigned char hw_get_position(int pwm_num);
void hw_close_pwm_device(void);

#endif
