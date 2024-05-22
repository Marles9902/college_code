// This is an example program for music programming.
// You will run this program without modification.
// The program will repeatedly play a specified song.

// The program will continuously play one of the song  
// defined in mysong on a speaker connected to pin PA2.
// Authors: Min He
// Date: August 26, 2018

// 1. Header files 
#include "tm4c123gh6pm.h"
#include "SysTick.h"
#include <stdint.h>

// 2. Declarations Section

// define music data structure 
struct Note {
  uint8_t tone_index;
  uint8_t delay;
};
typedef const struct Note NTyp;

// initial values for piano major tones.
// Assume SysTick clock frequency is 16MHz.
const uint32_t Tone_Tab[] =
// Notes:  C, D, E, F, G, A, B
// Offset: 0, 1, 2, 3, 4, 5, 6
{30534,27211,24242,22923,20408,18182,16194, // C4 Major notes
 15289,13621,12135,11454,10204,9091,8099, // C5 Major notes
 7645,6810,6067,5727,5102,4545,4050}; // C6 Major notes

#define PAUSE 255				// assume there are less than 255 tones used in any song

// indexes for notes used in music scores
#define C4 0
#define D4 1
#define E4 2
#define F4 3
#define G4 4
#define A4 5
#define B4 6
#define C5 0+7
#define D5 1+7
#define E5 2+7
#define F5 3+7
#define G5 4+7
#define A5 5+7
#define B5 6+7
#define C6 0+2*7
#define D6 1+2*7
#define E6 2+2*7
#define F6 3+2*7
#define G6 4+2*7
#define A6 5+2*7
#define B6 6+2*7

// doe ray mi fa so la ti 
// C   D   E  F  G  A  B
NTyp mysong[][255] = {
 
// score table for Happy Birthday version 1, higher pitch
//{//so   so   la   so   doe' ti
//   G4,2,G4,2,A4,4,G4,4,C5,4,B4,4,
//// pause so   so   la   so   ray' doe'
//   PAUSE,4,  G4,2,G4,2,A4,4,G4,4,D5,4,C5,4,
//// pause so   so   so'  mi'  doe' ti   la
//   PAUSE,4,  G4,2,G4,2,G5,4,E5,4,C5,4,B4,4,A4,8, 
//// pause fa'  fa'   mi'  doe' ray' doe' stop
//	 PAUSE,4,  F5,2,F5,2, E5,4,C5,4,D5,4,C5,8,0,0},

// score table for Happy Birthday version 2, lower pitch
{C4,2,C4,2,D4,4,C4,4,F4,4,E4,8,C4,2,C4,2,D4,4,C4,4,G4,4,F4,8,C4,2,C4,2,
 C5,4,A4,4,F4,4,E4,4,D4,8,B4,2,B4,2,A4,4,F4,4,G4,4,F4,12},
 
// score table for Mary Had A Little Lamb
{E4, 4, D4, 4, C4, 4, D4, 4, E4, 4, E4, 4, E4, 8, 
 D4, 4, D4, 4, D4, 8, E4, 4, G4, 4, G4, 8,
 E4, 4, D4, 4, C4, 4, D4, 4, E4, 4, E4, 4, E4, 8, 
 D4, 4, D4, 4, E4, 4, D4, 4, C4, 8, 0, 0 },

// score table for Twinkle Twinkle Little Stars
{C4,4,C4,4,G4,4,G4,4,A4,4,A4,4,G4,8,F4,4,F4,4,E4,4,E4,4,D4,4,D4,4,C4,8, 
 G4,4,G4,4,F4,4,F4,4,E4,4,E4,4,D4,8,G4,4,G4,4,F4,4,F4,4,E4,4,E4,4,D4,8, 
 C4,4,C4,4,G4,4,G4,4,A4,4,A4,4,G4,8,F4,4,F4,4,E4,4,E4,4,D4,4,D4,4,C4,8,0,0}};

	// Function Prototypes
void Speaker_Init(void);
void Delay(void);
extern void EnableInterrupts(void);
void play_a_song(NTyp scoretab[]);

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){
	uint8_t i;
	unsigned long In;
	
  Speaker_Init();
  SysTick_Init();
  EnableInterrupts();  // SysTick uses interrupts
	
	i=0;
  while(1){
		//for (i=0;i<3;i++)
		play_a_song(mysong[i]);
		if (GPIO_PORTF_RIS_R & 0x10) {
		GPIO_PORTF_ICR_R |= 0x10;      // acknowledge flag4: 00010000
			i++;
		}
  }

}

void play_a_song(NTyp scoretab[])
{
	uint8_t i=0, j;

	while (scoretab[i].delay) {
		if (scoretab[i].tone_index==PAUSE) // index = 255 indicate a pause: stop systick
			SysTick_stop(); // silence tone, turn off SysTick timer
		else {
			SysTick_Set_Current_Note(Tone_Tab[scoretab[i].tone_index]);
			SysTick_start();
		}
		
		// tempo control: 
		// play current note for duration 
		// specified in the music score table
		for (j=0;j<scoretab[i].delay;j++) 
			Delay();
		
		SysTick_stop();
		i++;  // move to the next note
	}
	
	// pause after each play
	for (j=0;j<15;j++) 
		Delay();
}

// Subroutine to wait 0.1 sec for 16MHz system clock
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){
	uint32_t volatile time;
  time = 727240*20/91;  // 0.1sec
  while(time){
		time--;
  }
}
// Make PA2 an output, enable digital I/O, ensure alt. functions off
void Speaker_Init(void){ 
	volatile uint32_t delay;
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

// COPIED FROM EDGEINTERRUPT.C
void switches(void){                          
  SYSCTL_RCGC2_R |= 0x00000020; // (a) activate clock for port F
	
	// added for second assignment
	GPIO_PORTF_LOCK_R = 0x4C4F434B;   	// unlock PortF PF0 
	GPIO_PORTF_CR_R |= 0x1F;         		// allow changes to PF4-0 :11111->0x1
	
	// changed 0x10 to 0x11 to account for both PF4(0x10) and PF0(0x01)
  GPIO_PORTF_DIR_R &= ~0x11;    // (c) make PF4 in (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x11;  //     disable alt funct on PF4
  GPIO_PORTF_DEN_R |= 0x11;     //     enable digital I/O on PF4   
  GPIO_PORTF_PCTL_R &= ~0x000F000F; // configure PF4 as GPIO
  GPIO_PORTF_AMSEL_R = 0;       //     disable analog functionality on PF
  GPIO_PORTF_PUR_R |= 0x11;     //     enable weak pull-up on PF4
  GPIO_PORTF_IS_R &= ~0x11;     // (d) PF4 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x11;    //     PF4 is not both edges
  GPIO_PORTF_IEV_R &= ~0x11;    //     PF4 falling edge event
  GPIO_PORTF_ICR_R |= 0x11;      // (e) clear flag4
  GPIO_PORTF_IM_R |= 0x11;      // (f) arm interrupt on PF4
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R |= 0x40000000;      // (h) enable interrupt 30 in NVIC           
}
/*
void GPIOPortF_Handler(void){
	if (GPIO_PORTF_RIS_R & 0x10) {
		GPIO_PORTF_ICR_R |= 0x10;      // acknowledge flag4: 00010000
		
	}
	
}
*/