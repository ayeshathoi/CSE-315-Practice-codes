#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	unsigned char c = 1;
	DDRA = 0x01; //A0
    while (1) 
    {
		PORTA = c;
		if(c) c = 0;
		else c = 1;
		_delay_ms(1000);
    }
}

