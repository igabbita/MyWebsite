/*adc.h
*******************************************************************************************
COPYRIGHT(C)Technophilia Systems
Date:...............31st May 2011
Author:.............Prasanta Kumar Nayak
Organization:.......Technophilia Syestems
compiler:...........WinAVR

Description:

	This header file enables ADC conversion and ADC channel selection.
	Include this header file in your C code.
	Call the adc_init() function before calling any other functions to initialize the adc.
	
Functions:

	adc_init();		Call this function to initialize the adc feature.
	getdata();  	This function provides delay in the form of micro second
	
*******************************************************************************************/

#ifndef _ADC_H_
#define _ADC_H_						//This is the header for AVR Microcontroller.
#include<avr/io.h>
#include<avr/interrupt.h>			//header file for using interrupt service routins
#include"delay.h"					//header file for genarating time delay
#include"lcd.h"						//headerfile for interfacing LCD

unsigned int adcdata,adcdata1;

void adc_init()
{
	ADCSRA=0X87;					//ADC enable, ADC interrupt enable, set prescaller to 64
}

unsigned char getdata(unsigned char chno)	
{
    ADMUX=0X60;						//right align the ADC result
    ADMUX|=chno;					//select the ADC channel
    ADCSRA|=0X40;					//start ADC convertion
    delayms(10);					//give some time delay to complit the aDC convertion
	return ADCH;
}

#endif 