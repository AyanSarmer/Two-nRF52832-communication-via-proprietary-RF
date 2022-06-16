#ifndef RADIO_H_
#define RADIO_H_

#include "nrf.h"
#include "nrf_delay.h"
#include <stdbool.h>

#define PAYLOAD_SIZE                1
#define PACKET_SIZE                 PAYLOAD_SIZE + 2

#define PRX                         0
#define PTX                         1

void radioInit(uint8_t channel);
void radioSetPTX();
void radioSetPRX();
void radioTransmit();
bool radioReceive();

extern uint8_t packet[PACKET_SIZE];
extern volatile unsigned char receiveFlag;

#endif /* RADIO_H_ */