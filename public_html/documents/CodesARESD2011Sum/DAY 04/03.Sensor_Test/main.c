/***********************************************************************

CODE4.3: Program for Sensor test

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
	PORTC=0X00;			// PortC initiallization as all bits low.
	DDRC=0X08;			// PortC data direction declaration as out put.
	
	PORTA=0XFF;			// PortA initiallization as all bits high.
	DDRA=0X00;			// PortA data direction declaration as input.
	
	while(1)			//This is for the the infinity loop.
	{	
		if((PINA&0x01)==0x00)	// Sensor at PA0 is sensing Obstacle
		 {
 		  PORTC=0x08;			// Buzzer ON
		 }
		else
		 {
		  PORTC=0X00;			// Buzzer OFF
		 }
	}
}
