// LEDSW.c
// Runs on TM4C123 for CECS347 Project 2
#include "tm4c123gh6pm.h"
#include "LEDSW.h"

void LEDSW_Init(void){
	
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;	// Activate F clocks
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOF)==0){};
		
  GPIO_PORTF_AMSEL_R &= ~0x1F;      // 3) disable analog function
  GPIO_PORTF_PCTL_R &= ~0x000FFFFF; // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R &= ~0x11; 
	GPIO_PORTF_DIR_R |= 0x0E;         // 6) PF1-PF3 output
  GPIO_PORTF_AFSEL_R &= ~0x1F;      // 7) no alternate function     
  GPIO_PORTF_DEN_R |= 0x1F;         // 8) enable digital pins PF3-PF1
  LED = Dark;                       // Turn off all LEDs.
	
}
