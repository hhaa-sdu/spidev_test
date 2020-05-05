/*
 * SPI.c
 *
 * Created: 22.2.2020 22:25:18
 *  Author: User
 */ 

 #include "spi.h"
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include <stdio.h>

 #define DDR_SPI     DDRB
 #define DD_MISO     DDB4
 #define DD_MOSI     DDB3
 #define DD_SS       DDB2
 #define DD_SCK      DDB5

 
 void spi_init()  // Initialize pins for spi communication
 {		
	
	 print = 0;	
	 data_received = 77;
	 i=0;
	 
	/* Set MISO output, all others input */
	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI with interrupts */
	SPCR = (1<<SPE)|(1<<SPIE)|(1<<CPOL)|(1<<CPHA);
	
	sei();	//Enable interrupts
		
 }


uint8_t SPI_SlaveReceive(void)
{
	
	SPDR = 27;
	/* Wait for reception complete */
	while (!(SPSR & (1<<SPIF)));
	
	/* Return data register */
	return SPDR;
}

ISR(SPI_STC_vect)
{
	
	rec_buff[i] = SPI_SlaveReceive();
	i++;
	if (i==2)
	{
		i=0;
		print=1;
	}

}