#ifndef __UART_H__
#define	__UART_H__

#include "stdint.h"

void UART5_Init(void);

uint8_t UART5_Available(void);

uint8_t UART5_Read(void);

void UART5_Write(uint8_t data);
void UART0_Init(void);

uint8_t UART0_Available(void);

uint8_t UART0_Read(void);

void UART0_Write(uint8_t data);

#endif // __UART_H__