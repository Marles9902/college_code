// LEDSW.h
// Runs on TM4C123 for CECS347 Project 2

void LEDSW_Init(void);
/////////////////////////////////////////////////////////////////////////////
// Course Number: CECS 347
// Assignment: Example project for Hardware PWM controlled Car
// Description: 
/////////////////////////////////////////////////////////////////////////////
#define LED (*((volatile unsigned long *)0x40025038))  	// use onboard three LEDs: PF321
#define BTN (*((volatile unsigned long *)0x40025044))		// use onboard push buttons: PF40
//#define LEDSW (*((volatile unsigned long *)0x4002507C))		// use onboard three LEDs: PF321, push buttons: PF40

////////// Constants //////////  
// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// white    RGB    0x0E
// pink     R-B    0x06
// cyan     -GB    0x0C

#define Dark    	0x00
#define Red     	0x02
#define Blue    	0x04
#define Green   	0x08
#define Yellow  	0x0A
#define Cyan      0x0C
#define White   	0x0E
#define Purple  	0x06

//////////////////////1. Declarations Section////////////////////////////////
////////// Function Prototypes //////////
// Dependency: None
// Inputs: None
// Outputs: None
// Description: Initializes PB5432 for use with L298N motor driver direction
void LED_Init(void);
/////////////////////////////////////////////////////////////////////////////

