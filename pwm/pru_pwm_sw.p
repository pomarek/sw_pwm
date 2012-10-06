
.origin 0
.entrypoint PWM_START

#include "pru_data.hp"
#include "pru_ecap.hp"
#include "pru_pwm_macros.hp"

//-------------------

.macro main
	pwm_init
	LOOPINF:

	init_step
	process_cycle
	next_cycle
	finish_step
	WAIT

	jmp LOOPINF
.endm

// ************************************************************************

PWM_START:
	main
	halt


// ************************************************************************


