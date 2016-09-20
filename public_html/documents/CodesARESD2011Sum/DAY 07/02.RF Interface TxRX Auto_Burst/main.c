/***********************************************************************

CODE7.2: Program for RF Transmitor & Receiver in Burst mode

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
#include"lcd.h"
#include"delay.h"
#include"cc2500b.h"

int main(void)
{
 int i=1, j=2, k=3;
 delayms(200);
 rf_init();
 lcd_init();
 delayms(1000);
 
 while(1)
 {
  rf_transmit_B(i,j,k);
  
  lcd_gotoxy(0,0);
  lcd_string("Tx");
  lcd_gotoxy(0,4);
  lcd_showvalue(i);
  lcd_gotoxy(0,8);
  lcd_showvalue(j);
  lcd_gotoxy(0,12);
  lcd_showvalue(k);
  
  lcd_gotoxy(1,0);
  lcd_string("Rx");
  lcd_gotoxy(1,4);
  lcd_showvalue(cc_data1);
  lcd_gotoxy(1,8);
  lcd_showvalue(cc_data2);
  lcd_gotoxy(1,12);
  lcd_showvalue(cc_data3);
  
  delayms(1000);
  
  i++;
  j++;
  k++;
 }
}

/*******************************************************************************/