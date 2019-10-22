#ifndef _MRCC_INTERFACE_H
#define _MRCC_INTERFACE_H

/*Buses*/
#define MRCC_AHB  0
#define MRCC_APB1 1
#define MRCC_APB2 2

/*AHB Peripherals*/
#define MRCC_DMA1    0x1
#define MRCC_DMA2    0x2
#define MRCC_SRAM    0x4
#define MRCC_FLITF   0x10
#define MRCC_CRC     0x40
#define MRCC_FSMC    0x100
#define MRCC_SDIO    0x400


/*APB1 Peripherals*/
#define MRCC_TIM2    0x1
#define MRCC_TIM3    0x2
#define MRCC_TIM4    0x4
#define MRCC_TIM5    0x8
#define MRCC_TIM6    0x10
#define MRCC_TIM7    0x20
#define MRCC_TIM12   0x40
#define MRCC_TIM13   0x80
#define MRCC_TIM14   0x100
#define MRCC_WWDG    0x800
#define MRCC_SPI2    0x4000
#define MRCC_SPI3    0x8000
#define MRCC_USART2  0x20000
#define MRCC_USART3  0x40000
#define MRCC_USART4  0x80000
#define MRCC_USART5  0x100000
#define MRCC_I2C1    0x200000
#define MRCC_I2c2    0x400000
#define MRCC_USB     0x800000
#define MRCC_CAN     0x2000000
#define MRCC_BKP     0x8000000
#define MRCC_PWR     0x10000000
#define MRCC_DAC     0x20000000



/*APB2 Peripherals*/
#define MRCC_AFIO    0x1
#define MRCC_PORTA   0x4
#define MRCC_PORTB   0x8
#define MRCC_PORTC   0x10
#define MRCC_PORTD   0x20
#define MRCC_PORTE   0x40
#define MRCC_PORTF   0x80
#define MRCC_PORTG   0x100
#define MRCC_ADC1    0x200
#define MRCC_ADC2    0x400
#define MRCC_TIM1    0x800
#define MRCC_SPI1    0x1000
#define MRCC_TIM8    0x2000
#define MRCC_USART1  0x4000
#define MRCC_ADC3    0x8000
#define MRCC_TIM9    0x80000
#define MRCC_TIM10   0x100000
#define MRCC_TIM11   0x200000



void MRCC_init(void);
void MRCC_EnableCLK(u8 bus,u32 peripheral);
void MRCC_DisableCLK(u8 bus,u32 peripheral);



#endif
