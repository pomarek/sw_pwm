/*
 * pwm_pru.h
 *
 *  Created on: 2011-12-22
 *      Author: szakal
 */

#ifndef PWM_PRU_H_
#define PWM_PRU_H_


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
	unsigned int eCAP0[0x0800];												/* 0x0003 0000 to 0x0003 2000 */
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



#endif /* PWM_PRU_H_ */
