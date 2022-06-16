#include "SPI.h"

void spiInit(void)
{
  NRF_GPIO->PIN_CNF[SCK]  |= (1 << GPIO_PIN_CNF_DIR_Pos);
  NRF_GPIO->PIN_CNF[MOSI] |= (1 << GPIO_PIN_CNF_DIR_Pos);   
}

void spiByte(unsigned char _byte)
{
    for(unsigned char bitNum = 8; bitNum; bitNum--)
    {
        if (_byte & MSBit)
            MOSI_HIGH;
        else
            MOSI_LOW; 
        _byte <<= 1;                      
        SCK_HIGH;  
        SCK_LOW; 
    }
}