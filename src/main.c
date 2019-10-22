/*
 * main.c
 *
 *  Created on: Nov 27, 2018
 *      Author: ahmed
 */
#include "LSTD_TYPES.h"
#include "LUTILS.h"

#include "MRCC_interface.h"
#include "MDIO_interface.h"
#include "MTIMER3_interface.h"
#include "HULTRA_interface.h"

int main(void)
{
	MRCC_init();
	MRCC_EnableCLK(MRCC_APB2,MRCC_PORTA);
	MRCC_EnableCLK(MRCC_APB2,MRCC_AFIO);
	MRCC_EnableCLK(MRCC_APB1,MRCC_TIM3);
	MRCC_EnableCLK(MRCC_APB1,MRCC_TIM2);

	MDIO_pinMode(MDIO_PORTA,0,OUTPUT_PUSHPULL_2);

	MTIMER3_init(PWM_channel_1_IN);
	MTIMER2_init(delay_us);

	HULTRA_attachPin(MDIO_PORTA,5,MTIMER3_CH1_PORTA_6);

	u16 distance = 0;
	while(1)
	{
		HULTRA_Trig(MDIO_PORTA,5);
		distance = HULTRA_Distance(MTIMER3_CH1_PORTA_6);
		if(distance > 30)
		{
			MDIO_setPin(MDIO_PORTA,0);
		}
		else
		{
			MDIO_clrPin(MDIO_PORTA,0);
		}
	}

	return 0;
}

