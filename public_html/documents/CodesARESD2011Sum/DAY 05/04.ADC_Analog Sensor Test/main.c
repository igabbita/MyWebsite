/***********************************************************************

CODE5.4: Program for Analog sensor testing

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
#include"adc.h"							//header file for ADC
#include"lcd.h"

int main(void)
{
 adc_init();	
 lcd_init();
 while(1)
  {
   lcd_gotoxy(0,0);						// Place the cursor at Row 0 & Column 0 on LCD
   lcd_showvalue(getdata(0x00));		// Read from channel 0 (PORTA0)
   delayms(100);   
  }
}