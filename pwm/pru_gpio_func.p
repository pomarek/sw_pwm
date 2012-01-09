

PWM_GPIO_INIT:
	ret
	
PWM_GPIO_SET_STATE:
	
	mov r25, GPIO1_BASE+GPIO_CLEARDATAOUT
	mov r4, 0
	set r4, 21
	set r4, 22
	set r4, 23
	set r4, 24
	qbeq LED_CLEAR, r1, 0
	add r25, r25, 4
LED_CLEAR:
	sbbo r4, r25, 0, 4
	ret
