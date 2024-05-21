// Timer1A.h
// implemented with reference to example project Timer0a.h

#ifndef __TIMER1INTS_H__ 
#define __TIMER1INTS_H__

#include <stdint.h>

void Timer1A_Init(void);
void Timer1A_Start(void);
void Timer1A_Stop(void);
void Timer1A_Wait(unsigned long delay);
uint32_t Timer1A_Get_MC_Elapsed(void);

#endif // __TIMER1INTS_H__