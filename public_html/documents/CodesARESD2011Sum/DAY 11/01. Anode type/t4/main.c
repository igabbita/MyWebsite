/***********************************************************************

CODE11: Anode type: Program for display scrolling Alphabets on matrix LED 

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
  dar[0]=0x88;
  dar[1]=0x70;
  dar[2]=0x70;
  dar[3]=0x70;
  dar[4]=0x00;
  dar[5]=0x70;
  dar[6]=0x70;
 }
 
void B() 
 {
  dar[0]=0x08;
  dar[1]=0x70;
  dar[2]=0x70;
  dar[3]=0x08;
  dar[4]=0x70;
  dar[5]=0x70;
  dar[6]=0x08;
 }
 
void C()
 {
  dar[0]=0x88;
  dar[1]=0x70;
  dar[2]=0x78;
  dar[3]=0x78;
  dar[4]=0x78;
  dar[5]=0x70;
  dar[6]=0x88;
 }
 
void D()
 {
  dar[0]=0x18;
  dar[1]=0x68;
  dar[2]=0x70;
  dar[3]=0x70;
  dar[4]=0x70;
  dar[5]=0x68;
  dar[6]=0x18;
 } 
 
void E()
 {
  dar[0]=0x00;
  dar[1]=0x78;
  dar[2]=0x78;
  dar[3]=0x00;
  dar[4]=0x78;
  dar[5]=0x78;
  dar[6]=0x00;
 }  
 
void F()
 {
  dar[0]=0x00;
  dar[1]=0x78;
  dar[2]=0x78;
  dar[3]=0x08;
  dar[4]=0x78;
  dar[5]=0x78;
  dar[6]=0x78;
 }  

void G()
 {
  dar[0]=0x88;
  dar[1]=0x70;
  dar[2]=0x78;
  dar[3]=0x60;
  dar[4]=0x70;
  dar[5]=0x70;
  dar[6]=0x80;
 } 
 
void H() 
 {
  dar[0]=0x70;
  dar[1]=0x70;
  dar[2]=0x70;
  dar[3]=0x00;
  dar[4]=0x70;
  dar[5]=0x70;
  dar[6]=0x70;
 }
 
void I() 
 {
  dar[0]=0x88;
  dar[1]=0xD8;
  dar[2]=0xD8;
  dar[3]=0xD8;
  dar[4]=0xD8;
  dar[5]=0xD8;
  dar[6]=0x88;
 }
 
void J() 
 {
  dar[0]=0xC0;
  dar[1]=0xE8;
  dar[2]=0xE8;
  dar[3]=0xE8;
  dar[4]=0xE8;
  dar[5]=0x68;
  dar[6]=0x98;
 }
 
void K() 
 {
  dar[0]=0x70;
  dar[1]=0x68;
  dar[2]=0x58;
  dar[3]=0x38;
  dar[4]=0x58;
  dar[5]=0x68;
  dar[6]=0x70;
 }
 
void L() 
 {
  dar[0]=0x78;
  dar[1]=0x78;
  dar[2]=0x78;
  dar[3]=0x78;
  dar[4]=0x78;
  dar[5]=0x78;
  dar[6]=0x00;
 }
void M() 
 {
  dar[0]=0x70;
  dar[1]=0x20;
  dar[2]=0x50;
  dar[3]=0x50;
  dar[4]=0x70;
  dar[5]=0x70;
  dar[6]=0x70;
 }
 
void N() 
 {
  dar[0]=0x70;
  dar[1]=0x70;
  dar[2]=0x30;
  dar[3]=0x50;
  dar[4]=0x60;
  dar[5]=0x70;
  dar[6]=0x70;
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
F();
delayus(10);
shift();
G();
delayus(10);
shift();
H();
delayus(10);
shift();
I();
delayus(10);
shift();
J();
delayus(10);
shift();
K();
delayus(10);
shift();
L();
delayus(10);
shift();
M();
delayus(10);
shift();
N();
delayus(10);
shift();
while(1);
 
  }
}