#include "display.h"

uint8_t temperatureSign = 0, temperatureTens = 0, temperatureUnits = 0, temperatureFraction = 0;

void displayInit()
{
    ssd1306Init();
    setColor(WHITE);
    setCursor(11, 0);
    drawTemperature();
}

void drawTemperature()
{
    ssd1306ClearDisplay();
    setCursor(TEMPERATURE_SIGN_X, TEMPERATURE_Y);
    if(temperatureSign == 0)
    {
        printChar('+');
    }
    else if(temperatureSign == 1)
    {
        printChar('-');
    }
    setCursor(TEMPERATURE_TENS_X, TEMPERATURE_Y);
    printChar(temperatureTens + 48);
    setCursor(TEMPERATURE_UNITS_X, TEMPERATURE_Y);
    printChar(temperatureUnits + 48);    
    setCursor(TEMPERATURE_DOT_X, TEMPERATURE_Y);
    printChar('.');            
    setCursor(TEMPERATURE_FRACTION_X, TEMPERATURE_Y);
    printChar(temperatureFraction + 48);
    setCursor(TEMPERATURE_CIRCLE_X, TEMPERATURE_Y);
    printChar('o');             
    setCursor(TEMPERATURE_C_X, TEMPERATURE_Y);
    printChar('C');                   
    ssd1306DrawDisplay();    
}
