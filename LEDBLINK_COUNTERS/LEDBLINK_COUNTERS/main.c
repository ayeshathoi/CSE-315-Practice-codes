#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
    DDRB = 0x01;//ledBlink
	unsigned char c = 1; //ledBlink
	
	DDRA = 0xFF; //ring Counter
	unsigned char check = 0x01; //ring counter
	
	DDRC = 0xFF;
	DDRD = 0xFE;
	MCUCSR = 1<<JTD;
	MCUCSR = 1<<JTD;
	unsigned char inc ;
	unsigned char ch = 0;
	PORTC = ch;
	
	
    while (1) 
    {
		PORTB = c; //ledBlink
		if(c) c = 0; //ledBlink
		else  c = 1;//ledBlink
		
		PORTA = check;//ring counter
		if(check == 1<<7) check =1 ;//ring counter
		else check =check<<1;//ring counter
		
		//simple counter
		inc = PIND;
		if (inc & 0x01 )
		{
			ch++;
			PORTC = ch;
		}
		//simple counter
		
		_delay_ms(1000);
		
		
	}
}

