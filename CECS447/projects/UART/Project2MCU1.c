// CECS447Project2MCU1.c
// Runs on TM4C123
// Starter file for CEC447 Project 2 UART MCU1
// Min He
// September 26, 2023

#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "UART0.h"
//#include "UART2.h"
//#include "LEDSW.h"

#define MAX_STR_LEN 20

// TODO: define bit values for all Colors 
#define DARK 		0
#define RED			0x02
#define GREEN 	0x08
#define BLUE		0x04
#define YELLOW	0x0A
#define CYAN		0x0C
#define PURPLE	0x06
#define WHITE		0x0E

// TODO: define all colors in the color wheel
const	uint8_t color_wheel[] = {};

// TODO: define bit addresses for the onboard three LEDs and two switches
#define LEDs 		()
#define SW1			()
#define SW2			()
	
extern void EnableInterrupts(void);
extern void WaitForInterrupt(void);
extern void DisableInterrupts(void);
void Mode1(void);
void Mode2(void);
void Mode3(void);
void Display_Menu(void); 
//void PortF_Init(void);
	
void Switch_Init(void);
void SysTick_Handler(void);
uint8_t currentLED = NULL;
extern unsigned long H,L;
#define PERIOD 			5000           	// Slow blink
#define MIN_DUTY    PERIOD/10							// minimum duty cycle 10%
#define MAX_DUTY    PERIOD*0.9						// maximum duty cycle 90%
#define DUTY_STEP		PERIOD/10							// duty cycle change for each button press

	

int main(void){
	DisableInterrupts();
  PLL_Init();
	//PortF_Init();
	
	Switch_Init();
	SysTick_Handler();
	
	
  UART0_Init(false, false);  // for PC<->MCU1
	//UART2_Iniit();  // for MCU1<->MCU2
	//LEDSW_Init();  // Initialize the onboard three LEDs and two push buttons
	EnableInterrupts();

  while(1){
		// displays the main menu 
		Display_Menu(); 
		switch(UART0_InChar()){
			case '1':
				Mode1();
				break;
			case '2':
				Mode2();
				break;
			case '3': 
				Mode3();
				break;
			default:
				break; 
		}
		OutCRLF0();
  }
}

unsigned long H,L;
void Mode1(void){
	while(1){
		OutCRLF0();
		UART0_OutString((uint8_t *)"Model 1 Menu");
		OutCRLF0();
		UART0_OutString((uint8_t *)"Please select an option from the following list (enter 1 or 2 or 3):");
		OutCRLF0();
		UART0_OutString((uint8_t *)"1. Choose an LED color.");	
		OutCRLF0();
		UART0_OutString((uint8_t *)"2. Change the brightness of current LED(s).");
		OutCRLF0();
		UART0_OutString((uint8_t *)"3. Exit");
		OutCRLF0();
		OutCRLF0();

		switch(UART0_InChar()){
			case '1':
				UART0_OutString((uint8_t *)"Please select a color from the following list:");
				OutCRLF0();
				UART0_OutString((uint8_t *)"(d(dark), r(red), g(green), b(blue), y(yellow),");
				OutCRLF0();
				UART0_OutString((uint8_t *)"c(cyan), p(purple), w(white))");
				OutCRLF0();
				OutCRLF0();
				char input = UART0_InChar();
				currentLED = charToHex(input);
				switch(input){
					case 'd':
						GPIO_PORTF_DATA_R =DARK;
						UART0_OutString((uint8_t *)"LED is off.");
						break;
					case 'r':
						GPIO_PORTF_DATA_R = RED;
						UART0_OutString((uint8_t *)"Red LED is on.");
						break;
					case 'g':
						GPIO_PORTF_DATA_R = GREEN;
						UART0_OutString((uint8_t *)"Green LED is on.");
						break;
					case 'b':
						GPIO_PORTF_DATA_R = BLUE;
						UART0_OutString((uint8_t *)"Blue LED is on.");
						break;
					case 'y':
						GPIO_PORTF_DATA_R = YELLOW;
						UART0_OutString((uint8_t *)"Yellow LED is on.");
						break;
					case 'c':
						GPIO_PORTF_DATA_R = CYAN;
						UART0_OutString((uint8_t *)"Cyan LED is on.");
						break;
					case 'p':
						GPIO_PORTF_DATA_R = PURPLE;
						UART0_OutString((uint8_t *)"Purple LED is on.");
						break;
					case 'w':
						GPIO_PORTF_DATA_R = WHITE;
						UART0_OutString((uint8_t *)"White LED is on.");
						break;
					}
					break;
			case '2':
				OutCRLF0();
				UART0_OutString((uint8_t *)"Change the brightness of the current LED(s).");
				OutCRLF0();
				UART0_OutString((uint8_t *)"Please enter a decimal number from 0 to 100.");
				OutCRLF0();
				uint32_t userInput = UART0_InUDec();
				OutCRLF0();
				if(userInput==0){
					GPIO_PORTF_DATA_R = DARK;
					NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;// turn off SysTick to reset reload value
				}else{
					NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE; // turn on systick to continue
					H = userInput * MAX_DUTY / 100;
					L = PERIOD - H;
				}
				OutCRLF0();
				UART0_OutString((uint8_t *)"LED is displayed at ");
				UART0_OutUDec(userInput); 
				UART0_OutString((uint8_t *)"% brightness.");
					break;
			case '3': 
				return;
			}
		OutCRLF0();
	}
	
}


void Mode2(void){
}

void Mode3(void){
}

void Display_Menu(void){
	UART0_OutString((uint8_t *)"Welcome to CECS 447 Project 2 - UART");
	OutCRLF0();
	UART0_OutString((uint8_t *)"MCU1");
	OutCRLF0();
	UART0_OutString((uint8_t *)"	1.	PC<->MCU1 LED Control");	
	OutCRLF0();
	UART0_OutString((uint8_t *)"	2.	MCU1<->MCU2 Color Wheel");
	OutCRLF0();
	UART0_OutString((uint8_t *)"	3.	PC<->MCU1<->MCU2<->PC Chat Room");
	OutCRLF0();
	UART0_OutString((uint8_t *)"Please choose a communication mode (enter 1 or 2 or 3):");	
	OutCRLF0();
}

void SysTick_Handler(void){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;// tur of SysTick to reset reload value
  if(GPIO_PORTF_DATA_R&currentLED){   // toggle PF3-1
    GPIO_PORTF_DATA_R &= ~currentLED; // make PA5 low
    NVIC_ST_RELOAD_R = L-1;     // reload value for low phase
  } else{
    GPIO_PORTF_DATA_R |= currentLED;  // make PA5 high
    NVIC_ST_RELOAD_R = H-1;     // reload value for high phase
  }
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE; // turn on systick to continue
}

/*
void PortF_Init(void){ 
  SYSCTL_RCGC2_R |= 0x00000020;         // activate F clock
    while ((SYSCTL_RCGC2_R&0x00000020)!=0x00000020){} // wait for the clock to be ready

  GPIO_PORTF_LOCK_R = 0x4C4F434B;       // unlock PortF PF0
    GPIO_PORTF_CR_R |= 0x1F;                 // allow changes to PF4-0 :11111->0x1F
  GPIO_PORTF_AMSEL_R &= ~0x1F;        // disable analog function
  GPIO_PORTF_PCTL_R &= ~0x000FFFFF;     // GPIO clear bit PCTL
  GPIO_PORTF_DIR_R &= ~0x11;          // PF4,PF0 input
  GPIO_PORTF_DIR_R |= 0x0E;              // PF3,PF2,PF1 output
    GPIO_PORTF_AFSEL_R &= ~0x1F;        // no alternate function
  GPIO_PORTF_PUR_R |= 0x11;              // enable pullup resistors on PF4,PF0
  GPIO_PORTF_DEN_R |= 0x1F;              // enable digital pins PF4-PF0
}
*/

//FIXME
// Initilize port F and arm PF4, PF0 for falling edge interrupts
void Switch_Init(void){
	volatile unsigned long delay;	
	SYSCTL_RCGC2_R |= 0x00000020; // activate clock for port F
	delay = SYSCTL_RCGC2_R;           // delay   
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
  H = L = PERIOD/2;            // 50% duty cycle, assume system clock 16MHz, 
	GPIO_PORTF_CR_R |= 0x0E;      // allow changes for PA5 take effect 
  GPIO_PORTF_AMSEL_R &= ~0x0E;  // disable analog functionality on PA5
  GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // configure PA5 as GPIO
  GPIO_PORTF_DIR_R |= 0x0E;     // make PA5 out
  GPIO_PORTF_DR8R_R |= 0x0E;    // Add this line if the PWM is used to drive a DC Motor to enable 8 mA drive on PA5
  GPIO_PORTF_AFSEL_R &= ~0x0E;  // disable alt funct on PA5
  GPIO_PORTF_DEN_R |= 0x0E;     // enable digital I/O on PA5
  GPIO_PORTF_DATA_R &= ~0x0E;   // make PA5 low
  NVIC_ST_CTRL_R = 0;           // disable SysTick during setup
  NVIC_ST_RELOAD_R = L-1;       // reload value for 50% duty cycle
  NVIC_ST_CURRENT_R = 0;        // any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x1FFFFFFF)|0x40000000; // bit 31-29 for SysTick, set priority to 2
  NVIC_ST_CTRL_R |= 0x00000007;  // enable with core clock and interrupts, start systick timer
}
