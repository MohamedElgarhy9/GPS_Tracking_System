#include "lcd_route.h"
#include "delay.h"
#include "Lcd_Function.h"

void lcd_routing(uint32_t Moved_dist)
{
			uint32_t hundreds = Moved_dist/100;
			uint32_t tens = Moved_dist - (hundreds*100);
			uint32_t tens1 = tens/10;
			uint32_t ones = tens - (tens1*10);


		Delay(10);
		Lcd_DATA(hundreds+48);
		Delay(10);
		Lcd_DATA(tens1+48);
		Delay(10);
		Lcd_DATA(ones+48);
}