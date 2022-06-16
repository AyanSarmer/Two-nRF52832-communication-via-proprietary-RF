#include "SSD1306.h"

static uint8_t buffer[SSD1306_LCDWIDTH * SSD1306_LCDHEIGHT/8];

void ssd1306Init()
{
    spiInit();
    NRF_GPIO->PIN_CNF[DC]  |= (1 << GPIO_PIN_CNF_DIR_Pos);
    NRF_GPIO->PIN_CNF[CS_SSD1306]  |= (1 << GPIO_PIN_CNF_DIR_Pos);
    NRF_GPIO->PIN_CNF[RESET]  |= (1 << GPIO_PIN_CNF_DIR_Pos);
    CS_SSD1306_HIGH;
    RESET_HIGH;

    RESET_LOW;
    nrf_delay_us(20);
    RESET_HIGH;
    nrf_delay_ms(120);

    ssd1306Command(SSD1306_CHARGEPUMP);
    ssd1306Command(CHARGEPUMP_ENABLE);
    ssd1306Command(SSD1306_MEMORYMODE);
    ssd1306Command(HORIZONTAL_ADDRESSING);
    ssd1306Command(SSD1306_DISPLAYON);
    nrf_delay_ms(120);

    ssd1306SetRotation(1);
    ssd1306ClearDisplay();
    ssd1306DrawDisplay();
}

void ssd1306Command(unsigned char command)
{
    DC_COMMAND;
    CS_SSD1306_LOW;
    spiByte(command);
    CS_SSD1306_HIGH;
}

void ssd1306Data(unsigned char data)
{
    DC_DATA;
    CS_SSD1306_LOW;
    spiByte(data);
    CS_SSD1306_HIGH;
}

void ssd1306SetRotation(unsigned char rotation)
{
    if(rotation == 1) 
    {
        ssd1306Command(SSD1306_SEGREMAP | SEGREMAP_ON);      
        ssd1306Command(SSD1306_COMSCANDEC);   
    }
    if(rotation == 2)  
    {
        ssd1306Command(SSD1306_SEGREMAP | SEGREMAP_OFF);      
        ssd1306Command(SSD1306_COMSCANINC);   
    }    
}

void ssd1306ClearDisplay()
{
    memset(buffer, 0, (SSD1306_LCDWIDTH *SSD1306_LCDHEIGHT / 8));
}

void ssd1306DrawDisplay()
{
    ssd1306Command(SSD1306_COLUMNADDR);
    ssd1306Command(0);   
    ssd1306Command(SSD1306_LCDWIDTH - 1); 
    ssd1306Command(SSD1306_PAGEADDR);
    ssd1306Command(0); 
    ssd1306Command(7); 

    DC_DATA; 
    CS_SSD1306_LOW; 
    for (unsigned int i  =0; i < (SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT / 8); i++) 
    {
        spiByte(buffer[i]);
    }
    CS_SSD1306_HIGH;        
}

void drawPixel(unsigned int x, unsigned int y, unsigned int color)
{
    switch (color) 
    {
        case TEXT_COLOR: buffer[x + (y / 8) * SSD1306_LCDWIDTH] |=  (1 << (y & 7)); break;
        case BACKGROUND_COLOR: buffer[x + (y / 8) * SSD1306_LCDWIDTH] &= ~(1 << (y & 7)); break; 
    }   
}
