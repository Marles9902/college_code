#include "tm4c123gh6pm.h"
#include "UART0.h"
#include <stdint.h>
#include <stdbool.h>  // for C boolean data type

#define NVIC_EN0_UART0 0x20     // UART0 IRQ number 5
// #define NVIC_EN1_UART2 0x02

void UART0_Init(bool RxInt, bool TxInt){
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART0; // activate UART0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; // activate port A
  UART0_CTL_R = 0;                      // disable UART
	UART0_IBRD_R = 54;                    // IBRD = int(50,000,000 / (16 * 57600)) = int(54.253472)
  UART0_FBRD_R = 16;                    // FBRD = int(0.253472 * 64 + 0.5) = int(16.722)
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
//  UART0_LCRH_R = UART_LCRH_WLEN_8;
	
	// take care of interrupt setup
	if ( RxInt | TxInt) {
		NVIC_PRI1_R = (NVIC_PRI1_R&~0x0000E000)|0x0000A000; // bits 15-13, priority 5
		NVIC_EN0_R = NVIC_EN0_UART0;           // enable UART0 interrupt in NVIC
		if (RxInt) {
			UART0_IM_R |= UART_IM_RXIM;         // Enable RX interrupt
		}
		
		if (TxInt) {
			UART0_IM_R |= UART_IM_TXIM;         // Enable TX interrupt
		}
	}
	
	/*
		// take care of interrupt setup
	if ( RxInt | TxInt) {
		NVIC_PRI1_R = (NVIC_PRI1_R&~0x0000E000)|0x0000A000; // bits 15-13, priority 5
		NVIC_EN0_R = NVIC_EN0_UART0;           // enable UART0 interrupt in NVIC
		if (RxInt) {
			UART0_IM_R |= UART_IM_RXIM;         // Enable RX interrupt
		}
		
		if (TxInt) {
			UART0_IM_R |= UART_IM_TXIM;         // Enable TX interrupt
		}
	}
	*/

  UART0_CTL_R |= UART_CTL_RXE|UART_CTL_TXE|UART_CTL_UARTEN;// enable Tx, RX and UART
  GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1-0
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA
}

//-------------------------------------------------------------------------------------------------------------------------------------

void OutCRLF0(void){
  UART0_OutChar(CR);
  UART0_OutChar(LF);
}

//-------------------------------------------------------------------------------------------------------------------------------------

uint8_t UART0_InChar(void){
  while((UART0_FR_R&UART_FR_RXFE) != 0); // wait until the receiving FIFO is not empty
  return((uint8_t)(UART0_DR_R&0xFF));
}

//-------------------------------------------------------------------------------------------------------------------------------------

void UART0_OutChar(uint8_t data){
  while((UART0_FR_R&UART_FR_TXFF) != 0);
  UART0_DR_R = data;
}

//-------------------------------------------------------------------------------------------------------------------------------------

void UART0_OutString(uint8_t *pt){
  while(*pt){
    UART0_OutChar(*pt);
    pt++;
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------

uint32_t UART0_InUDec(void){
uint32_t number=0, length=0;
char character;
  character = UART0_InChar();
  while(character != CR){ // accepts until <enter> is typed
// The next line checks that the input is a digit, 0-9.
// If the character is not 0-9, it is ignored and not echoed
    if((character>='0') && (character<='9')) {
      number = 10*number+(character-'0');   // this line overflows if above 4294967295
      length++;
      UART0_OutChar(character);
    }
// If the input is a backspace, then the return number is
// changed and a backspace is outputted to the screen
    else if((character==BS) && length){
      number /= 10;
      length--;
      UART0_OutChar(character);
    }
    character = UART0_InChar();
  }
  return number;
}

//-------------------------------------------------------------------------------------------------------------------------------------

void UART0_OutUDec(uint32_t n){
// This function uses recursion to convert decimal number
//   of unspecified length as an ASCII string
  if(n >= 10){
    UART0_OutUDec(n/10);
    n = n%10;
  }
  UART0_OutChar(n+'0'); /* n is between 0 and 9 */
}

//-------------------------------------------------------------------------------------------------------------------------------------

uint32_t UART0_InUHex(void){
uint32_t number=0, digit, length=0;
char character;
  character = UART0_InChar();
  while(character != CR){
    digit = 0x10; // assume bad
    if((character>='0') && (character<='9')){
      digit = character-'0';
    }
    else if((character>='A') && (character<='F')){
      digit = (character-'A')+0xA;
    }
    else if((character>='a') && (character<='f')){
      digit = (character-'a')+0xA;
    }
// If the character is not 0-9 or A-F, it is ignored and not echoed
    if(digit <= 0xF){
      number = number*0x10+digit;
      length++;
      UART0_OutChar(character);
    }
// Backspace outputted and return value changed if a backspace is inputted
    else if((character==BS) && length){
      number /= 0x10;
      length--;
      UART0_OutChar(character);
    }
    character = UART0_InChar();
  }
  return number;
}

//-------------------------------------------------------------------------------------------------------------------------------------

void UART0_OutUHex(uint32_t number){
// This function uses recursion to convert the number of
//   unspecified length as an ASCII string
  if(number >= 0x10){
    UART0_OutUHex(number/0x10);
    UART0_OutUHex(number%0x10);
  }
  else{
    if(number < 0xA){
      UART0_OutChar(number+'0');
     }
    else{
      UART0_OutChar((number-0x0A)+'A');
    }
  }
}

//-------------------------------------------------------------------------------------------------------------------------------------

void UART0_InString(uint8_t *bufPt, uint16_t max) {
int length=0;
char character;
  character = UART0_InChar();
  while(character != CR){
    if(character == BS){ // back space
      if(length){
        bufPt--;
        length--;
        UART0_OutChar(BS);
      }
    }
    else if(length < max){
      *bufPt = character;
      bufPt++;
      length++;
      UART0_OutChar(character);
    }
    character = UART0_InChar();
  }
  *bufPt = 0; // adding null terminator to the end of the string.
}

//-------------------------------------------------------------------------------------------------------------------------------------

uint8_t charToHex	(char color){
	switch(color){
		case 'r':
			return 0x02;
			break;
		case 'd':
			return 0x00;
			break;
		case 'g':
			return 0x08;
			break;
		case 'b':
			return 0x04;
			break;
		case 'c':
			return 0x0C;
			break;
		case 'w':
			return 0x0E;
			break;
		case 'y':
			return 0x0A;
			break;
		case 'p':
			return 0x06;
			break;
		}
	return 0x00;
}