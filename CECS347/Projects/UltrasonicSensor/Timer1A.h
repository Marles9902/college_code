// Timer1A.h
// implemented using similar structure to example project Timer0a.h

#ifndef __TIMER1INTS_H__ // do not include more than once
#define __TIMER1INTS_H__

#include <stdint.h>

// Timer1_Init 
void Timer1A_Init(void);
void Timer1A_Start(void);
void Timer1A_Stop(void);
void Timer1A_Wait1us(unsigned long delay);
uint32_t Timer1A_Get_MC_Elapsed(void);

#endif // __TIMER2INTS_H__
