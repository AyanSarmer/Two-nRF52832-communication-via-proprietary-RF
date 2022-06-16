#include "device.h"

void SystemInit()
{
  
}

int main(void)
{
  deviceInit();
	
  while(1)
  {
    deviceControl();
  }
}