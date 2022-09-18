#include <avr/io.h>

void SPI_MasterInit(void)
{
	/* Set MOSI, SCK output, all others input */
	DDRB = (1<<DDB5)|(1<<DDB7);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDRB = (1<<DDB6);
	/* Enable SPI */
	SPCR = (1<<SPE);
}

void SPI_Transmit(char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
}

char SPI_Receive(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
}



void master_main()
{
	DDRA = 0x00;
	SPI_MasterInit();
	while(1)
	{
		char data = PINA;
		SPI_Transmit(data);
	}
}

void slave_main()
{
	DDRA = 0xFF;
	SPI_SlaveInit();
	while(1)
	{
		char data = SPI_Receive();
		PORTA = data;
	}
}


int main(void)
{
    DDRC = 0x00;
	if(PINC) {
		master_main();
	}
	else
	{
		slave_main();
	}
}

