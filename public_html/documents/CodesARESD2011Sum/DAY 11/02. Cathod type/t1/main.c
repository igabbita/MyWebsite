/***********************************************************************

CODE11: cathode type: Program for Display T on matrix LED

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
int main()
{
 unsigned char d;
 DDRA=0xFF;
 PORTA=0x00;
 
 d=1;
 while(1)
  {
   PORTA=0xF8|0x00;
   delayms(d);
   PORTA=0xF8|0x01;
   delayms(d);
   PORTA=0x20|0x02;
   delayms(d);
   PORTA=0x20|0x03;
   delayms(d);
   PORTA=0x20|0x04;
   delayms(d);
   PORTA=0x20|0x05;
   delayms(d);
   PORTA=0x20|0x06;
   delayms(d);
   
   
  }
}