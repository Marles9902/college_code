// PWMtest.c
// Runs on TM4C123
// Use PWM0/PB6 and PWM1/PB7 to generate pulse-width modulated outputs.
// Min He
// September 7, 2021

// This is an example program to show how to use hardware PWM on TM4C123.
#include <stdint.h>
#include "PWM.h"

#define DIRECTION (*((volatile unsigned long *)0x4002403C)) // Mask for PE0-3
#define FORWARD 		0x0F		// 1111
#define BACKWARD 		0x0A		// 1010

#define PERIOD 10000				// Total PWM period
#define STEP 1000						// increments of duty cycle
#define MAX_DUTY 9000				// max duty cycle (90%)
#define STOP 1							// min duty cycle (0%)
#define SPEED_35 3500				// 35% duty cycle
#define SPEED_60 6000				// 60% duty cycle
#define SPEED_80 8000				// 80% duty cycle
#define SPEED_98 9800				// 98% duty cycle

void Delay(void);
extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts
extern void WaitForInterrupt(void);  // low power mode

int main(void){
	
 	DisableInterrupts();
	PLL_Init();									// 50MHz system clock
  PWM0A_Init(PERIOD);         // initialize PWM0, PB6 LEFT MOTOR
  PWM0B_Init(PERIOD);         // initialize PWM0, PB7 RIGHT MOTOR
	PortE_Init();								// initialize PE0-3, direction - PE0&1 for R, PE2&3 for L
	SwitchLED_Init();							// switches controls car direction, LEDs indicates car direction
	EnableInterrupts();
	
	DIRECTION = FORWARD;
	PWM0A_Duty(STOP);
	PWM0B_Duty(STOP);
	
	while(1){
		WaitForInterrupt();
  }
}

// Subroutine to wait 0.5 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){unsigned long volatile time;
  time = 727240*100/91;  // 1 sec
  while(time){
		time--;
  }
	for (time=0;time<1000;time=time+10) {
	}
}
