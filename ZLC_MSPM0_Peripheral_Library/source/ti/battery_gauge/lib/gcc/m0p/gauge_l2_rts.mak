SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
AR = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-ar"

NAME = gauge_l2_rts

OBJ_DIR = ../../../obj/gcc/m0p/gauge_l2_rts
SRC_DIR = ../../../gauge_level2

CFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" -mcpu=cortex-m0plus -march=armv6-m -mtune=cortex-m0plus -mthumb -mfloat-abi=soft -Wall -ffunction-sections -fdata-sections -std=c99 -c -g -gstrict-dwarf -O2
AFLAGS = -cr --target=elf32-little
ASMFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" 

OBJECTS = $(OBJ_DIR)/CapacityLearn.o $(OBJ_DIR)/CurtGauge.o $(OBJ_DIR)/Mixing.o $(OBJ_DIR)/VoltGauge.o

all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@ echo Archiving $@
	@ $(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/CapacityLearn.o: $(SRC_DIR)/CapacityLearn.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/CurtGauge.o: $(SRC_DIR)/CurtGauge.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/Mixing.o: $(SRC_DIR)/Mixing.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/VoltGauge.o: $(SRC_DIR)/VoltGauge.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).a > $(DEVNULL) 2>&1
