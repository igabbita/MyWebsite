
/****************************************************************************
HEADER:delay.h

*****************************************************************************

COPYRIGHT(c): Technophilia embedded systems
AUTHOR:Technophilia

DESCRIPTION: 

    This header file provides time delay in the form of mili second 
	and micro second without affecting any interrupts.

	delayus();  this function provides delay in the form of micro second
    delayms();  this function provides delay in the form of mili second
	
*****************************************************************************/

#ifndef _DELAY_H_
#define _DELAY_H_

unsigned int delaycounter1,delaycounter2;

void delayus(unsigned int delaytime)//microsecond delay ********************/1
{
	for(delaycounter1=0;delaycounter1<=delaytime;delaycounter1++)
	{
		asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		asm("nop");asm("nop");asm("nop");asm("nop");
	}
}

void delayms(unsigned int delaytime)//milisecond delay *********************/2
{
	for(delaycounter1=0;delaycounter1<=delaytime;delaycounter1++)
	{
		for(delaycounter2=0;delaycounter2<=800;delaycounter2++)
		{
		  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		  asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		}
		
	}
}

#endif 

/****************************************************************************/