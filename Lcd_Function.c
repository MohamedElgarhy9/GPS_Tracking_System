#include "Lcd_Function.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>
void Lcd_Command(uint8_t cmd){
    GPIO_PORTA_DATA_R=0;
    GPIO_PORTB_DATA_R=cmd;
    GPIO_PORTA_DATA_R |=0x80;
    Delay(500);
    GPIO_PORTA_DATA_R=0;


    }
void Lcd_DATA(uint8_t D){
    GPIO_PORTA_DATA_R=0x20;
    GPIO_PORTB_DATA_R=D;
    GPIO_PORTA_DATA_R |=0x80;
    Delay(500);
    GPIO_PORTA_DATA_R=0;
        }


void LCD_INIT(void){

		SYSCTL_RCGCGPIO_R |= 0x00000002;
		while(SYSCTL_PRGPIO_R && 0x00000002==0){};
		GPIO_PORTB_LOCK_R = 0x4C4F434B;
		GPIO_PORTB_CR_R|=0xFF;
		GPIO_PORTB_AMSEL_R &= ~0xFF;
		GPIO_PORTB_PCTL_R &= ~0xFF;
		GPIO_PORTB_AFSEL_R &= ~0xFF;
		GPIO_PORTB_DEN_R |= 0xFF;
		GPIO_PORTB_DIR_R |= 0xFF;
		SYSCTL_RCGCGPIO_R |= 0x00000001;
		while(SYSCTL_PRGPIO_R && 0x00000001==0){};
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R|=0xE0;
		GPIO_PORTA_AMSEL_R &= ~0xE0;
		GPIO_PORTA_PCTL_R &= ~0xE0;
		GPIO_PORTA_AFSEL_R &= ~0xE0;
		GPIO_PORTA_DEN_R |= 0xE0;
		GPIO_PORTA_DIR_R |= 0xE0;
			
	}


