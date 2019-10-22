#include"LSTD_TYPES.h"
#include"LUTILS.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"


void MDIO_pinMode(u8 port,u8 pin,u8 mode)
{
	if(pin < 8)
	{
		switch(port)
		{
			case MDIO_PORTA:

				if(mode == INPUT_ANALOG)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == INPUT_FLOAT)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == INPUT_PULLUP)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
					SET_BIT((GPIOA -> ODR),pin);
				}

				else if(mode == INPUT_PULLDOWN)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
					CLEAR_BIT((GPIOA -> ODR),pin);
				}

				else if(mode == OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					CLEAR_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOA -> CRL),(pin*4));
					SET_BIT((GPIOA -> CRL),(pin*4)+1);
					SET_BIT((GPIOA -> CRL),(pin*4)+2);
					SET_BIT((GPIOA -> CRL),(pin*4)+3);
				}

				break;

			case MDIO_PORTB:

				if(mode == INPUT_ANALOG)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == INPUT_FLOAT)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == INPUT_PULLUP)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
					SET_BIT((GPIOB -> ODR),pin);
				}

				else if(mode == INPUT_PULLDOWN)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
					CLEAR_BIT((GPIOB -> ODR),pin);
				}

				else if(mode == OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					CLEAR_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOB -> CRL),(pin*4));
					SET_BIT((GPIOB -> CRL),(pin*4)+1);
					SET_BIT((GPIOB -> CRL),(pin*4)+2);
					SET_BIT((GPIOB -> CRL),(pin*4)+3);
				}

				break;

			case MDIO_PORTC:

				if(mode == INPUT_ANALOG)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == INPUT_FLOAT)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == INPUT_PULLUP)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
					SET_BIT((GPIOC -> ODR),pin);
				}

				else if(mode == INPUT_PULLDOWN)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
					CLEAR_BIT((GPIOC -> ODR),pin);
				}

				else if(mode == OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					CLEAR_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOC -> CRL),(pin*4));
					SET_BIT((GPIOC -> CRL),(pin*4)+1);
					SET_BIT((GPIOC -> CRL),(pin*4)+2);
					SET_BIT((GPIOC -> CRL),(pin*4)+3);
				}

				break;

		}
	}

	else
	{
		pin = pin-8;

		switch(port)
		{
			case MDIO_PORTA:

				if(mode == INPUT_ANALOG)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == INPUT_FLOAT)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == INPUT_PULLUP)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
					SET_BIT((GPIOA -> ODR),pin);
				}

				else if(mode == INPUT_PULLDOWN)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
					CLEAR_BIT((GPIOA -> ODR),pin);
				}

				else if(mode == OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					CLEAR_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOA -> CRH),(pin*4));
					SET_BIT((GPIOA -> CRH),(pin*4)+1);
					SET_BIT((GPIOA -> CRH),(pin*4)+2);
					SET_BIT((GPIOA -> CRH),(pin*4)+3);
				}

				break;

			case MDIO_PORTB:

				if(mode == INPUT_ANALOG)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == INPUT_FLOAT)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == INPUT_PULLUP)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
					SET_BIT((GPIOB -> ODR),pin);
				}

				else if(mode == INPUT_PULLDOWN)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
					CLEAR_BIT((GPIOB -> ODR),pin);
				}

				else if(mode == OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					CLEAR_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOB -> CRH),(pin*4));
					SET_BIT((GPIOB -> CRH),(pin*4)+1);
					SET_BIT((GPIOB -> CRH),(pin*4)+2);
					SET_BIT((GPIOB -> CRH),(pin*4)+3);
				}

				break;

			case MDIO_PORTC:

				if(mode == INPUT_ANALOG)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == INPUT_FLOAT)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == INPUT_PULLUP)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
					SET_BIT((GPIOC -> ODR),pin);
				}

				else if(mode == INPUT_PULLDOWN)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
					CLEAR_BIT((GPIOC -> ODR),pin);
				}

				else if(mode == OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_2)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_10)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_PUSHPULL_50)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_2)
				{
					CLEAR_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_10)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					CLEAR_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				else if(mode == AF_OUTPUT_OPENDRAIN_50)
				{
					SET_BIT((GPIOC -> CRH),(pin*4));
					SET_BIT((GPIOC -> CRH),(pin*4)+1);
					SET_BIT((GPIOC -> CRH),(pin*4)+2);
					SET_BIT((GPIOC -> CRH),(pin*4)+3);
				}

				break;
		}
	}

	return;
}

void MDIO_setPin(u8 port,u8 pin)
{
	switch(port)
	{
		case MDIO_PORTA:
			GPIOA -> BSRR = 1<<pin;
			break;

		case MDIO_PORTB:
			GPIOB -> BSRR = 1<<pin;
			break;

		case MDIO_PORTC:
			GPIOC -> BSRR = 1<<pin;
			break;
	}
	return;
}

void MDIO_clrPin(u8 port,u8 pin)
{
	switch(port)
	{
		case MDIO_PORTA:
			GPIOA -> BRR = 1<<pin;
			break;

		case MDIO_PORTB:
			GPIOB -> BRR = 1<<pin;
			break;

		case MDIO_PORTC:
			GPIOC -> BRR = 1<<pin;
			break;
	}
	return;
}


u8 MDIO_readPin(u8 port,u8 pin)
{
	u8 value=0;
	switch(port)
	{
		case MDIO_PORTA:
			value = GET_BIT((GPIOA -> IDR),pin);
			break;

		case MDIO_PORTB:
			value = GET_BIT((GPIOB -> IDR),pin);
			break;

		case MDIO_PORTC:
			value = GET_BIT((GPIOC -> IDR),pin);
			break;
	}

	return value;

}
void MDIO_setPort(u8 port,u16 value)
{
	switch(port)
	{
		case MDIO_PORTA:
			GPIOA -> ODR |= value;
			break;

		case MDIO_PORTB:
			GPIOB -> ODR |= value;
			break;

		case MDIO_PORTC:
			GPIOC -> ODR |= value;
			break;
	}
	return;
}

