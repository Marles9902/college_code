// UARTTestMain.c
// Runs on LM4F120/TM4C123
// Used to test the UART.c driver
// Daniel Valvano
// September 12, 2013

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
// Modified by Dr. Min He on 9/23/2023

// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1

#include "PLL.h"
#include "UART.h"
#include <stdint.h>
#include <stdbool.h>  // for C boolean data type

// NEW
#include "tm4c123gh6pm.h"
#include <string.h>

#define MAX_STR_LEN 20

// NEW
// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06

#define DARK 		0
#define RED 		0x02
#define GREEN 	0x08
#define BLUE 		0x04

void PortF_Init(void);

int main(void){
  uint8_t i;
  uint8_t string[MAX_STR_LEN];  // global to assist in debugging
  uint32_t n;
	
	PortF_Init();
  PLL_Init();
  UART_Init(false,false);              // initialize UART
  OutCRLF();
	
	char color;
	
  for(i='A'; i<='Z'; i=i+1){// print the uppercase alphabet
    UART_OutChar(i);
  }
  OutCRLF();
  UART_OutChar(' ');
  for(i='a'; i<='z'; i=i+1){// print the lowercase alphabet
    UART_OutChar(i);
  }
  OutCRLF();
  UART_OutChar('-');
  UART_OutChar('-');
  UART_OutChar('>');
  OutCRLF();
  while(1){
		
		/*
    UART_OutString((uint8_t *)"InString(less than 19 characters): ");
    UART_InString(string,19);
    OutCRLF();
    UART_OutString((uint8_t *)" OutString="); UART_OutString(string); OutCRLF();

    UART_OutString((uint8_t *)"InUDec: ");  n=UART_InUDec(); OutCRLF();
    UART_OutString((uint8_t *)" OutUDec="); UART_OutUDec(n); OutCRLF();

    UART_OutString((uint8_t *)"InUHex: ");  n=UART_InUHex(); OutCRLF();
    UART_OutString((uint8_t *)" OutUHex="); UART_OutUHex(n); OutCRLF();
		*/
		
		// SWITCHING COLORS (THREE METHODS)
		UART_OutString((uint8_t *)"Enter a color (r, g, b): ");
		
		/*
		// METHOD 1
		OutCRLF();
		color = UART_InChar();
		switch(color){
			case 'r':
				GPIO_PORTF_DATA_R = RED;
				UART_OutString((uint8_t *)"red");
				OutCRLF();
				break;
			
			case 'g':
				GPIO_PORTF_DATA_R = GREEN;
				UART_OutString((uint8_t *)"green");
				OutCRLF();
				break;
			
			case 'b':
				GPIO_PORTF_DATA_R = BLUE;
				UART_OutString((uint8_t *)"blue");
				OutCRLF();
				break;
		}
		*/
		
		
		// METHOD 2
		UART_InString(string, MAX_STR_LEN);
		OutCRLF();
		if (string[0] == 'r') {
				GPIO_PORTF_DATA_R = RED;
				UART_OutString((uint8_t *)"red");
				OutCRLF();
		} else if (string[0] == 'g') {
				GPIO_PORTF_DATA_R = GREEN;
				UART_OutString((uint8_t *)"green");
				OutCRLF();
		} else if (string[0] == 'b') {
				GPIO_PORTF_DATA_R = BLUE;
				UART_OutString((uint8_t *)"blue");
				OutCRLF();
		} else {
				UART_OutString((uint8_t *)"Invalid color. Please enter 'r', 'g', or 'b'.");
				GPIO_PORTF_DATA_R = DARK;
				OutCRLF();
		}
		
		
		
		/*
		// METHOD 3 
		UART_InString(string, MAX_STR_LEN);
		OutCRLF();
		if (strcmp((char *)string, "red") == 0) {
			GPIO_PORTF_DATA_R = RED;
				UART_OutString((uint8_t *)"red");
			OutCRLF();
		} 
		else if (strcmp((char *)string, "green") == 0){
			GPIO_PORTF_DATA_R = GREEN;
				UART_OutString((uint8_t *)"GREEN");
			OutCRLF();
		}
		else if (strcmp((char *)string, "blue") == 0){
			GPIO_PORTF_DATA_R = BLUE;
				UART_OutString((uint8_t *)"blue");
			OutCRLF();
		}
		*/
  }
}

void PortF_Init(void){ 
  SYSCTL_RCGC2_R |= 0x00000020;     	// activate F clock
	while ((SYSCTL_RCGC2_R&0x00000020)!=0x00000020){} // wait for the clock to be ready
		
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   	// unlock PortF PF0  
	GPIO_PORTF_CR_R |= 0x1F;         		// allow changes to PF4-0 :11111->0x1F     
  GPIO_PORTF_AMSEL_R &= ~0x1F;        // disable analog function
  GPIO_PORTF_PCTL_R &= ~0x000FFFFF; 	// GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R &= ~0x11;          // PF4,PF0 input   
  GPIO_PORTF_DIR_R |= 0x0E;          	// PF3,PF2,PF1 output   
	GPIO_PORTF_AFSEL_R &= ~0x1F;        // no alternate function
  GPIO_PORTF_PUR_R |= 0x11;          	// enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R |= 0x1F;          	// enable digital pins PF4-PF0        
}
