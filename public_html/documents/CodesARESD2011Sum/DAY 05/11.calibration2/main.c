/***********************************************************************
interfacing 4 wire resistive touch screen with avr
CODE5.11: Program to calibrate a touch screen interfacing with a 16x2 charactor LCD

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
   delayms(200);
  }
  
  void calibration()
  {
   
   lcd_gotoxy(0,0);
   lcd_string("calibration");
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("1            ");
   touchdetect();
   xaxis();yaxis();
   fx=xcod;fy=ycod;
   touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("1          ok");
   bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("   2         ");
   touchdetect();
   xaxis();yaxis();
   bx=xcod;by=ycod;
	touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("   2       ok");
    bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("      3      ");
   touchdetect();
   xaxis();yaxis();
   lx=xcod;ly=ycod;
   touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("      3    ok");
    bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("         4   ");
   touchdetect();
   xaxis();yaxis();
   rx=xcod;ry=ycod;
   touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("         4 ok");
    bz();
   delayms(1000);
   
   lcd_gotoxy(0,0);
   lcd_string("            5");
   touchdetect();
   xaxis();yaxis();
   sx=xcod;sy=ycod;
   touchbreak();
   lcd_gotoxy(0,0);
   lcd_string("ok          5");
    bz();
   delayms(500);
   
   
   lcd_gotoxy(0,0);
   lcd_string("calibration ok");
   delayms(500);
   lcd_gotoxy(0,0);
   lcd_string("1  2  3  4  5 ");
    
	 
	
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
   
   if((xcod<(fx+10))&(xcod>(fx-10))&(ycod<(fy+5))&(ycod>(fy-5)))
   {
     touchbreak();
	lcd_gotoxy(0,0);
	lcd_string("*  2  3  4  5 ");
	bz();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  4  5 ");
	lcd_gotoxy(1,10);
	lcd_string("1");
   }
	
  if((xcod<(bx+10))&(xcod>(bx-10))&(ycod<(by+5))&(ycod>(by-5)))
   {
    touchbreak();
    lcd_gotoxy(0,0);
	lcd_string("1  *  3  4  5 ");
	bz();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  4  5 ");
	lcd_gotoxy(1,10);
	lcd_string("2");
   } 
   
   if((xcod<(lx+10))&(xcod>(lx-10))&(ycod<(ly+5))&(ycod>(ly-5)))
   {
    touchbreak();
    lcd_gotoxy(0,0);
	lcd_string("1  2  *  4  5 ");
	bz();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  4  5 ");
	lcd_gotoxy(1,10);
	lcd_string("3");
   } 
   
   if((xcod<(rx+10))&(xcod>(rx-10))&(ycod<(ry+5))&(ycod>(ry-5)))
   {
   
    touchbreak();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  *  5 ");
	bz();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  4  5 ");
	lcd_gotoxy(1,10);
	lcd_string("4");
   } 
   
   if((xcod<(sx+10))&(xcod>(sx-10))&(ycod<(sy+5))&(ycod>(sy-5)))
   {
    touchbreak();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  4  * ");
	bz();
    lcd_gotoxy(0,0);
	lcd_string("1  2  3  4  5 ");
	lcd_gotoxy(1,10);
	lcd_string("5");
   }
	
   }
 }