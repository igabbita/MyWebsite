/***********************************************************************

CODE7.5: Program for Rx of PC controlled bot

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

#include <avr/io.h >
#include "cc2500b.h"
#include "delay.h"
int main()
{
rf_init();
DDRD=0xF0;
PORTD=0X00;
while(1)
 {
 PORTD=cc_data3;
 delayms(10);
 }
}