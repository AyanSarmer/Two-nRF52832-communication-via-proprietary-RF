#ifndef GFX_H_
#define GFX_H_

#include "SSD1306.h"
#include "iconsFonts.h"

#define SUBSTRUCT                   0x2B
#define BYTES_PER_HIGHT             5

void drawByte(unsigned char data);
void setCursor(unsigned int x, unsigned int y);
void setColor(unsigned int color);    
void drawVerticalLine(unsigned int _hight);
void drawHorizontalLine(unsigned int _length);
void drawRectangle(unsigned int _width, unsigned int _hight);
void fillRectangle(unsigned int _width, unsigned int _hight);
void printChar(unsigned char myChar);
void printString(const char *myString);
void drawIcon(const unsigned char *image, unsigned int width, unsigned int hight);

extern unsigned int currentX, currentY, currentColor;

#endif /* GFX_H_ */