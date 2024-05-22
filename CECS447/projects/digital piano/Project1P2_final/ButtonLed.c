// Project 1 Part 2
// By: Joshua Siajuat and Marwin Gonzales
// ButtonLed.c: starter file for CECS447 Project 1 Part 1
// Originally by Dr. Min He
// September 15, 2023
// Port B bits 5-0 outputs to the 6-bit DAC
// Port D bits 3-0 inputs from piano keys: CDEF:doe ray mi fa,negative logic connections.
// Port F is onboard LaunchPad switches and LED
// SysTick ISR: PF3 is used to implement heartbeat

// header files
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "ButtonLed.h"

// Constants
#define SW1 0x10  // bit position for onboard switch 1(left switch)
#define SW2 0x01  // bit position for onboard switch 2(right switch)
#define NVIC_EN0_PORTF 0x40000000  // enable PORTF edge interrupt
#define NVIC_EN0_PORTD 0x00000008  // enable PORTD edge interrupt

// globals
volatile uint8_t curr_mode=PIANO;  // 0: piano mode, 1: auto-play mode

//---------------------Switch_Init---------------------
// initialize onboard switch and LED interface
// Input: none
// Output: none 
void ButtonLed_Init(void){ 
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0x11;
	GPIO_PORTF_DIR_R &= ~0x11;
	GPIO_PORTF_AFSEL_R &= ~0x11;
	GPIO_PORTF_DEN_R |= 0x11;
	GPIO_PORTF_PCTL_R &= 0x000F000F;
	GPIO_PORTF_AMSEL_R &= ~0x11;
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_IS_R &= ~0x11;
	GPIO_PORTF_IBE_R &= ~0x11;
	GPIO_PORTF_IEV_R &= ~0x11;
	GPIO_PORTF_ICR_R = 0x11;
	GPIO_PORTF_IM_R |= 0x11;
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF) | 0x00800000;
	NVIC_EN0_R |= 0x40000000;
}

//---------------------PianoKeys_Init---------------------
// initialize onboard Piano keys interface: PORT D 0 - 3 are used to generate 
// tones: CDEF:doe ray mi fa
// No need to unlock. Only PD7 needs to be unlocked.
// Input: none
// Output: none 
void PianoKeys_Init(void){ 
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD;
	GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTD_CR_R |= 0x0F;
	GPIO_PORTD_DIR_R &= ~0x0F;
	GPIO_PORTD_AFSEL_R &= ~0x0F;
	GPIO_PORTD_DEN_R |= 0x0F;
	GPIO_PORTD_PCTL_R &= 0x0000FFFF;
	GPIO_PORTD_AMSEL_R &= ~0x0F;
	GPIO_PORTD_PUR_R |= 0x0F;
	GPIO_PORTD_IS_R &= ~0x0F;
	GPIO_PORTD_IBE_R |= 0x0F;
	GPIO_PORTD_IEV_R |= 0x0F;
	GPIO_PORTD_ICR_R = 0x0F;
	GPIO_PORTD_IM_R |= 0x0F;
	NVIC_PRI0_R = (NVIC_PRI0_R&0x0FFFFFFF) | 0xA0000000;
	NVIC_EN0_R |= 0x00000008;
}

// read switch input
unsigned long Switch_In(void){
	return (GPIO_PORTD_DATA_R&0x0F)^0x0F;
}

// get current mode
uint8_t get_current_mode(void)
{
	return curr_mode;
}

// set current mode
void set_current_mode(uint8_t mode){
  curr_mode ^= mode;
}