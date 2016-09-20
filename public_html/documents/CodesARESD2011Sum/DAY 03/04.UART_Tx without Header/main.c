/***********************************************************************

CODE3.4: Program for UART Transmission without header

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

int main(void)
{
 	UCSRA=0x00;
	UCSRB=0x08;  	//tx enable
	UCSRC=0x06;		//charactoor size 8bit 86
	UBRRH=0x00;
	UBRRL=0x67;		//103
	delayms(100);

	while(1)
	{
		UDR='k';
		while((UCSRA&0x40)==0x00);
		delayms(1000);
	}
}