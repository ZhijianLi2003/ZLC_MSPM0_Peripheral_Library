/*****************************************************************************

  Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

   Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the
   distribution.

   Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*****************************************************************************/

#include <stdint.h>
#include <ti/devices/msp/msp.h>

/* Linker variable that marks the top of the stack. */
extern unsigned long __STACK_END;

/* External declaration for the reset handler that is to be called when the */
/* processor is started                                                     */
extern __NO_RETURN void __PROGRAM_START(void);

/* Forward declaration of the default fault handlers. */
void Default_Handler(void) __attribute__((weak));
extern void Reset_Handler(void) __attribute__((weak));

/* Processor Exceptions */
extern void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern void HardFault_Handler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern void PendSV_Handler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void SysTick_Handler(void)
    __attribute__((weak, alias("Default_Handler")));

/* Device Specific Interrupt Handlers */
extern void GROUP0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void GROUP1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMG12_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void UART4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void ADC0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void SPI0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void SPI1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void SPI2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void UART2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void UART3_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void UART0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void UART1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMA0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMA1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMG8_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMG0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMG4_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void TIMG5_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void I2C0_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void I2C1_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void I2C2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void AESADV_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void LFSS_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
extern void DMA_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));

/* Interrupt vector table.  Note that the proper constructs must be placed on this to */
/* ensure that it ends up at physical address 0x0000.0000 or at the start of          */
/* the program if located at a start address other than 0.                            */
#if defined(__ARM_ARCH) && (__ARM_ARCH != 0)
void (*const interruptVectors[])(void) __attribute((used))
__attribute__((section(".intvecs"))) =
#elif defined(__TI_ARM__)
#pragma RETAIN(interruptVectors)
#pragma DATA_SECTION(interruptVectors, ".intvecs")
void (*const interruptVectors[])(void) =
#else
#error "Compiler not supported"
#endif
    {
        (void (*)(void))((uint32_t) &__STACK_END),
        /* The initial stack pointer */
        Reset_Handler,       /* The reset handler         */
        NMI_Handler,         /* The NMI handler           */
        HardFault_Handler,   /* The hard fault handler    */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        SVC_Handler,         /* SVCall handler            */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        PendSV_Handler,      /* The PendSV handler        */
        SysTick_Handler,     /* SysTick handler           */
        GROUP0_IRQHandler,   /* GROUP0 interrupt handler  */
        GROUP1_IRQHandler,   /* GROUP1 interrupt handler  */
        TIMG12_IRQHandler,   /* TIMG12 interrupt handler  */
        UART4_IRQHandler,    /* UART4 interrupt handler   */
        ADC0_IRQHandler,     /* ADC0 interrupt handler    */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        0,                   /* Reserved                  */
        SPI0_IRQHandler,     /* SPI0 interrupt handler    */
        SPI1_IRQHandler,     /* SPI1 interrupt handler    */
        SPI2_IRQHandler,     /* SPI1 interrupt handler    */
        0,                   /* Reserved                  */
        UART2_IRQHandler,    /* UART2 interrupt handler   */
        UART3_IRQHandler,    /* UART3 interrupt handler   */
        UART0_IRQHandler,    /* UART0 interrupt handler   */
        UART1_IRQHandler,    /* UART1 interrupt handler   */
        0,                   /* Reserved                  */
        TIMA0_IRQHandler,    /* TIMA0 interrupt handler   */
        TIMA1_IRQHandler,    /* TIMA1 interrupt handler   */
        TIMG8_IRQHandler,    /* TIMG8 interrupt handler   */
        TIMG0_IRQHandler,    /* TIMG0 interrupt handler   */
        TIMG4_IRQHandler,    /* TIMG4 interrupt handler   */
        TIMG5_IRQHandler,    /* TIMG5 interrupt handler   */
        I2C0_IRQHandler,     /* I2C0 interrupt handler    */
        I2C1_IRQHandler,     /* I2C1 interrupt handler    */
        I2C2_IRQHandler,     /* I2C2 interrupt handler    */
        0,                   /* Reserved                  */
        AESADV_IRQHandler,   /* AESADV interrupt handler*/
        0,                   /* Reserved                  */
        LFSS_IRQHandler,     /* LFSS interrupt handler    */
        DMA_IRQHandler       /* DMA interrupt handler     */
    };

/* Forward declaration of the default fault handlers. */
/* This is the code that gets called when the processor first starts execution */
/* following a reset event.  Only the absolutely necessary set is performed,   */
/* after which the application supplied entry() routine is called.  Any fancy  */
/* actions (such as making decisions based on the reset cause register, and    */
/* resetting the bits in that register) are left solely in the hands of the    */
/* application.                                                                */
void Reset_Handler(void)
{
    /* Jump to the ticlang C Initialization Routine. */
    __asm(
        "    .global _c_int00\n"
        "    b       _c_int00");
}

/* This is the code that gets called when the processor receives an unexpected  */
/* interrupt.  This simply enters an infinite loop, preserving the system state */
/* for examination by a debugger.                                               */
void Default_Handler(void)
{
    /* Enter an infinite loop. */
    while (1) {
    }
}
