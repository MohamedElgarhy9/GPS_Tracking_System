#include "tm4c123gh6pm.h"
#include "math.h"
#include "stdint.h"
#include "string.h"
#include "stdio.h"
#define CPAC (*((volatile uint32_t *)0xE000ED88))
#include "UART_header_file.h" 
#include "Led.h"
#include "Distance_Gps.h"
#include "delay.h"
#include "Lcd_Function.h"
#include "Lcd_route.h"
#include "constants_phase1.h"
#define  PI  3.141592654
void SystemInit()
{
	CPAC |= 0X00F00000;
}

float coords_obtained[200][2];
uint16_t indx1=0;


//parse the coordinates.
void read_coords()
{
	char all_data[90],parsed_values[12][50];//we have 12 values for our data 
	char *ptr ;
	const char delimiter[2]=",";
	uint32_t deg = 0;
	float lat = 0.0, longt = 0.0, mint = 0.0, parsed_lat = 0.0, parsed_longt = 0.0;
	char a,b,c,d,e,f,g,h;
	
	uint8_t indx=0;
	//while((UART7_FR_R & 0x10)!=0);
	a = UART5_Read();//(UART7_DR_R&0xFF);
	//We will use $GPRMC – Essential GPS pvt (position, velocity, time) data
	//here we are going to check for $GPRMC, and extract the values after then.
	if(a == '$')
	{
		//while((UART7_FR_R & 0x10)!=0);
		b = UART5_Read();//(UART7_DR_R&0xFF);
 		if (b == 'G')
		{
			//while((UART7_FR_R & 0x10)!=0);
			c = UART5_Read();//(UART7_DR_R&0xFF);
			if (c == 'P')
			{
				//while((UART7_FR_R & 0x10)!=0);
				d = UART5_Read();//(UART7_DR_R&0xFF);
				if (d == 'R')
				{
					//while((UART7_FR_R & 0x10)!=0);
					e = UART5_Read();//(UART7_DR_R&0xFF);
					if (e == 'M')
					{
						//while((UART7_FR_R & 0x10)!=0);
						f = UART5_Read();//(UART7_DR_R&0xFF);
						if (f == 'C')
						{
							//while((UART7_FR_R & 0x10)!=0);
							g = UART5_Read();//(UART7_DR_R&0xFF);
							if (g == ',')
							{
								//while((UART7_FR_R & 0x10)!=0);
								h = UART5_Read();//(UART7_DR_R&0xFF);
								
								while(h != '*')//getting all useful values from gps until we reah the *
								{
									all_data[indx] = h; 
									if(h == 'V')
										break;
									//while((UART7_FR_R & 0x10)!=0);
									h = UART5_Read();//(UART7_DR_R&0xFF);
									indx++;
								}
								//excluding all the commas from our array all_data
								indx = 0;
								ptr = strtok(all_data,delimiter);
								while(ptr != NULL)
								{
									strcpy(parsed_values[indx],ptr);
									ptr = strtok(NULL,delimiter);
									indx++;
								}
								//if the parsed_value[1] == A the data was read succefully if it was V then something went wrong
								if(strcmp(parsed_values[1] , "A")==0)
								{
									lat = atof(parsed_values[2]);//DDMM.MMMM
									longt = atof(parsed_values[4]);
									
									//transform the lattiude to the form used in distance function
									deg = lat/100;
									mint = lat - (float) (deg*100);
									mint = mint/60;
									parsed_lat = deg+ mint;
									
									//transform the longitude to the form used in distance function
									deg = longt/100;
									mint = longt - (float) (deg*100);
									mint = mint/60;
									parsed_longt = deg+ mint;
									//save the whole coordinates obtained in the 2d coords_obtained[] array
									coords_obtained[indx1][0] = parsed_lat;
									coords_obtained[indx1][1] = parsed_longt;
									indx1++;
								}
								
							}
						}
					}
				}
			}
		}
	}
}

int main(){
		long double Moved_dist;
		char out;
	  uint32_t word_count ;
	  int i=0,j=0;
		LEDSinit();
		UART5_Init();//for GPS 
		
		LCD_INIT();
		Lcd_Command(Function_set_8bit); /* Select 8-bit Mode of LCD */
		Delay(10);
		Lcd_Command(DisplayOn);  /* Enable Display and cursor blinking */
		Lcd_Command(0x01); /* clear whatever is written on display */
		while(1)
		{
			//read_coords();
			out = UART5_Read();
			Lcd_DATA(out);
	
		}

		for( j=0;j<200;j+=2){
			Moved_dist = dist(coords_obtained[j][1],coords_obtained[j+1][1],coords_obtained[j][0],coords_obtained[j+1][0]);
		}
			if(Moved_dist >= 100){
			lcd_routing(Moved_dist);
			DETECT_DISTANCE();
	}
	}