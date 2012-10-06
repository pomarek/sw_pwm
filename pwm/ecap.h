/*
 * ecap.h
 *
 *  Created on: 2012-03-13
 *      Author: pomarek
 */

#ifndef ECAP_H_
#define ECAP_H_


//#define ECCTL2_APWMPOL_BIT		10
//#define ECCTL2_CAP_APWM_BIT		9
//#define ECCTL2_TSCTRSTOP_BIT	4

//#define ECEINT_CTROVF_BIT		5



//typedef enum
//{
//	ECAP_ID_ECAP0,
//	ECAP_ID_ECAP1,
//	ECAP_ID_ECAP2
//}ecap_id_t;


typedef struct
{
	unsigned int TSCTR;
	unsigned int CTRPHS;
	unsigned int CAP1;
	unsigned int CAP2;
	unsigned int CAP3;
	unsigned int CAP4;
	unsigned _pad0[4];
	unsigned short ECCTL1;
	unsigned short ECCTL2;
	unsigned short ECEINT;
	unsigned short ECFLG;
	unsigned short ECCLR;
	unsigned short ECFRC;
	unsigned int _pad1[10];
	unsigned int REVID;
}ecap_mem_t;


//int ecap_enable(ecap_id_t id);
//ecap_mem_t * ecap_init(ecap_id_t id);
//void ecap_close(ecap_id_t id);
//int ecap_set_apwm_mode(ecap_mem_t * mem, BOOL active_high, unsigned int phase, unsigned int cmp);
//int ecap_enable_int(ecap_mem_t * mem);


#endif /* ECAP_H_ */
