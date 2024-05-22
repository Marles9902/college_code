#include <stdint.h>
#include <stdbool.h>  

#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define ESC  0x1B
#define SP   0x20
#define DEL  0x7F
#define NULL 0

void UART0_Init(bool RxInt, bool TxInt);

void OutCRLF0(void);

uint8_t UART0_InChar(void);

void UART0_OutChar(uint8_t data);

void UART0_OutString(uint8_t *pt);

uint32_t UART0_InUDec(void);

void UART0_OutUDec(uint32_t n);

uint32_t UART0_InUHex(void);

void UART0_OutUHex(uint32_t number);

void UART0_InString(uint8_t *bufPt, uint16_t max);

uint8_t charToHex	(char color);