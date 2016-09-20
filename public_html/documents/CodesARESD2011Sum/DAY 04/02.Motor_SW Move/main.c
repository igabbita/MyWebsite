/***********************************************************************

CODE4.2: Program for MOTOR test by switches

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

#include<avr/io.h>		//This is the header for AVR Microcontroller.
#include"delay.h"       //This is the working header file for delay.

void main()
{
	PORTD=0X00;			// PortD initiallization as all bits low.
	DDRD=0XF0;			// PortD data direction declaration as out put.
	
	PORTA=0XF0;			// PortA initiallization, upper nibble high
	DDRA=0X00;			// PortA data direction declaration as input.
	
	while(1)			//This is for the the infinity loop.
	{	
		if((PINA&0x10)==0x00)
		 {
 		  PORTD=0x50;		// Move forward
		 }
		if((PINA&0x20)==0x00)
		 {
 		  PORTD=0xA0;		// Move backward
		 }		 
		if((PINA&0x40)==0x00)
		 {
 		  PORTD=0x40;		// Turn right
		 }
		if((PINA&0x80)==0x00)
		 {
 		  PORTD=0x10;		// Turn left
		 }
	}
}
