/*
 * Timer1toggle.c
 *
 * Created: 9/4/2022 8:31:58 AM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char overflowCount = 0;

ISR(TIMER1_OVF_vect)
{
	overflowCount++;
	if(overflowCount ==31)
	{
		overflowCount = 0;
		PORTB = ~PORTB;
	}
}

int main(void)
{
    
	DDRB = 0xFF;
	PORTB = 0xFF;
	
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000001;
	TIMSK  = 0b00000100;
	
	sei();
	
    while (1) 
    {}
}

