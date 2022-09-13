

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
    DDRA = 0x00;
	DDRB = 0xFF;
	unsigned char c;
    while (1) 
    {
		c = PINA;
		PORTB = c;
		
    }
}

