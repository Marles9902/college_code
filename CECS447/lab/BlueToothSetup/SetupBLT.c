// SetupBLT.c
// Runs on TM4C123
// Modified example project for purpose of Project 3 - Bluetooth Car
// This is an example program to setup HC-05 Bluetooth module with no user interface.
// UART0 is used for the TM4C123 to communicate with PC serial terminal, 
// UART1 is used for the TM4C123 to cummunicate with HC-05 Bluetooth module
// U1Rx (PB0) connects to HC-05 TXD pin
// U1Tx (PB1) connects to HC-05 RXD pin
// HC-05 VCC connects to vbus pin on TM4C123
// HC-05 EN connects to +3.3v
// By Min He -- 10/11/2022
// Students: Marwin Gonzales, Joshua Siajuat

#include "tm4c123gh6pm.h"
#include "UART0.h"
#include "BLT.h"
#include <stdint.h>  // for data type alias

// main function for programming BT device with no UI
int main(void) {
	uint8_t string[30];
	uint8_t command[30];
	uint8_t i;
	UART0_Init();
	BLT_Init();
	
	UART0_OutString((uint8_t *)">>> Welcome to Serial Terminal.<<<\r\n");
	UART0_OutString((uint8_t *)">>> This is the setup program for HC-05 Bluetooth module. <<<\r\n");
	UART0_OutString((uint8_t *)">>> You are at 'AT' command mode. <<<\r\n");
	UART0_OutString((uint8_t *)">>> Type 'AT' and followed with a command. <<<\r\n");
	UART0_OutString((uint8_t *)">>> Example: AT+NAME = Your Name <<<\r\n");
	
	uint8_t SetCommands[][30] = {"AT+NAME=BT-Group5\r\n","AT+UART=57600,0,1\r\n","AT+PSWD=5318008\r\n","AT+ROLE=0\r\n"};
	uint8_t QueryCommands[][30] = {"AT+NAME?\r\n","AT+UART?\r\n","AT+PSWD?\r\n","AT+ROLE?\r\n"};
  
  // Setup the HC-05 bluetooth module
while(1){
		UART0_InString(command, 29);
		BLT_OutString(command);
		BLT_OutString((uint8_t *)"\r\n");
		while ((UART1_FR_R&UART_FR_BUSY) != 0){};
		BLT_InString(string);	
		UART0_NextLine();
		UART0_OutString(string);
		//UART0_NextLine();		
		UART0_NextLine();
	
  // Query the HC-05 bluetooth module: HC-05 reply format example:
	// AT+NAME?
	// +NAME:CECS447\r\n OK\r\n
	/*
	for (i=0;i<4;i++) {
		UART0_OutString(QueryCommands[i]); 		
		BLT_OutString(QueryCommands[i]); 		
    while ((UART1_FR_R&UART_FR_BUSY) != 0){};
    BLT_InString(string);  // get the 1st string before OK
    UART0_OutString(string);
		BLT_InString(string);  // get OK
		UART0_OutChar(SP);
    UART0_OutString(string);
		UART0_NextLine();
		UART0_NextLine();
	}
	*/
	if(command[7] == '?'){
			BLT_InString(string);
			UART0_OutString(string);
			UART0_NextLine();
		}
	}	
}