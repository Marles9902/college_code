// ADCTestMain.c
// Runs TM4C123
// This program periodically samples ADC channel 1 and stores the
// result to a global variable that can be accessed with the JTAG
// debugger and viewed with the variable watch feature.
// Daniel Valvano
// October 20, 2013
// Modified by Min He, 10/9/2022

/* This example accompanies the book
   "Embedded Systems: Real Time Interfacing to Arm Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2013

 Copyright 2013 by Jonathan W. Valvano, valvano@mail.utexas.edu
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


#include "ADC0SS3.h"  
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include <stdint.h>

void PORTF_Init(void);
uint16_t median(uint16_t u1, uint16_t u2, uint16_t u3);
uint16_t ReadADCMedianFilter(void);

volatile uint16_t ADCvalue;
// The digital number ADCvalue is a representation of the voltage on PE2 
// voltage  ADCvalue
// 0.00V     0
// 0.75V    1024
// 1.50V    2048
// 2.25V    3072
// 3.00V    4095

int main(void){
	uint32_t volatile delay;
	
  PLL_Init();                         // 80 MHz
	PORTF_Init();
//  ADC0_InitSWTriggerSeq3_Ch1();     // ADC initialization PE2/AIN1
	ADC0_InitSWTriggerSeq3_Ch7();       // ADC initialization PD0/AIN7
	
  while(1){
    GPIO_PORTF_DATA_R |= 0x04;          // profile
    ADCvalue = ReadADCMedianFilter();
    for(delay=0; delay<100000; delay++){};
    GPIO_PORTF_DATA_R &= ~0x04;
  }
}

void PORTF_Init(void){
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port F
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOF)!=SYSCTL_RCGC2_GPIOF){}
		
  GPIO_PORTF_DIR_R |= 0x04;             // make PF2 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x04;          // disable alt funct on PF2
  GPIO_PORTF_DEN_R |= 0x04;             // enable digital I/O on PF2
                                        // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;               // disable analog functionality on PF
}

// Median function: 
// A helper function for ReadADCMedianFilter()
uint16_t median(uint16_t u1, uint16_t u2, uint16_t u3){
uint16_t result;
	
  if(u1>u2)
    if(u2>u3)   result=u2;     // u1>u2,u2>u3       u1>u2>u3
      else
        if(u1>u3) result=u3;   // u1>u2,u3>u2,u1>u3 u1>u3>u2
        else      result=u1;   // u1>u2,u3>u2,u3>u1 u3>u1>u2
  else
    if(u3>u2)   result=u2;     // u2>u1,u3>u2       u3>u2>u1
      else
        if(u1>u3) result=u1;   // u2>u1,u2>u3,u1>u3 u2>u1>u3
        else      result=u3;   // u2>u1,u2>u3,u3>u1 u2>u3>u1
  return(result);
}

// This function samples one value, apply a software filter to the value and
// returns filter result.  Some kind of filtering is required because 
// the IR distance sensors output occasional erroneous spikes.  
// This function implements a median filter:
// y(n) = median(x(n), x(n-1), x(n-2))
// Assumes: ADC has already been initialized. 
uint16_t ReadADCMedianFilter(void){
  static uint16_t oldest=0, middle=0;	
  uint16_t newest;
	uint16_t NewValue;
	
  newest = ADC0_InSeq3();  // read one value
  NewValue = median(newest, middle, oldest);
  oldest = middle; 
  middle = newest; 
	return NewValue;
}