#include <avr/io.h>
#define  F_CPU 1000000
#include <util/delay.h>
#include <avr/interrupt.h>
volatile uint8_t ch = 0;
ISR(INT0_vect)
{
	ch++;
}

ISR(INT2_vect)
{
	ch--;
}

int main(void)
{
    DDRA   = 0xFF;
	PORTA  = 0x00;
	GICR   = GICR | (1<< INT0);
	GICR   = GICR | (1<< INT2);
	
	MCUCR  = MCUCR  | (1<<ISC00);
	MCUCR  = MCUCR  | (1<<ISC01);
	MCUCSR = MCUCSR | (1<<INT2); 
	sei();
	while (1) 
    {
		PORTA = ch;
    }
}

