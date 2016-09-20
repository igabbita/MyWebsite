/***********************************************************************

CODE7.4: Program for Remote controlled robot

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
#include"delay.h"
#include"cc2500b.h"

int main(void)
{
 int i=5;
 delayms(500);
 rf_init();
 PORTA=0xF0;
 DDRA=0x00;							//initialidation for Switch
 PORTD=0x00;
 DDRD=0xF0;							//data direction for motor
 PORTC=0x00;
 DDRC=0xF0;							//data direction for LED
 delayms(1000);
 
 while(1)
 {
   
   rf_transmit_B(5,2,(PINA & 0xf0));
   delayms(100);
   PORTC=cc_data3;
   switch(cc_data3)
   {
    case 0xF0:
	 PORTD=0x00;			//stop
	 break;
	case 0xE0: 
	 PORTD=0x50;			//Forward
	 break;
	case 0xC0: 
	 PORTD=0x10;			//Left turn
	 break;
	case 0xA0: 
	 PORTD=0x40;			//right turn
	 break; 
	case 0x60: 
	 PORTD=0xA0;			//backward
	 break;
   }
   
  
}
  
  
 } 

/*******************************************************************************/