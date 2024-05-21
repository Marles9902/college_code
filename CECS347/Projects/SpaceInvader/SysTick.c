#include "tm4c123gh6pm.h"
#include <stdint.h>

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;           // disable SysTick during setup
  NVIC_ST_RELOAD_R = 399999;       // reload value for 50% duty cycle
  NVIC_ST_CURRENT_R = 0;        // any write to current clears it
  NVIC_PRI1_R = (NVIC_PRI1_R&0xFFFFFF1F)|0x00000040; // bit 23-21 for SysTick PortE, set priority to 2
  NVIC_ST_CTRL_R |= 0x00000007;  // enable with core clock and interrupts, start systick timer
}