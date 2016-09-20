/*CODE1:Test code MB107010
*******************************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............31st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
Target system:......AVR devlopment board s/n-107010
Manufacturer:.......Technophilia Syestems
Microcontroller:....ATmega-8535
Clock:..............16mhz

///compiler WinAVR
==================
PORTS USED
==================

LCD on PORTC
===============
RS PORTC.0
RW PORTC.1 
E  PORTC.2
D4 PORTC.4
D5 PORTC.5
D6 PORTC.6
D7 PORTC.7

Switches
===============
S1 PortA4
S2 PortA5
S3 PortA6
S4 PortA7
RS Reset

LED-Active High
===============
LED1 PortC4
LED2 PortC5
LED3 PortC6
LED4 PortC7
Green-power on indicator

BUZZER-Active High
==================
PortC3

MOTOR DRIVERS
===============
m0-PortB0
m1-PortB1
m2-PortB2
m3-PortB3
m4-PortD4
m5-PortD5
m6-PortD6
m7-PortD7

*********************************************************************************/
#include<avr/io.h>
#include "delay.h"
#include "lcd.h"
#include "uart.h"
#include "adc.h"
#define led PORTC
#define s1 (PINA&0x10)
#define s2 (PINA&0x20)
#define s3 (PINA&0x40)
#define s4 (PINA&0x80)

unsigned char flag;

void checkswitch()
{  
	ADCSRA=0x00;
    if(s1==0){flag=1;}
	if(s2==0){flag=2;}
	if(s3==0){flag=3;}
	if(s4==0){flag=4;}
	ADCSRA=0x87;
}
 
int main()
{  
    DDRB=0x1F;
	DDRD=0xFE;
	PORTA=0xf0;
	DDRA=0x00;
	lcd_init();
	
	lcd_string("Technophilia");
	delayms(1000);
  
	lcd_gotoxy(0,0);
	lcd_string("Playing Buzzer  ");
	DDRC|=0x08;
	PORTC|=0x08;
	delayms(500);
	PORTC&=~0x08;
	delayms(500);
  
	lcd_gotoxy(0,0);
	lcd_string("Blinking LEDs   ");
    lcd_gotoxy(1,0);
	lcd_string("/Press S1       ");
	
	flag=0;
	uart_init();
	adc_init();
	
	while(1)
	{
		led=0xF0;
		delayms(1000);
		led=0x00;
		delayms(1000);
	 
		checkswitch(); 
	 
		while(flag==1)
		{
			lcd_gotoxy(0,0);
			lcd_string("Motor Clockwise ");
			lcd_gotoxy(1,0);
			lcd_string("/Press S2       ");
			PORTB=0x05;
			PORTD=0X50;
			checkswitch();
		}
	 
		while(flag==2)
		{
			lcd_gotoxy(0,0);
			lcd_string("Motor Anticlock-");
			lcd_gotoxy(1,0);
			lcd_string("wise/Press S3   ");
			PORTB=0x0A;
			PORTD=0XA0;
			checkswitch();
		}
	 
		while(flag==3)
		{
			lcd_gotoxy(0,0);
			lcd_string("ADC ");
			lcd_showvalue(getdata(0));
			lcd_string(",");
			lcd_showvalue(getdata(0));
			lcd_string(",");
			lcd_showvalue(getdata(0));
			lcd_gotoxy(1,0);
			lcd_string("/Press S4       ");
			checkswitch();
		}
	 
		if(flag==4) 
		{  
		    lcd_gotoxy(0,0);
			lcd_string(" UART RX        ");
			lcd_gotoxy(1,0);
			lcd_string("ConectUARTcable ");
			uart_string("Press any key");
			lcd_gotoxy(0,9);
			lcd_char(uart_read());
		}
	   
	}
}
