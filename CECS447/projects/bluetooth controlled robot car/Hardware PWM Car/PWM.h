/////////////////////////////////////////////////////////////////////////////
// Course Number: CECS 347
// Assignment: Example project for Hardware PWM controlled Car
// Description: 
/////////////////////////////////////////////////////////////////////////////
#include <stdint.h>

// Constant definitions based on the following hardware interface:
// System clock is 16MHz.
#define PERIOD 16000 //  16MHz/1000=16000
#define START_SPEED 12000	//(16000*0.75 = 12000)

// ADDED
#define STEP 1600						// increments of duty cycle
#define STOP 1							// min duty cycle (0%)
#define SPEED_30 4800				// 30% duty cycle (16000*0.3 = 4800)
#define SPEED_60 9600				// 60% duty cycle (16000*0.6 = 9600)
#define SPEED_98 15680			// 98% duty cycle (16000*0.98 = 15680)

// PE3210 are used for direction control on L298.
// Motor 1 is connected to the left wheel, Motor 2 is connected to the right wheel.

//////////////////////1. Declarations Section////////////////////////////////
////////// Function Prototypes //////////
// Dependency: None
// Inputs: None
// Outputs: None
// Description: 
//	Initializes the PWM module 1 signals tied to PF321 on the Tiva Launchpad 
//		to allow for changing brightness of LEDs based on vehicle speed.
//	Initializes the PWM module 0 signals tied to PB76 to be used with the 
//		L298N motor driver allowing for a variable speed of robot car.
void PWM_PB76_Init(void);

// Dependency: PWM_PB76_Init()
// Inputs: 
//	duty_L is the value corresponding to the duty cycle of the left wheel
//	duty_R is the value corresponding to the duty cycle of the right wheel
// Outputs: None 
// Description: Changes the duty cycles of PB76 by changing the CMP registers
void PWM_PB76_Duty(uint16_t duty_L, uint16_t duty_R);
/////////////////////////////////////////////////////////////////////////////
