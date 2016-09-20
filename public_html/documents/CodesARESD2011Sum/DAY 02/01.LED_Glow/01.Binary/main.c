/***********************************************************************

CODE2.1.1: Program to glow all LED connected in PORTC (Binary)

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

#include<avr/io.h>		//This is the header for AVR Microcontroller.

int main(void)
 {	
	PORTC=0b00000000;			//PortC initiallization as all bits low.
	DDRC=0b11110000;			//PortC data direction declaration as out put.
	
	while(1)					//This is for the the infinity loop.
	{	
		PORTC=0b11110000;		//Turning ON all LED's
	}
}
