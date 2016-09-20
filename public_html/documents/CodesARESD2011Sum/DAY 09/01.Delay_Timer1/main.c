/***********************************************************************

CODE9.1: Program for Delay using Timer1

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

#include<avr/io.h>					// This is the header for AVR Microcontroller.
#include<avr/interrupt.h>


ISR (TIMER1_OVF_vect)				// Subroutine of Timer1 overflow interrupt
{

	PORTC^=0xF0; 
}

int main(void)         
{
	DDRC=0xF0;						// Port C data direction configuration as output port.
  
	TIMSK=0x04;						// This is for interrupt enable for timer1.
	TCCR1A=0x00;						// This is for timer0 initialization.
	TCCR1B=0X05;
	TCNT1H=0x00;
	TCNT1L=0X00;
	sei();
	
 while(1)
  {

  }
  
}
