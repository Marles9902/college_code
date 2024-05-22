// SysTick.c
// Runs on TM4C123. 
// This module provides timing control for CECS447 Project 1 Part 1.
// Authors: Min He
// Date: August 28, 2022

#include "tm4c123gh6pm.h"
#include <stdint.h>

// TODO: Define the bit address for PA3 which connects to the speaker.
#define SPEAKER (*((volatile unsigned long *)0x40004020))
#define Speaker_Toggle_Mask     0x00000008  // mask used to toggle the speaker output

// Initialize SysTick with interrupt priority 2. Do not start it.
void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000; // priority 2
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC+NVIC_ST_CTRL_INTEN;
}

// Start running systick timer
void SysTick_start(void)
{
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
}
// Stop running systick timer
void SysTick_stop(void)
{
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
}

// update the reload value for current note with with n_value
void SysTick_Set_Current_Note(uint32_t n_value)
{
	  NVIC_ST_RELOAD_R = n_value-1;// update reload value
		NVIC_ST_CURRENT_R = 0;                // any write to current clears it
}

// Interrupt service routine, 
// frequency is determined by current tone being played:
// stop systick timer, toggle speaker output, update reload value with current note reload value, 
// clear the CURRENT register and restart systick timer.
void SysTick_Handler(void){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE; //clr bit 0
	SPEAKER ^= Speaker_Toggle_Mask; // inverse bit 3	
  NVIC_ST_CURRENT_R = 0;      // any write to current clears it
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;  // set bit 0
}
