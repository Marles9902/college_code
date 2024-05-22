/////////////////////////////////////////////////////////////////////////////
// Course Number: CECS 347
// Assignment: Example project for Hardware PWM controlled Car
// Description: 
/////////////////////////////////////////////////////////////////////////////

//////////////////////1. Pre-processor Directives Section////////////////////
#include "tm4c123gh6pm.h"
#include "GPIO.h"

/////////////////////////////////////////////////////////////////////////////

//////////////////////2. Declarations Section////////////////////////////////
////////// Constants //////////

////////// Local Global Variables //////////
/////////////////////////////////////////////////////////////////////////////

//////////////////////3. Subroutines Section/////////////////////////////////
// Dependency: None
// Inputs: None
// Outputs: None
// Description: Initializes PB5432 for use with L298N motor driver direction
void Car_Dir_Init(void){
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOE; //activate E clock
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOE)!= SYSCTL_RCGC2_GPIOE){} //wait for clk
	
	GPIO_PORTE_AMSEL_R &= ~0x0F; //disable analog function
	GPIO_PORTE_PCTL_R &= ~0x0000FFFF; //GPIO clear bit PCTL
	GPIO_PORTE_DIR_R |= 0x0F; //PE0-3 output
	GPIO_PORTE_AFSEL_R &= ~0x0F; //no alternate function
	GPIO_PORTE_DEN_R |= 0x0F; //enable digital pins PE0-3
}

// Port F Initialization
void LED_Init(void){ 
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;	// Activate F clocks
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOF)==0){};
		
  GPIO_PORTF_AMSEL_R &= ~0x0E;      // 3) disable analog function
  GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // 4) GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R |= 0x0E;         // 6) PF1-PF3 output
  GPIO_PORTF_AFSEL_R &= ~0x0E;      // 7) no alternate function     
  GPIO_PORTF_DEN_R |= 0x0E;         // 8) enable digital pins PF3-PF1
  LED = Dark;                       // Turn off all LEDs.
}

/////////////////////////////////////////////////////////////////////////////
