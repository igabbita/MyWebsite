/***********************************************************************

CODE10.1: IR Receiver : Program for IR receiver

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............1st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz

PORTS USED

	data in-PORTB.1


*********************************************************************************/
#include<avr/io.h>
#include"delay.h" //header file for generating timing delay
#include"lcd.h"   //header file for interfacing LCD

void delay_us(unsigned int delaytime)  //funtion for generating time delay in micro seconds
{

	 for(delaycounter1=0;delaycounter1<=delaytime;delaycounter1++)
	 {
		 
		  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		  asm("nop");asm("nop");asm("nop");asm("nop");
	 }
}

int main()
 {
 unsigned char data,i;    	 	//"data" is the variable where received data shood be stored, "i" is the incrementer variable
 DDRB=0x00;				    	//set the port B as input port
 PORTB=0x02;			  		//initialize port B 
 lcd_init();			   		//initialization of LCD
 lcd_string("IR receiver");		//function to print a string in lcd
 
 
 
  while(1)
   {
   
    if((PINB&0x02)==0x02)       //polling continiously for start bit
	 {
	  data=0;					 
	  delay_us(1500);
	  for(i=0;i<=7;i++)
	   {
	    data>>=1;
	    if((PINB&0x02)==0x02)
		 {
		  data|=0x80;
		 }
       delay_us(2000); 
	   }

	   lcd_gotoxy(1,0);				//function to move the cursor position of LCD
	   lcd_showvalue(data);			//function to print a decimal number in LCD
	   delayms(500);				//function to generate delay in mili seconds
	 }
   }
 } 