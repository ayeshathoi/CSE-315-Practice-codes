#include <avr/io.h>
#define  F_CPU 1000000
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB   = 0xFB;
	DDRD   = 0xFB;
	DDRA   = 0xFF;
	PORTA  = 0x00;
	unsigned char counter = 0;

	int ager_inputB = 0;
	int ager_inputD = 0;
	PINB = 0 ;
	PIND = 0;


	PORTA  = counter;
	while (1)
	{

		if((PINB & 0x04) && ager_inputB == 0)
		{
			counter--;
			PORTA = counter;

		}
		if((PIND & 0x04) && ager_inputD == 0)
		{
			counter++;
			PORTA = counter;
		}

		ager_inputB = !!(PINB & 0x04);

		ager_inputD = !!(PIND & 0x04);
		_delay_ms(20);
	}
}