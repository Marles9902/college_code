// This is an example program to show music programming on the LaunchPad.
// You can run this program without modification.
// The program will play 8 basic notes in selected C scale: Happy Birthday, 
// doe ray mi fa so la ti 
// C   D   E  F  G  A  B
// in forward and backward order and repeat forever.
// Hardware connection: 
// Positive logic Speaker/Headset is connected to PA2.
// Authors: Min He
// Date: August 28, 2018

// 1. Pre-processor Directives Section
// Constant declarations to access port registers using 
// symbolic names instead of addresses
#include "tm4c123gh6pm.h"
#include "SysTick.h"

#define TEMPO 2 // each tone uses the same duration 

// 2. Declarations Section
// Constants

// initial values for piano major tones: 
// Assume system clock is 16MHz.
const unsigned long Tone_Tab[] = 
// Note name: C, D, E, F, G, A, B, C'
// Offset:0, 1, 2, 3, 4, 5, 6, 7
{30534,27211,24242,22923,20408,18182,16194,15289}; // C4 Major notes
//{15289,13621,12135,11454,10204,9091,8099,7645}; // C5 Major notes
//{7645,6810,6067,5727,5102,4545,4050,3822}; // C6 Major notes

//   Function Prototypes
void Speaker_Init(void);
void Delay(void);
extern void EnableInterrupts(void);
void switches(void);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){
  unsigned char i,j;
	
  Speaker_Init();
  SysTick_Init();
  EnableInterrupts();  // SysTick uses interrupts
	switches();
	while(1){
		for (i=0;i<8;i++) {
			j=0;
			 
			// load the inital value for current note
			SysTick_Set_Current_Note(Tone_Tab[i]);
			SysTick_start();
			while (j++<TEMPO) // play the note for specified duration: tempo control
				Delay();
			SysTick_stop();
		}
		// i=8 or i--;
		for (;i>0;i--) {  // i=8 to 1
			j=0;
			 
			// load the inital value for current note
			SysTick_Set_Current_Note(Tone_Tab[i-1]);
			SysTick_start();
			while (j++<TEMPO) // play the note for specified duration
				Delay();
			SysTick_stop();
		}
	}

	/*	
	// REMOVED WHILE LOOP FROM ABOVE TO HERE FOR 8/28 PARTICIPATION
	while(1){
		// sw1 is pressed
    if(GPIO_PORTF_DATA_R&0x10){
			// COPIED FROM ABOVE
			SysTick_Set_Current_Note(Tone_Tab[i]);
			SysTick_start();
			while (j++<TEMPO)
				Delay();
			SysTick_stop();
		}
		// sw2 is pressed 
		if(GPIO_PORTF_DATA_R&0x01){
			// COPIED FROM ABOVE
			SysTick_Set_Current_Note(Tone_Tab[i-1]);
			SysTick_start();
			while (j++<TEMPO)
				Delay();
			SysTick_stop();
		}
	}
	
	*/
}

// Subroutine to wait 0.1 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){
	unsigned long volatile time;
  time = 727240*50/91;  // 0.1sec
  while(time){
		time--;
  }
}
// Make PA2 an output, enable digital I/O, ensure alt. functions off
void Speaker_Init(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x01;           // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
                                    // 2) no need to unlock PA2
  GPIO_PORTA_PCTL_R &= ~0x00000F00; // 3) regular GPIO
  GPIO_PORTA_AMSEL_R &= ~0x04;      // 4) disable analog function on PA2
  GPIO_PORTA_DIR_R |= 0x04;         // 5) set direction to output
  GPIO_PORTA_AFSEL_R &= ~0x04;      // 6) regular port function
  GPIO_PORTA_DEN_R |= 0x04;         // 7) enable digital port
  GPIO_PORTA_DR8R_R |= 0x04;        // 8) optional: enable 8 mA drive on PA2 to increase the voice volumn
}

// COPIED FROM HELLOLAUNCHPAD.C
void switches(void){
  SYSCTL_RCGC2_R |= 0x00000020;     	// activate F clock
	while ((SYSCTL_RCGC2_R&0x00000020)!=0x00000020){} // wait for the clock to be ready
		
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   	// unlock PortF PF0  
	GPIO_PORTF_CR_R |= 0x11;         		// allow changes to PF4,PF0 :10001->0x11     
  GPIO_PORTF_AMSEL_R &= ~0x11;        // disable analog function
  GPIO_PORTF_PCTL_R &= ~0x000F000F; 	// GPIO clear bit PCTL  
  GPIO_PORTF_DIR_R &= ~0x11;          // PF4,PF0 input   
	GPIO_PORTF_AFSEL_R &= ~0x11;        // no alternate function
  GPIO_PORTF_PUR_R |= 0x11;          	// enable pullup resistors on PF4,PF0       
  GPIO_PORTF_DEN_R |= 0x11;          	// enable digital pins PF4-PF0        
}