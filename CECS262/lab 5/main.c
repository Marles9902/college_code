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
P1MDOUT = P1MDOUT_B0__PUSH_PULL | P1MDOUT_B1__PUSH_PULL
| P1MDOUT_B2__PUSH_PULL | P1MDOUT_B3__PUSH_PULL
| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__PUSH_PULL
| P1MDOUT_B6__PUSH_PULL | P1MDOUT_B7__PUSH_PULL;

//Enable Weak Pullups
XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;

//Disable Interrupts
IE = IE_EA__DISABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
| IE_ET2__ENABLED | IE_ES0__DISABLED;

}

// declare variables
unsigned char x,y,angle; 
unsigned int ValueTHTL;

void LCDCommandWrite(unsigned char Data){
	P1 = P1&~(0x01<<2);					// RS = 0
	P1 = P1&~(0x01<<1); 				// RW = 0
	P0 = Data; 									// D0~D7 = Data
	P1 = P1|(0x01<<0); 					// E = 1
	
	// delay	
	for(x=0;x<0x02;x++){
		for(y=0;y<0xFF;y++){
			};
		};
		
	P1 = P1&~(0x01<<0); 				// E = 0
}

void LCDDataWrite(unsigned char Data){
	P1 = P1|(0x01<<2); 					// RS = 1
	P1 = P1&~(0x01<<1); 				// RW = 0
	P0 = Data; 									// D0~D7 = Data
	P1 = P1|(0x01<<0); 					// E = 1
		
	// delay
	for(x=0;x<0x02;x++){
		for(y=0;y<0xFF;y++){
			};
		};
		
	P1 = P1&~(0x01<<0); 				// E = 0
}

void T0_ISR(void) interrupt 1{
	
	P1 = P1|(0x01<<5); 					// Servo set to P1.5
	
	TCON = TCON&~(0x01<<4); 		// TR0 = 0
	TL0 = 0x10;
	TH0 = 0xEC;
	TCON = TCON|(0x01<<4); 			// TR0 = 1
	TCON = TCON&~(0x01<<6); 		// TR0 = 0
	TL1 = (unsigned char)((ValueTHTL)& 0x00FF);
	TH1 = (unsigned char)((ValueTHTL>>8)& 0x00FF);
	TCON = TCON|(0x01<<6); 			// TR = 0

	while(!(TCON&(0x01<<7))); 
	
	TCON = TCON&~(0x01<<6); 
	TCON = TCON&~(0x01<<7); 
	
	P1 = P1&~(0x01<<5);
	
}

void main(void)
{
	InitDevice();

	TMOD = 0x11; 								// Timer 16 bit mode
	TCON = TCON&~(0x01<<4);			// TR0 = 0
	TL0 = 0x10; 
	TH0 = 0xEC; 
	TCON = TCON|(0x01<<4); 			// TR0 = 1
	
	// initialize LCD
	LCDCommandWrite(0x38); 
	LCDCommandWrite(0x06); 
	LCDCommandWrite(0x0C); 
	LCDCommandWrite(0x01); 

	// write initial angle
	LCDDataWrite('-'); 
	LCDDataWrite('4'); 
	LCDDataWrite('5'); 
	
	IE = 0x82; 								// enable interrupt 
	
	while(1){
			
		ValueTHTL = 65281 - (12*angle);
		
		// increment button set to P1.3
		if(!(P1&(0x01<<3))){
			angle = angle+1;
			while(!(P1&(0x01<<3)));
		}
		
		// decrement button set to P1.4
		if(!(P1&(0x01<<4))){
			angle = angle-1;
			while(!(P1&(0x01<<4)));
		}
		
		if((angle<0)|(angle>20)){
			angle=0;
		}
		
		// cases for each angle in 20 increments 
		if(angle == 20){
			LCDCommandWrite(0x01); 
			LCDDataWrite('4');
			LCDDataWrite('5');
		}
		if(angle == 19){
			LCDCommandWrite(0x01); 
			LCDDataWrite('4');
			LCDDataWrite('0');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 18){
			LCDCommandWrite(0x01); 
			LCDDataWrite('3');
			LCDDataWrite('6');
		}
		if(angle == 17){
			LCDCommandWrite(0x01); 
			LCDDataWrite('3');
			LCDDataWrite('1');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 16){
			LCDCommandWrite(0x01); 
			LCDDataWrite('2');
			LCDDataWrite('7');
		}
		if(angle == 15){
			LCDCommandWrite(0x01); 
			LCDDataWrite('2');
			LCDDataWrite('2');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 14){
			LCDCommandWrite(0x01); 
			LCDDataWrite('1');
			LCDDataWrite('8');
		}
		if(angle == 13){
			LCDCommandWrite(0x01); 
			LCDDataWrite('1');
			LCDDataWrite('3');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 12){
			LCDCommandWrite(0x01); 
			LCDDataWrite('9');
		}
		if(angle == 11){
			LCDCommandWrite(0x01); 
			LCDDataWrite('4');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 10){
			LCDCommandWrite(0x01); 
			LCDDataWrite('0');
		}
		if(angle == 9){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('4');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 8){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('9');
		}
		if(angle == 7){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('1');
			LCDDataWrite('3');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 6){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('1');
			LCDDataWrite('8');
		}
		if(angle == 5){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('2');
			LCDDataWrite('2');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 4){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('2');
			LCDDataWrite('7');
		}
		if(angle == 3){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('3');
			LCDDataWrite('1');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 2){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('3');
			LCDDataWrite('6');
		}
		if(angle == 1){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('4');
			LCDDataWrite('0');
			LCDDataWrite('.');
			LCDDataWrite('5');
		}
		if(angle == 0){
			LCDCommandWrite(0x01); 
			LCDDataWrite('-');
			LCDDataWrite('4');
			LCDDataWrite('5');
		}
	}
}