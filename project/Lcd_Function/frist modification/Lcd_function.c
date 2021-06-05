#include "tm4c123gh6pm.h"
#include <stdint.h>
void SystemInit(){}

void Delay(int x){
    int i;
    int j;
    for(;i<x;i++){
        for(;j<x;j++){}
        }
    }

void LCD_Command(char com){
    GPIO_PORTA_DATA_R=0;
    GPIO_PORTB_DATA_R=com;
    GPIO_PORTA_DATA_R |=0x80;
    Delay(500);
    GPIO_PORTA_DATA_R=0;


    }
void LCD_DATA(char data){
    GPIO_PORTA_DATA_R=0x20;
    GPIO_PORTB_DATA_R=data;
    GPIO_PORTA_DATA_R |=0x80;
    Delay(500);
    GPIO_PORTA_DATA_R=0;


    }


void Init(void){       
	SYSCTL_RCGCGPIO_R |= 0x03;
        while ((SYSCTL_PRGPIO_R&0x03) == 0){};
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        GPIO_PORTB_CR_R |= 0xFF;
        GPIO_PORTA_CR_R |= 0xE0;
        GPIO_PORTB_DIR_R|=0xFF;
        GPIO_PORTB_DEN_R|=0xFF;
        GPIO_PORTA_DIR_R|=0xE0;
        GPIO_PORTA_DEN_R|=0xE0;
        GPIO_PORTB_AFSEL_R=0;
        GPIO_PORTB_AMSEL_R=0;
        GPIO_PORTB_PCTL_R=0;
        LCD_Command(0x01);
        LCD_Command(0x02);
        LCD_Command(0x06);
        LCD_Command(0x0F);
        LCD_Command(0x30);
        LCD_Command(0x38);

    }




int main(){
	Init();
		while(1){
		LCD_DATA('A');

		}
}
