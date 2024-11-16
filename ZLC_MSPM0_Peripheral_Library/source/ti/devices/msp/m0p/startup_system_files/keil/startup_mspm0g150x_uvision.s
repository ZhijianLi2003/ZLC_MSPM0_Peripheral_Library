;//*****************************************************************************
;//
;// Copyright (C) 2022 Texas Instruments Incorporated - http://www.ti.com/
;//
;// Redistribution and use in source and binary forms, with or without
;// modification, are permitted provided that the following conditions
;// are met:
;//
;//  Redistributions of source code must retain the above copyright
;//  notice, this list of conditions and the following disclaimer.
;//
;//  Redistributions in binary form must reproduce the above copyright
;//  notice, this list of conditions and the following disclaimer in the
;//  documentation and/or other materials provided with the
;//  distribution.
;//
;//  Neither the name of Texas Instruments Incorporated nor the names of
;//  its contributors may be used to endorse or promote products derived
;//  from this software without specific prior written permission.
;//
;// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
;// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
;// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
;// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
;// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;//
;// MSPM0G3507 startup file
;//
;//****************************************************************************
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/

; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000100

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     GROUP0_IRQHandler         ;  1:  GROUP0 interrupt handler
                DCD     GROUP1_IRQHandler         ;  2:  GROUP1 interrupt handler
                DCD     TIMG8_IRQHandler          ;  3:  TIMG8 interrupt handler
                DCD     UART3_IRQHandler          ;  4:  UART3 interrupt handler
                DCD     ADC0_IRQHandler           ;  5:  ADC0 interrupt handler
                DCD     ADC1_IRQHandler           ;  6:  ADC1 interrupt handler
                DCD     0                         ;  7:  Reserved
                DCD     DAC0_IRQHandler           ;  8:  DAC0 interrupt handler
                DCD     0                         ;  9:  Reserved
                DCD     SPI0_IRQHandler           ; 10:  SPI0 interrupt handler
                DCD     SPI1_IRQHandler           ; 11:  SPI1 interrupt handler
                DCD     0                         ; 12:  Reserved
                DCD     0                         ; 13:  Reserved
                DCD     UART1_IRQHandler          ; 14:  UART1 interrupt handler
                DCD     UART2_IRQHandler          ; 15:  UART2 interrupt handler
                DCD     UART0_IRQHandler          ; 16:  UART0 interrupt handler
                DCD     TIMG0_IRQHandler          ; 17:  TIMG0 interrupt handler
                DCD     TIMG6_IRQHandler          ; 18:  TIMG6 interrupt handler
                DCD     TIMA0_IRQHandler          ; 19:  TIMA0 interrupt handler
                DCD     TIMA1_IRQHandler          ; 20:  TIMA1 interrupt handler
                DCD     TIMG7_IRQHandler          ; 21:  TIMG7 interrupt handler
                DCD     TIMG12_IRQHandler         ; 22:  TIMG12 interrupt handler
                DCD     0                         ; 23:  Reserved
                DCD     0                         ; 24:  Reserved
                DCD     I2C0_IRQHandler           ; 25:  I2C0 interrupt handler
                DCD     I2C1_IRQHandler           ; 26:  I2C1 interrupt handler
                DCD     0                         ; 27:  Reserved
                DCD     0                         ; 28:  Reserved
                DCD     AES_IRQHandler            ; 29:  AES interrupt handler
                DCD     0                         ; 30:  Reserved
                DCD     RTC_IRQHandler            ; 31:  RTC interrupt handler
                DCD     DMA_IRQHandler            ; 32:  DMA interrupt handler

__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                ;IMPORT  SystemInit
                IMPORT  __main
				; SystemInit can be called here, but not necessary for MSPM0
                ;LDR     R0, =SystemInit
                ;BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  Default_Handler           [WEAK]
				EXPORT  GROUP0_IRQHandler         [WEAK]
                EXPORT  GROUP1_IRQHandler         [WEAK]
                EXPORT  TIMG8_IRQHandler          [WEAK]
                EXPORT  UART3_IRQHandler          [WEAK]
                EXPORT  ADC0_IRQHandler           [WEAK]
                EXPORT  ADC1_IRQHandler           [WEAK]
                EXPORT  DAC0_IRQHandler           [WEAK]
                EXPORT  SPI0_IRQHandler           [WEAK]
                EXPORT  SPI1_IRQHandler           [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
                EXPORT  UART2_IRQHandler          [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  TIMG0_IRQHandler          [WEAK]
                EXPORT  TIMG6_IRQHandler          [WEAK]
                EXPORT  TIMA0_IRQHandler          [WEAK]
                EXPORT  TIMA1_IRQHandler          [WEAK]
                EXPORT  TIMG7_IRQHandler          [WEAK]
                EXPORT  TIMG12_IRQHandler         [WEAK]
                EXPORT  I2C0_IRQHandler           [WEAK]
                EXPORT  I2C1_IRQHandler           [WEAK]
                EXPORT  AES_IRQHandler            [WEAK]
                EXPORT  RTC_IRQHandler            [WEAK]
                EXPORT  DMA_IRQHandler            [WEAK]

GROUP0_IRQHandler
GROUP1_IRQHandler
TIMG8_IRQHandler
UART3_IRQHandler
ADC0_IRQHandler
ADC1_IRQHandler
DAC0_IRQHandler
SPI0_IRQHandler
SPI1_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
UART0_IRQHandler
TIMG0_IRQHandler
TIMG6_IRQHandler
TIMA0_IRQHandler
TIMA1_IRQHandler
TIMG7_IRQHandler
TIMG12_IRQHandler
I2C0_IRQHandler
I2C1_IRQHandler
AES_IRQHandler
RTC_IRQHandler
DMA_IRQHandler
                B       .
                ENDP

                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
