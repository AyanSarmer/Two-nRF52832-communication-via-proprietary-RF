#include "timer.h"

volatile unsigned char timerFlag = 0;

void TIMER2_IRQHandler(void)
{
    NRF_TIMER2->EVENTS_COMPARE[0] = 0;
    timerFlag = 1;
}

void timerInit()
{
    NRF_TIMER2->MODE = TIMER_MODE_MODE_Timer;
    NRF_TIMER2->BITMODE = TIMER_BITMODE_BITMODE_16Bit;
    NRF_TIMER2->PRESCALER = PSC_VALUE;
    NRF_TIMER2->CC[0] = CC_VALUE;
    NRF_TIMER2->INTENSET = (1 << TIMER_INTENSET_COMPARE0_Pos);
    NVIC_EnableIRQ(TIMER2_IRQn);
    NRF_TIMER2->TASKS_START = 1;   
}