/***********************************************************************

CODE8.1: Program for Delay using Timer0

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

#include<avr/io.h>					// Header for AVR Microcontroller.
#include<avr/interrupt.h>

ISR (TIMER0_OVF_vect)				// Subroutine of Timer0 overflow interrupt
{

	PORTC^=0xF0; 
}


int main(void)         
{
	
	DDRC=0xF0;						// Port C data direction configuration as output port.
   
	TIMSK=0x01;						//This is for interrupt enable for timer0.
	TCCR0=0x05;						//This is for timer0 initialization.
	TCNT0=0x00;
	sei();
	
 while(1)
  {
        
  }
  
}
