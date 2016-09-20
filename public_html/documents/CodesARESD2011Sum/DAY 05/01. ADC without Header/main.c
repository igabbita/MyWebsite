/***********************************************************************

CODE5.1: Program for ADC without using Header

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
#include"lcd.h"

int main(void)
{
 ADMUX=0x20;
 ADCSRA=0x87;
 lcd_init();
 while(1)
  {
   ADCSRA|=0x40;
   delayms(100);
   lcd_gotoxy(0,0);
   lcd_showvalue(ADCH);
  }
  
}