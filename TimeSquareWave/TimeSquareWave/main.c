#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

volatile uint16_t period;

ISR(TIMER1_CAPT_vect)
{
	period = ICR1;
	TCNT1 = 0;
	PORTA = period>>8;
	PORTB = period<<8;
	
}
int main(void)
{
	DDRB = 0xFF;
	DDRA = 0xFF;
    TCCR1A = 0x00;
	TCCR1B = 0xC1;
	TIMSK  = 0x20; 
	sei();
    while (1) 
    {
    }
}

