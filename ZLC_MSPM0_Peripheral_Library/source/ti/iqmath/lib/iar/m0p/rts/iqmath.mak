SDK_INSTALL_DIR ?= $(abspath ../../../../../../..)

include $(SDK_INSTALL_DIR)/imports.mak

CC  = "$(IAR_ARMCOMPILER)/bin/iccarm"
ASM = "$(IAR_ARMCOMPILER)/bin/iasmarm"
AR  = "$(IAR_ARMCOMPILER)/bin/iarchive"

NAME = rts/iqmath

OBJ_DIR = ../../../../obj/iar/m0p/rts/iqmath
SRC_DIR = ../../../../_IQNfunctions

CFLAGS = "-I$(IAR_ARMCOMPILER)/inc/c" "-I$(SDK_INSTALL_DIR)/source/third_party/CMSIS/Core/Include" "-I$(SDK_INSTALL_DIR)/source" --cpu Cortex-M0+ -D__MSPM0G3507__ --aeabi --guard_calls --endian=little --thumb --silent -e --use_unix_directory_separators --diag_suppress=Pa050,Go005 --debug -Ohs
AFLAGS = 
ASMFLAGS = "-I$(IAR_ARMCOMPILER)/inc/c" 

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
