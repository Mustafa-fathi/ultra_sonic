#include"LSTD_TYPES.h"
#include"MRCC_interface.h"
#include"MRCC_private.h"

void MRCC_init(void)
{
	RCC -> CR   = 0x00010000;
	RCC -> CFGR = 0x00000001;
}

void MRCC_EnableCLK(u8 bus,u32 peripheral)
{
	switch(bus)
	{
		case MRCC_AHB : RCC -> AHBENR  |= peripheral; break;
		case MRCC_APB1: RCC -> APB1ENR |= peripheral; break;
		case MRCC_APB2: RCC -> APB2ENR |= peripheral; break;
	}
	return;
}

void MRCC_DisableCLK(u8 bus,u32 peripheral)
{
	switch(bus)
	{
		case MRCC_AHB : RCC -> AHBENR  &= ~peripheral; break;
		case MRCC_APB1: RCC -> APB1ENR &= ~peripheral; break;
		case MRCC_APB2: RCC -> APB2ENR &= ~peripheral; break;
	}
	return;
}
