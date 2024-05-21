// TrackExplorer.c
// Joshua Siajuat, Marwin Gonzales
// April 3, 2023
// Runs on TM4C123

// This is the starter file for CECS 347 Project 2 - A Track Explorer
// This project uses hardware PWM to control two DC Motors, 
// ADC to collect analog inputs from three Sharp IR sensors.
// The three Sharp analog IR distance sensors (GP2Y0A21YK0F) are used
// to allowthe robot to navigate through a track with two walls: 
// one mounted looking directly forward to avoid a head-on collision, 
// the other two looking forward to the left and to the right to detect  
// the distances between the car and the two walls. The goal is to 
// control power to each wheel so the left and right distances to the 
// walls are equal.
// If an object is detected too close to the robot, 
// the robot should be able to avoid it.
/*
    ------------------------------------------wall---------
                      /
                     /
                    / 
                   /
         -----------
         |         |
         | Robot   | ---> direction of motion and third sensor
         |         |
         -----------
                   \
                    \
                     \
                      \
    ------------------------------------------wall---------
*/
// The original project is designed by Dr. Daniel Valvano, Jonathan Valvano
// September 12, 2013
// Modifications are made by Dr. Min He.

// PE1 connected to forward facing IR distance sensor
// PE4 connected to right IR distance sensor
// PE5 connected to left IR distance sensor

#include "tm4c123gh6pm.h"
#include "Sensors.h"
#include "Motors.h"
#include "LEDSW.h"
#include "PLL.h"
#include "PWM.h"
#include "stdint.h"

// basic functions defined at end of startup.s
extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts
extern void WaitForInterrupt(void);  // low power mode
void Delay(void);

// You use datasheet to calculate the following ADC values
// then test your sensors to adjust the values 
#define CRASH             IR15CM// if there is less than this distance ahead of the robot, it will immediately stop
#define IR15CM            2233  // ADC output for 15cm:1.8v -> (1.8/3.3)*4095=2233 
#define IR20CM            1724  // ADC output for 20cm:1.39v -> (1.39/3.3)*4095=1724
#define IR30CM            1116  // ADC output for 30cm:0.9v -> (0.9/3.3)*4095=1116
#define IR40CM            918   // ADC output for 40cm:0.74v -> (0.74/3.3)*4095=918
#define IR80CM            496   // ADC output for 80cm:0.4v -> (0.4/3.3)*4095=496
                                // with equal power to both motors (LeftH == RightH), the robot still may not drive straight
                                // due to mechanical differences in the motors, so bias the left wheel faster or slower than
                                // the constant right wheel
#define LEFTPOWER        	0.5*PERIOD   // duty cycle of left wheel 
#define RIGHTPOWER        0.5*PERIOD    // duty cycle of left wheel 

void System_Init(void);
void steering(uint16_t ahead_dist,uint16_t right_dist, uint16_t left_dist);

int main(void){
	uint32_t volatile delay;
  uint16_t left, right, ahead;
  DisableInterrupts();  // disable interrupts while initializing
  System_Init();
  EnableInterrupts();   // enable after all initialization are done
	
  // TODO: Calibrate the sensors: read at least 5 times from the sensor 
	// before the car starts to move: this will allow software to filter the sensor outputs.	
	for (int i = 0; i < 4; i++){
			ReadSensorsMedianFilter(&ahead, &right, &left);
			for(delay=0; delay<100000; delay++){};
	}
	
	/*
	// TODO: start with moving forward, LED green 
	LED = Green;
	WHEEL_DIR = FORWARD;
	PWM0_ENABLE_R |= 0x00000003; // enable both wheels
	Delay();
	
	// stop
	LED = Dark;
	WHEEL_DIR = 0;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();
	
	// backward
	LED = Blue;
	WHEEL_DIR = BACKWARD;
	PWM0_ENABLE_R |= 0x00000003; // enable both wheels
	Delay();
	
	// stop
	LED = Dark;
	WHEEL_DIR = 0;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();
	
	// Forward right 
	LED = Yellow;
	WHEEL_DIR = FORWARD;
	PWM0_ENABLE_R |= 0x00000002; // Enable right wheel
	PWM0_ENABLE_R &= ~0x00000001; // Disable left wheel
	Delay();
	
	// stop
	LED = Dark;
	WHEEL_DIR = 0;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();
	
	// Forward left
	LED = Purple;
	WHEEL_DIR = FORWARD;
	PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
	PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	Delay();
	
	// stop
	LED = Dark;
	WHEEL_DIR = 0;
	PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	Delay();
	*/

  while(1){
		// choose one of the following three software filter methods
		ReadSensorsMedianFilter(&ahead, &right, &left);
//		ReadSensorsIIRFilter(&ahead, &right, &left);
//		ReadSensorsFIRFilter(&ahead, &right, &left);
		
		steering(ahead,right,left);
  }
}

void System_Init(void) {
  PLL_Init();           // bus clock at 16 MHz
  Sensors_Init();       // initialize ADC to sample AIN2 (PE1), AIN9 (PE4), AIN8 (PE5)
  LEDSW_Init();         // configure onboard LEDs and push buttons
  Motors_Init();        // Initialize signals for the two DC Motors
}

// buttons to activate/deactivate the car
void GPIOPortF_Handler(void){
}

void steering(uint16_t ahead_dist,uint16_t right_dist, uint16_t left_dist){
  // Suggest the following simple control as starting point:
  // 1. Take care of off center positions:
	//    If left off center track, turn right; 
	//    If right off center track, turn left
  // 2. Take care of turning track: 
	//    make a right turn if left opening detected;
	//    make a left turn if right opening detected;
  // 3. Optional: Take care of crash ahead: stop if crash ahead
	// 4.	go straight if moving in the center area
  // Feel free to add more controls to fine tune your robot car.
  // Make sure to take care of both wheel movements and LED display.  

	// 1. off center positions
	// left off center, turn right
	if(left_dist < right_dist){
		LED = Green;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
		PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	}
	
	// right off center, turn left
	else if(right_dist < left_dist){
		LED = Green;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R |= 0x00000002; // Enable right wheel
		PWM0_ENABLE_R &= ~0x00000001; // Disable left wheel
	}
	
	// too close to object on left
	else if(left_dist <= CRASH){
		LED = Red;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
		PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	}
	
	// centered, go straight
	else if(left_dist == right_dist){
		LED = Green;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R |= 0x00000003; // enable both wheels
	}
	
	// 2. turning track
	// left opening detected, turn right
	else if(left_dist > IR30CM && right_dist <= IR80CM){
		LED = Green;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
		PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	}
	
	// right opening detected, turn left
	else if(right_dist > IR30CM && left_dist <= IR80CM){
		LED = Green;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R |= ~0x00000002; // Enable right wheel
		PWM0_ENABLE_R &= 0x00000001; // Disable left wheel
	}
	
	// blocking left and ahead
	
	// crash ahead
	else if(ahead_dist <= CRASH || left_dist <= CRASH || right_dist <= CRASH){
		LED = Red;
		WHEEL_DIR = 0;
		PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	}
		
/*	
	// something blocks all sensors
	if(ahead_dist <= CRASH){
		LED = Red;
		WHEEL_DIR = 0;
		PWM0_ENABLE_R &= ~0x00000003; // stop both wheels
	}
	
	// if car is too close to object on its left, try to manuever right
	else if (left_dist < right_dist){
		LED = Green;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R &= ~0x00000002; // Disable right wheel
		PWM0_ENABLE_R |= 0x00000001; // Enable left wheel
	}
	
	// if object too close on right, manuever left
	else if (right_dist < left_dist){
		LED = Blue;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R |= 0x00000002; // Enable right wheel
		PWM0_ENABLE_R &= ~0x00000001; // Disable left wheel
	}
	
	// if no object detected, proceed
	else{
		LED = White;
		WHEEL_DIR = FORWARD;
		PWM0_ENABLE_R |= 0x00000003; // enable both wheels
	}
	*/
	
}

void Delay(void){
	unsigned long volatile time;
  time = 727240*500/91;  // 0.25sec
  while(time){
		time--;
  }
}
