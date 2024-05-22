// switch.c
// Runs on TM4C123
// Provide functions that initialize the onboard push buttons
// Author: Min He
// August 26, 2022

#include "tm4c123gh6pm.h"
#include "switch.h"
#include "music.h"

// Subroutine to initialize port F pins for the two onboard switches
// enable PF4 and PF0 for SW1 and SW2 respectively with falling edge interrupt enabled.
// Inputs: None
// Outputs: None
void Switch_Init(void){   volatile unsigned long  delay;
  SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R &= ~0x1F;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R &= ~0x000FFFFF;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R |= 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_DIR_R &= ~0x11;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_AFSEL_R &= ~0x1F;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R |= 0x11;          // enable pull-up on PF0 and PF4
  GPIO_PORTF_DEN_R |= 0x1F;          // 7) enable digital I/O on PF4-0
}

// ISR for PORTF
unsigned long GPIOPortF_Handler(void){
  return (GPIO_PORTF_DATA_R&0x11)^0x11;
}

