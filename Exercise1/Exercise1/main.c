#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
    DDRC = 0x00;
	MCUCSR = 1<<JTD; //MCU Control and Status Register
	MCUCSR = 1<<JTD;
	DDRB = 0xFF;
	DDRD = 0xFF;
	unsigned char c ;
    while (1) 
    {
		c = PINC;
		if(c<100)
		{
			PORTB = c;
			PORTD = 0;
		}
		else {
			PORTB = 0;
			PORTD = c;
		}
		_delay_ms(1000);
		
    }
}

