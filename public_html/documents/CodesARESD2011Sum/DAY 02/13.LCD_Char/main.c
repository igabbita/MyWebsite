/***********************************************************************

CODE2.13: Program to display character on LCD 

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
	lcd_init();			//initialisation of LCD
	lcd_char('A');		//function to display a character on LCD
	while(1);
}