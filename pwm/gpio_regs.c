#include <linux/kernel.h> /* printk() */
#include <linux/io.h>
#include <linux/ioport.h>
#include "gpio_regs.h"


#define CM_BASE		0x44E10000

typedef enum
{
	GPIO_BANK_0,
	GPIO_BANK_1,
	GPIO_BANK_2,
	GPIO_BANK_3,
	GPIO_BANK_NUM
}gpio_banks_t;

typedef enum
{
	GPIO_REVISION 			= 0x0,
	GPIO_SYSCONFIG 			= 0x10,
	GPIO_EOI 				= 0x20,
	GPIO_IRQSTATUS_RAW_0 	= 0x24,
	GPIO_IRQSTATUS_RAW_1 	= 0x28,
	GPIO_IRQSTATUS_0 		= 0x2C,
	GPIO_IRQSTATUS_1 		= 0x30,
	GPIO_IRQSTATUS_SET_0 	= 0x34,
	GPIO_IRQSTATUS_SET_1 	= 0x38,
	GPIO_IRQSTATUS_CLR_0 	= 0x3C,
	GPIO_IRQSTATUS_CLR_1 	= 0x40,
	GPIO_SYSSTATUS 			= 0x114,
	GPIO_CTRL 				= 0x130,
	GPIO_OE 				= 0x134,
	GPIO_DATAIN 			= 0x138,
	GPIO_DATAOUT 			= 0x13C,
	GPIO_LEVELDETECT0		= 0x140,
	GPIO_LEVELDETECT1 		= 0x144,
	GPIO_RISINGDETECT 		= 0x148,
	GPIO_FALLINGDETECT 		= 0x14C,
	GPIO_DEBOUNCENABLE 		= 0x150,
	GPIO_DEBOUNCINGTIME 	= 0x154,
	GPIO_CLEARDATAOUT 		= 0x190,
	GPIO_SETDATAOUT 		= 0x194

}gpio_regs_t;

unsigned int banks[GPIO_BANK_NUM]={0x44E07000, 0x4804C000, 0x481AC000, 0x481AE000 };

gpio_desc_t  gpio_mux[]=
{
/* gpio0_0 */		{"MDIO", 				CM_BASE+0x948,		0},
/* gpio0_1 */		{"MDC",					CM_BASE+0x94C,		0},
/* gpio0_2 */		{"SPI0_SCLK",			CM_BASE+0x950,		1},
/* gpio0_3 */		{"SPI0_D0",				CM_BASE+0x954,		1},
/* gpio0_4 */		{"SPI0_D1",				CM_BASE+0x958,		1},
/* gpio0_5 */		{"SPI0_CS0",			CM_BASE+0x95C,		1},
/* gpio0_6 */		{"SPI0_CS1",			CM_BASE+0x960,		0},
/* gpio0_7 */		{"ECAP0_IN_PWM0_OUT",	CM_BASE+0x964,		1},
/* gpio0_8 */		{"LCD_DATA12",			CM_BASE+0x8D0,		1},
/* gpio0_9 */		{"LCD_DATA13",			CM_BASE+0x8D4,		1},
/* gpio0_10 */		{"LCD_DATA14",			CM_BASE+0x8D8,		1},
/* gpio0_11 */		{"LCD_DATA15",			CM_BASE+0x8DC,		1},
/* gpio0_12 */		{"UART1_CTSn",			CM_BASE+0x978,		1},
/* gpio0_13 */		{"UART1_RTSn",			CM_BASE+0x97C,		1},
/* gpio0_14 */		{"UART1_RXD",			CM_BASE+0x980,		1},
/* gpio0_15 */		{"UART1_TXD",			CM_BASE+0x984,		1},
/* gpio0_16 */		{"MII1_TXD3",			CM_BASE+0x91C,		0},
/* gpio0_17 */		{"MII1_TXD2",			CM_BASE+0x920,		0},
/* gpio0_18 */		{"USB0_DRVVBUS",		CM_BASE+0xA1C,		0},
/* gpio0_19 */		{"XDMA_EVENT_INTR0",	CM_BASE+0x9B0,		0},
/* gpio0_20 */		{"XDMA_EVENT_INTR1",	CM_BASE+0x9B4,		0},
/* gpio0_21 */		{"MII1_TXD1",			CM_BASE+0x924,		0},
/* gpio0_22 */		{"GPMC_AD8",			CM_BASE+0x820,		1},
/* gpio0_23 */		{"GPMC_AD9",			CM_BASE+0x824,		1},
/* gpio0_24 */		{"NONE",				0,					0},
/* gpio0_25 */		{"NONE",				0,					0},
/* gpio0_26 */		{"GPMC_AD10",			CM_BASE+0x828,		1},
/* gpio0_27 */		{"GPMC_AD11",			CM_BASE+0x82C,		1},
/* gpio0_28 */		{"MII1_TXD0",			CM_BASE+0x928,		0},
/* gpio0_29 */		{"RMII1_REF_CLK",		CM_BASE+0x944,		0},
/* gpio0_30 */		{"GPMC_WAIT0",			CM_BASE+0x870,		1},
/* gpio0_31 */		{"GPMC_WPn",			CM_BASE+0x874,		1},

/* gpio1_0 */		{"GPMC_AD0",			CM_BASE+0x800,		1},
/* gpio1_1 */		{"GPMC_AD1",			CM_BASE+0x804,		1},
/* gpio1_2 */		{"GPMC_AD2",			CM_BASE+0x808,		1},
/* gpio1_3 */		{"GPMC_AD3",			CM_BASE+0x80C,		1},
/* gpio1_4 */		{"GPMC_AD4",			CM_BASE+0x810,		1},
/* gpio1_5 */		{"GPMC_AD5",			CM_BASE+0x814,		1},
/* gpio1_6 */		{"GPMC_AD6",			CM_BASE+0x818,		1},
/* gpio1_7 */		{"GPMC_AD7",			CM_BASE+0x81C,		1},
/* gpio1_8 */		{"UART0_CTSn",			CM_BASE+0x968,		0},
/* gpio1_9 */		{"UART0_RTSn",			CM_BASE+0x96C,		0},
/* gpio1_10 */		{"UART0_RXD",			CM_BASE+0x970,		0},
/* gpio1_11 */		{"UART0_TXD",			CM_BASE+0x974,		0},
/* gpio1_12 */		{"GPMC_AD12",			CM_BASE+0x830,		1},
/* gpio1_13 */		{"GPMC_AD13",			CM_BASE+0x834,		1},
/* gpio1_14 */		{"GPMC_AD14",			CM_BASE+0x838,		1},
/* gpio1_15 */		{"GPMC_AD15",			CM_BASE+0x83C,		1},
/* gpio1_16 */		{"GPMC_A0",				CM_BASE+0x840,		1},
/* gpio1_17 */		{"GPMC_A1",				CM_BASE+0x844,		1},
/* gpio1_18 */		{"GPMC_A2",				CM_BASE+0x848,		1},
/* gpio1_19 */		{"GPMC_A3",				CM_BASE+0x84C,		1},
/* gpio1_20 */		{"GPMC_A4",				CM_BASE+0x850,		0},
/* gpio1_21 */		{"GPMC_A5",				CM_BASE+0x854,		1},/* LED */
/* gpio1_22 */		{"GPMC_A6",				CM_BASE+0x858,		1},/* LED */
/* gpio1_23 */		{"GPMC_A7",				CM_BASE+0x85C,		1},/* LED */
/* gpio1_24 */		{"GPMC_A8",				CM_BASE+0x860,		1},/* LED */
/* gpio1_25 */		{"GPMC_A9",				CM_BASE+0x864,		0},
/* gpio1_26 */		{"GPMC_A10",			CM_BASE+0x868,		0},
/* gpio1_27 */		{"GPMC_A11",			CM_BASE+0x86C,		0},
/* gpio1_28 */		{"GPMC_BEn1",			CM_BASE+0x878,		1},
/* gpio1_29 */		{"GPMC_CSn0",			CM_BASE+0x87C,		1},
/* gpio1_30 */		{"GPMC_CSn1",			CM_BASE+0x880,		1},
/* gpio1_31 */		{"GPMC_CSn2",			CM_BASE+0x884,		1},

/* gpio2_0 */		{"GPMC_CSn3",			CM_BASE+0x888,		0},
/* gpio2_1 */		{"GPMC_CLK",			CM_BASE+0x88C,		1},
/* gpio2_2 */		{"GPMC_ADVn_ALE",		CM_BASE+0x890,		1},
/* gpio2_3 */		{"GPMC_OEn_REn",		CM_BASE+0x894,		1},
/* gpio2_4 */		{"GPMC_WEn",			CM_BASE+0x898,		1},
/* gpio2_5 */		{"GPMC_BEn0_CLE",		CM_BASE+0x89C,		1},
/* gpio2_6 */		{"LCD_DATA0",			CM_BASE+0x8A0,		1},
/* gpio2_7 */		{"LCD_DATA1",			CM_BASE+0x8A4,		1},
/* gpio2_8 */		{"LCD_DATA2",			CM_BASE+0x8A8,		1},
/* gpio2_9 */		{"LCD_DATA3",			CM_BASE+0x8AC,		1},
/* gpio2_10 */		{"LCD_DATA4",			CM_BASE+0x8B0,		1},
/* gpio2_11 */		{"LCD_DATA5",			CM_BASE+0x8B4,		1},
/* gpio2_12 */		{"LCD_DATA6",			CM_BASE+0x8B8,		1},
/* gpio2_13 */		{"LCD_DATA7",			CM_BASE+0x8BC,		1},
/* gpio2_14 */		{"LCD_DATA8",			CM_BASE+0x8C0,		1},
/* gpio2_15 */		{"LCD_DATA9",			CM_BASE+0x8C4,		1},
/* gpio2_16 */		{"LCD_DATA10",			CM_BASE+0x8C8,		1},
/* gpio2_17 */		{"LCD_DATA11",			CM_BASE+0x8CC,		1},
/* gpio2_18 */		{"MII1_RXD3",			CM_BASE+0x934,		0},
/* gpio2_19 */		{"MII1_RXD2",			CM_BASE+0x938,		0},
/* gpio2_20 */		{"MII1_RXD1",			CM_BASE+0x93C,		0},
/* gpio2_21 */		{"MII1_RXD0",			CM_BASE+0x940,		0},
/* gpio2_22 */		{"LCD_VSYNC",			CM_BASE+0x8E0,		1},
/* gpio2_23 */		{"LCD_HSYNC",			CM_BASE+0x8E4,		1},
/* gpio2_24 */		{"LCD_PCLK",			CM_BASE+0x8E8,		1},
/* gpio2_25 */		{"LCD_AC_BIAS_EN",		CM_BASE+0x8EC,		1},
/* gpio2_26 */		{"MMC0_DAT3",			CM_BASE+0x8F0,		0},
/* gpio2_27 */		{"MMC0_DAT2",			CM_BASE+0x8F4,		0},
/* gpio2_28 */		{"MMC0_DAT1",			CM_BASE+0x8F8,		0},
/* gpio2_29 */		{"MMC0_DAT0",			CM_BASE+0x8FC,		0},
/* gpio2_30 */		{"MMC0_CLK",			CM_BASE+0x900,		0},
/* gpio2_31 */		{"MMC0_CMD",			CM_BASE+0x904,		0},


/* gpio3_0 */		{"MII1_COL",			CM_BASE+0x908,		0},
/* gpio3_1 */		{"MII1_CRS",			CM_BASE+0x90C,		0},
/* gpio3_2 */		{"MII1_RX_ER",			CM_BASE+0x910,		0},
/* gpio3_3 */		{"MII1_TX_EN",			CM_BASE+0x914,		0},
/* gpio3_4 */		{"MII1_RX_DV",			CM_BASE+0x918,		0},
/* gpio3_5 */		{"I2C0_SDA",			CM_BASE+0x988,		0},
/* gpio3_6 */		{"I2C0_SCL",			CM_BASE+0x98C,		0},
/* gpio3_7 */		{"EMU0",				CM_BASE+0x9E4,		0},
/* gpio3_8 */		{"EMU1",				CM_BASE+0x9E8,		0},
/* gpio3_9 */		{"MII1_TX_CLK",			CM_BASE+0x92C,		0},
/* gpio3_10 */		{"MII1_RX_CLK",			CM_BASE+0x930,		0},
/* gpio3_11 */		{"NONE",				0,					0},
/* gpio3_12 */		{"NONE",				0,					0},
/* gpio3_13 */		{"USB1_DRVVBUS",		CM_BASE+0xA34,		0},
/* gpio3_14 */		{"MCASP0_ACLKX",		CM_BASE+0x990,		1},
/* gpio3_15 */		{"MCASP0_FSX",			CM_BASE+0x994,		1},
/* gpio3_16 */		{"MCASP0_AXR0",			CM_BASE+0x998,		1},
/* gpio3_17 */		{"MCASP0_AHCLKR",		CM_BASE+0x99C,		1},
/* gpio3_18 */		{"MCASP0_ACLKR",		CM_BASE+0x9A0,		0},
/* gpio3_19 */		{"MCASP0_FSR",			CM_BASE+0x9A4,		1},
/* gpio3_20 */		{"MCASP0_AXR1",			CM_BASE+0x9A8,		0},
/* gpio3_21 */		{"MCASP0_AHCLKX",		CM_BASE+0x9AC,		1},
/* gpio3_22 */		{"NONE",				0,					0},
/* gpio3_23 */		{"NONE",				0,					0},
/* gpio3_24 */		{"NONE",				0,					0},
/* gpio3_25 */		{"NONE",				0,					0},
/* gpio3_26 */		{"NONE",				0,					0},
/* gpio3_27 */		{"NONE",				0,					0},
/* gpio3_28 */		{"NONE",				0,					0},
/* gpio3_29 */		{"NONE",				0,					0},
/* gpio3_30 */		{"NONE",				0,					0},
/* gpio3_31 */		{"NONE",				0,					0},
};

int set_ball_mux(int bank, int bit, int mux_fun)
{
	unsigned int *reg;
	if(gpio_mux[bank*32 +bit].valid)
	{
		printk(KERN_INFO "set mux fun %d for gpio%d_%d\r\n", mux_fun, bank, bit);
		reg = (unsigned int *) ioremap_nocache(gpio_mux[bank*32 +bit].mux_addr, sizeof(unsigned int));
		if(reg == NULL)
		{
			printk(KERN_ERR "unable to set mux fun %d for gpio%d_%d\r\n", mux_fun, bank, bit);
			return -1;
		}
		*reg = mux_fun;
		iounmap(reg);
		printk(KERN_INFO "set mux fun %d for gpio%d_%d done\r\n", mux_fun, bank, bit);
		return 0;
	}
	else
	{
		printk(KERN_ERR "mux fun %d for gpio%d_%d not valid\r\n", mux_fun, bank, bit);
		return -1;
	}

}

int set_gpio_dir(int bank, int bit, gpio_dir_t dir, int state)
{
	unsigned int *reg;
	if(gpio_mux[bank*32 +bit].valid)
	{
		printk(KERN_INFO "set dir for gpio%d_%d\r\n", bank, bit);
		reg = (unsigned int *) ioremap_nocache(banks[bank]+GPIO_OE, sizeof(unsigned int));
		if(reg == NULL)
		{
			printk(KERN_ERR "unable to set dir for gpio%d_%d\r\n", bank, bit);
			return -1;
		}

		if(dir == GPIO_DIR_OUT)
		{
			*reg &=~ (1<<bit);
			iounmap(reg);
			printk(KERN_INFO "set STATE for gpio%d_%d\r\n", bank, bit);
			reg = (unsigned int *) ioremap_nocache(banks[bank]+(state?GPIO_SETDATAOUT:GPIO_CLEARDATAOUT), sizeof(unsigned int));
			if(reg == NULL)
			{
				printk(KERN_ERR "unable to set state for gpio%d_%d\r\n", bank, bit);
				return -1;
			}
			*reg = 1<<bit;
		}
		else
			*reg |= (1<<bit);
		iounmap(reg);
		return 0;
	}
	else
	{
		printk(KERN_ERR "gpio%d_%d is not valid\r\n", bank, bit);
		return -1;
	}
}
