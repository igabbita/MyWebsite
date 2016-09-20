/***********************************************************************

CODE4.4: Program for Obstacle Avoider

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

#include<avr/io.h>

int main(void)
{
  DDRA=0X00;					// Initialization of PORTA as input
  PORTA=0XFF;
  
  DDRD=0XF0;					// Initailization of PORTD as output
  PORTD=0X00;
  
  while(1)
  {
	if((PINA&0X01)==0X00)		// Right Sensor(at PA0) is detecting Obstacle
	 {
	 PORTD=0X10;				// Turn Left
	 }
	else if((PINA&0X02)==0X00)	// Left Sensor(at PA1) is detecting Obstacle
	 {
	 PORTD=0x40;				// Turn Right
	 }
	else
	 {
	 PORTD=0X50;				// Move Forward
	 }
  }
 }