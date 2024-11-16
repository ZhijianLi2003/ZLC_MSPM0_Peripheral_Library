SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
AR = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-ar"

NAME = drivers_mspm0l11xx_l13xx

OBJ_DIR = ../../../obj/gcc/m0p/drivers_mspm0l11xx_l13xx
SRC_DIR = ../../..

CFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" -mcpu=cortex-m0plus -march=armv6-m -mtune=cortex-m0plus -mthumb -mfloat-abi=soft -DDeviceFamily_MSPM0L130X -DUART_NO_DMA -Wall -ffunction-sections -fdata-sections -std=c99 -c -g -gstrict-dwarf -O2
AFLAGS = -cr --target=elf32-little
ASMFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" 

OBJECTS = $(OBJ_DIR)/DMAMSPM0.o $(OBJ_DIR)/List.o $(OBJ_DIR)/RingBuf.o $(OBJ_DIR)/StructRingBuf.o $(OBJ_DIR)/ADC.o $(OBJ_DIR)/GPIO.o $(OBJ_DIR)/I2C.o $(OBJ_DIR)/I2CTarget.o $(OBJ_DIR)/UART.o $(OBJ_DIR)/SPI.o $(OBJ_DIR)/ADCMSPM0.o $(OBJ_DIR)/GPIOMSPM0.o $(OBJ_DIR)/I2CMSPM0.o $(OBJ_DIR)/I2CTargetMSPM0.o $(OBJ_DIR)/UARTMSPM0.o $(OBJ_DIR)/SPIMSPM0.o

all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@ echo Archiving $@
	@ $(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/DMAMSPM0.o: $(SRC_DIR)/dma/DMAMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/List.o: $(SRC_DIR)/utils/List.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/RingBuf.o: $(SRC_DIR)/utils/RingBuf.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/StructRingBuf.o: $(SRC_DIR)/utils/StructRingBuf.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/ADC.o: $(SRC_DIR)/ADC.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/GPIO.o: $(SRC_DIR)/GPIO.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/I2C.o: $(SRC_DIR)/I2C.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/I2CTarget.o: $(SRC_DIR)/I2CTarget.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/UART.o: $(SRC_DIR)/UART.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/SPI.o: $(SRC_DIR)/SPI.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/ADCMSPM0.o: $(SRC_DIR)/adc/ADCMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/GPIOMSPM0.o: $(SRC_DIR)/gpio/GPIOMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/I2CMSPM0.o: $(SRC_DIR)/i2c/I2CMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/I2CTargetMSPM0.o: $(SRC_DIR)/i2ctarget/I2CTargetMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/UARTMSPM0.o: $(SRC_DIR)/uart/UARTMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/SPIMSPM0.o: $(SRC_DIR)/spi/SPIMSPM0.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).a > $(DEVNULL) 2>&1
