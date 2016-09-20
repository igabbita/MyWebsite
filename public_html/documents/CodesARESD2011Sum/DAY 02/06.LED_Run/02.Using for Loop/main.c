/***********************************************************************

CODE2.6.2: Program to Run LEDs connected in PORTC (using for loop)

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
	unsigned char x;	//Define character
  
	while(1)
	{
		for(x=0x10;x!=0x00;x<<=1)
		{
			PORTC=x;
			delayms(500);
		}
			x=0x10;    	//Return value for LED1
	}	
}