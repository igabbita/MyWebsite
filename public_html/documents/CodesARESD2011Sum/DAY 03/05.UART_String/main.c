/***********************************************************************

CODE3.5: Program to send a string through UART with header

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

#include<avr/io.h>		//This is the header file for AVR microcontroller
#include"uart.h"		//This is the header file for UART Communication

int main(void)
{
	uart_init();
	uart_string("Technophilia"); //Function to print a string of characters on the Uart
	while(1);
}