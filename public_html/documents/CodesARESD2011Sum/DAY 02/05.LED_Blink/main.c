/***********************************************************************

CODE2.5: Program to blink all LEDs connected in PORTC (With Header)

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
#include"delay.h"       //This is the working header file for delay.

int main(void)
{
	PORTC=0X00;			//PortC initiallization as all bits low.
	DDRC=0XF0;			//PortC data direction declaration as out put.
	
	while(1)			//This is for the the infinity loop.
	{	
		PORTC=0xF0;		//Turning ON all LED
		delayms(1000);	//Delay of 1sec
		PORTC=0x00;		//Turning OFF all LED
		delayms(1000);  //Delay of 1sec
	}
}
