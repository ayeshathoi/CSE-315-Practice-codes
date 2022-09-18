/*
 * usart-terminal-code.c
 *
 * Created: 6/20/2021 10:09:04 AM
 * Author : Tareq
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void uart_init() 
{
	UCSRA = 0b00000010;
	UCSRB = 0b00011000;
	UCSRC = 0b10000110;
	
	UBRRH = 0;
	UBRRL = 12;
}


void uart_send(unsigned char data){	
	while ((UCSRA & (1<<UDRE)) == 0x00);	
	UDR = data; 
}

unsigned char uart_receive(void){
	while ((UCSRA & (1<<RXC)) == 0x00);
	return UDR;
}


int main(void)
{
    /* Replace with your application code */
	
	uart_init();
	
	stdout = fdevopen(uart_send, NULL);
	stdin = fdevopen(NULL, uart_receive);
	
	
	printf("Password\n\r");
	
	int a;
	scanf("%d", &a); 
	printf("%d\n\r", a);
	
	printf("Countdown\n\r");
	
	int count = 10;
	
    while (count >= 0) 
    {
		printf("%d\n\r", count--);
		_delay_ms(1000);
    }
}

