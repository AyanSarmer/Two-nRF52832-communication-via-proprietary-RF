#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "GFX.h"

#define TEMPERATURE_Y                   15
#define TEMPERATURE_SIGN_X              9
#define TEMPERATURE_TENS_X              26
#define TEMPERATURE_UNITS_X             43
#define TEMPERATURE_DOT_X               60
#define TEMPERATURE_FRACTION_X          69
#define TEMPERATURE_CIRCLE_X            86
#define TEMPERATURE_C_X                 98

void displayInit();
void drawTemperature();

extern uint8_t temperatureSign, temperatureTens, temperatureUnits, temperatureFraction;

#endif /* DISPLAY_H_ */