SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC = "$(TICLANG_ARMCOMPILER)/bin/tiarmclang"
AR = "$(TICLANG_ARMCOMPILER)/bin/tiarmar"

NAME = vchop_intchop_n_int

OBJ_DIR = ../../../obj/ticlang/m0p/vchop_intchop_n_int
SRC_DIR = ../../../driver

CFLAGS = -I$(TICLANG_ARMCOMPILER)/include "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" -mcpu=cortex-m0plus -march=armv6-m -mtune=cortex-m0plus -mthumb -mfloat-abi=soft -Ofast -D__MSPM0L1306__ -DN_PULSE_INT -DVCHOP_INTCHOP -c -g -gdwarf-3
AFLAGS = rc
ASMFLAGS = -I$(TICLANG_ARMCOMPILER)/include 

OBJECTS = $(OBJ_DIR)/sasi_adc.o $(OBJ_DIR)/sasi_analog.o $(OBJ_DIR)/sasi_aq.o $(OBJ_DIR)/sasi_cal.o $(OBJ_DIR)/sasi_gpio.o $(OBJ_DIR)/sasi_hdc2010.o $(OBJ_DIR)/sasi_i2c.o $(OBJ_DIR)/sasi_power.o $(OBJ_DIR)/sasi_pwm.o $(OBJ_DIR)/sasi_rtc.o $(OBJ_DIR)/sasi_smoke_detection.o $(OBJ_DIR)/sasi_ssproc.o $(OBJ_DIR)/sasi_sysctl.o $(OBJ_DIR)/sasi_uart.o

all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@ echo Archiving $@
	@ $(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/sasi_adc.o: $(SRC_DIR)/sasi_adc.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_analog.o: $(SRC_DIR)/sasi_analog.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_aq.o: $(SRC_DIR)/sasi_aq.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_cal.o: $(SRC_DIR)/sasi_cal.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_gpio.o: $(SRC_DIR)/sasi_gpio.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_hdc2010.o: $(SRC_DIR)/sasi_hdc2010.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_i2c.o: $(SRC_DIR)/sasi_i2c.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_power.o: $(SRC_DIR)/sasi_power.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_pwm.o: $(SRC_DIR)/sasi_pwm.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_rtc.o: $(SRC_DIR)/sasi_rtc.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_smoke_detection.o: $(SRC_DIR)/sasi_smoke_detection.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_ssproc.o: $(SRC_DIR)/sasi_ssproc.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_sysctl.o: $(SRC_DIR)/sasi_sysctl.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/sasi_uart.o: $(SRC_DIR)/sasi_uart.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).a > $(DEVNULL) 2>&1
