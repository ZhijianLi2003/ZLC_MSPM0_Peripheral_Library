/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size  = 0;      /* required amount of heap  */
_Min_Stack_Size = 0x80; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
    FLASH           (RX)  : ORIGIN = 0x00000000, LENGTH = 0x00002000
    SRAM            (RWX) : ORIGIN = 0x20000000, LENGTH = 0x00000400
    BCR_CONFIG      (R)   : ORIGIN = 0x41C00000, LENGTH = 0x00000080
}

/* Note: SRAM length must match MPPC/MEMSS config! Please edit it manually. */

REGION_ALIAS("REGION_TEXT", FLASH);
REGION_ALIAS("REGION_PREINIT_ARRAY", FLASH);
REGION_ALIAS("REGION_INIT_ARRAY", FLASH);
REGION_ALIAS("REGION_FINI_ARRAY", FLASH);
REGION_ALIAS("REGION_BSS", SRAM);
REGION_ALIAS("REGION_NOINIT", SRAM);
REGION_ALIAS("REGION_DATA", SRAM);
REGION_ALIAS("REGION_STACK", SRAM);
REGION_ALIAS("REGION_HEAP", SRAM);
REGION_ALIAS("REGION_TEXT_RAM", SRAM);
REGION_ALIAS("REGION_ARM_EXIDX", FLASH);
REGION_ALIAS("REGION_ARM_EXTAB", FLASH);

/* Define output sections */
SECTIONS
{
    /* section for the interrupt vector area                                 */
    PROVIDE (_intvecs_base_address =
        DEFINED(_intvecs_base_address) ? _intvecs_base_address : 0x00000000);

    .intvecs (_intvecs_base_address) : AT (_intvecs_base_address) {
        KEEP (*(.intvecs))
    } > REGION_TEXT

    PROVIDE (_vtable_base_address =
        DEFINED(_vtable_base_address) ? _vtable_base_address : 0x20000000);

    .vtable (_vtable_base_address) (NOLOAD) : AT (_vtable_base_address) {
        KEEP (*(.vtable))
    } > REGION_DATA

   .text : {
        CREATE_OBJECT_SYMBOLS
        KEEP (*(.text))
        . = ALIGN(0x8);
        *(.text.*)
        . = ALIGN(0x8);
        KEEP (*(.ctors))
        . = ALIGN(0x8);
        KEEP (*(.dtors))
        . = ALIGN(0x8);
        KEEP (*(.init))
        . = ALIGN(0x8);
        KEEP (*(.fini*))
        . = ALIGN(0x8);
    } > REGION_TEXT AT> REGION_TEXT

    .ramfunc : {
        __ramfunct_load__ = LOADADDR (.ramfunc);
        __ramfunct_start__ = .;
       *(.ramfunc)
       . = ALIGN(0x8);
       __ramfunct_end__ = .;
    } > REGION_TEXT_RAM AT> REGION_TEXT

    .rodata : {
        *(.rodata)
        . = ALIGN(0x8);
        *(.rodata.*)
        . = ALIGN(0x8);
    } > REGION_TEXT AT> REGION_TEXT

    .preinit_array : {
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*));
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } > REGION_PREINIT_ARRAY AT> REGION_TEXT

    .init_array : {
        . = ALIGN(0x8);
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > REGION_INIT_ARRAY AT> REGION_TEXT

    .fini_array : {
        . = ALIGN(0x8);
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        PROVIDE_HIDDEN (__fini_array_end = .);
    	. = ALIGN(0x8);
    } > REGION_FINI_ARRAY AT> REGION_TEXT

    .ARM.exidx : {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > REGION_ARM_EXIDX AT> REGION_ARM_EXIDX

    .ARM.extab : {
        . = ALIGN(0x8);
        KEEP (*(.ARM.extab* .gnu.linkonce.armextab.*))
         . = ALIGN(0x8);
    } > REGION_ARM_EXTAB AT> REGION_ARM_EXTAB

    __etext = .;

    .data : {
        __data_load__ = LOADADDR (.data);
        __data_start__ = .;
        KEEP (*(.data))
        KEEP (*(.data*))
        . = ALIGN (8);
        __data_end__ = .;
    } > REGION_DATA AT> REGION_TEXT

    .bss : {
        __bss_start__ = .;
        *(.shbss)
        KEEP (*(.bss))
        *(.bss.*)
        *(COMMON)
        . = ALIGN (8);
        __bss_end__ = .;
    } > REGION_BSS AT> REGION_BSS

    .noinit : {
        /* place all symbols in input sections that start with .noinit */
        KEEP(*(*.noinit*))
        . = ALIGN (8);
    } > REGION_NOINIT AT> REGION_NOINIT

    .heap : {
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        KEEP (*(.heap))
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > REGION_HEAP AT> REGION_HEAP

    .stack (NOLOAD) : ALIGN(0x8) {
        _stack = .;
        KEEP(*(.stack))
    } > REGION_STACK AT> REGION_STACK

    .BCRConfig :
    {
        KEEP(*(.BCRConfig))
    } > BCR_CONFIG

    __StackTop = ORIGIN(REGION_STACK) + LENGTH(REGION_STACK);
    PROVIDE(__stack = __StackTop);
}