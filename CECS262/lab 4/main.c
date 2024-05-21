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

// declare variables
unsigned char x,y; 

void LCDCommandWrite(unsigned char Data){
	P1 = P1&~(0x01<<2);			// RS = 0
	P1 = P1&~(0x01<<1);			// RW = 0
	P0 = Data;							// D0~D7 = Data
	P1 = P1|(0x01<<0);			// E = 1
	
	// delay
	for(x=0;x<0x02;x++){
		for(y=0;y<0xFF;y++){	
		};
	};
	
	P1 = P1&~(0x01<<0);			// E = 0
}

void LCDDataWrite(unsigned char Data){
	P1 = P1|(0x01<<2);			// RS = 1
	P1 = P1&~(0x01<<1);			// RW = 0
	P0 = Data;							// D0~D7 = Data
	P1 = P1|(0x01<<0);			// E = 1
	
	// delay
	for(x=0;x<0x02;x++){
		for(y=0;y<0xFF;y++){
		};
	};
	
	P1 = P1&~(0x01<<0);			// E = 0
}

main(void){
	InitDevice();
	
	// initialize LCD
	LCDCommandWrite(0x38);	// 8bit interface, 2 lines, 5x7 font
	LCDCommandWrite(0x06);	// auto incrememnt, no display shift
	LCDCommandWrite(0x0E);	// diplay on, cursor on, no blinking
	LCDCommandWrite(0x01);	// clear display, set cursor to 0
	
	// write name
	LCDDataWrite('M');
	LCDDataWrite('a');
	LCDDataWrite('r');
	LCDDataWrite('w');
	LCDDataWrite('i');
	LCDDataWrite('n');
	
	while(1);
}
