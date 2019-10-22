#ifndef _LUTILS_H
#define _LUTILS_H

#define SET_BIT(REG,BIT)     					   REG |= (1<<BIT)
#define CLEAR_BIT(REG,BIT)   					   REG &= (~(1<<BIT))
#define GET_BIT(REG,BIT)    					   ((REG>>BIT)&1)
#define TOGGLE_BIT(REG,BIT)  					   REG ^= (1<<BIT)
#define MAP(value,in_min,in_max,out_min,out_max)   ((value-in_min)*(out_max-out_min)/(in_max-in_min))+out_min

#endif
