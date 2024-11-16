/*
 * Copyright (c) 2023, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!****************************************************************************
 *  @file       dl_scratchpad.h
 *  @brief      Scratchpad Memory Driver Library
 *  @defgroup   Scratchpad Memory
 *
 *  @anchor ti_dl_dl_scratchpad_Overview
 *  # Overview
 *
 *  The Scratchpad Memory Library allows full configuration of
 *  the MSPM0 Scratchpad Memory within the LFSS IP.
 *
 *  The LFSS scratch pad memory is a 16- to 128-byte register based memory,
 *  which will retain data similar to a non-volatile memory as long as VBAT is
 *  supplied. The number of implemented bytes shall be configurable in a granularity
 *  of 4 bytes. This means the scratch pad memory retains data when the main VDD supply
 *  is lost or during the SHUTDOWN mode. However, the memory content won’t be retained,
 *  when the VBAT domain itself is lost.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup Scratchpad Memory
 * @{
 */
#ifndef ti_dl_dl_scratchpad__include
#define ti_dl_dl_scratchpad__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/driverlib/dl_lfss.h>

#ifdef __MSPM0_HAS_SCRATCHPAD__

#ifdef __cplusplus
extern "C" {
#endif

/* clang-format off */

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_0
 */
#define DL_SCRATCHPAD_MEM_WORD_0                            DL_LFSS_SCRATCHPAD_MEM_WORD_0

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_1
 */
#define DL_SCRATCHPAD_MEM_WORD_1                            DL_LFSS_SCRATCHPAD_MEM_WORD_1

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_1
 */
#define DL_SCRATCHPAD_MEM_WORD_1                            DL_LFSS_SCRATCHPAD_MEM_WORD_1

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_2
 */
#define DL_SCRATCHPAD_MEM_WORD_2                            DL_LFSS_SCRATCHPAD_MEM_WORD_2

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_3
 */
#define DL_SCRATCHPAD_MEM_WORD_3                            DL_LFSS_SCRATCHPAD_MEM_WORD_3

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_4
 */
#define DL_SCRATCHPAD_MEM_WORD_4                            DL_LFSS_SCRATCHPAD_MEM_WORD_4

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_5
 */
#define DL_SCRATCHPAD_MEM_WORD_5                            DL_LFSS_SCRATCHPAD_MEM_WORD_5

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_6
 */
#define DL_SCRATCHPAD_MEM_WORD_6                            DL_LFSS_SCRATCHPAD_MEM_WORD_6

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_7
 */
#define DL_SCRATCHPAD_MEM_WORD_7                            DL_LFSS_SCRATCHPAD_MEM_WORD_7

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_BYTE_0
 */
#define DL_SCRATCHPAD_MEM_BYTE_0                            DL_LFSS_SCRATCHPAD_MEM_BYTE_0

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_BYTE_1
 */
#define DL_SCRATCHPAD_MEM_BYTE_1                            DL_LFSS_SCRATCHPAD_MEM_BYTE_1

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_BYTE_2
 */
#define DL_SCRATCHPAD_MEM_BYTE_2                            DL_LFSS_SCRATCHPAD_MEM_BYTE_2

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_WORD_2
 */
#define DL_SCRATCHPAD_MEM_WORD_2                            DL_LFSS_SCRATCHPAD_MEM_WORD_2

/*!
 * @brief Redirects to common @ref DL_LFSS_SCRATCHPAD_MEM_BYTE_3
 */
#define DL_SCRATCHPAD_MEM_BYTE_3                            DL_LFSS_SCRATCHPAD_MEM_BYTE_3

/*!
 * @brief Redirects to common @ref DL_LFSS_writeScratchPadData32
 */
#define DL_ScratchPad_writeDataWord(lfss, memIndex, data)              DL_LFSS_writeScratchPadData32(lfss,    \
                                                                      (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,  \
                                                                                                      data)

/*!
 * @brief Redirects to common @ref DL_LFSS_writeScratchPadData8
 */
#define DL_ScratchPad_writeDataByte(lfss, memIndex, byteIndex, data)   DL_LFSS_writeScratchPadData8(lfss,     \
                                                                      (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,  \
                                                                      (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex, \
                                                                                                      data)

/*!
 * @brief Redirects to common @ref DL_LFSS_readScratchPadDataWord
 */
#define DL_ScratchPad_readDataWord(lfss, memIndex)                      DL_LFSS_readScratchPadDataWord(lfss,  \
                                                                       (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex)

/*!
 * @brief Redirects to common @ref DL_LFSS_readScratchPadDataByte
 */
#define DL_ScratchPad_readDataByte(lfss, memIndex, byteIndex)          DL_LFSS_readScratchPadDataByte(lfss,  \
                                                                      (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex, \
                                                                      (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)

/*!
 * @brief Redirects to common @ref DL_LFSS_enableScratchPadWriteProtectByte
 */
#define DL_ScratchPad_enableWriteProtectByte(lfss, memIndex, byteIndex)                    DL_LFSS_enableScratchPadWriteProtectByte(lfss, \
                                                                                          (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,          \
                                                                                          (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)

/*!
 * @brief Redirects to common @ref DL_LFSS_isScratchPadWriteProtectByteEnabled
 */
#define DL_ScratchPad_isWriteProtectByteEnabled(lfss, memIndex, byteIndex)                 DL_LFSS_isScratchPadWriteProtectByteEnabled(lfss, \
                                                                                          (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,             \
                                                                                          (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)


/*!
 * @brief Redirects to common @ref DL_LFSS_disableScratchPadWriteProtectByte
 */
#define DL_ScratchPad_disableWriteProtectByte(lfss, memIndex, byteIndex)                    DL_LFSS_disableScratchPadWriteProtectByte(lfss,  \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,            \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)

/*!
 * @brief Redirects to common @ref DL_LFSS_enableScratchPadTamperEraseByte
 */
#define DL_ScratchPad_enableTamperEraseByte(lfss, memIndex, byteIndex)                      DL_LFSS_enableScratchPadTamperEraseByte(lfss, \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,         \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)


/*!
 * @brief Redirects to common @ref DL_LFSS_isScratchPadTamperEraseByteEnabled
 */
#define DL_ScratchPad_isTamperEraseByteEnabled(lfss, memIndex, byteIndex)                   DL_LFSS_isScratchPadTamperEraseByteEnabled(lfss, \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,            \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)


/*!
 * @brief Redirects to common @ref DL_LFSS_disableScratchPadTamperEraseByte
 */
#define DL_ScratchPad_disableTamperEraseByte(lfss, memIndex, byteIndex)                     DL_LFSS_disableScratchPadTamperEraseByte(lfss, \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_WORD)memIndex,         \
                                                                                           (DL_LFSS_SCRATCHPAD_MEM_BYTE)byteIndex)

/* clang-format on */

#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_SCRATCHPAD__ */

#endif /* ti_dl_dl_scratchpad__include */
/** @}*/
