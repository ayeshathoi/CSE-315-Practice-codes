/*
 * negEdge.cpp
 *
 * Created: 9/26/2022 7:38:56 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)

{
	DDRB   = 0xFB;
	DDRD   = 0xFB;
	DDRA   = 0xFF;
	PORTA  = 0x00;
	unsigned char counter = 0;

	int old_inputB = 1;
	int old_inputD = 1;
	PINB = 0 ;
	PIND = 0;


	PORTA  = counter;
	while (1)
	{

		if((PINB & 0x04) == 0 && old_inputB == 1)
		{
			counter--;
			PORTA = counter;

		}
		if((PIND & 0x04) ==0 && old_inputD == 1)
		{
			counter++;
			PORTA = counter;
		}

		old_inputB = ((PINB >> 2) & 1);

		old_inputD = ((PIND >> 2) & 1);
		_delay_ms(20);
	}
}

