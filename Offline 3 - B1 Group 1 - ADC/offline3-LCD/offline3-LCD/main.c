/*
 * offline3-LCD.c
 *
 * Created: 8/29/2022 10:47:34 AM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7

#include <util/delay.h>
#include "lcd.h" 
#include <stdlib.h>

int main(void)
{
	DDRD = 0xFF;
	DDRC = 0xFF;
	DDRA = 0x00;
	ADMUX = 0b01100001;
	ADCSRA = 0b10000001;
	Lcd4_Init();
    float ans;
	char result[16];
	while (1) 
    {
		ADCSRA |= 1 << ADSC;
		
		while(ADCSRA & (1 << ADSC));
		
		ans = ADCL >> 6;
		ans += ((int)ADCH << 2); 
	
		ans = (ans * 5) / 1024;
		
		Lcd4_Set_Cursor(1, 1);
		Lcd4_Write_String("Voltage:");
		Lcd4_Set_Cursor(2, 1);
		dtostrf(ans, 4, 2, result);
		Lcd4_Write_String(result);
		_delay_ms(1000);
	}
}

