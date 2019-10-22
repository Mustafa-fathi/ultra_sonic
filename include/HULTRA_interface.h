#ifndef HULTRA_INTERFACE_H
#define HULTRA_INTERFACE_H

/*Ultra-Sonic functions*/
void HULTRA_attachPin(u8 trig_port,u8 trig,u8 echo);
void HULTRA_Trig(u8 port,u8 pin);
u16 HULTRA_Distance(u8 channel);

#endif
