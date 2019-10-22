#include "LUTILS.h"
#include "LSTD_TYPES.h"
#include "MTIMER2_private.h"
#include "MTIMER2_interface.h"
#include "MDIO_interface.h"



void MTIMER2_init(u8 delay_type)
{
	switch(delay_type)
	{
		case delay_ms:
			MTIMER2 -> PSC  = (u16)7999;
			MTIMER2 -> CR1  = (u16)0x0088;
			break;

		case delay_us:
			MTIMER2 -> PSC  = (u16)7;
			MTIMER2 -> CR1  = (u16)0x0088;
			break;
	}
	return;
}

void MTIMER2_delay_ms(u16 value)
{
	MTIMER2 -> ARR = value;
	SET_BIT((MTIMER2 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER2 -> SR),SR_UIF) == 0);
	CLEAR_BIT((MTIMER2 -> SR),SR_UIF);
	return;
}

void MTIMER2_delay_us(u16 value)
{
	MTIMER2 -> ARR = value;
	SET_BIT((MTIMER2 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER2 -> SR),SR_UIF) == 0);
	CLEAR_BIT((MTIMER2 -> SR),SR_UIF);
	return;
}

