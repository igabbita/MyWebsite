/****************************************************************************
HEADER:UART.h

*****************************************************************************

COPYRIGHT(c): Technophilia embedded systems
AUTHOR:Technophilia

DESCRIPTION: 

    This header files gives an interface between computer and motherboard for 
	serial communicating purpose. Include this header file in your C code. 
	Call the uartinit() function before calling any other functions of UART.

	uartinit();------Call the uartinit() function before calling any other 
					 functions of UART.
	printrchar();----This function is used to display characters on computer 
					 dispalay screen.
	printstring();---This function will display a string.
					 An example of this would be like printstring("This is AVR")
	printnum();------This will show decimal value on the computer screen. 
	
*****************************************************************************/

#ifndef _UART_H_
#define _UART_H_

void uartinit() //**********************************************************/1
{
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRH=0x00;
	UBRRL=0x67;
	delayms(100);
}

void printchar(unsigned char uchar)//***************************************/2
{
	UDR=uchar;
	while((UCSRA&0x40)==0x00);
	delayuart(1000);
}
 
void printstring(const unsigned char *ustring) //***************************/3
{
	while ( *ustring )
	{
		UDR=*ustring++;
		while((UCSRA&0x40)==0x00);
		delayuart(1000);
 	}
}
 
void printnum(unsigned char num) //*****************************************/4
{
    unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));
	
	printchar(H+48);
	printchar(T+48);
	printchar(O+48);
}
 
unsigned char read_UART() //*************************************************/5
{
	while((UCSRA&0x80)==0x00);
	return UDR;
}
 
void delayuart(unsigned int delaytime) //***********************************/6
{
	unsigned int dc;
	for(dc=0;dc<=delaytime;dc++)
	{
		asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		asm("nop");asm("nop");asm("nop");asm("nop");
	}
}

#endif 

/*****************************************************************************/