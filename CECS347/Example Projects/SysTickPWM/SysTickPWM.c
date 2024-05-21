// SysTickPWM.c
// Runs on TM4C123
// Use SysTick interrupts to implement a timer-based PWM: this PWM signal can be used 
// to control the brightness of an LED or to drive and change the speed of a DC motor
// The onboard puch button SW1 increases the delivered power, and SW2 decreases the delivered power.
// By Min He, 09/12/2022

#include "tm4c123gh6pm.h"

// Constants
#define PERIOD 			160000           	  // number of machine cycles for 10ms, value is based on 16MH system clock
#define MIN_DUTY    PERIOD/10						// minimum duty cycle 10%
#define MAX_DUTY    PERIOD*0.9					// maximum duty cycle 90%
#define HALF_DUTY   PERIOD/2					// 50% duty cycle
#define DUTY_STEP		PERIOD/10					  // duty cycle change for each button press
#define NVIC_EN0_PORTF 0x40000000
#define BLUE 				0x04
#define SW1 				0x10
#define SW2 				0x01

// Function prototypes
// External functions for interrupt control defined in startup.s
extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts
extern void WaitForInterrupt(void);  // low power mode

// This function initialize PF2(Blue LED) to output PWM signal and 
// Systick to generate required timing for PWM signal
void PWM_Output_Init(void);

// This function initilizes port F and arm PF4, PF0 for falling edge interrupts
void Sw_PWM_Init(void);
void SysTick_Init(void);

// Global variables: 
// H: number of clocks cycles for duty cycle
// L: number of clock cycles for non-duty cycle
volatile unsigned long H,L;

int main(void){
  DisableInterrupts();  // disable interrupts to allow initializations
  Sw_PWM_Init();        // arm PF4, PF0 for falling edge interrupts
	SysTick_Init();
  EnableInterrupts();   // enable after initializations are done
  while(1){
    WaitForInterrupt(); // low power mode
  }
}

// This function initialize PF2 to output PWM signal and 
// Systick to generate required timing for PWM signal
void Sw_PWM_Init(void){
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;     	// activate F clock
	while ((SYSCTL_RCGC2_R & SYSCTL_RCGC2_GPIOF)!= SYSCTL_RCGC2_GPIOF){} // wait for the clock to be ready
		
  H = L = HALF_DUTY;            			// 50% duty cycle, assume system clock 16MHz, 
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; 	// unlock GPIO Port F
  GPIO_PORTF_CR_R |= 0x15;         		// allow changes to PF4,0
  GPIO_PORTF_AMSEL_R &= ~0x15;  			// disable analog functionality on PF2
  GPIO_PORTF_PCTL_R &= ~0x000F0F0F; 	// configure PF2 as GPIO
  GPIO_PORTF_DIR_R |= 0x04;     			// make PF2 out
  GPIO_PORTF_DATA_R &= ~BLUE;					// Turn off Blue to start Blue with duty cycle.
  GPIO_PORTF_DIR_R &= ~0x11;    			// (c) make PF4,0 in (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x15;  			// disable alt funct on PF2
  GPIO_PORTF_DEN_R |= 0x15;     			// enable digital I/O on PF2
  GPIO_PORTF_PUR_R |= 0x11;     //     enable weak pull-up on PF4,0
  GPIO_PORTF_IS_R &= ~0x11;     // (d) PF4,PF0 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x11;    //     PF4,PF0 is not both edges
  GPIO_PORTF_IEV_R |= ~0x11;    //     PF4,PF0 falling edge event
  GPIO_PORTF_ICR_R |= 0x11;      // (e) clear flags 4,0
  GPIO_PORTF_IM_R |= 0x11;      // (f) arm interrupt on PF4,PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x00400000; // (g) bits:23-21 for PORTF, set priority to 2
  NVIC_EN0_R = NVIC_EN0_PORTF;      // (h) enable interrupt 30 in NVIC
}

void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;           			// disable SysTick during setup
  NVIC_ST_RELOAD_R = HALF_DUTY-1;     // reload value for 50% duty cycle
  NVIC_ST_CURRENT_R = 0;        			// any write to current clears it
  NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x1FFFFFFF)|0x40000000; // bit 31-29 for SysTick, set priority to 2
  NVIC_ST_CTRL_R |= NVIC_ST_CTRL_CLK_SRC + NVIC_ST_CTRL_INTEN + NVIC_ST_CTRL_ENABLE;  // enable with core clock and interrupts, start systick timer
}

// SysTick ISR:
// 1. Implement timing control for duty cycle and non-duty cycle
// 2. Output a waveform based on current duty cycle
void SysTick_Handler(void){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;// turn off SysTick 
	GPIO_PORTF_DATA_R ^= BLUE;              // Toggle Blue LED
  if(GPIO_PORTF_DATA_R&BLUE){   // previous cycle is duty cycle
    NVIC_ST_RELOAD_R = L-1;     // switch to non-duty cycle
  } else{ // previous cycle is not duty cycle
    NVIC_ST_RELOAD_R = H-1;     // switch to duty cycle
  }
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE; // turn on systick to continue
}

// PORTF ISR:
// Change delivered power based on switch press: 
// sw1: increase 10% until reach 90%
// sw2: decrease 10% until reach 10%
void GPIOPortF_Handler(void){ // called on touch of either SW1 or SW2
  if(GPIO_PORTF_RIS_R&SW2){  // SW1 touched
    GPIO_PORTF_ICR_R = SW2;  // acknowledge flag0
    if(H<MAX_DUTY) H = H+DUTY_STEP;   // increment duty cycle by one step
  }
	
  if(GPIO_PORTF_RIS_R&SW1){  // SW2 touched 
    GPIO_PORTF_ICR_R = SW1;  // acknowledge flag4
    if(H>MIN_DUTY) H = H-DUTY_STEP;    // decrement duty cycle by one step
  }
	
  L = PERIOD-H; // constant period of 10ms, variable duty cycle
}
