/***********************************************************************

CODE10.1: IR Transmitter: Program for IR transmitter

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............1st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz
IR TX PortB0		used for transmitter only
IR Rx PortB1  

*********************************************************************************/
#include<avr/io.h>
#include<avr/interrupt.h>
#include"delay.h"

void delay_us(unsigned int delaytime)	//funtion for generating time delay in micro seconds
{

	 for(delaycounter1=0;delaycounter1<=delaytime;delaycounter1++)
	 {
		 
		  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		  asm("nop");asm("nop");asm("nop");asm("nop");
	 }
}


ISR (TIMER0_OVF_vect) 				//interrupt subroutine for timer 0 overflow vector
 {
  TCNT0=46;							//initializing the timer registor for generating frequency of 38Khz
  PORTB^=0x01;						//Toggle the port pin for generating frequency
 }
 
 
 void tx(unsigned char data)			//function for transmitting a data byte
 {
 unsigned char i;
  TCCR0=0x01;						//start bit 
  delay_us(800);
  TCCR0=0x00;
  for(i=0;i<=7;i++)				//bit 0 to 7
   {
    
	if((data&0x01)==0x01)
	  {
	  TCCR0=0x01;
	  delay_us(1600);
	  }
	  
	else
	  {
	  TCCR0=0x00;
	  delay_us(2000);
	  }
	  
    
    data>>=1;	
   }
   TCCR0=0x00;
   PORTA=0xf0;
 }	
 

int main()
 {
 unsigned char tx1;
 TCNT0=46;      //timer counter register
 TCCR0=0X00;	//timer counter control register
 
 TIMSK=0X01;	//timer interrupt mask register
 
 DDRB=0x01;		//data direction register
 PORTB=0x00;	//port B  initialization
 DDRA=0x00;
 PORTA=0xf0;
 
 
 sei();			//set global interrupt enable
 
 while(1)
	{
	if((PINA&0x10)==0x00)			//if S1(switch 1 is pressed)
	 {
	  while((PINA&0x10)==0x00);
      tx(tx1);
	  PORTA=0xf0;
	  tx1++;
	 }

	 
	}
 } 