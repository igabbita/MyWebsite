/***********************************************************************

CODE3.6: Program to send character and number through UART with header

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
	uart_init();		//UART initialization
	uart_char(13);		//Carriage return value
	uart_char('S'); 	//Function to print a character on the Uart
	uart_char('\n');	//New line
	uart_char(13);		//Carriage return value
	uart_num(157);		//Function to print a number on the Uart
	uart_char('\n');	//New line
	while(1);
}