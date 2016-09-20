/***********************************************************************

CODE9.2: Program for Servo control using Timer1

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
#include<avr/interrupt.h>
#include"delay.h"


ISR (TIMER1_COMPA_vect) // Subroutine of Timer1 compare match A interrupt
 {
	PORTB=0xFF;
	
 }

ISR (TIMER1_COMPB_vect) // Subroutine of Timer1 compare match B interrupt
 {
 PORTB=0x00;
 }


int main(void)         
{
	
	DDRB=0xFF; 			// Port B data direction configuration as output port.
	
   
	TCCR1A=0x03;  		//fast PWM mode  prescaller 8
	TCCR1B=0x1A;
	
	TCNT1H=0x00;
	TCNT1L=0x00;
	
	OCR1AH=0x9c;
	OCR1AL=0x40;
	
	OCR1BH=0x07;
	OCR1BL=0xd0;
	TIMSK=0x18;			// Timer(s)/Counter(s) Interrupt(s) initialization
	sei();
	
 while(1)
  {
  OCR1BH=0x07;			// Value of OCR1B for 1 msec pulse
  OCR1BL=0xd0;
  delayms(2000);
  
  OCR1BH=0x0b;			// Value of OCR1B for 1.5 msec pulse
  OCR1BL=0xb8;
  delayms(2000);
  
  
  OCR1BH=0x0F;			// Value of OCR1B for 2 msec pulse
  OCR1BL=0xA0;
  delayms(2000);
  
	
  }
  
}
