#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

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
	TCNT1 = 0;
	
	sei();
	
	//time starts
	for (i=0;i<100;i++)
	{
		for (j=0;j<100;j++)
		{
			
		}
	}
	//time ends
	
	elapsed_time = 65536 * overflowCount + (uint32_t) TCNT1 ;//in microseconds
	//65536 = 2^16
	
	cli();
	
	return 0;
}