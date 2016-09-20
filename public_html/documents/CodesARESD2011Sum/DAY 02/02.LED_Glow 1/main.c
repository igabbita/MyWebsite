/***********************************************************************

CODE2.2: Program to glow 1 LED connected in PORTC (Hexadecimal)

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
	PORTC=0X00;			//PortC initiallization as all bits low.
	DDRC=0XF0;			//PortC data direction declaration as out put.
	
	while(1)			//This is for the the infinity loop.
	{	
		PORTC=0X10;		//Turning ON 1st LED
	}
}
