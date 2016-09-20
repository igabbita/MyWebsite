/***********************************************************************

CODE11: cathode type: Program for Display Incremented Binary value on matrix LED 

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

unsigned char d;
unsigned char dar[7];


void charactor()
  {
   PORTA=dar[0]|0x00;
   delayms(d);
   PORTA=dar[1]|0x01;
   delayms(d);
   PORTA=dar[2]|0x02;
   delayms(d);
   PORTA=dar[3]|0x03;
   delayms(d);
   PORTA=dar[4]|0x04;
   delayms(d);
   PORTA=dar[5]|0x05;
   delayms(d);
   PORTA=dar[6]|0x06;
   delayms(d);
  }
  
 
int main()
{
 DDRA=0xff;
 PORTA=0x00;
 d=1;
  dar[0]=0x00;
  dar[1]=0x10;
  dar[2]=0x20;
  dar[3]=0x30;
  dar[4]=0x40;
  dar[5]=0x50;
  dar[6]=0x60;
  
  
 
 while(1)
  {
   
   charactor();

  
 
  
  }
}