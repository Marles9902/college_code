// Project 1 Part 1
// By: Joshua Siajuat and Marwin Gonzales
// This is startup program for CECS447 Project 1 part 1.
// Hardware connection: 
// Positive logic Speaker/Headset is connected to PA3.
// onboard two switches are used for music box control.
// Switch 1 toggle between music on/off, switch 2 toggle through the three songs.
// Original Author: Min He
// Date: September 13, 2023

// header files
#include "tm4c123gh6pm.h"
#include "music.h"
#include "SysTick.h"
#include "switch.h"
#include <stdint.h>

// declarations
void Delay(void);
extern void EnableInterrupts(void);
extern void WaitForInterrupt(void);
extern void DisableInterrupts(void);

// flags for statuses
unsigned long current_song = 0;
unsigned long music_state = 0;
uint8_t i,j;
extern unsigned int sw2_pressed;

// initial values for piano major notes: assume SysTick clock is 16MHz.
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

#define PAUSE 255				// assume there are less than 255 tones used in any song
#define MAX_NOTES 50  // assume maximum number of notes in any song is 100. You can change this value if you add a long song.
 
// doe ray mi fa so la ti 
// C   D   E  F  G  A  B
NTyp Score_Tab[][MAX_NOTES] = {  


// score table for Happy Birthday
{
	G5,	2,	G5,	2,	A5,	4,	G5,	4,	C6,	4,	B5,	4,	PAUSE,	4,	
	G5,	2,	G5,	2,	A5,	4,	G5,	4,	D6,	4,	C6,	4, 	PAUSE,	4, 	G5,	2,	
	G5,	2,	G6,	4,	E6,	4,	C6,	4,	B5,	4,	A5,	8, 	PAUSE,	4, 	F6,	2,	
	F6,	2, 	E6,	4,	C6,	4,	D6,	4,	C6,	8,	0,	0
},
	
// score table for Mary Had A Little Lamb
{
	E4, 4, D4, 4, C4, 4, D4, 4, E4, 4, E4, 4, E4, 8, 
	D4, 4, D4, 4, D4, 8, E4, 4, G4, 4, G4, 8,	E4, 4, 
	D4, 4, C4, 4, D4, 4, E4, 4, E4, 4, E4, 8, D4, 4, 
	D4, 4, E4, 4, D4, 4, C4, 8, 0, 0 
},

// score table for Twinkle Twinkle Little Star
{
	C4,	4,	C4,	4,	G4,	4,	G4,	4,	A4,	4,	A4,	4,	G4,	8,	
	F4,	4,	F4,	4,	E4,	4,	E4,	4,	D4,	4,	D4,	4,	C4,	8, 
	G4,	4,	G4,	4,	F4,	4,	F4,	4,	E4,	4,	E4,	4,	D4,	8,
	G4,	4,	G4,	4,	F4,	4,	F4,	4,	E4,	4,	E4,	4,	D4,	8, 
	C4,	4,	C4,	4,	G4,	4,	G4,	4,	A4,	4,	A4,	4,	G4,	8,
	F4,	4,	F4,	4,	E4,	4,	E4,	4,	D4,	4,	D4,	4,	C4,	8,
	0,	0
}
};

// play the current song once
void play_a_song(void)
{
	// start song from beginning
	i=0;
	
	// from example projects
	// reads the score tab data 
	while (Score_Tab[current_song][i].delay){
		
		// check music state or switch press before playing
		if (music_state == 0 || sw2_pressed) {
			SysTick_stop();  	// stop playing immediately 
			sw2_pressed = 0;		// set SW2 flag back to 0
			return;
		}
		
		// play the notes
		if(Score_Tab[current_song][i].tone_index==PAUSE)
			SysTick_stop();	// silence tone, turn off SysTick, speaker off
		else{
			SysTick_Set_Current_Note(Tone_Tab[Score_Tab[current_song][i].tone_index]);	// set speaker to play a note
			SysTick_start();	// start SysTick
		}
	
		// tempo control: 
		// play current note for duration 
		// specified in the music score table
		for (j=0;j<Score_Tab[current_song][i].delay;j++){
			Delay();
		}
		SysTick_stop();
		i++;	// move to next note in tab
	}
	Delay();
}

// Move to the next song
void next_song(void)
{
	// increment current song
	current_song++;
	// start song from beginning when going to new song
	i=0;
	// wrap around to first song after going through all 3 songs
	if (current_song >= NUM_SONGS){
		current_song = 0;
	}
}

// check to see if the music is on or not
uint8_t is_music_on(void)
{
	return music_state;
}

// turn off the music
void turn_off_music(void)
{
	SysTick_stop();		// turn off SysTick
	music_state = 0;	// set flag to 0 (off)
}

// turn on the music
void turn_on_music(void)
{
	i=0;							// start song at beginning
	current_song = 0;	// reset back to first song
	SysTick_start();	// turn on SysTick
	music_state = 1;	// set flag to 1 (on)
}

// Initialize music output pin:
// Make PA3 an output to the speaker, 
// enable digital I/O, ensure alt. functions off
void Music_Init(void){ 
	volatile uint32_t delay;
  SYSCTL_RCGC2_R |= 0x01;           // activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_PCTL_R &= ~0x0000F000; // regular GPIO
  GPIO_PORTA_AMSEL_R &= ~0x08;      // disable analog function on PA3
  GPIO_PORTA_DIR_R |= 0x08;         // set direction to output
  GPIO_PORTA_AFSEL_R &= ~0x08;      // regular port function
  GPIO_PORTA_DEN_R |= 0x08;         // enable digital port
  GPIO_PORTA_DR8R_R |= 0x08;        // optional: enable 8 mA drive on PA3 to increase the voice volume
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
