SDK_INSTALL_DIR ?= $(abspath ../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
AR = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-ar"

NAME = gui_composer

OBJ_DIR = ../../../obj/gcc/m0p/gui_composer
SRC_DIR = ../../..

CFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" "-I$(SDK_INSTALL_DIR)/source" -mcpu=cortex-m0plus -march=armv6-m -mtune=cortex-m0plus -mthumb -mfloat-abi=soft -Wall -ffunction-sections -fdata-sections -std=c99 -c -g -gstrict-dwarf -O2
AFLAGS = -cr --target=elf32-little
ASMFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" 

OBJECTS = $(OBJ_DIR)/jsmn.o $(OBJ_DIR)/mpack.o

all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@ echo Archiving $@
	@ $(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/jsmn.o: $(SRC_DIR)/jsmn/jsmn.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/mpack.o: $(SRC_DIR)/mpack/mpack.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).a > $(DEVNULL) 2>&1
