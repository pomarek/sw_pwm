#include <stdio.h>
#include "pru.h"

#define STRUCT_OFFSET(STRUCT, FIELD) (&(((STRUCT*)0)->FIELD))

#define PRINT_FIELD(STRUCT,FIELD) printf("Structure %s field %s, offset %p, field size 0x%x\r\n", #STRUCT, #FIELD, STRUCT_OFFSET(STRUCT, FIELD), sizeof(((STRUCT*)0)->FIELD))
#define PRINT_STRUCT(STRUCT) printf("Struct %s, size %x\r\n", #STRUCT, sizeof(STRUCT));

int print_structures(void);

int main(int argc, char *argv[])
{
	print_structures();
	return 0;
}


int print_pru_data(void)
{
	PRINT_STRUCT(pruss_mem_t);
	PRINT_FIELD(pruss_mem_t, PRU0_data_ram);
	PRINT_FIELD(pruss_mem_t, PRU1_data_ram);
	PRINT_FIELD(pruss_mem_t, shared_ram);
	PRINT_FIELD(pruss_mem_t, INTC);
	PRINT_FIELD(pruss_mem_t, PRU0_control);
	PRINT_FIELD(pruss_mem_t, PRU0_debug);
	PRINT_FIELD(pruss_mem_t, PRU1_control);
	PRINT_FIELD(pruss_mem_t, PRU1_debug);
	PRINT_FIELD(pruss_mem_t, CFG);
	PRINT_FIELD(pruss_mem_t, UART0);
	PRINT_FIELD(pruss_mem_t, Reserved0);
	PRINT_FIELD(pruss_mem_t, Reserved1);
	PRINT_FIELD(pruss_mem_t, IEP);
	PRINT_FIELD(pruss_mem_t, eCAP0);
	PRINT_FIELD(pruss_mem_t, MII_RT_CFG);
	PRINT_FIELD(pruss_mem_t, MII_MDIO);
	PRINT_FIELD(pruss_mem_t, PRU0_iram);
	PRINT_FIELD(pruss_mem_t, PRU1_iram);
	return 0;
}

int print_structures(void)
{
	return print_pru_data();
}
