// PWMtest.c
// Runs on TM4C123
// Use PWM0/PB6 and PWM1/PB7 to generate pulse-width modulated outputs.
// Min He
// September 7, 2021

// This is an example program to show how to use hardware PWM on TM4C123.
#include <stdint.h>
#include "PWM.h"

#define PERIOD 10000
#define STEP 1000
#define MAX_DUTY 9000

void Delay(void);

int main(void){
	uint16_t dutyA, dutyB;
	uint8_t i;
	
  PWM1B_Init(PERIOD);         // initialize PWM1, PF2
  PWM1A_Init(PERIOD);         // initialize PWM1, PF1
	
	while(1){
		dutyA=STEP;
		dutyB=MAX_DUTY;
		for (i=0;i<8;i++){
			PWM1A_Duty(dutyA);
			PWM1B_Duty(dutyB);
			Delay();
			dutyA+=STEP;
			dutyB-=STEP;
		}
		for (i=0;i<8;i++){
			PWM1A_Duty(dutyA);
			PWM1B_Duty(dutyB);
			Delay();
			dutyA-=STEP;
			dutyB+=STEP;
		}
		dutyA=STEP;
		dutyB=STEP;
		for (i=0;i<8;i++){
			PWM1A_Duty(dutyA);
			PWM1B_Duty(dutyB);
			Delay();
			dutyA+=STEP;
			dutyB+=STEP;
		}
		for (i=0;i<8;i++){
			PWM1A_Duty(dutyA);
			PWM1B_Duty(dutyB);
			Delay();
			dutyA-=STEP;
			dutyB-=STEP;
		}
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
