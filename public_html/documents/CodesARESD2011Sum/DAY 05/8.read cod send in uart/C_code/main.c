/***********************************************************************
interfacing 4 wire resistive touch screen with avr
CODE5.8: Program to Send X and Y coordinates upon UART

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............31st May 2011
Author:.............Technophilia team R&D
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz


connection details

YM-PA0
XM-PA1
YP-PA2
XP-PA3


 4  3   2  1    //pin numbar
 X+,Y+, X-,Y-
 3  2   1  0

 1  ad  0  x		reading x axis 
 ad 0   x  1		reading y axis

 1  0  r  0		touch detect  DDRA=0x05;  PORTA=0x08;

***********************************************************************/

#include <avr/io.h>
#include <adc.h>
#include <lcd.h>
#include <delay.h>
#include <uart.h>

unsigned char xcod,ycod;

void xaxis()                      	//for reading X cordinate
 {
  DDRA=0x0A;						
  PORTA=0x08;
  delayus(100);
  xcod=getdata(2);
  delayus(100);
 }
 
void yaxis() 						//for reading Y coordinate
 {
  DDRA=0x05;
  PORTA=0x01;
  delayus(100);
  ycod=getdata(3);
  delayus(100);
 }
 
 
int main(void)
 {
 
  
 adc_init();					//initialization of ADC
 uartinit();
  while(1)
   {
   DDRA=0x05;					//setup for touch detect
   PORTA=0x08;
   delayus(100);
   while((PINA & 0x02)==0x02);//touch detect test
   
   xaxis();
   yaxis();
   printnum(xcod);
   printnum(ycod);
   //printchar(13);
   }
 }