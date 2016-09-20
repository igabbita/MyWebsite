/***********************************************************************

CODE3.7: Program to Display values for number of times switch pressed UART

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
#include"uart.h"		//This is the header file for UART Communication

int main(void)
{
	unsigned char x;
	uart_init();
	DDRA=0x00;
	PORTA=0x10;
	
	while(1)
	{
		if((PINA & 0x10)==0x00)
		{
			while((PINA & 0x10)==0x00);
			x++;
			uart_num(x);
			uart_char(13);
		}
	}
}