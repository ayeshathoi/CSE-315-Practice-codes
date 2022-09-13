/*
 * ADCInterrupt.c
 *
 * Created: 9/3/2022 9:47:39 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char result;
ISR(ADC_vect)
{
	result = ADCH;
}

int main(void)
{
	ADMUX = 0b01100000;
	ADCSRA = 0b10001000;
	
	sei();
	
    while (1) 
    {
		ADCSRA |= 1 << ADSC;
		
		PORTB = ~result;

    }
	return 0;
}

