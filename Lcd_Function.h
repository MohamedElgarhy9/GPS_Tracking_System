#ifndef LCD_CMD_DATA_H_INCLUDED
#define LCD_CMD_DATA_H_INCLUDED
#include "tm4c123gh6pm.h"
#include "delay.h"
#include "stdint.h"

void LCD_Command(char com);
void LCD_DATA(char data);
void Init(void);

#endif