/***********************************************************************

CODE7.1: Program for RF Transmitor & Receiver in Normal mode

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
 int i=5;
 delayms(500);
 rf_init();
 lcd_init();
 lcd_gotoxy(0,1);
 lcd_string("TX Rx Check");
 delayms(1000);
 while(1)
 {
  rf_transmit(i);
  lcd_gotoxy(1,2);
  lcd_string("Tx=");
  lcd_showvalue(i);
 
  
  lcd_gotoxy(1,9);
  lcd_string("Rx=");
  lcd_showvalue(cc_data); //read the received data and display in LCD
  
  delayms(1000);
  i++;
 }
}

/*******************************************************************************/