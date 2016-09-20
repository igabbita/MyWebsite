/***********************************************************************

CODE3.8: Program for UART Reception without header

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
#include"delay.h"
#include"lcd.h"

int main(void)
{
 	UCSRA=0x00;
	UCSRB=0x10;  	//rx enable
	UCSRC=0x06;		//charactoor size 8bit  86
	UBRRH=0x00;
	UBRRL=0x67;		//103
	lcd_init();
	delayms(100);
 
	while(1)
	{
		while((UCSRA&0x80)==0x00);
		lcd_char(UDR);
	}
}