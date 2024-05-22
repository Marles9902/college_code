/////////////////////////////////////////////////////////////////////////////
// Course Number: CECS 347
// Example project for Hardware PWM controlled Car
// Description: 
// Hardware connections: assume L298N is used for DC motor driver
// PB67 for motor PWM signals: PB6 - Left DC Motor, PB7 - Right DC Motor
// PB5432 for motor directions: PB54 - left DC Motor, PB32 - right DC Motor
// By Min He, 10/19/2022
/////////////////////////////////////////////////////////////////////////////

//////////////////////1. Pre-processor Directives Section////////////////////
#include "tm4c123gh6pm.h"
#include "PWM.h"
#include "GPIO.h"
/////////////////////////////////////////////////////////////////////////////

//////////////////////2. Declarations Section////////////////////////////////

////////// Local Global Variables //////////
// standard ASCII symbols
#define CR   0x0D
#define LF   0x0A
////////// Function Prototypes //////////
void UART_Init(void);
unsigned char UART1_InChar(void);
void BLT_InString(unsigned char *bufPt);
void UART0_OutChar(unsigned char data);
void UART0_OutString(unsigned char *pt);
void Delay(void);
uint16_t carSpeed;
uint16_t newCarSpeed;

//////////////////////3. Subroutines Section/////////////////////////////////
// MAIN: This main is meant for the command configuration of the hc05.
int main(void){ 
	unsigned char control_symbol; // for bluetooth controlled LEDs
	UART_Init(); // Initialize UART1
	carSpeed = START_SPEED;
	LED_Init();
	Car_Dir_Init();
	PWM_PB76_Init();
	PWM_PB76_Duty(START_SPEED, START_SPEED);
			
	while(1){
		control_symbol = UART1_InChar();
		UART0_OutChar(control_symbol);
		UART0_OutChar(CR);
		UART0_OutChar(LF);
		
		switch(control_symbol){
			
			case 'F':
			case 'f':
				// moving forward
				LED = Green;
				DIRECTION = FORWARD;
				PWM0_ENABLE_R |= 0x00000003; // enable both wheels
			break;
				
			case 'S':
			case 's':
				// stop
				LED = Dark;
				PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
			break;
			
			case 'B':
			case 'b':
				// Enable blue LED, moving backward
				LED = Blue;
				DIRECTION = BACKWARD;
				PWM0_ENABLE_R |= 0x00000003; // enable both wheels
			break;
			
			case 'L':
			case 'l':
				// left turn
				LED = Yellow;
				PWM0_ENABLE_R |= 0x00000002; // Enable right wheel
				PWM0_ENABLE_R &= ~0x00000001; // Disable left wheel
			break;

			case 'R':
			case 'r':
				// right turn
				LED = Purple;
				PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
				PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
			break;

			case 'U':
			case 'u':
			// speed up
			switch(carSpeed){
				case SPEED_30:
					newCarSpeed = SPEED_60;
					break;
				case SPEED_60:
					newCarSpeed = START_SPEED;
					break;
				case START_SPEED:
					newCarSpeed = SPEED_98; 	
					break;
			}
			// update duty cycle
			PWM_PB76_Duty(newCarSpeed, newCarSpeed);
			carSpeed = newCarSpeed;
			break;
			
			case 'D':
			case 'd':
			// slow down
			switch(carSpeed){
				case SPEED_60:
					newCarSpeed = SPEED_30;
					break;
				case START_SPEED:
					newCarSpeed = SPEED_60;
					break;
				case SPEED_98:
					newCarSpeed = START_SPEED;
					break;
			}
			// update duty cycle
			PWM_PB76_Duty(newCarSpeed, newCarSpeed);
			carSpeed = newCarSpeed;
			break;
		}
	}
}

// Subroutine to wait 0.25 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){
	unsigned long volatile time;
  time = 727240*500/91;  // 0.25sec
  while(time){
		time--;
  }
}

// ADDED

//------------UART_Init------------
// Initialize the UART for 19200 baud rate (assuming 16 MHz UART clock),
// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
// Input: none
// Output: none
void UART_Init(void){
	// Activate Clocks
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART1; // activate UART1
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
	SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART0; // activate UART0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA; // activate port A
	
	
	UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART0_IBRD_R = 17;                    // IBRD = int(16,000,000 / (16 * 57600)) = int(17.3611111)
  UART0_FBRD_R = 23;                     // FBRD = round(3611111 * 64) = 27
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART0_CTL_R |= 0x301;                 // enable UART for both Rx and Tx

  GPIO_PORTA_AFSEL_R |= 0x03;           // enable alt funct on PA1,PA0
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1,PA0
                                        // configure PA1,PA0 as UART0
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA1,PA0
	
  UART1_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
	
	// Data Communication Mode, Buad Rate = 57600
  UART1_IBRD_R = 17;                    // IBRD = int(16,000,000 / (16 * 57600)) = int(17.3611111)
  UART1_FBRD_R = 23;                     // FBRD = round(3611111 * 64) = 27
	
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART1_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART1_CTL_R |= 0x301;                 // enable UART for both Rx and Tx
  
  GPIO_PORTB_AFSEL_R |= 0x03;           // enable alt funct on PB1,PB0
  GPIO_PORTB_DEN_R |= 0x03;             // enable digital I/O on PB1,PB0
                                        // configure PB1,PB0 as UART1
  GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R&0xFFFFFF00)+0x00000011;
  GPIO_PORTB_AMSEL_R &= ~0x03;          // disable analog functionality on PB1,PB0

}

//------------UART0_OutChar------------
// Output 8-bit to serial port
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UART0_OutChar(unsigned char data){
  while((UART0_FR_R&UART_FR_TXFF) != 0);
  UART0_DR_R = data;
}

//------------UART0_OutString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void UART0_OutString(unsigned char *pt){
  while(*pt){
    UART0_OutChar(*pt);
    pt++;
  }
}

//------------UART1_InChar------------
// Wait for new serial port input
// Input: none
// Output: ASCII code for key typed
unsigned char UART1_InChar(void){
  while((UART1_FR_R&UART_FR_RXFE) != 0);
  return((unsigned char)(UART1_DR_R&0xFF));
}

// This function reads response from HC-05 Bluetooth module.
void BLT_InString(unsigned char *bufPt) {
  unsigned char length=0;
  bufPt[length] = UART1_InChar();
  
  // Two possible endings for a reply from HC-05: OK\r\n, ERROR:(0)\r\n
  while (bufPt[length]!=LF) {
    length++;
    bufPt[length] = UART1_InChar();
  };
    
  // add null terminator
  length++;
  bufPt[length] = 0;
}