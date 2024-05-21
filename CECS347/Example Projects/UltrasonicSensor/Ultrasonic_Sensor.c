// Project 1 - Ultrasonic_Sensor.c
// implemented with reference to Ultrasonic_Sensor

#include <stdint.h>
#include "PLL.h"
#include "SysTick.h"
#include "Timer1A.h"
#include "tm4c123gh6pm.h"

// Constant defines
// Ultrasonic Sensor
#define TRIGGER_PIN 		(*((volatile unsigned long *)0x40005080))  	// PB5 is the trigger pin	
#define TRIGGER_VALUE 	0x20   																			// trigger at bit 5
#define ECHO_PIN 				(*((volatile unsigned long *)0x40005040))  	// PB4 is the echo pin	
#define ECHO_VALUE 			0x10   																			// trigger at bit 4
#define MC_LEN 					0.025 																			// length of one machine cycle in microsecond for 40 MHz clock
#define SOUND_SPEED 		0.0343 																			// centimeter per micro-second

// PWM
#define MIN_DUTY	PERIOD/40		// minimum duty cycle 40%
#define MAX_DUTY	PERIOD*0.9	// maximum duty cycle 90%
#define	HALF_DUTY	PERIOD/2		// 50% duty cycle --> 65% duty cycle for 40% - 90%
#define	DUTY_STEP	PERIOD/10		// duty cycle change for each distance change

// LEDs
#define OFF				0				
#define RED       0x02
#define WHITE 		0x0E

// Port F 
#define NVIC_EN0_PORTF 					0x40000000
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

// Function prototypes
extern void DisableInterrupts(void);	// Disable interrupts
extern void EnableInterrupts(void);		// Enable interrupts
extern void WaitForInterrupt(void);		// low power mode
extern void GPIOPortB_Handler(void);	// Ultrasonic Sensor

void PortB_Init(void);								// Ultrasonic Sensor
void PortF_Init(void);								// LEDs

// Ultrasonic Sensor global variables
static volatile uint8_t done=0;
static volatile uint32_t distance=0;

// PWM global variables
uint32_t PERIOD;
char RED_LED = 0;
char WHITE_LED = 0;
// H: number of clocks cycles for duty cycle
// L: number of clock cycles for non-duty cycle
volatile unsigned long H,L;

int main(void){
	DisableInterrupts();			// disable interrupts to allow initialization
	PortB_Init();							// ultrasonic sensor
	PortF_Init();							// onboard LEDs
	Timer1A_Init();						// trigger pulses for sensor
	SysTick_Init();						// timer-based PWM
	PLL_Init();								// 40 MHz clock
	EnableInterrupts();				// enable interrupts after initialization
  while(1){
		
		done = 0;
		TRIGGER_PIN &= ~TRIGGER_VALUE; // send low to trigger
		Timer1A_Wait(2);
		TRIGGER_PIN |= TRIGGER_VALUE; // send high to trigger
		Timer1A_Wait(10);
		TRIGGER_PIN &= ~TRIGGER_VALUE; // send low to trigger
		
		TIMER1_TAR_R = 0;
    while (!done);
	}
}

// Port B -- ultrasonic sensor
void PortB_Init(void){ 
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;           										// 1) activate clock for Port B
	while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOB)!=SYSCTL_RCGC2_GPIOB){}; 	// wait for clock to start -- 2) no need to unlock PB
	
  GPIO_PORTB_PCTL_R &= ~0x00FF0000; 																	// 3) regular GPIO
  GPIO_PORTB_AMSEL_R &= (uint32_t)~0x30;      												// 4) disable analog function on PB4
  GPIO_PORTB_DIR_R &= ~0x10;        																	// 5) PB4:echo pin, input
  GPIO_PORTB_DIR_R |= 0x20;         																	// 5) PB5:trigger pin, output
	GPIO_PORTB_AFSEL_R &= ~0x30;      																	// 6) regular port function
  GPIO_PORTB_DEN_R |= 0x30;         																	// 7) enable digital port
  GPIO_PORTB_IS_R &= ~0x10;         																	// PB4 is edge-sensitive
  GPIO_PORTB_IBE_R |= 0x10;         																	// PB4 is both edges
  GPIO_PORTB_IEV_R &= ~0x10;        																	// PB4 both edge event
  GPIO_PORTB_ICR_R = 0x10;          																	// clear flag 4
  GPIO_PORTB_IM_R |= 0x10;          																	// arm interrupt on PB4
  NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF1FFF)|0x00006000; 									// (g) priority 3
  NVIC_EN0_R = 0x00000002;          																	// (h) enable Port B edge interrupt
}

// Port F is for the onboard LEDs
// initialize PF1-3 to output PWM signal and 
// SysTick to generate required timing for PWM signal
void PortF_Init(void){ 
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;             									// 1) activate clock for Port F
  while ((SYSCTL_RCGC2_R&SYSCTL_RCGC2_GPIOF) == 0){}; 								// wait for clock to start -- 2) no need to unlock
  
  H = L = 400000;            																					// 50% duty cycle, system clock -- 40 MHz, 
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; 																	// unlock GPIO Port F
  GPIO_PORTF_AMSEL_R &= ~0x0E;  																			// disable analog functionality on PF1-PF3
  GPIO_PORTF_PCTL_R &= ~0x0000FFF0; 																	// configure PF3,2,1 as GPIO
  GPIO_PORTF_DIR_R |= 0x0E;     																			// make PF1-PF3 out
  GPIO_PORTF_DATA_R &= ~WHITE;																				// Turn off white to start white with duty cycle.
  GPIO_PORTF_AFSEL_R &= ~0x0E;  																			// disable alt function on PF1-PF3
  GPIO_PORTF_DEN_R |= 0x0E;     																			// enable digital I/O on PF1-PF3
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x00400000; 									// (g) bits:23-21 for PORTF, set priority to 2
  NVIC_EN0_R = NVIC_EN0_PORTF;      																	// (h) enable interrupt 30 in NVIC
}

// handles the LED brightness and blinking based on distance
void GPIOPortB_Handler(void){
	if (ECHO_PIN==ECHO_VALUE){  // echo pin rising edge is detected, start timing
		Timer1A_Start();
	}
	else{
		// echo pin falling edge is detected, end timing and calculate distance.
    // The following code is based on the fact that the HCSR04 ultrasonic sensor 
    // echo pin will always go low after a trigger with bouncing back
    // or after a timeout. The maximum distance can be detected is 400cm.
		// The speed of sound is approximately 340 meters per second, 
		// or  .0343 c/µS.
    // Distance = (echo pulse width * 0.0343)/2; = ((# of mc)*MC_LEN*SOUND_SPEED)/2		
		Timer1A_Stop();
		distance = (uint32_t)(Timer1A_Get_MC_Elapsed()*MC_LEN*SOUND_SPEED)/2;	
		
		PERIOD = 400000;			// number of machine cycles for 10ms, value is based on 40 MHz system clock	
		
		if (distance < 10){
			WHITE_LED = 0;
			RED_LED = 1;
			PERIOD = 20000000;	// 400000 * 50 = 20000000	--> 0.25s on, 0.25s off -- 0.5s total
			H = PERIOD / 2;
		} 
		else if (distance >= 10 && distance < 20) {
			// duty cycle @ 90% when distance is 10-19cm
			H = PERIOD * 0.40;
			WHITE_LED = 1;
			RED_LED = 0;
		} 
		else if (distance >= 20 && distance < 30) {
			// duty cycle @ 80% when distance is 20-29cm
			H = PERIOD * 0.50;
			WHITE_LED = 1;
			RED_LED = 0;
		} 
		else if (distance >= 30 && distance < 40){
			// duty cycle @ 70% when distance is 30-39cm 
			H = PERIOD * 0.60;
			WHITE_LED = 1;
			RED_LED = 0;
		} 
		else if (distance >= 40 && distance < 50){
			// duty cycle @ 60% when distance is 40-49cm
			H = PERIOD * 0.70;
			WHITE_LED = 1;
			RED_LED = 0;
		} 
		else if (distance >= 50 && distance < 60){
			// duty cycle @ 50% when distance is 50-59cm
			H = PERIOD * 0.80;
			WHITE_LED = 1;
			RED_LED = 0;	
		}
		else if (distance >= 60 && distance < 70){
			// duty cycle @ 40% when distance is 60-69cm
			H = PERIOD * 0.90;
			WHITE_LED = 1;
			RED_LED = 0;
		} 
		else if (distance >= 70){
			// duty cycle @ 0% when distance is >= 70cm
			GPIO_PORTF_DATA_R = OFF;		// LED off
			WHITE_LED = 0;
			RED_LED = 0;
		}
			L = PERIOD - H;
			done = 1;
			GPIO_PORTF_DATA_R = OFF;		// LED off
		}
		GPIO_PORTB_ICR_R = 0x10;      // acknowledge flag 4
}

// SysTick ISR:
// 1. Implement timing control for duty cycle and non-duty cycle
// 2. Output a waveform based on current duty cycle
void SysTick_Handler(void){
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;	// turn off SysTick 
	
	if(RED_LED){   													// previous cycle is duty cycle
		GPIO_PORTF_DATA_R ^= RED;							// toggle red LED
		if(GPIO_PORTF_DATA_R & RED){
			NVIC_ST_RELOAD_R = L-1;     				// switch to non-duty cycle
		} 
		else{ 																// previous cycle is not duty cycle
			NVIC_ST_RELOAD_R = H-1;     				// switch to duty cycle
		} 
	} 
	
	if(WHITE_LED){													// previous cycle is duty cycle
		GPIO_PORTF_DATA_R ^= WHITE;						// toggle white LED
		if (GPIO_PORTF_DATA_R & WHITE){
			NVIC_ST_RELOAD_R = L-1;
		} 
		else { 																// previous cycle is not duty cycle
			NVIC_ST_RELOAD_R = H-1;							// switch to duty cycle
		}
	}
	
	if (RED_LED == 0 && WHITE_LED == 0){
		GPIO_PORTF_DATA_R = 0;
	}

	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE; 	// turn on SysTick to continue
}