/*
 * elapseTimer.c
 *
 * Created: 9/4/2022 9:27:40 AM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t overflowCount;

ISR(TIMER1_OVF_vect)
{
	overflowCount++;
}
int main(void)
{
    int i,j;
	uint32_t elapsed_time;
	
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000001;
	TIMSK  = 0b00000100;
	
	overflowCount=0;
	TCNT1 = 1;
	
	sei();
	for (i=0;i<100;i++)
	{
		for (j=0;j<1000;j++)
		{
			
		}
	}
	
	elapsed_time = 65536 * overflowCount + (uint32_t) TCNT1 ;
	//65536 = 2^16
    
	cli();
	
	return 0;
}

