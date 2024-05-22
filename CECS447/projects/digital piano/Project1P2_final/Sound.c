// Project 1 Part 2
// By: Joshua Siajuat and Marwin Gonzales
// This is the starter file for CECS 447 Project 1 Part 2
// Originally by Dr. Min He
// September 15, 2023
// Port B bits 5-0 outputs to the 6-bit DAC
// Port D bits 3-0 inputs from piano keys: CDEF:doe ray mi fa,negative logic connections.
// Port F is onboard LaunchPad switches and LED
// SysTick ISR: PF3 is used to implement heartbeat

// header files
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "ButtonLed.h"
#include <stdint.h>

// define bit addresses for Port B bits 0,1,2,3,4,5 => DAC inputs 
#define DAC (*((volatile unsigned long *) 0x4000503F ))   
unsigned char i=0, j=0;
unsigned char index;
// 6-bit: value range 0 to 2^6-1=63, 64 samples
// x = 32 + 31sin(t)
const uint8_t SineWave[64] = {32,35,38,41,44,47,49,52,54,56,58,59,61,62,62,63,63,63,62,62,
															61,59,58,56,54,52,49,47,44,41,38,35,32,29,26,23,20,17,15,12,
															10, 8, 6, 5, 3, 2, 2, 1, 1, 1, 2, 2, 3, 5, 6, 8,10,12,15,17,
															20,23,26,29};

// initial values for piano major tones.
// Assume SysTick clock frequency is 16MHz.
const uint32_t tonetab[] =
// C, D, E, F, G, A, B
// 1, 2, 3, 4, 5, 6, 7
// lower C octave:130.813, 146.832,164.814,174.614,195.998, 220,246.942
// calculate reload value for the whole period:Reload value = Fclk/Ft = 16MHz/Ft
{122137,108844,96970,91429,81633,72727,64777,
 30534*2,27211*2,24242*2,22923*2,20408*2,18182*2,16194*2, // C4 Major notes
 15289*2,13621*2,12135*2,11454*2,10204*2,9091*2,8099*2,   // C5 Major notes
 7645*2,6810*2,6067*2,5727*2,5102*2,4545*2,4050*2};        // C6 Major notes

// Constants
// index definition for tones in the songs.

#define C3 0
#define D3 1
#define E3 2
#define F3 3
#define G3 4
#define A3 5
#define B3 6
#define C4 0 + 7
#define D4 1 + 7
#define E4 2 + 7
#define F4 3 + 7
#define G4 4 + 7
#define A4 5 + 7
#define B4 6  + 7
 
#define MAX_NOTES 255 // maximum number of notes for a song to be played in the program
#define NUM_SONGS 3   // number of songs in the play list.
#define SILENCE MAX_NOTES // use the last valid index to indicate a silence note. The song can only have up to 254 notes. 
#define NUM_OCT  3   // number of octave defined in tontab[]
#define NUM_NOTES_PER_OCT 7  // number of notes defined for each octave in tonetab
#define NVIC_EN0_PORTF 0x40000000  // enable PORTF edge interrupt
#define NVIC_EN0_PORTD 0x00000008  // enable PORTD edge interrupt
#define NUM_SAMPLES 64  // number of sample in one sin wave period

// doe ray mi fa so la ti 
// C   D   E  F  G  A  B
NTyp playlist[][MAX_NOTES] = 
{{
	// Happy Birthday
	SILENCE, 4, G3, 2, G3, 2, A3, 4, G3, 4, C4, 4, B3, 4,
	SILENCE, 4, G3, 2, G3, 2, A3, 4, G3, 4, D4, 4, C4, 4,
	SILENCE, 4, G3, 2, G3, 2, G4, 4, E4, 4, C4, 4, B3, 4, A3, 8, 
	SILENCE, 4, F4, 2, F4, 2, E4, 4, C4, 4, D4, 4, C4, 8, 
	SILENCE, 0
},

{
	// Mary Had A Little Lamb
	SILENCE, 4, 
	E3, 4, D3, 4, C3, 4, D3, 4, E3, 4, E3, 4, 
	E3, 8, D3, 4, D3, 4, D3, 8, E3, 4, G3, 4, 
	G3, 8, E3, 4, D3, 4, C3, 4, D3, 4, E3, 4, 
	E3, 4, E3, 8, D3, 4, D3, 4, E3, 4, D3, 4, 
	C3, 8, 
	SILENCE, 0
},

{
	// Twinkle Twinkle Little Star
	SILENCE, 4, 
	C3, 4, C3, 4, G3, 4, G3, 4, A3, 4, A3, 4, G3, 8, F3, 4, 
	F3, 4, E3, 4, E3, 4, D3, 4, D3, 4, C3, 8,	G3, 4, G3, 4, 
	F3, 4, F3, 4, E3, 4, E3, 4, D3, 8, G3, 4, G3, 4, F3, 4, 
	F3, 4, E3, 4, E3, 4, D3, 8, C3, 4, C3, 4, G3, 4, G3, 4, 
	A3, 4, A3, 4, G3, 8, F3, 4, F3, 4, E3, 4, E3, 4, D3, 4, 
	D3, 4, C3, 8, 
	SILENCE, 0
}};

// File scope global
volatile uint8_t curr_song=0;      // 0: Happy Birthday, 1: Mary Had A Little Lamb. 2: Twinkle Twinkle Little Stars
volatile uint8_t stop_play=1;      // 0: continue playing a song, 1: stop playing a song
volatile uint8_t octave=0;         // 0: lower C, 1: middle C, 2: upper C

																		// **************DAC_Init*********************
// Initialize 6-bit DAC 
// Input: none
// Output: none
void DAC_Init(void){ volatile unsigned long delay;
	SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
	delay = SYSCTL_RCGC2_R; // give time to activate
	GPIO_PORTB_AMSEL_R &= ~0x3F; // no analog
	GPIO_PORTB_PCTL_R &= ~0x00FFFFFF; // regular function
	GPIO_PORTB_DIR_R |= 0x3F; 	// make PB5-0 an output
	GPIO_PORTB_AFSEL_R &= ~0x3F;
	GPIO_PORTB_DEN_R |= 0x3F; // enable digital I/O on PB5-0
}

// **************Sound_Start*********************
// Set reload value and enable systick timer
// Input: time duration to be generated in number of machine cycles
// Output: none
void Sound_Start(uint32_t period){
	index = 0;
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = period-1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF) | 0x20000000; // priority 1
	NVIC_ST_CTRL_R = 0x07; 
}

// stop SysTick and sound
void Sound_stop(void)
{
	NVIC_ST_CTRL_R = 0;
}

// go to next song upon SW2 press 
void Next_Song(void){
	Sound_stop();
	i = 0;
	curr_song++;
	curr_song=curr_song%NUM_SONGS;
}

// Interrupt service routine
// Executed based on number of sampels in each period
void SysTick_Handler(void){
	index = (index+1)%64;
	GPIO_PORTB_DATA_R = SineWave[index];
}

void GPIOPortF_Handler(void){
	// simple debouncing code: generate 20ms to 30ms delay
	for (uint32_t time=0;time<72724;time++);
	// SW1
	if (GPIO_PORTF_RIS_R& 0x10){
		GPIO_PORTF_ICR_R = 0x10;		// SW1 press
		set_current_mode(1);				// toggle between modes
	}
	// SW2
	if (GPIO_PORTF_RIS_R&0x01){			// SW2 press
		GPIO_PORTF_ICR_R = 0x01;
		if (get_current_mode() == 1){	// go to next song if SW2 pressed in auto-play mode
			Next_Song();							
		} else if (get_current_mode() == 0){	// go to the next octave if SW1 pressed in piano mode
			octave++;
			octave = octave%NUM_OCT;		// wrap around octave back to first octave
		}
	}
}

// Dependency: Requires PianoKeys_Init to be called first, assume at any time only one key is pressed
// Inputs: None
// Outputs: None
// Description: Rising/Falling edge interrupt on PD6-PD0. Whenever any 
// button is pressed, or released the interrupt will trigger.
void GPIOPortD_Handler(void){  
  // simple debouncing code: generate 20ms to 30ms delay
	for (uint32_t time=0;time<72724;time++);
	PianoKeys_Init();
	if(get_current_mode() == 0){
		if (Switch_In() == 0x01){	
			Sound_Start(tonetab[C4+(NUM_NOTES_PER_OCT*octave)]/NUM_SAMPLES);
		} else if (Switch_In() == 0x02){
			Sound_Start(tonetab[D4+(NUM_NOTES_PER_OCT*octave)]/NUM_SAMPLES);
		} else if (Switch_In() == 0x04){
			Sound_Start(tonetab[E4+(NUM_NOTES_PER_OCT*octave)]/NUM_SAMPLES);
		} else if (Switch_In() == 0x08){
			Sound_Start(tonetab[F4+(NUM_NOTES_PER_OCT*octave)]/NUM_SAMPLES);
		} else {
			Sound_stop();
		}
	}
		GPIO_PORTD_ICR_R |= 0x0F;
}

// Subroutine to wait 0.1 sec
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

void play_a_song()
{
	i=0;
	while (playlist[curr_song][i].delay && get_current_mode() == 1){
		if (playlist[curr_song][i].tone_index == SILENCE) {
			Sound_stop();
		} else {
			Sound_Start(tonetab[playlist[curr_song][i].tone_index+(NUM_NOTES_PER_OCT*octave)]/NUM_SAMPLES);
		}
		for (j=0;j<playlist[curr_song][i].delay;j++){
			Delay();
		}
		Sound_stop();
		i++; // move to next note
	}
	// delay for next note
	for (j=0;j<15;j++){
		Delay();
	}
}


