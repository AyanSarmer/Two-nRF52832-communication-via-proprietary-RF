#include "device.h"

void deviceInit() 
{
    radioInit(2);
    radioSetPTX();
    timerInit();
}

void deviceControl()
{     
    if(timerFlag)
    {
        timerFlag = 0;
        NRF_TEMP->TASKS_START = 1;
        while(!NRF_TEMP->EVENTS_DATARDY);
        NRF_TEMP->EVENTS_DATARDY = 0;  
        packet[2] = (uint8_t)NRF_TEMP->TEMP;
        radioTransmit();
    }
}