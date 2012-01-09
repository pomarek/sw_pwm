#ifndef _AM335X_H_
	#define _AM335_H_



typedef struct
{
	unsigned int GPIO_REVISION;
	unsigned int _pad0[3];
	unsigned int GPIO_SYSCONFIG;
	unsigned int _pad1[3];	
	unsigned int GPIO_EOI;
	unsigned int GPIO_IRQSTATUS_RAW_0;
	unsigned int GPIO_IRQSTATUS_RAW_1;
	unsigned int GPIO_IRQSTATUS_0;
	unsigned int GPIO_IRQSTATUS_1;
	unsigned int GPIO_IRQSTATUS_SET_0;
	unsigned int GPIO_IRQSTATUS_SET_1;
	unsigned int GPIO_IRQSTATUS_CLR_0;
	unsigned int GPIO_IRQSTATUS_CLR_1;
	unsigned int _pad2[52];
	unsigned int GPIO_SYSSTATUS;
	unsigned int _pad3[6];
	unsigned int GPIO_CTRL;
	unsigned int GPIO_OE;
	unsigned int GPIO_DATAIN;
	unsigned int GPIO_DATAOUT;
	unsigned int GPIO_LEVELDETECT0;
	unsigned int GPIO_LEVELDETECT1;
	unsigned int GPIO_RISINGDETECT;
	unsigned int GPIO_FALLINGDETECT;
	unsigned int GPIO_DEBOUNCENABLE;
	unsigned int GPIO_DEBOUNCINGTIME;
	unsigned int _pad4[14];
	unsigned int GPIO_CLEARDATAOUT;
	unsigned int GPIO_SETDATAOUT;
}gpio_mem_t;



/*
#define L4_SLOW_AM33XX_BASE	(void *)(0x48000000u)

#define AM33XX_SCM_BASE		(void *)(0x44E10000u)
#define AM33XX_CTRL_BASE	AM33XX_SCM_BASE
#define AM33XX_PRCM_BASE	(void *)(0x44E00000u)

#define AM33XX_GPIO0_BASE	(void *)(0x44E07000u)
#define AM33XX_GPIO1_BASE	(void *)(0x4804C000u)
#define AM33XX_GPIO2_BASE	(void *)(0x481AC000u)
#define AM33XX_GPIO3_BASE	(void *)(0x481AE000u)

#define AM33XX_TSC_BASE		(void *)(0x44E0D000u)
#define AM33XX_RTC_BASE		(void *)(0x44E3E000u)

#define AM33XX_D_CAN0_BASE	(void *)(0x481CC000u)
#define AM33XX_D_CAN1_BASE	(void *)(0x481D0000u)

#define AM33XX_ASP0_BASE	(void *)(0x48038000u)
#define AM33XX_ASP1_BASE	(void *)(0x4803C000u)

#define AM33XX_MMC0_BASE	(void *)(0x48060100u)
#define AM33XX_MMC1_BASE	(void *)(0x481D8100u)
#define AM33XX_MMC2_BASE	(void *)(0x47810100u)

#define AM33XX_SPI0_BASE	(void *)(0x48030000u)
#define AM33XX_SPI1_BASE	(void *)(0x481A0000u)
*/

#endif
