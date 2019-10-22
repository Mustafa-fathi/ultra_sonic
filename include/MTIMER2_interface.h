#ifndef MTIMER2_INTERFACE_H
#define MTIMER2_INTERFACE_H

/*TIMER2 Functions*/
void MTIMER2_init(u8 delay_type);
void MTIMER2_delay_ms(u16 value);
void MTIMER2_delay_us(u16 value);


/*TIMER2 delay types*/
#define delay_ms   1
#define delay_us   2

#endif
