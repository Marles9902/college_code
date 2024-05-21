//Timer1A.c
// implemented using similar structure to example project Timer0a.c

#include "Timer1A.h"
#include <stdint.h>
#include "tm4c123gh6pm.h"

#define MAX 4294967295

// Timer1 initialization 
void Timer1A_Init(void) {
	SYSCTL_RCGCTIMER_R |= 0x02; // Activate timer 1
	TIMER1_CTL_R = 0x00000000; // disable timer 1
	TIMER1_CFG_R = 0x00000000; // 16 bit timer
	TIMER1_TAMR_R = 0x00000002; // periodic count down
	TIMER1_TAPR_R = 0; 					// 0 prescale
}

// Timer1 start function
void Timer1A_Start(void) {
	TIMER1_TAILR_R = MAX;
	TIMER1_CTL_R = 0x00000001; 
}

// Timer1 stop function
void Timer1A_Stop(void) {
	TIMER1_CTL_R = 0;
}

// Timer1 wait function
void Timer1A_Wait1us(unsigned long delay) {
	TIMER1_TAILR_R = (delay * 40) - 1;
	TIMER1_CTL_R = 0x00000001;
	while(TIMER1_TAR_R);
	TIMER1_CTL_R = 0;
}

// function to get the distance from Timer1
uint32_t Timer1A_Get_MC_Elapsed(void) {
	return (uint32_t) MAX - TIMER1_TAR_R;
}
