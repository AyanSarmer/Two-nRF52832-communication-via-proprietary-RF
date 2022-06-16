#include "GFX.h"

unsigned int currentX, currentY, currentColor;

void setColor(unsigned int color)
{
	currentColor = color;
}

void setCursor(unsigned int x, unsigned int y)
{
	currentX = x;
	currentY = y;   
}

void drawVerticalLine(unsigned int _hight)
{
	while(_hight--)
	{
		drawPixel(currentX, currentY, currentColor);
		currentY++;
	}    
}

void drawHorizontalLine(unsigned int _length)
{
	while(_length--)
	{
		drawPixel(currentX, currentY, currentColor);
		currentX++;
	}
}

void drawRectangle(unsigned int _width, unsigned int _hight)
{
	unsigned int startX = currentX, startY = currentY;
	
	drawVerticalLine(_hight);
	currentY--;
	drawHorizontalLine(_width);

	currentX = startX; currentY = startY;
	
	drawHorizontalLine(_width);
	currentX--;
	drawVerticalLine(_hight);
}

void fillRectangle(unsigned int _width, unsigned int _hight)
{
    unsigned int startX = currentX;
    
	for(unsigned int coordinateY = 0; coordinateY < _hight; coordinateY++)
	{
		drawHorizontalLine(_width);
        currentY++;
        currentX = startX;
	}
}

void drawByte(unsigned char data)
{ 
   	unsigned char bitNumber = 8;
	   
    while (bitNumber--)
    {
        if(data & MSBit)
        {
            drawPixel(currentX, currentY, currentColor);
        }
        data <<= 1;
        currentY++;        
    }
}

void printChar(unsigned char myChar)
{
	if(myChar == 'C')
	{
		myChar = 16;
	}
	else if(myChar == 'o')
	{
		myChar = 15;
	}
	else
	{
		myChar -= SUBSTRUCT; 
	}	
    unsigned int startX = currentX, startY = currentY;
    unsigned int width = widthValue_Arial28[myChar];
    unsigned int bytesPerHight = BYTES_PER_HIGHT;
    unsigned int imageByteNum = 0;
	
	for(unsigned int imageHigt = 0; imageHigt < bytesPerHight; imageHigt++)
	{
		for(unsigned int imageWidth = 0; imageWidth < width; imageWidth++)
		{
			drawByte(image_data_Arial28[myChar][imageByteNum]);
			currentX++;
			currentY = startY;
			imageByteNum++;
		}
		
		startY += 8;
		currentY = startY;
		currentX = startX;
	}
}

void printString(const char *myString)
{
	unsigned int startY = currentY;
	
	while(*myString != '\0')
	{
		unsigned char myChar = *myString - SUBSTRUCT;
		unsigned int width = widthValue_Arial28[myChar];
		
		printChar(*myString);
		myString++;
		currentY = startY;
		currentX += width + 1;
	}	
}

void drawIcon(const unsigned char *image, unsigned int width, unsigned int hight)
{
  unsigned int startX = currentX, startY = currentY;

  unsigned int imageByteNum = 0;
  
  unsigned int bytesPerHight = (unsigned int)(hight / 8); 
  if ((bytesPerHight * 8) != hight) bytesPerHight += 1;
  
  for(unsigned int imageHigt = 0; imageHigt < bytesPerHight; imageHigt++) 
   {
      for(unsigned int imageWidth = 0; imageWidth < width; imageWidth++) 
        {
           drawByte(image[imageByteNum]);
           currentX++;
           currentY = startY;
           imageByteNum++;      
        }
      
      startY += 8;
      currentY = startY;  
      currentX = startX;
   }      
}