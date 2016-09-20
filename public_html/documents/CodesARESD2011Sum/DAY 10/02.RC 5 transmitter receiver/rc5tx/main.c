/***********************************************************************

CODE10: Program for RC5 transmitter

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............1st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz
IR TX PortB0		used for transmitter
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
 
 
 void tx(unsigned char data)			//function for transmitting a data frame
 {
  unsigned char i;
  unsigned char rchad=0B11101001;	//bit 8,7 (2 runin bit=11), 6 (1 chekbit=1), 5,4,3,2,1 (5 system address010001)	

  for(i=0;i<=7;i++)			    //for transmission of 2 runin bits, 1 chekbit, 5 system address bits	
   {
    
	if((rchad&0x80)==0x80)
	  {TCCR0=0x00;delay_us(889);TCCR0=0x01;delay_us(720);}
	else
	  {TCCR0=0x01;delay_us(720);TCCR0=0x00;delay_us(889);}
	  
    
    rchad<<=1;	
   }
   
  for(i=0;i<=5;i++)				//for transmission of 6 command bits or data bits
   {
    
	if((data&0x20)==0x20)
	  {TCCR0=0x00;delay_us(889);TCCR0=0x01;delay_us(720);}
	else
	  {TCCR0=0x01;delay_us(720);TCCR0=0x00;delay_us(889);}
	  
    
    data<<=1;	
   }
   TCCR0=0x00;
   PORTB=0x00;
  
 }	
 

int main()
 {
 unsigned char tx1;
 TCNT0=46;      //timer counter register
 TCCR0=0X00;	//timer counter control register
 
 TIMSK=0X01;	//timer interrupt mask register
 
 DDRB=0x01;		//data direction register
 PORTB=0x00;	//port B  initialization
 PORTA=0xf0;
 DDRA=0x00;
 
 sei();			//set global interrupt enable
 
 while(1)
	{
	

	 if((PINA&0x10)==0x00)
	  {
	   tx(0x01);
	   delayms(113);
	  }
	  
	 if((PINA&0x20)==0x00)
	  {
	   tx(0x02);
	   delayms(113);
	  }

	if((PINA&0x40)==0x00)
	  {
	   tx(0x03);
	   delayms(113);
	  }
	  
	 if((PINA&0x80)==0x00)
	  {
	   tx(0x04);
	   delayms(113);
	  } 
	}
 } 