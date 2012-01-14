/*
 * timer.h
 *
 *  Created on: 2012-01-14
 *      Author: pomarek
 */

#ifndef TIMER_H_
#define TIMER_H_


typedef struct
{
	unsigned int TIDR;
	unsigned int _pad0[3];
	unsigned int TIOCP_CFG;
	unsigned int _pad1[3];
	unsigned int IRQ_EOI;
	unsigned int IRQSTATUS_RAW;
	unsigned int IRQSTATUS;
	unsigned int IRQSTATUS_SET;
	unsigned int IRQSTATUS_CLR;
	unsigned int IRQWAKEEN;
	unsigned int TCLR;
	unsigned int TCRR;
	unsigned int TLDR;
	unsigned int TTGR;
	unsigned int TWPS;
	unsigned int TMAR;
	unsigned int TCAR1;
	unsigned int TSICR;
	unsigned int TCAR2;
}dmtimer_mem_t;


#define DMTIMER0_BASE 		0x44E05000
#define DMTIMER1_1MS_BASE 	0x44E31000
#define DMTIMER2_BASE 		0x48040000
#define DMTIMER3_BASE 		0x48042000
#define DMTIMER4_BASE 		0x48044000
#define DMTIMER5_BASE 		0x48046000
#define DMTIMER6_BASE 		0x48048000
#define DMTIMER7_BASE 		0x4804A000




#endif /* TIMER_H_ */
