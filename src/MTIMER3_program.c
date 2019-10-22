#include "LUTILS.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MTIMER3_private.h"
#include "MTIMER3_interface.h"

void MTIMER3_init(u8 mode)
{
	switch(mode)
	{
		case delay_ms:
			MTIMER3 -> PSC  = (u16)7999;
			MTIMER3 -> CR1  = (u16)0x0088;
			break;

		case delay_us:
			MTIMER3 -> PSC  = (u16)7;
			MTIMER3 -> CR1  = (u16)0x0088;
			break;

		case PWM_channel_1_us:
			MTIMER3 -> CR1 	 = (u16)0x0081;
			MTIMER3 -> PSC 	 = (u16)7;
			MTIMER3 -> CCMR1 = (u16)0x0068;
			MTIMER3 -> CCER  = (u16)0x0001;
			break;

		case PWM_channel_1_IN:
			MTIMER3 -> CR1   = (u16)0x0001;
			MTIMER3 -> PSC 	 = (u16)7;
			MTIMER3 -> CCMR1 = (u16)0x0201;
			MTIMER3 -> CCER  = (u16)0x0031;
	}
	return;
}

void MTIMER3_delay_ms(u16 value)
{
	MTIMER3 -> ARR = value;
	SET_BIT((MTIMER3 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER3 -> SR),SR_UIF) == 0);
	CLEAR_BIT((MTIMER3 -> SR),SR_UIF);
	return;
}

void MTIMER3_delay_us(u16 value)
{
	MTIMER3 -> ARR = value;
	SET_BIT((MTIMER3 -> CR1),CR1_CEN);
	while(GET_BIT((MTIMER3 -> SR),SR_UIF) == 0);
	CLEAR_BIT((MTIMER3 -> SR),SR_UIF);
	return;
}


void MTIMER3_PWM(u8 channel,u16 CNT_value,u16 PWM_value)
{

	MTIMER3 -> ARR = CNT_value;
	switch(channel)
	{
		case MTIMER3_CH1_PORTA_6:
			MTIMER3 -> CCR1 = PWM_value;
			break;

		case MTIMER3_CH2_PORTA_7:
			MTIMER3 -> CCR2 = PWM_value;
			break;

		case MTIMER3_CH3_PORTB_0:
			MTIMER3 -> CCR3 = PWM_value;
			break;

		case MTIMER3_CH4_PORTB_1:
			MTIMER3 -> CCR4 = PWM_value;
			break;
	}

	while(GET_BIT((MTIMER3 -> SR),SR_UIF) == 0);
	CLEAR_BIT((MTIMER3 -> SR),SR_UIF);

	return;
}

u16 MTIMER3_PWM_PulseIn(u8 channel,u16 CNT_value)
{
	u16 value = 0;
	MTIMER3 -> ARR = CNT_value;
	switch(channel)
	{
		case MTIMER3_CH1_PORTA_6:
			while(!(GET_BIT((MTIMER3 -> SR),1) && GET_BIT((MTIMER3 -> SR),2)));
			CLEAR_BIT((MTIMER3 -> SR),1);
			CLEAR_BIT((MTIMER3 -> SR),2);
			value = ((MTIMER3 -> CCR2)-(MTIMER3 -> CCR1));
			return value;
			break;

		case MTIMER3_CH2_PORTA_7:
			while(GET_BIT((MTIMER3 -> SR),1) && GET_BIT((MTIMER3 -> SR),2));
			CLEAR_BIT((MTIMER3 -> SR),1);
			CLEAR_BIT((MTIMER3 -> SR),2);
			value = ((MTIMER3 -> CCR1)-(MTIMER3 -> CCR2));
			return value;
			break;

		case MTIMER3_CH3_PORTB_0:
			while(GET_BIT((MTIMER3 -> SR),3) && GET_BIT((MTIMER3 -> SR),4));
			CLEAR_BIT((MTIMER3 -> SR),3);
			CLEAR_BIT((MTIMER3 -> SR),4);
			value = ((MTIMER3 -> CCR3)-(MTIMER3 -> CCR4));
			return value;
			break;

		case MTIMER3_CH4_PORTB_1:
			while(GET_BIT((MTIMER3 -> SR),3) && GET_BIT((MTIMER3 -> SR),4));
			CLEAR_BIT((MTIMER3 -> SR),3);
			CLEAR_BIT((MTIMER3 -> SR),4);
			value = ((MTIMER3 -> CCR3)-(MTIMER3 -> CCR4));
			return value;
			break;

	}
	return value;
}
