/***********************************************************************

CODE7.5: Program for Tx of PC controlled bot 

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
#include "uart.h"
#include "delay.h"
#include "cc2500b.h"
int main()
{
uart_init();
rf_init();
DDRD=0xF0;
while(1)
 {

	switch(uart_read())
	{
	case 'F':
	    rf_transmit_B(5,2,0x50);
	    break;
	case 'B':
	    rf_transmit_B(5,2,0xA0);
	    break;
	case 'R':
	    rf_transmit_B(5,2,0x40);
	    break;
	case 'L':
	    rf_transmit_B(5,2,0x10);
	    break;
	case 'S':
	    rf_transmit_B(5,2,0x00);
	    break;
	}
	 delayms(10);	
 }
}