#include <reg51.h>

//main provides the entry point to our code
void main(void){
	
	//variable declarations at beginning of functions
	unsigned char x;
	
	//Superloop Architecture/Structure of Embedded Programming
	while (1){
		
		P1=0xF5; //output to Port 1 the value of 0xF5
		
		//Busy Wait Delay 
		for(x=0;x<0xFE;x=x+1){
		};
		
		P1=0x0A; //output to Port 1 the value of 0x0A
		
		//Busy Wait Delay 
		for(x=0;x<0xFE;x=x+1){
		};
		
	}
	
}
