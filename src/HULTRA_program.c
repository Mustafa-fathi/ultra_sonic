#include "LUTILS.h"
#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "MTIMER2_interface.h"
#include "MTIMER3_interface.h"
#include "HULTRA_private.h"
#include "HULTRA_interface.h"

void HULTRA_attachPin(u8 trig_port,u8 trig,u8 echo)
{
	MDIO_pinMode(trig_port,trig,OUTPUT_PUSHPULL_2);

	switch(echo)
	{
		case MTIMER3_CH1_PORTA_6:
			MDIO_pinMode(MDIO_PORTA,6,INPUT_FLOAT);
			break;

		case MTIMER3_CH2_PORTA_7:
			MDIO_pinMode(MDIO_PORTA,7,INPUT_FLOAT);
			break;

		case MTIMER3_CH3_PORTB_0:
			MDIO_pinMode(MDIO_PORTB,0,INPUT_FLOAT);
			break;

		case MTIMER3_CH4_PORTB_1:
			MDIO_pinMode(MDIO_PORTB,1,INPUT_FLOAT);
			break;
	}
	return;
}

void HULTRA_Trig(u8 port,u8 pin)
{
	MDIO_setPin(port,pin);
	MTIMER2_delay_us(1000);
	MDIO_clrPin(port,pin);
	return;
}

u16 HULTRA_Distance(u8 channel)
{
	u16 time = 0;

	switch(channel)
	{
		case MTIMER3_CH1_PORTA_6:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH1_PORTA_6,38000);
			MTIMER2_delay_us(60000);
			return (u16)(0.034*(time/2));
			break;

		case MTIMER3_CH2_PORTA_7:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH2_PORTA_7,38000);
			return (u16)(0.034*(time/2));
			break;

		case MTIMER3_CH3_PORTB_0:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH3_PORTB_0,38000);
			return (u16)(0.034*(time/2));
			break;

		case MTIMER3_CH4_PORTB_1:
			time = MTIMER3_PWM_PulseIn(MTIMER3_CH4_PORTB_1,38000);
			return (u16)(0.034*(time/2));
			break;
	}

	return 0;
}
