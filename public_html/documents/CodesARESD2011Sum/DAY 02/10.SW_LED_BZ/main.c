/***********************************************************************

CODE2.10: Program for Switches pressed and perform 

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
	DDRC=0XF8;			//PortC data direction declaration as output.
	
	PORTA=0XFF;			//PortA initiallization as all bits high (Pull-up Mode).
	DDRA=0X00;			//PortA data direction declaration as input.
	
	while(1)			//This is for the the infinity loop.
	{	
		if((PINA & 0x10)==0x00)			//checking for switch press at s1. 
		{			
			PORTC=0x10;						//LED1 ON
		}
		
		if((PINA & 0x20)==0x00)			//checking for switch press at s2. 
		{
			PORTC=0x20; 					//LED2 ON
		}
		
		if((PINA & 0x40)==0x00)			//checking for switch press at s3. 
		{
			PORTC=0x40; 					//LED3 ON
		}
		
		if((PINA & 0x80)==0x00)			//checking for switch press at s4. 
		{
			PORTC=0x08; 					//BZ ON
			while((PINA & 0x80)==0x00);	//continuosly checking for s4
			PORTC=0x00; 					//BZ OFF
		}
		
		//else
		//PORTC=0X00;
	}
}
