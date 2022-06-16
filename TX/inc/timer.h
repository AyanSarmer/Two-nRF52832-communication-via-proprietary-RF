#ifndef TIMER_H_
#define TIMER_H_

#include "nrf.h"

#define PSC_VALUE               8
#define CC_VALUE                50

void timerInit();

extern volatile unsigned char timerFlag;

#endif /* TIMER_H_ */