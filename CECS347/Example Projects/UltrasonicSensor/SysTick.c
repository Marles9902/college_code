// SysTick.c
// implemented with reference to example SysTick.c from Ultrasonic_Sensor

#include <stdint.h>
#include "SysTick.h"
#include "tm4c123gh6pm.h"

#define ONE_MICRO_SECOND          16     											// number of machine cycles to generate 1us delay for 16MHz system clock

void SysTick_Start(void){
  NVIC_ST_CTRL_R = 0;
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M; 												// number of counts to wait
  NVIC_ST_CURRENT_R = 0; 																			// any value written to CURRENT clears   
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC; // enable SysTick with core clock
}

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;           																											// disable SysTick during setup
  NVIC_ST_RELOAD_R = 400000-1;     																										// reload value for 50% duty cycle
  NVIC_ST_CURRENT_R = 0;        																											// any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x1FFFFFFF)|0x40000000; 													// bit 31-29 for SysTick, set priority to 2
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC + NVIC_ST_CTRL_INTEN + NVIC_ST_CTRL_ENABLE;  // enable with core clock and interrupts, start systick timer
}

// Disable Systick timer
void SysTick_Stop(void){
	NVIC_ST_CTRL_R = 0;
}

// Calculate number of machine cycles elapsed
uint32_t SysTick_Get_MC_Elapsed(void){
	return NVIC_ST_RELOAD_R-NVIC_ST_CURRENT_R;
}

// Time delay using busy wait.
// This function assumes 40 MHz system clock.
void SysTick_Wait(uint8_t delay){
  NVIC_ST_CTRL_R = 0;
  NVIC_ST_RELOAD_R = delay*ONE_MICRO_SECOND-1; 									// number of counts to wait
  NVIC_ST_CURRENT_R = 0; 																				// any value written to CURRENT clears
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
  while((NVIC_ST_CTRL_R&NVIC_ST_CTRL_COUNT)==0); 								// wait for count flag
  NVIC_ST_CTRL_R = 0;
}