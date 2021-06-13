#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "UART_header_file.h"


void UART5_Init(void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R5;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	
	UART5_CTL_R &= ~0x00000001;
	UART5_IBRD_R = 104;    
  UART5_FBRD_R = 11;
	UART5_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART5_CTL_R |= 0x00000001;
	GPIO_PORTE_AFSEL_R |= 0x30;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFF00FFFF) | (0x00110000);
	GPIO_PORTE_DEN_R |= 0x30;
}

uint8_t UART5_Available(void){
	return ((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART5_Read(void){
	while(UART5_Available() != 1);
	return (uint8_t)(UART5_DR_R&0xFF);
}

void UART5_Write(uint8_t data){
	while((UART5_FR_R&UART_FR_TXFF) != 0);
	UART5_DR_R = data;
}
void UART0_Init(void){
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	
	UART0_CTL_R &= ~UART_CTL_UARTEN;
	UART0_IBRD_R = 104;    
  UART0_FBRD_R = 11;
	UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
	UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTA_AFSEL_R |= 0x03;
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	GPIO_PORTA_DEN_R |= 0x03;
}

uint8_t UART0_Available(void){
	return ((UART0_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}

uint8_t UART0_Read(void){
	while(UART0_Available() != 1);
	return (uint8_t)(UART0_DR_R&0xFF);
}

void UART0_Write(uint8_t data){
	while((UART0_FR_R&UART_FR_TXFF) != 0);
	UART0_DR_R = data;
}
