/***********************************************************************

CODE7.3: Program for RF Transmitor & Receiver by switch

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
#include"cc2500b.h"

int main(void)
{
 int i=5;
 delayms(500);
 rf_init();
 lcd_init();
 PORTA=0x10;
 DDRA=0x00;
 lcd_string("\n Press S1 \n\n");
 delayms(1000);
 
 while(1)
 {
  lcd_gotoxy(1,0); 
  if((PINA & 0x10)==0x00)
  {
   while((PINA & 0x10)==0x00);
   i++;
   rf_transmit_B(5,2,i);
  }
   
 
   lcd_string("Tx=");
   lcd_showvalue(i);
   lcd_string(" RX=");
   lcd_showvalue(cc_data3);
 
}
  
  
 } 

/*******************************************************************************/