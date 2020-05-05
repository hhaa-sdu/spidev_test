/*
 * SPI.h
 *
 * Created: 22.2.2020 22:20:31
 *  Author: User
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

volatile int print;
volatile uint8_t data_received;
volatile uint8_t i;

uint8_t rec_buff[128];

extern void spi_init();
extern uint8_t SPI_SlaveReceive(void);



#endif /* SPI_H_ */