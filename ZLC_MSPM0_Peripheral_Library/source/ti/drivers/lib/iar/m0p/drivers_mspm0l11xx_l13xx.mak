SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC  = "$(IAR_ARMCOMPILER)/bin/iccarm"
ASM = "$(IAR_ARMCOMPILER)/bin/iasmarm"
AR  = "$(IAR_ARMCOMPILER)/bin/iarchive"

NAME = drivers_mspm0l11xx_l13xx

OBJ_DIR = ../../../obj/iar/m0p/drivers_mspm0l11xx_l13xx
SRC_DIR = ../../..

CFLAGS = "-I$(IAR_ARMCOMPILER)/inc/c" "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" --cpu Cortex-M0+ -DDeviceFamily_MSPM0L130X -DUART_NO_DMA --aeabi --guard_calls --endian=little --thumb --silent -e --use_unix_directory_separators --diag_suppress=Pa050,Go005 --debug -Ohs
AFLAGS = 
ASMFLAGS = "-I$(IAR_ARMCOMPILER)/inc/c" 

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
