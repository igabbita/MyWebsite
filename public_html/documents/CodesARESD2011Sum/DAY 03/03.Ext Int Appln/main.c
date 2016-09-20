/***********************************************************************

CODE3.3: Program for when external interrupt 2 (INT2) than play Buzzer

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
#include"delay.h"

ISR (INT2_vect)
{
	PORTC=0x08;
	delayms(500);
	PORTC=0x00;
	delayms(500);
	lcd_gotoxy(1,0);
	lcd_string("Buzzing Sound");
}

int main(void)
{
	PORTC=0x00;
	DDRC=0x08;
	
	MCUCR=0x00;				//falling edge
	GICR=0x20;				//interrupt 2 enabled
	lcd_init();
	lcd_string("Ext INT2");
	sei();					//Global Interrupt Enable
	
	while(1)
	{
   
	}
}