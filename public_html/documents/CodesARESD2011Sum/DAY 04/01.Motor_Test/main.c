/***********************************************************************

CODE4.1: Program for MOTOR test

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
	
	while(1)			//This is for the the infinity loop.
	{	
		PORTD=0x50;		// Rotate clock wise
		delayms(1000);	// Delay of 1sec
		PORTD=0xA0;		// Rotate anticlockwise
		delayms(1000);  // Delay of 1sec
	}
}
