/*
 * Ring Counter.c
 *
 * Created: 9/2/2022 8:27:46 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
	unsigned char c=1;
	DDRB = 0xFF;
	
    while (1) 
    {
		PORTB = c;
		if(c==1<<7) c = 1;
		else c = c<<1;
		_delay_ms(1000);
	}
}

