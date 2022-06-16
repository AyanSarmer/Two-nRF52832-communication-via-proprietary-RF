# Основные параметры проекта
FILE 				= TX
CPU					= cortex-m4
# Папки хранения файлов
SRC_DIR       		= src
INC_DIR       		= inc
EXE_DIR       		= exe
CORE_DIR			= D:/GNU/ARM/NRF52_SDK/16_0/components/toolchain/cmsis/include
DEVICE_DIR			= D:/GNU/ARM/NRF52_SDK/16_0/modules/nrfx/mdk
STARTUP_DIR			= D:/GNU/ARM/NRF52_SDK/16_0/modules/nrfx/mdk
LIB_DIR				= -I D:/GNU/ARM/NRF52_SDK/16_0/components/libraries/delay
LIB_DIR				+= -I D:/GNU/ARM/NRF52_SDK/16_0/modules/nrfx
LIB_DIR				+= -I D:/GNU/ARM/NRF52_SDK/16_0/integration/nrfx
LIB_DIR				+= -I D:/GNU/ARM/NRF52_SDK/16_0/config/nrf52832/config
LIB_DIR				+= -I D:/GNU/ARM/NRF52_SDK/16_0/components/libraries/util
LIB_DIR				+= -I D:/GNU/ARM/NRF52_SDK/16_0/components/softdevice/s132/headers
# Список объектных файлов
SOURCES 			= $(wildcard $(SRC_DIR)/*.c)
ASM_SOURCES 		= $(STARTUP_DIR)/gcc_startup_nrf52.S
OBJECTS 			= $(SOURCES:.c=.o)
OBJECTS       		+= $(ASM_SOURCES:.S=.o)
# Компилятор GCC и опции его утилит
PREAMBLE 			= arm-none-eabi-
CC 					= $(PREAMBLE)gcc
	CC_OPTIONS  	= -mcpu=$(CPU)
	CC_OPTIONS  	+= -mthumb
	CC_OPTIONS  	+= -D NRF52832_XXAA
	CC_OPTIONS  	+= -I $(INC_DIR)
	CC_OPTIONS  	+= -I $(DEVICE_DIR)
	CC_OPTIONS  	+= -I $(CORE_DIR)
	CC_OPTIONS  	+= $(LIB_DIR)	
	CC_OPTIONS  	+= -Og
	CC_OPTIONS  	+= -fdata-sections
	CC_OPTIONS  	+= -ffunction-sections
	CC_OPTIONS  	+= -Wall
	CC_OPTIONS  	+= -c
	CC_OPTIONS  	+= -o
AS					= $(PREAMBLE)gcc
	AS_OPTIONS		= -x assembler-with-cpp
	LL_OPTIONS  	= -mcpu=$(CPU)
	LL_OPTIONS  	+= -mthumb
	LL_OPTIONS		+= -specs=nano.specs
	LL_OPTIONS		+= -specs=nosys.specs
	LL_OPTIONS		+= -u _printf_float
	LL_OPTIONS		+= -TLinkerScript.ld
	LL_OPTIONS		+= -Wl,--gc-sections
	LL_OPTIONS		+= -o
# Копировщик и его опции
COPIER				= $(PREAMBLE)objcopy
	CP_OPTIONS		= -O ihex
# Загрузчик и его опции
UPLOADER      		= openocd
	U_OPTIONS		= -f interface/stlink-v2.cfg
	U_OPTIONS		+= -f target/nrf52.cfg 
	U_OPTIONS		+= -c "init"
	U_OPTIONS		+= -c "reset init"
	U_OPTIONS		+= -c "flash write_image erase $(EXE_DIR)/$(FILE).hex"
	U_OPTIONS		+= -c "reset" -c "exit"