/***********************************************************************
interfacing 4 wire resistive touch screen with avr
CODE5.10: Program to calibrate a touch screen

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
#include "adc.h"
#include "lcd.h"
#include "delay.h"


unsigned char xcod,ycod,pxcod,pycod,dx,dy,fx,fy,bx,by,lx,ly,rx,ry,sx,sy;

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
 
void touchdetect()
 {
   DDRA=0x05;
   PORTA=0x08;
   delayus(100);
   while((PINA & 0x02)==0x02);//touch detect
 } 
 
void touchbreak()
 {
   DDRA=0x09;
   PORTA=0x08;
   delayus(100);
   while(getdata(2)!=0);
   delayus(100);
 } 
 
 void bz()
  {
   DDRC|=0x08;
   PORTC|=0x08;
   delayms(50);
   PORTC&=~0x08;
  }
  
  void calibration()
  {
   
   lcd_gotoxy(0,0);
   lcd_string("calibration");
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("forward    ");
   touchdetect();
   xaxis();yaxis();
   fx=xcod;fy=ycod;
   touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("forward  ok");
   bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("backword   ");
   touchdetect();
   xaxis();yaxis();
   bx=xcod;by=ycod;
     touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("backward ok");
    bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("left       ");
  touchdetect();
   xaxis();yaxis();
   lx=xcod;ly=ycod;
     touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("left     ok");
    bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("right      ");
   touchdetect();
   xaxis();yaxis();
   rx=xcod;ry=ycod;
     touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("right    ok");
    bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("stop       ");
   touchdetect();
   xaxis();yaxis();
   sx=xcod;sy=ycod;
    touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("stop     ok");
    bz();
   delayms(1000);
    
   lcd_gotoxy(0,0);
   lcd_string("cal      ok");
   
  }
  
int main(void)
 {
 
  
 adc_init();
 lcd_init();
 DDRB=0x0f;
 
 calibration();
 
  while(1)
   {
   
   touchdetect();
   xaxis();
   yaxis();
   
   if((xcod<(fx+10))&(xcod>(fx-10))&(ycod<(fy+10))&(ycod>(fy-10)))
   {
   touchbreak();
	bz();
    lcd_gotoxy(0,0);
	lcd_string("forward     ");
   }
	
  if((xcod<(bx+10))&(xcod>(bx-10))&(ycod<(by+10))&(ycod>(by-10)))
   {
   touchbreak();
	bz();
    lcd_gotoxy(0,0);
	lcd_string("backward    ");
   } 
   
   if((xcod<(lx+10))&(xcod>(lx-10))&(ycod<(ly+10))&(ycod>(ly-10)))
   {
   touchbreak();
	bz();
    lcd_gotoxy(0,0);
	lcd_string("left       ");
   } 
   
   if((xcod<(rx+10))&(xcod>(rx-10))&(ycod<(ry+10))&(ycod>(ry-10)))
   {
   touchbreak();
	bz();
    lcd_gotoxy(0,0);
	lcd_string("right     ");
   } 
   
   if((xcod<(sx+10))&(xcod>(sx-10))&(ycod<(sy+10))&(ycod>(sy-10)))
   {
   touchbreak();
	bz();
    lcd_gotoxy(0,0);
	lcd_string("stop      ");
   }
	
   }
 }