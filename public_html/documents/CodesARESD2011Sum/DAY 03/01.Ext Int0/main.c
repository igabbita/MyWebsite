/***********************************************************************

CODE3.1: Program to understand external interrupt 0 (INT0)

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............1st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz

***********************************************************************/

#include<avr/io.h>
#include<avr/interrupt.h> 	//Header file for AVR microcontroller Interrupt
#include"lcd.h"

ISR (INT0_vect)
{
	lcd_string(" ok");
}

int main(void)
{
	MCUCR=0x01;				//any logic change
	GICR=0x40;				//interrupt 0 enabled
	lcd_init();
	lcd_string("Ext INT0");
	sei();					//Global Interrupt Enable
	
	while(1)
	{
   
	}
}