/***********************************************************************

CODE8.3: Program for LED Dimmer using Timer0_PWM

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
#include"delay.h"

ISR (TIMER0_OVF_vect)				// Subroutine of Timer0 overflow interrupt
{

	PORTC=0xF0; 
}

ISR (TIMER0_COMP_vect)				// Subroutine of Timer0 compare match interrupt
{
	PORTC=0x00;
}


int main(void)         
{
	DDRC=0xF0;						// Port C data direction configuration as output port.
	DDRA=0x00;
	PORTA=0xF0;
   
	TIMSK=0x03;						// This is for interrupt enable for timer0.
	TCCR0=0x4A;						// This is for timer0 initialization.
	TCNT0=0x00;
	OCR0=150;
	sei();
	
 while(1)
  {
	if((PINA & 0x10)==0)
		{
		delayms(10);
		OCR0++;
		if(OCR0>=253){OCR0=253;}
		}
	if((PINA & 0x20)==0)
		{
		delayms(10);
		OCR0--;
		if(OCR0<=3){OCR0=3;}
		}	
  }
  
}
