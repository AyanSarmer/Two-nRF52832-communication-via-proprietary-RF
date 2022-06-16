#include "device.h"

void deviceInit() 
{
    displayInit();
    radioInit(2);
    radioSetPRX();
}

void deviceControl()
{     
    if(receiveFlag)
    {
        receiveFlag = 0;
        unsigned int data = (unsigned int)(packet[2] * 2.5);
        temperatureTens = (uint8_t)(data / 100);
        temperatureUnits = (uint8_t)((data - temperatureTens * 100) / 10);
        temperatureFraction = (uint8_t)(data - temperatureTens * 100 - temperatureUnits * 10);    
        drawTemperature();
    }
}