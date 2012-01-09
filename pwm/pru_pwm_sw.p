
.origin 0
.entrypoint PWM_START

#include "pru_data.hp"


// ************************************************************************  
PWM_START:
	call PWM_INIT

LOOPINF:
//-------------------
INIT_STEP:
	qbne INIT_STEP_END, ctrl.cycle, 0 
	call INIT_SERVOS_FOR_STEP
INIT_STEP_END:

//-------------------
	call PROCESS_CYCLE
//-------------------
FINISH_STEP:
	qbne FINISH_STEP_END, ctrl.cycle, 250
	call FINISH_SERVO_STEP
	jmp LOOPINF
FINISH_STEP_END:

//-------------------	
TIMER_WAIT:
	mov r10, DELAY // to be removed, and WAIT needs to be updated 
	call WAIT
	add ctrl.cycle, ctrl.cycle, 1
TIMER_WAIT_END:	
	jmp LOOPINF

// ************************************************************************
PROCESS_CYCLE:
	qbne PROCESS_CYCLE_S0_END, pos4.s0, ctrl.cycle
	pwm_clear PWM0_REG_OFFSET, PWM0_MASK_OFFSET
PROCESS_CYCLE_S0_END:
	qbne PROCESS_CYCLE_S1_END, pos4.s1, ctrl.cycle
	pwm_clear PWM1_REG_OFFSET, PWM1_MASK_OFFSET
PROCESS_CYCLE_S1_END:
	qbne PROCESS_CYCLE_S2_END, pos4.s2, ctrl.cycle
	pwm_clear PWM2_REG_OFFSET, PWM2_MASK_OFFSET
PROCESS_CYCLE_S2_END:
	qbne PROCESS_CYCLE_S3_END, pos4.s3, ctrl.cycle
	pwm_clear PWM3_REG_OFFSET, PWM3_MASK_OFFSET
PROCESS_CYCLE_S3_END:
	ret

// ************************************************************************
PWM_END:
	halt
// ************************************************************************
PWM_INIT:
	ldi ctrl.cycle, 0
	ldi ctrl.step, 0	
	mov ctrl.data, DESC_START
	lbbo ctrl.servo_per_step, ctrl.data, 0, 1 	
	mov ctrl.data, DATA_START
	ret
// ************************************************************************
INIT_SERVOS_FOR_STEP:
// #1 
	pwm_set PWM0_REG_OFFSET, PWM0_MASK_OFFSET
// #2 
	pwm_set PWM1_REG_OFFSET, PWM1_MASK_OFFSET
// #3 
	pwm_set PWM2_REG_OFFSET, PWM2_MASK_OFFSET
// #4 
	pwm_set PWM3_REG_OFFSET, PWM3_MASK_OFFSET
// positions 
	lbbo pos4, ctrl.data, POS4_OFFSET, REG_SIZE
	ret
// ************************************************************************
FINISH_SERVO_STEP:
	add ctrl.step, ctrl.step, 1
	add ctrl.data, ctrl.data, NEXT_STEP_DATA_OFFSET
	ldi ctrl.cycle, 0
	qbgt FINISH_SERVO_STEP_EXIT, ctrl.step, 8
	ldi ctrl.step, 0
	mov ctrl.data, DATA_START
FINISH_SERVO_STEP_EXIT:
	ret
// ************************************************************************

WAIT:
	sub r10, r10, 1
	qblt WAIT, r10, 0  
	ret
// ************************************************************************

