/***********************************************************************

CODE5.5: Program for Line Follower using IF Statement

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

#include<avr/io.h>

int main(void)
{
  DDRA=0X00;					// Initialization of PORTA as input
  PORTA=0XFF;
  
  DDRD=0XF0;					// Initailization of PORTD as output
  PORTD=0X00;
  
  while(1)
  {
	if((PINA&0X01)==0X01)		// Right Sensor(at PA0) is detecting Black Line
	 {
	 PORTD=0X40;				// Turn Right
	 }
	else if((PINA&0X02)==0X02)	// Left Sensor(at PA1) is detecting Black line
	 {
	 PORTD=0x10;				// Turn Left
	 }
	else
	 {
	 PORTD=0X50;				// Move Forward
	 }
  }
 }