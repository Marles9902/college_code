//main.c

#include <SI_EFM8BB1_Register_Enums.h>

void InitDevice(void)
{
	//Disable Watchdog Timer
	//Disable Watchdog with key sequence
	WDTCN = 0xDE; //First key
	WDTCN = 0xAD; //Second key
	// [WDTCN – Watchdog Timer Control]$

	//Setup Defaults for P1
	P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__OPEN_DRAIN
	| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN
	| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__OPEN_DRAIN
	| P1MDOUT_B6__OPEN_DRAIN | P1MDOUT_B7__OPEN_DRAIN;

	//Enable Weak Pullups
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;

	//Disable Interrupts
	IE = IE_EA__DISABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
	| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
	| IE_ET2__ENABLED | IE_ES0__DISABLED;

}

void main(void){

	// declare variables
	unsigned char x;
	unsigned counter, counter_limit;
	unsigned shifting;
	
	InitDevice();
	
	// initializing variables
	x = 0x01;
	counter = 0;
	shifting = 1;
	
	TMOD = 0x01;	// timer 0 16-bit mode
	TCON = TCON|(0x01<<4);	// start timer 0 
	
	// Superloop Architcture
	while(1){
		
		// check if TF = 1
		if(TCON&(0x01 << 5)){		
			// overflow has happened
			TCON = TCON&~(0x01 << 4);	//stop the timer 
			
			counter += 1;	// counter goes up 1
			
			// check if 8051 button is pressed
			if(P0&0x02<<1){
				// unpressed
				counter_limit = 5;	// half second delay
			}else{
				//pressed
				counter_limit = 10;	// one second delay
			}
			
			// check counter amount 
			if(counter >= counter_limit){
				
				// check if breadboard button is pressed 
				if(P0&0x01<<1){
					P1 = ~x;	// one LED on
				}else{
					P1 = x;	// one LED off
				}
				
				// check direction of shift
				if(shifting){
					x = x<<1;	// shift left by one 
				}else{
					x = x>>1;	// shift right by one
				}
				
				// check if LED should shift
				if(x==0x01){
					shifting = 1;	// shift left
				}
				else if(x==0x01<<7){
					shifting = 0;	// shift right
				}
				
				counter = 0;	// reset counter
				
			}
			
			// .1 seconds has happened
			TL0 = 0x4F;
			TH0 = 0x9C;
			
			TCON = TCON&~(0x01<<5);	// clear the flag
			TCON = TCON|(0x01<<4);	// start timer 0 again 
			
		}
	}
}