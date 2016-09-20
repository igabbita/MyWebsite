/***********************************************************************

CODE3.2: Program to understand external interrupt 2 (INT2)

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

#include<avr/io.h>
#include<avr/interrupt.h> 	//Header file for AVR microcontroller Interrupt
#include"lcd.h"

ISR (INT2_vect)
{
	lcd_string(" ok");
}

int main(void)
{
	MCUCR=0x00;				//falling edge
	GICR=0x20;				//interrupt 2 enabled
	lcd_init();
	lcd_string("Ext INT2");
	sei();					//Global Interrupt Enable
	
	while(1)
	{
   
	}
}