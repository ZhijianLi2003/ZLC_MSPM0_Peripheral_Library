SDK_INSTALL_DIR ?= $(abspath ../../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-gcc"
AR = "$(GCC_ARMCOMPILER)/bin/arm-none-eabi-ar"

NAME = rts/iqmath

OBJ_DIR = ../../../../obj/gcc/m0p/rts/iqmath
SRC_DIR = ../../../../_IQNfunctions

CFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" -mcpu=cortex-m0plus -march=armv6-m -mtune=cortex-m0plus -mthumb -mfloat-abi=soft -D__MSPM0G3507__ -Wall -ffunction-sections -fdata-sections -std=c99 -c -g -gstrict-dwarf -O2
AFLAGS = -cr --target=elf32-little
ASMFLAGS = "-I$(GCC_ARMCOMPILER)/arm-none-eabi/include" 

OBJECTS = $(OBJ_DIR)/_IQNasin_acos.o $(OBJ_DIR)/_IQNatan2.o $(OBJ_DIR)/_IQNdiv.o $(OBJ_DIR)/_IQNexp.o $(OBJ_DIR)/_IQNfrac.o $(OBJ_DIR)/_IQNlog.o $(OBJ_DIR)/_IQNmpy.o $(OBJ_DIR)/_IQNmpyIQX.o $(OBJ_DIR)/_IQNrepeat.o $(OBJ_DIR)/_IQNrmpy.o $(OBJ_DIR)/_IQNrsmpy.o $(OBJ_DIR)/_IQNsin_cos.o $(OBJ_DIR)/_IQNsqrt.o $(OBJ_DIR)/_IQNtables.o $(OBJ_DIR)/_IQNtoF.o $(OBJ_DIR)/_IQNtoa.o $(OBJ_DIR)/_IQNversion.o $(OBJ_DIR)/_atoIQN.o

all: $(NAME).a

$(NAME).a: $(OBJECTS)
	@ echo Archiving $@
	@ $(AR) $(AFLAGS) $@ $^

$(OBJ_DIR)/_IQNasin_acos.o: $(SRC_DIR)/_IQNasin_acos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNatan2.o: $(SRC_DIR)/_IQNatan2.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNdiv.o: $(SRC_DIR)/_IQNdiv.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNexp.o: $(SRC_DIR)/_IQNexp.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNfrac.o: $(SRC_DIR)/_IQNfrac.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNlog.o: $(SRC_DIR)/_IQNlog.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNmpy.o: $(SRC_DIR)/_IQNmpy.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNmpyIQX.o: $(SRC_DIR)/_IQNmpyIQX.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNrepeat.o: $(SRC_DIR)/_IQNrepeat.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNrmpy.o: $(SRC_DIR)/_IQNrmpy.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNrsmpy.o: $(SRC_DIR)/_IQNrsmpy.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNsin_cos.o: $(SRC_DIR)/_IQNsin_cos.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNsqrt.o: $(SRC_DIR)/_IQNsqrt.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNtables.o: $(SRC_DIR)/_IQNtables.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNtoF.o: $(SRC_DIR)/_IQNtoF.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNtoa.o: $(SRC_DIR)/_IQNtoa.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_IQNversion.o: $(SRC_DIR)/_IQNversion.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/_atoIQN.o: $(SRC_DIR)/_atoIQN.c
	@ echo Building $@
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $< -o $@

clean:
	@ echo Cleaning...
	@ $(RM) $(OBJECTS) > $(DEVNULL) 2>&1
	@ $(RM) $(NAME).a > $(DEVNULL) 2>&1
