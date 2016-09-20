/***********************************************************************

CODE11: cathode type: Program for display scrolling Alphabets on matrix LED 

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
#include<avr/interrupt.h>
#include"delay.h"

unsigned char d,imat;
unsigned char dar[7];

ISR (TIMER1_COMPA_vect) // void timer1_compA_isr(void)
{
  PORTA=dar[imat]|imat;
   delayms(1);
   if(imat>=6)
    imat=0;
   else	
	imat++;
}
 
void shift()
  {
  unsigned char i;
  for(i=0;i<5;i++)
   {
    dar[0]<<=1;
	dar[1]<<=1;
	dar[2]<<=1;
	dar[3]<<=1;
	dar[4]<<=1;
	dar[5]<<=1;
	dar[6]<<=1;
	delayus(1);
   }
  }
  
void A() 
 {
  dar[0]=0x70;
  dar[1]=0x88;
  dar[2]=0x88;
  dar[3]=0x88;
  dar[4]=0xf8;
  dar[5]=0x88;
  dar[6]=0x88;
 }
 
void B() 
 {
  dar[0]=0xf0;
  dar[1]=0x88;
  dar[2]=0x88;
  dar[3]=0xf0;
  dar[4]=0x88;
  dar[5]=0x88;
  dar[6]=0xf0;
 }
 
void C()
 {
  dar[0]=0x70;
  dar[1]=0x88;
  dar[2]=0x80;
  dar[3]=0x80;
  dar[4]=0x80;
  dar[5]=0x88;
  dar[6]=0x70;
 }
 
void D()
 {
  dar[0]=0xE0;
  dar[1]=0x90;
  dar[2]=0x88;
  dar[3]=0x88;
  dar[4]=0x88;
  dar[5]=0x90;
  dar[6]=0xE0;
 } 
 
void E()
 {
  dar[0]=0xF8;
  dar[1]=0x80;
  dar[2]=0x80;
  dar[3]=0xF8;
  dar[4]=0x80;
  dar[5]=0x80;
  dar[6]=0xF8;
 }  
 
 
int main()
{
imat=0;
TCCR1A=0x03;
TCCR1B=0x1A;
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x07;
OCR1AL=0xFF;
TIMSK=0x18;
sei();

 DDRA=0xff;
 PORTA=0x00;
 d=100;
  dar[0]=0xF8;
  dar[1]=0xF8;
  dar[2]=0xF8;
  dar[3]=0xF8;
  dar[4]=0xF8;
  dar[5]=0xF8;
  dar[6]=0xF8;
 while(1)
  {
A();
delayus(10);
shift();
B();
delayus(10);
shift();
C();
delayus(10);
shift();
D();
delayus(10);
shift();
E();
delayus(10);
shift();

  }
}