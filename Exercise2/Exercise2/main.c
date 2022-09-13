/*
 * Exercise2.c
 *
 * Created: 9/2/2022 10:24:10 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
	DDRA = 0x00;
	DDRB = 0b00001111;
	DDRC = 0b11110000;
	MCUCSR = 1<<JTD; //MCU Control and Status Register
	MCUCSR = 1<<JTD;
	unsigned char c;

    while (1) 
    {
			c = PINA;
			PORTB = c>>4;
			PORTC = c<<4;
			_delay_ms(1000);
    }
}

