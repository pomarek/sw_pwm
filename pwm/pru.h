/*
 * pwm_pru.h
 *
 *  Created on: 2011-12-22
 *      Author: szakal
 */

#ifndef PWM_PRU_H_
#define PWM_PRU_H_
#include "ecap.h"
/*****************************************************/
/********	DEFINES **********************************/
/*****************************************************/
#define PRU_INTERNAL_RAM_SIZE	(8*1024) /* in bytes */
#define PRU_SHARED_DATA_RAM_SIZE	(12*1024)





/*****************************************************/
/********	ENUMS   **********************************/
/*****************************************************/
typedef enum
{
	PRU_ID_PRU0,
	PRU_ID_PRU1,
	PRU_ID_PRU_NUM
}pru_id_t;

typedef enum
{
	PRU_ERROR_NO_ERROR = 0,
	PRU_ERROR_CLOCKING,
	PRU_ERROR_POWER_DOMAIN,
	PRU_ERROR_NOT_INITIALIZED,
	PRU_ERROR_PRU_NOT_RUNNING,
	PRU_ERROR_PRU_NOT_HALTED,
	PRU_ERROR_INVALID_ID,
	PRU_ERROR_DATA_ERROR,
	PRU_ERROR_ALREADY_INITIALIZED,
	PRU_ERROR_ALLOCATION_ERROR,
	PRU_ERROR_ECAP_INIT_ERROR,
	PRU_ERROR_UNKNOWN_ERROR
}pru_error_t;

/*****************************************************/
/********	MEMORY STRUCTURES ************************/
/*****************************************************/
typedef struct
{
	unsigned int CONTROL;			/* @ 0x000 */
	unsigned int STATUS;			/* @ 0x04h */
	unsigned int WAKEUP;			/* @ 0x08h */
	unsigned int CYCLE;				/* @ 0x0Ch */
	unsigned int STALL;				/* @ 0x10h */
	unsigned int _par[3];			/* @ 0x14h, 0x18h, 0x1Ch */
	unsigned int CTBIR0;			/* @ 0x20h */
	unsigned int CTBIR1;			/* @ 0x24h */
	unsigned int CTPPR0;			/* @ 0x28h */
	unsigned int CTPPR1;			/* @ 0x2Ch */
}PRUSS_PRU_CTRL_t;


typedef struct
{
	unsigned int GPREG[32]; 		/* 0x00h - 0x80h */
	unsigned int CT_REG[32]; 		/* 0x80h - 0x100h */
}PRUSS_PRU_DEBUG_t;

#define CH_MAP_0_3		0
#define CH_MAP_8_11		0
#define CH_MAP_16_19	0
#define CH_MAP_24_27	0
#define INTC_INT_CLEAR	1
#define SECOND_REG_OFFSET	32

#define GET_INT_INDEX(X) (((X)>31)?((X)-SECOND_REG_OFFSET):(X))

typedef enum
{
	INTC_INTERRUPTS_DISABLED = 0,
	INTC_INTERRUPTS_ENABLED  = 1
}intc_interrupt_state_t;

typedef enum
{
	/*add here others - there are too many of them for me to add them all */
	ECAP_INTR_INTR_PEND_ECAP0	= 42
}intc_system_event_t;
typedef enum
{
	INTC_CH_MAP_0 		= CH_MAP_0_3,
	INTC_CH_MAP_1		= CH_MAP_8_11,
	INTC_CH_MAP_2		= CH_MAP_16_19,
	INTC_CH_MAP_3		= CH_MAP_24_27,
	INTC_CH_MAP_4 		= CH_MAP_0_3,
	INTC_CH_MAP_5		= CH_MAP_8_11,
	INTC_CH_MAP_6		= CH_MAP_16_19,
	INTC_CH_MAP_7		= CH_MAP_24_27,
	INTC_CH_MAP_8 		= CH_MAP_0_3,
	INTC_CH_MAP_9		= CH_MAP_8_11,
	INTC_CH_MAP_10		= CH_MAP_16_19,
	INTC_CH_MAP_11		= CH_MAP_24_27,
	INTC_CH_MAP_12 		= CH_MAP_0_3,
	INTC_CH_MAP_13		= CH_MAP_8_11,
	INTC_CH_MAP_14		= CH_MAP_16_19,
	INTC_CH_MAP_15		= CH_MAP_24_27,
	INTC_CH_MAP_16 		= CH_MAP_0_3,
	INTC_CH_MAP_17		= CH_MAP_8_11,
	INTC_CH_MAP_18		= CH_MAP_16_19,
	INTC_CH_MAP_19		= CH_MAP_24_27,
	INTC_CH_MAP_20 		= CH_MAP_0_3,
	INTC_CH_MAP_21		= CH_MAP_8_11,
	INTC_CH_MAP_22		= CH_MAP_16_19,
	INTC_CH_MAP_23		= CH_MAP_24_27,
	INTC_CH_MAP_24 		= CH_MAP_0_3,
	INTC_CH_MAP_25		= CH_MAP_8_11,
	INTC_CH_MAP_26		= CH_MAP_16_19,
	INTC_CH_MAP_27		= CH_MAP_24_27,
	INTC_CH_MAP_28 		= CH_MAP_0_3,
	INTC_CH_MAP_29		= CH_MAP_8_11,
	INTC_CH_MAP_30		= CH_MAP_16_19,
	INTC_CH_MAP_31		= CH_MAP_24_27,
	INTC_CH_MAP_32 		= CH_MAP_0_3,
	INTC_CH_MAP_33		= CH_MAP_8_11,
	INTC_CH_MAP_34		= CH_MAP_16_19,
	INTC_CH_MAP_35		= CH_MAP_24_27,
	INTC_CH_MAP_36 		= CH_MAP_0_3,
	INTC_CH_MAP_37		= CH_MAP_8_11,
	INTC_CH_MAP_38		= CH_MAP_16_19,
	INTC_CH_MAP_39		= CH_MAP_24_27,
	INTC_CH_MAP_40 		= CH_MAP_0_3,
	INTC_CH_MAP_41		= CH_MAP_8_11,
	INTC_CH_MAP_42		= CH_MAP_16_19,
	INTC_CH_MAP_43		= CH_MAP_24_27,
	INTC_CH_MAP_44 		= CH_MAP_0_3,
	INTC_CH_MAP_45		= CH_MAP_8_11,
	INTC_CH_MAP_46		= CH_MAP_16_19,
	INTC_CH_MAP_47		= CH_MAP_24_27,
	INTC_CH_MAP_48 		= CH_MAP_0_3,
	INTC_CH_MAP_49		= CH_MAP_8_11,
	INTC_CH_MAP_50		= CH_MAP_16_19,
	INTC_CH_MAP_51		= CH_MAP_24_27,
	INTC_CH_MAP_52 		= CH_MAP_0_3,
	INTC_CH_MAP_53		= CH_MAP_8_11,
	INTC_CH_MAP_54		= CH_MAP_16_19,
	INTC_CH_MAP_55		= CH_MAP_24_27,
	INTC_CH_MAP_56 		= CH_MAP_0_3,
	INTC_CH_MAP_57		= CH_MAP_8_11,
	INTC_CH_MAP_58		= CH_MAP_16_19,
	INTC_CH_MAP_59		= CH_MAP_24_27,
	INTC_CH_MAP_60 		= CH_MAP_0_3,
	INTC_CH_MAP_61		= CH_MAP_8_11,
	INTC_CH_MAP_62		= CH_MAP_16_19,
	INTC_CH_MAP_63		= CH_MAP_24_27
}intc_ch_map_t;

typedef enum
{
	INTC_CHANNEL_0	= 0,
	INTC_CHANNEL_1,
	INTC_CHANNEL_2,
	INTC_CHANNEL_3,
	INTC_CHANNEL_4,
	INTC_CHANNEL_5,
	INTC_CHANNEL_6,
	INTC_CHANNEL_7,
	INTC_CHANNEL_8,
	INTC_CHANNEL_9
}intc_channel_t;

typedef enum
{
	INTC_SIPR_ACTIVE_LOW 		= 0x0,
	INTC_SIPR_ACTIVE_HIGH 		= 0x1,
	INTC_SIPR_ALL_ACTIVE_LOW 	= 0x0,
	INTC_SIPR_ALL_ACTIVE_HIGH 	= 0xFFFFFFFF
}intc_sipr_vals_t;

typedef enum
{
	INTC_SIPR_INDEX_0_31	= 0,
	INTC_SIPR_INDEX_32_63
}intc_sipr_index_t;

typedef enum
{
	INTC_SITR_PULSE 	= 0x0,
	INTC_SITR_EDGE 		= 0x1,
	INTC_SITR_ALL_PULSE = 0x0,
	INTC_SITR_ALL_EDGE 	= 0xFFFFFFFF
}intc_sitr_vals_t;

typedef enum
{
	INTC_SITR_INDEX_0_31	= 0,
	INTC_SITR_INDEX_32_63
}intc_sitr_index_t;


typedef enum
{
	INTC_SECR_INDEX_0_31	= 0,
	INTC_SECR_INDEX_32_63
}intc_secr_index_t;


typedef enum
{
	INTC_CMR_INDEX_0_3	= 0,
	INTC_CMR_INDEX_4_7,
	INTC_CMR_INDEX_8_11,
	INTC_CMR_INDEX_12_15,
	INTC_CMR_INDEX_16_19,
	INTC_CMR_INDEX_20_23,
	INTC_CMR_INDEX_24_27,
	INTC_CMR_INDEX_28_31,
	INTC_CMR_INDEX_32_35,
	INTC_CMR_INDEX_36_39,
	INTC_CMR_INDEX_40_43,
	INTC_CMR_INDEX_44_47,
	INTC_CMR_INDEX_48_51,
	INTC_CMR_INDEX_52_55,
	INTC_CMR_INDEX_56_59,
	INTC_CMR_INDEX_60_63
}intc_cmr_index_t;

typedef enum
{
	INTC_HINT_MAP_0 = 0,
	INTC_HINT_MAP_1	= 8,
	INTC_HINT_MAP_2 = 16,
	INTC_HINT_MAP_3 = 24,
	INTC_HINT_MAP_4 = 0,
	INTC_HINT_MAP_5 = 8,
	INTC_HINT_MAP_6 = 16,
	INTC_HINT_MAP_7 = 24,
	INTC_HINT_MAP_8 = 0,
	INTC_HINT_MAP_9 = 8
}intc_hint_map_offset_t;

typedef enum
{
	INTC_HMR_INDEX_0_3 = 0,
	INTC_HMR_INDEX_4_7,
	INTC_HMR_INDEX_8_10
}intc_hmr_index_t;


typedef struct
{
	unsigned int REVID; 				/* 0x0000h */
	unsigned int _par0[3];
	unsigned int GER;					/* 0x0010h */
	unsigned int _pad1[2];
	unsigned int GNLR;					/* 0x001Ch */
	unsigned int SISR;					/* 0x0020h */
	unsigned int SICR;					/* 0x0024h */
	unsigned int EISR;					/* 0x0028h */
	unsigned int EICR;					/* 0x002Ch */
	unsigned int _pad2[1];
	unsigned int HIEISR;				/* 0x0034h */
	unsigned int HIDISR;				/* 0x0038h */
	unsigned int _pad3[0x11];
	unsigned int GPIR;					/* 0x0080h */
	unsigned int _pad4[0x5F];
	unsigned int SRSR[2];				/* 0x0200h */
	unsigned int _pad5[0x1E];
	unsigned int SECR[2];				/* 0x0280h */
	unsigned int _pad6[0x1E];
	unsigned int ERS[2];				/* 0x0300h */
	unsigned int _pad7[0x1E];
	unsigned int ECR[2];				/* 0x0380h */
	unsigned int _pad8[0x1E];
	unsigned int CMR[16];				/* 0x0400h */
	unsigned int _pad9[0xF0];
	unsigned int HMR[3];				/* 0x0800h */
	unsigned int _pad10[0x3D];
	unsigned int HIPIR[10];				/* 0x0900h */
	unsigned int _pad11[0xF6];
	unsigned int SIPR[2];				/* 0x0D00h */
	unsigned int _pad12[0x1E];
	unsigned int SITR[2];				/* 0x0D80h */
	unsigned int _pad13[0xDE];
	unsigned int HINLR[10];				/* 0x1100h */
	unsigned int _pad14[0xF6];
	unsigned int HIER;					/* 0x1500h */
}PRUSS_INTC_t;

typedef struct
{
	unsigned int REVID;					/* 0x00 */
	unsigned int SYSCFG;				/* 0x04 */
	unsigned int GPCFG0;				/* 0x08 */
	unsigned int GPCFG1;				/* 0x0C */
	unsigned int CGR;					/* 0x10 */
 	unsigned int ISRP;					/* 0x14 */
	unsigned int ISP;					/* 0x18 */
	unsigned int IESP;					/* 0x1C */
	unsigned int IECP;					/* 0x20 */
	unsigned int SCRP;					/* 0x24 */
	unsigned int PMAO;					/* 0x28 */
	unsigned int MII_RT;				/* 0x2C */
	unsigned int IEPCLK;				/* 0x30 */
	unsigned int SPP;					/* 0x34 */
	unsigned int _pad[2];				/* 0x38, 0x3C */
	unsigned int PIN_MX;				/* 0x40 */
}PRUSS_CFG_t;

typedef struct
{
	unsigned int PRU_data_ram[PRU_ID_PRU_NUM][PRU_INTERNAL_RAM_SIZE>>2];	/* 0x0000 0000 to 0x0000 2000 *//* 0x0000 2000 to 0x0000 4000 */
//	unsigned int PRU1_data_ram[PRU_INTERNAL_RAM_SIZE>>2];					/* 0x0000 2000 to 0x0000 4000 */
	unsigned int _pad0[0x03000];											/* 0x0000 4000 to 0x0001 0000 */
	unsigned int shared_ram[PRU_SHARED_DATA_RAM_SIZE>>2];					/* 0x0001 0000 to 0x0001 3000 */
	unsigned int _pad1[0x03400];											/* 0x0001 3000 to 0x0002 0000 */
	PRUSS_INTC_t INTC;														/* 0x0002 0000 to 0x0002 1504 */
	unsigned int _pad2[0x02BF];											 	/* 0x0002 1504 to 0x0002 2000 */
	PRUSS_PRU_CTRL_t PRU0_control;											/* 0x0002 2000 to 0x0002 2030 */
	unsigned int _pad3[0x0F4];												/* 0x0002 2030 to 0x0002 2400 */
	PRUSS_PRU_DEBUG_t PRU0_debug;											/* 0x0002 2400 to 0x0002 2500 */
	unsigned int _pad4[0x06C0];												/* 0x0002 2500 to 0x0002 4000 */
	PRUSS_PRU_CTRL_t PRU1_control;					 						/* 0x0002 4000 to 0x0002 4030 */
	unsigned int _pad5[0x0F4];												/* 0x0002 4030 to 0x0002 4400 */
	PRUSS_PRU_DEBUG_t PRU1_debug;											/* 0x0002 4400 to 0x0002 4500 */
	unsigned int _pad6[0x06C0];												/* 0x0002 4500 to 0x0002 6000 */
	PRUSS_CFG_t CFG;														/* 0x0002 6000 to 0x0002 6044 */
	unsigned int _pad7[0x07EF];												/* 0x0002 6044 to 0x0002 8000 */
	unsigned int UART0[0x0800];												/* 0x0002 8000 to 0x0002 A000 */
	unsigned int Reserved0[0x0800];											/* 0x0002 A000 to 0x0002 C000 */
	unsigned int Reserved1[0x0800];											/* 0x0002 C000 to 0x0002 E000 */
	unsigned int IEP[0x0800];												/* 0x0002 E000 to 0x0003 0000 */
	ecap_mem_t eCAP0;														/* 0x0003 0000 to 0x0003 0060 */
	unsigned int _pad8[0x07E8];												/* 0x0003 0060 to 0x0003 2000 */
	unsigned int MII_RT_CFG[0x0100];										/* 0x0003_2000 to 0x0003 2400 */
	unsigned int MII_MDIO[0x0700];											/* 0x0003_2400 to 0x0003 4000 */
	unsigned int PRU0_iram[PRU_INTERNAL_RAM_SIZE>>2];						/* 0x0003_4000 to 0x0003_6000 */
	unsigned int pad13[PRU_INTERNAL_RAM_SIZE>>2];							/* 0x0003_6000 to 0x0003_8000 */
	unsigned int PRU1_iram[PRU_INTERNAL_RAM_SIZE>>2];						/* 0x0003_8000 to 0x0003_A000 */
}pruss_mem_t;


/*****************************************************/
/********	FUNCTION PROTOTYPES   ********************/
/*****************************************************/

pru_error_t pru_init(void);
pruss_mem_t * pru_get_memory_space(void);
pru_error_t pru_close(void);
pru_error_t pru_upload(pru_id_t id, const unsigned int * data, unsigned int len);
pru_error_t pru_run(pru_id_t id);
pru_error_t pru_halt(pru_id_t id);
pru_error_t pru_reset(pru_id_t id);
pru_error_t pru_config_int(pru_id_t id);



#endif /* PWM_PRU_H_ */
