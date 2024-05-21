// Ultrasonic_Sensor.c

#include <stdint.h>
#include "PLL.h"
#include "Timer1A.h"
#include "tm4c123gh6pm.h"

// Part 2 Constants
#define TRIGGER_PIN 		(*((volatile unsigned long *)0x40005080))  // PB5 is the trigger pin	
#define TRIGGER_VALUE 	0x20   	// trigger at bit 5
#define ECHO_PIN 				(*((volatile unsigned long *)0x40005040))  // PB4 is the echo pin	
#define ECHO_VALUE 			0x10   	// trigger at bit 4
#define MC_LEN 					0.025 	// length of one machine cycle in microsecond for 40 MHz clock
#define SOUND_SPEED 		0.0343 	// centimeter per micro-second

// Part 3 Constants
#define PERIOD		160000
#define MIN_DUTY	PERIOD/40		// minimum duty cycle 40%
#define MAX_DUTY	PERIOD*0.9
#define	HALF_DUTY	PERIOD/2
#define	DUTY_STEP	PERIOD/10
#define RED       0x02
#define BLUE      0x04
#define GREEN     0x08
#define WHITE 		RED + GREEN + BLUE
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

extern void DisableInterrupts(void);	// Part 3
extern void EnableInterrupts(void);		// Part 2
extern void WaitForInterrupt(void);		// Part 3
extern void GPIOPortB_Handler(void);	// Part 2
extern void GPIOPortF_Handler(void);	// Part 3
void PortB_Init(void);								// Part 2
//void PortF_Init(void);								// Part 3
void Delay(void);											// Part 2

// Part 2
static volatile uint8_t done=0;
static volatile uint32_t distance=0;

int main(void){
	DisableInterrupts();
	PortB_Init();
	//PortF_Init();
	PLL_Init();
	Timer1A_Init();
	EnableInterrupts();
  while(1){
		
		done = 0;
		distance = 0;
		TRIGGER_PIN &= ~TRIGGER_VALUE; // send low to trigger
		Timer1A_Wait1us(2);
		TRIGGER_PIN |= TRIGGER_VALUE; // send high to trigger
		Timer1A_Wait1us(10);
		TRIGGER_PIN &= ~TRIGGER_VALUE; // send low to trigger
		
		Delay();
		GPIO_PORTF_DATA_R = WHITE;
		Delay();
		
		WaitForInterrupt();
		
    while (!done);
  }
}

void PortB_Init(void){ 
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;           		// 1) activate clock for Port A
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOB)!=SYSCTL_RCGC2_GPIOB){}; // wait for clock to start -- 2) no need to unlock PA2
	
  GPIO_PORTB_PCTL_R &= ~0x00FF0000; 									// 3) regular GPIO
  GPIO_PORTB_AMSEL_R &= (uint32_t)~0x30;      				// 4) disable analog function on PA2
  GPIO_PORTB_DIR_R &= ~0x10;        									// 5) PB4:echo pin, input
  GPIO_PORTB_DIR_R |= 0x20;         									// 5) PB5:trigger pin, output
  GPIO_PORTB_AFSEL_R &= ~0x30;      									// 6) regular port function
  GPIO_PORTB_DEN_R |= 0x30;         									// 7) enable digital port
  GPIO_PORTB_IS_R &= ~0x10;         									// PB4 is edge-sensitive
  GPIO_PORTB_IBE_R |= 0x10;         									// PB4 is both edges
  GPIO_PORTB_IEV_R &= ~0x10;        									// PB4 both edge event
  GPIO_PORTB_ICR_R = 0x10;          									// clear flag 4
  GPIO_PORTB_IM_R |= 0x10;          									// arm interrupt on PB4
  NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF1FFF)|0x00006000; 	// (g) priority 3
  NVIC_EN0_R = 0x00000002;          									// (h) enable Port B edge interrupt
}


void GPIOPortB_Handler(void){
	
	if (ECHO_PIN==ECHO_VALUE){  // echo pin rising edge is detected, start timing
		Timer1A_Start();
	}
	else { 
		
		Timer1A_Stop();
		distance = (uint32_t)(Timer1A_Get_MC_Elapsed()*MC_LEN*SOUND_SPEED)/2;	
		done = 1;
		
	}
  GPIO_PORTB_ICR_R = 0x10;      // acknowledge flag 4
}


/*
#define PF1       (*((volatile unsigned long *)0x40025008))
#define PF2       (*((volatile unsigned long *)0x40025010))
#define PF3       (*((volatile unsigned long *)0x40025020))
#define LEDS      (*((volatile unsigned long *)0x40025038))
#define RED       0x02
#define BLUE      0x04
#define GREEN     0x08

WHITE = RED + BLUE + GREEN

  GPIO_PORTF_DIR_R |= 0x0E;        // make PF3-1 output (PF3-1 built-in LEDs)
  GPIO_PORTF_AFSEL_R &= ~0x0E;     // disable alt funct on PF3-1
  GPIO_PORTF_DEN_R |= 0x0E;        // enable digital I/O on PF3-1
*/
