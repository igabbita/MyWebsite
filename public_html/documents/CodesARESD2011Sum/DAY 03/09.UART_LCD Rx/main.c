/***********************************************************************

CODE3.9: Program for UART Reception on LCD with header

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............31st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz

***********************************************************************/

#include<avr/io.h>
#include"uart.h"
#include"lcd.h"
#include"delay.h"

int main(void)
{
 	uart_init();
	lcd_init();
	delayms(100);
	
	while(1)
	{
		lcd_char(uart_read());
	}
}