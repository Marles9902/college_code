// switch.c
// Runs on TM4C123
// Provide functions that initialize the onboard push buttons
// Author: Min He
// August 26, 2022

#include "tm4c123gh6pm.h"
#include "switch.h"
#include "music.h"
#include "SysTick.h"

#define NVIC_EN0_PORTF 0x40000000
extern void EnableInterrupts(void);
extern void DisableInterrupts(void);
extern void WaitForInterrupt(void);  // low power mode
extern void Delay(void);
extern unsigned long music_state;
extern unsigned long current_song;
unsigned int sw_pressed;

// Subroutine to initialize port F pins for the two onboard switches
// enable PF4 and PF0 for SW1 and SW2 respectively with falling edge interrupt enabled.
// Inputs: None
// Outputs: None
void Switch_Init(void){ 
	unsigned long volatile delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;	// Activate F clocks
	delay = SYSCTL_RCGC2_R;

	// standard PortF initializations -- PF0 and PF4
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0x11;					// allow changes to PF4, PF0
	GPIO_PORTF_AMSEL_R &= ~0x11;      // disable analog function
	GPIO_PORTF_PCTL_R &= ~0x000F000F; // GPIO clear bit PCTL  
	GPIO_PORTF_DIR_R &= ~0x11; 				// PF0-PF4 input
	GPIO_PORTF_AFSEL_R &= ~0x11;      // no alternate function     
	GPIO_PORTF_DEN_R |= 0x11;         // enable digital pins PF4, PF0
	GPIO_PORTF_PUR_R |= 0x11;					// enable weak pull-upp on PF4,0

	// Enable interrupt on PF0 and PF4
	GPIO_PORTF_IS_R &= ~0x11;    // Clear interrupt sense for PF0 and PF4
	GPIO_PORTF_IBE_R &= ~0x11;   // Disable both edges interrupt
	GPIO_PORTF_IEV_R &= ~0x11;   // Interrupt on falling edge (PF0 and PF4 are active low)
	GPIO_PORTF_ICR_R = 0x11;     // Clear any previous interrupt
	GPIO_PORTF_IM_R |= 0x11;     // Enable interrupt on PF0 and PF4	

	// Enable Port F interrupt
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x80000000; // (g) bits:23-21 for PORTF, set priority to 5
	NVIC_EN0_R |= NVIC_EN0_PORTF;      // (h) enable interrupt 30 in NVIC
}

// ISR for PORTF
void GPIOPortF_Handler(void){
	
	// SW1
	if (GPIO_PORTF_RIS_R & 0x10){	// check if SW1 pressed
	sw_pressed = 1;
		GPIO_PORTF_ICR_R = 0x10;		// clear interrupt flag
		if(music_state){						// toggle music state
			turn_off_music();
		}
		else{
			turn_on_music();
		}
	}
	
	// SW2
	if (GPIO_PORTF_RIS_R & 0x01){	// check if SW2 pressed
	sw_pressed = 1;
		GPIO_PORTF_ICR_R = 0x01;		// clear interrupt flag
		next_song();
	}
	
}
