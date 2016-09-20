/***********************************************************************

CODE6.3: Program for Controlling Bot by PC

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

#include <avr/io.h >
#include "delay.h"
#include "uart.h"
int main()
{
UCSRA=0x00;
UCSRB=0x10;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x67;
DDRD=0xF0;		
while(1)
 {
 switch(uart_read())
  {
   case 'F':
    PORTD=0x50;
	break;
   case 'B':
    PORTD=0xA0;
	break;
   case 'L':
    PORTD=0x10;
	break;	
   case 'R':
    PORTD=0x40;
	break;
   case 'S':
    PORTD=0x00;
	break;	
  }
	
 }
}