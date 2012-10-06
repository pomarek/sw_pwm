/*
 * gpio_regs.h
 *
 *  Created on: 2012-10-05
 *      Author: pomarek
 */

#ifndef GPIO_REGS_H_
#define GPIO_REGS_H_


#define MUX_FUN_7		7
#define MUX_FUN_GPIO	MUX_FUN_7
typedef struct
{
	char* name;
	unsigned int mux_addr;
	int	valid;
} gpio_desc_t;

typedef enum
{
	GPIO_DIR_OUT,
	GPIO_DIR_IN
}gpio_dir_t;

extern gpio_desc_t  gpio_mux[];

int set_ball_mux(int bank, int bit, int mux_fun);
int set_gpio_dir(int bank, int bit, gpio_dir_t dir, int state);

#endif /* GPIO_REGS_H_ */
