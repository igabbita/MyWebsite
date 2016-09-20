/***********************************************************************

CODE10: Program for RC5 Receiver

***********************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............1st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz
IR TX PortB0		used for transmitter
IR Rx PortB1  		used for receiver 

*********************************************************************************/
#include<avr/io.h>
#include "delay.h"
#include "lcd.h"

int main(void)
{

delayms(300);
lcd_cmd(0x01);
delayms(300);
unsigned char i,a[14];
 lcd_init();
 lcd_string("RC 5 decoder");
 delayms(1000);
 DDRB=0X00;
 lcd_clear();
 delayms(100);
 while(1)
  {
   if((PINB&0x02)==0x02)
   {
    delayus(100);
    for(i=0;i<14;i++)
	 {
	  if((PINB&0x02)==0x02)
	    {a[i]=1;}
	  else{a[i]=0;}	
	  delayus(1777);
	 }
	  lcd_gotoxy(0,0);			//  to use it as a IR remote controller receiver 
	  
	  lcd_char((a[0])+0x30);	//instread if displaying its received data in LCD 
	  lcd_char((a[1])+0x30);	//separate the data and address bit check the 
	  lcd_char((a[2])+0x30);	//address and on the respective matching command 
	  lcd_char((a[3])+0x30);	//or data do the necessary action
	  lcd_char((a[4])+0x30);
	  lcd_char((a[5])+0x30);
	  lcd_char((a[6])+0x30);
	  lcd_char((a[7])+0x30);
	  
	  lcd_gotoxy(1,0);
	  
	  lcd_char((a[8])+0x30);
	  lcd_char((a[9])+0x30);
	  lcd_char((a[10])+0x30);
	  lcd_char((a[11])+0x30);
	  lcd_char((a[12])+0x30);
	  lcd_char((a[13])+0x30);
	  
   }
 }
}