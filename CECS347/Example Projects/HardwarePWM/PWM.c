// PWM.c
// Runs on TM4C123
// Use PWM0/PB6 and PWM1/PB7 to generate pulse-width modulated outputs.
// Daniel Valvano
// March 28, 2014
// Modified by Min He, September 7, 2021

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
  Program 6.7, section 6.3.2

 Copyright 2014 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"

// period is 16-bit number of PWM clock cycles in one period 
// Output on PF2/M1PWM6
void PWM1A_Init(uint16_t period){
  SYSCTL_RCGCPWM_R |= 0x02;             // 1) activate PWM1
  SYSCTL_RCGCGPIO_R |= 0x20;            // 2) activate port F: 1000000
  while((SYSCTL_RCGCGPIO_R&0x20) == 0){};
	GPIO_PORTF_AFSEL_R |= 0x04;           // enable alt funct on PF2: 0000 0010
  GPIO_PORTF_PCTL_R &= ~0x00000F00;     // configure PF2 as PWM1
  GPIO_PORTF_PCTL_R |= 0x00000500;
  GPIO_PORTF_AMSEL_R &= ~0x04;          // disable analog functionality on PF2
  GPIO_PORTF_DEN_R |= 0x04;             // enable digital I/O on PF2
  GPIO_PORTF_DR8R_R |= 0x06;    // enable 8 mA drive on PF1,2
  SYSCTL_RCC_R = 0x00100000 |           // 3) use PWM divider
    (SYSCTL_RCC_R & (~0x001E0000));   //    configure for /2 divider: PWM clock: 80Mhz/2=40MHz
  PWM1_3_CTL_R = 0;                     // 4) re-loading down-counting mode
  PWM1_3_GENA_R = 0xC8;                 // low on LOAD, high on CMPA down
  // PF2 goes low on LOAD
  // PF2 goes high on CMPA down
  PWM1_3_LOAD_R = period - 1;           // 5) cycles needed to count down to 0
  PWM1_3_CMPA_R = 0;             // 6) count value when output rises
  PWM1_3_CTL_R |= 0x00000001;           // 7) start PWM1
  PWM1_ENABLE_R |= 0x00000040;          // enable PF2/M1PWM6		0100_0000 -> 0x40
}
// change duty cycle of PF2
// duty is number of PWM clock cycles output is high  
void PWM1A_Duty(uint16_t duty){
  PWM1_3_CMPA_R = duty - 1;             // 6) count value when output rises
}
// period is 16-bit number of PWM clock cycles in one period 
// Output on PF1/M1PWM5
void PWM1B_Init(uint16_t period){
  volatile unsigned long delay;
  SYSCTL_RCGCPWM_R |= 0x02;             // 1) activate PWM1
  SYSCTL_RCGCGPIO_R |= 0x20;            // 2) activate port F
  delay = SYSCTL_RCGCGPIO_R;            // allow time to finish activating
  GPIO_PORTF_AFSEL_R |= 0x02;           // enable alt funct on PF1
  GPIO_PORTF_PCTL_R &= ~0x000000F0;     // configure PF1 as M1PWM5
  GPIO_PORTF_PCTL_R |= 0x00000050;
  GPIO_PORTF_AMSEL_R &= ~0x02;          // disable analog functionality on PF1
  GPIO_PORTF_DEN_R |= 0x02;             // enable digital I/O on PF1
  SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV; // 3) use PWM divider
  SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M; //    clear PWM divider field
  SYSCTL_RCC_R += SYSCTL_RCC_PWMDIV_2;  //    configure for /2 divider
  PWM1_2_CTL_R = 0;                     // 4) re-loading down-counting mode
  PWM1_2_GENB_R = (PWM_1_GENB_ACTCMPBD_ONE|PWM_1_GENB_ACTLOAD_ZERO); // 0xC08
  // PB7 goes low on LOAD
  // PB7 goes high on CMPB down
  PWM1_2_LOAD_R = period - 1;           // 5) cycles needed to count down to 0: LAB2: PF1->M1PWM5:PWM1_2_
  PWM1_2_CMPB_R = 0;             // 6) count value when output rises: Lab 2:5%2=1->CMPB, GENB
  PWM1_2_CTL_R |= 0x00000001;           // 7) start PWM1: odd->B, even->A
  PWM1_ENABLE_R |= 0x00000020;          // enable PF1/M1PWM5
}
// change duty cycle of PF1
// duty is number of PWM clock cycles output is high  
void PWM1B_Duty(uint16_t duty){
  PWM1_2_CMPB_R = duty - 1;             // 6) count value when output rises
}
