#include <avr/io.h>
#include <avr/interrupt.h> //STEP1

ISR(INT1_vect)//STEP2
{
	PORTB = ~PORTB;
}
int main(void)
{
	DDRB = 0xFF;
	PORTB = 0b01010101;
	GICR = (1 << INT1); //STEP3
	MCUCR = MCUCR | (1 << ISC11);//STEP4 (setting 10 here)
	MCUCR = MCUCR & (~(1 << ISC10));//STEP4
	sei();//STEP5
	while(1);
}
