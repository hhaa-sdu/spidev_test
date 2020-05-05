/*
 * SPI_atmega_328.c
 *
 * Created: 22.2.2020 22:19:49
 * Author : User
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SPI.h"
#include "usart.h"

uint8_t data =0;
int main(void)
{	
	uart_init(); // open the communication to the microcontroller
	io_redirect(); // redirect input and output to the uart
	
	spi_init();
  
	printf(" Data received from master ");
	
    while (1) 
    {
		if (print==1)
		{
			for (int i=0; i<3; i++)
			{
				printf(" %d",rec_buff[i]);
			}
				printf("\n");
			print = 0;
		}			
    }
	
}

