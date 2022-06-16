#ifndef SPI_H_
#define SPI_H_

#include "nrf.h"

#define SCK                 25
#define MOSI                26          

#define SCK_HIGH            NRF_GPIO->OUT |= (1 << SCK)
#define SCK_LOW             NRF_GPIO->OUT &= ~(1 << SCK)

#define MOSI_HIGH           NRF_GPIO->OUT |= (1 << MOSI)
#define MOSI_LOW            NRF_GPIO->OUT &= ~(1 << MOSI)

#define MSBit               0x80
#define LSBit               0x01

void spiInit(void);
void spiByte(unsigned char _byte);

#endif /* SPI_H_ */
