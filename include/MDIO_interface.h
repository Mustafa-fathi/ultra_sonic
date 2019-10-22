#ifndef _MDIO_interface_H
#define _MDIO_interface_H



/*Function to set the pin direction(INPUT,OUTPUT,INPUT_PULLUP,......)*/
void MDIO_pinMode(u8 port,u8 pin,u8 mode);

/*Function to set the pin value as digital output HIGH*/
void MDIO_setPin(u8 port, u8 pin);

/*Function to set the pin value as digital output LOW*/
void MDIO_clrPin(u8 port,u8 pin);

/*Function to Read the pin status(HIGH,LOW)*/
u8 MDIO_readPin(u8 port,u8 pin);

/*Function to set value on PORT*/
void MDIO_setPort(u8 port,u16 value);

/*PORTs*/
#define MDIO_PORTA 	0
#define MDIO_PORTB 	1
#define MDIO_PORTC 	2
#define MDIO_PORTD 	3
#define MDIO_PORTE 	4
#define MDIO_PORTF 	5
#define MDIO_PORTG 	6

/*Digital Operation Values*/
#define HIGH 1
#define LOW  0

/*Digital pin directions*/
#define INPUT_ANALOG           	0
#define INPUT_FLOAT 		  	1
#define INPUT_PULLUP 		  	2
#define INPUT_PULLDOWN         	3
#define OUTPUT_OPENDRAIN_2      4
#define OUTPUT_OPENDRAIN_10		5
#define OUTPUT_OPENDRAIN_50		6
#define OUTPUT_PUSHPULL_2		7
#define OUTPUT_PUSHPULL_10		8
#define OUTPUT_PUSHPULL_50		9
#define AF_OUTPUT_OPENDRAIN_2	10
#define AF_OUTPUT_OPENDRAIN_10	11
#define AF_OUTPUT_OPENDRAIN_50  12
#define AF_OUTPUT_PUSHPULL_2	13
#define AF_OUTPUT_PUSHPULL_10	14
#define AF_OUTPUT_PUSHPULL_50	15


#endif
