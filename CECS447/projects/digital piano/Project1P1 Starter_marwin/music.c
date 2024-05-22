// This is startup program for CECS447 Project 1 part 1.
// Hardware connection: 
// Positive logic Speaker/Headset is connected to PA3.
// onboard two switches are used for music box control.
// Switch 1 toggle between music on/off, switch 2 toggle through the three songs.
// Authors: Min He
// Date: August 28, 2022

#include "tm4c123gh6pm.h"
#include "music.h"
#include "SysTick.h"
#include "switch.h"
#include <stdint.h>

void Delay(void);

// initail values for piano major notes: assume SysTick clock is 16MHz.
const uint32_t Tone_Tab[] =
// initial values for three major notes for 16MHz system clock
// Note name: C, D, E, F, G, A, B
// Offset:0, 1, 2, 3, 4, 5, 6
{30534,27211,24242,22923,20408,18182,16194, // C4 major notes
 15289,13621,12135,11454,10204,9091,8099, // C5 major notes
 7645,6810,6067,5727,5102,4545,4050};// C6 major notes

// Index for notes used in music scores
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

#define PAUSE 255				// assume there are less than 255 tones used in any song
#define MAX_NOTES 50  // assume maximum number of notes in any song is 100. You can change this value if you add a long song.
 
// doe ray mi fa so la ti 
// C   D   E  F  G  A  B
NTyp Score_Tab[][MAX_NOTES] = {  
// score table for Happy Birthday
{//so   so   la   so   doe' ti
   G5,2,G5,2,A5,4,G5,4,C6,4,B5,4,
// pause so   so   la   so   ray' doe'
   PAUSE,4,  G5,2,G5,2,A5,4,G5,4,D6,4,C6,4,
// pause so   so   so'  mi'  doe' ti   la
   PAUSE,4,  G5,2,G5,2,G6,4,E6,4,C6,4,B5,4,A5,8, 
// pause fa'  fa'   mi'  doe' ray' doe' stop
	 PAUSE,4,  F6,2,F6,2, E6,4,C6,4,D6,4,C6,8,0,0},
	
// score table for Mary Had A Little Lamb
{E4, 4, D4, 4, C4, 4, D4, 4, E4, 4, E4, 4, E4, 8, 
 D4, 4, D4, 4, D4, 8, E4, 4, G4, 4, G4, 8,
 E4, 4, D4, 4, C4, 4, D4, 4, E4, 4, E4, 4, E4, 8, 
 D4, 4, D4, 4, E4, 4, D4, 4, C4, 8, 0, 0 },

// score table for Twinkle Twinkle Little Stars
 {C4,4,C4,4,G4,4,G4,4,A4,4,A4,4,G4,8,F4,4,F4,4,E4,4,E4,4,D4,4,D4,4,C4,8, 
 G4,4,G4,4,F4,4,F4,4,E4,4,E4,4,D4,8,G4,4,G4,4,F4,4,F4,4,E4,4,E4,4,D4,8, 
 C4,4,C4,4,G4,4,G4,4,A4,4,A4,4,G4,8,F4,4,F4,4,E4,4,E4,4,D4,4,D4,4,C4,8,0,0}
};

unsigned int currSong;

// play the current song once
void play_a_song(void)
{
	while(1){
		NTyp Score_Tab[currSong];
	}
}

// Move to the next song
void next_song(void)
{
	unsigned char in = GPIOPortF_Handler()&0x01;
	if(in){
		
	}
	
	
}

// check to see if the music is on or not
uint8_t is_music_on(void)
{
	if(NVIC_ST_CTRL_R){
		return 1;
	}
	return 0;
}

// turn off the music
void turn_off_music(void)
{
	NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
}

// turn on the music
void turn_on_music(void)
{
	NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE;
	NTyp Score_Tab[0];
	
}

// Initialize music output pin:
// Make PA3 an output to the speaker, 
// enable digital I/O, ensure alt. functions off
void Music_Init(void){
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

// Subroutine to wait 0.1 sec
// Inputs: None
// Outputs: None
// Notes: ...
void Delay(void){
	uint32_t volatile time;
  time = 727240*20/91;  // 0.1sec for 16MHz
//  time = 727240*100/91;  // 0.1sec for 80MHz
  while(time){
		time--;
  }
}
