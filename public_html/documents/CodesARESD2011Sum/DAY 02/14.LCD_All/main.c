/***********************************************************************

CODE2.14: Program to display name, character and variable on LCD

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............31st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz

***********************************************************************/

#include<avr/io.h>		//This is the header file for AVR microcontroller
#include"lcd.h"			//This is the working header file for lcd .

int main(void)
{	
	unsigned char x=32;
	lcd_init();
	lcd_string("Technophilia"); 
	lcd_gotoxy(1,0);
	lcd_char('N');
	lcd_gotoxy(1,7);
	lcd_showvalue(x);
	while(1);
}