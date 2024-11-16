/*
 * Copyright (c) 2020, Texas Instruments Incorporated
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
 *  @file       dl_crc.h
 *  @brief      Cyclic Redundancy Check (CRC) Driver Library
 *  @defgroup   CRC Cyclic Redundancy Check (CRC)
 *
 *  @anchor ti_dl_dl_crc_Overview
 *  # Overview
 *
 *  The CRC DriverLib allows full configuration of the MSPM0 CRC module.
 *  The cyclic redundancy check (CRC) accelerator generates signatures for a
 *  given data sequence based on the CRC16-CCITT polynomial or the
 *  CRC32-ISO3309 polynomial.
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup CRC
 * @{
 */
#ifndef ti_dl_dl_crc__include
#define ti_dl_dl_crc__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_CRC__

#ifdef __cplusplus
extern "C" {
#endif

#if (CRC_SYS_CRC32_ENABLE == 1)
/*!
 * @brief Device has support for CRC 32-bit polynomials
 */
#define DEVICE_HAS_CRC_32_BIT_POLYNOMIAL
#endif

/*! @enum DL_CRC_POLYNOMIAL */
typedef enum {
    /*! Use 16-bit polynomial for calculation. Follows CRC-16-CCITT standard
     * with a polynomial value of 0x1021. */
    DL_CRC_16_POLYNOMIAL = CRC_CRCCTRL_POLYSIZE_CRC16,
#ifdef DEVICE_HAS_CRC_32_BIT_POLYNOMIAL
    /*! Use 32-bit polynomial for calculation. Follows CRC32-ISO3309 standard
     * with a polynomial value of 0x04C11DB7.*/
    DL_CRC_32_POLYNOMIAL = CRC_CRCCTRL_POLYSIZE_CRC32
#endif /* DEVICE_HAS_CRC_32_BIT_POLYNOMIAL */
} DL_CRC_POLYNOMIAL;

/*! @enum DL_CRC_BIT */
typedef enum {
    /*! CRC Bit Input and output are reversed */
    DL_CRC_BIT_REVERSED = CRC_CRCCTRL_BITREVERSE_REVERSED,
    /*! CRC Bit Input and output are not reversed */
    DL_CRC_BIT_NOT_REVERSED = CRC_CRCCTRL_BITREVERSE_NOT_REVERSED
} DL_CRC_BIT;

/*! @enum DL_CRC_INPUT_ENDIANESS */
typedef enum {
    /*! CRC Input is proccessed in little endian.
     *  LSB is lowest memory address and first to be processed. */
    DL_CRC_INPUT_ENDIANESS_LITTLE_ENDIAN =
        CRC_CRCCTRL_INPUT_ENDIANNESS_LITTLE_ENDIAN,
    /*! CRC Input is proccessed in big endian.
     *  LSB is highest memory address and last to be processed. */
    DL_CRC_INPUT_ENDIANESS_BIG_ENDIAN = CRC_CRCCTRL_INPUT_ENDIANNESS_BIG_ENDIAN
} DL_CRC_INPUT_ENDIANESS;

/*! @enum DL_CRC_OUTPUT_BYTESWAP */
typedef enum {
    /*! CRC output byteswap is enabled */
    DL_CRC_OUTPUT_BYTESWAP_ENABLED = CRC_CRCCTRL_OUTPUT_BYTESWAP_ENABLE,
    /*! CRC output byteswap is disabled */
    DL_CRC_OUTPUT_BYTESWAP_DISABLED = CRC_CRCCTRL_OUTPUT_BYTESWAP_DISABLE
} DL_CRC_OUTPUT_BYTESWAP;

/**
 * @brief Enables power on crc module
 *
 * @param crc        Pointer to the register overlay for the CRC peripheral
 */
__STATIC_INLINE void DL_CRC_enablePower(CRC_Regs *crc)
{
    crc->GPRCM.PWREN = (CRC_PWREN_KEY_UNLOCK_W | CRC_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on crc module
 *
 * @param crc        Pointer to the register overlay for the CRC peripheral
 */
__STATIC_INLINE void DL_CRC_disablePower(CRC_Regs *crc)
{
    crc->GPRCM.PWREN = (CRC_PWREN_KEY_UNLOCK_W | CRC_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if power on crc module is enabled
 *
 * @param crc        Pointer to the register overlay for the CRC peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 *
 */
__STATIC_INLINE bool DL_CRC_isPowerEnabled(CRC_Regs *crc)
{
    return (
        (crc->GPRCM.PWREN & CRC_PWREN_ENABLE_MASK) == CRC_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets crc peripheral
 *
 * @param crc        Pointer to the register overlay for the CRC peripheral
 */
__STATIC_INLINE void DL_CRC_reset(CRC_Regs *crc)
{
    crc->GPRCM.RSTCTL =
        (CRC_RSTCTL_KEY_UNLOCK_W | CRC_RSTCTL_RESETSTKYCLR_CLR |
            CRC_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if crc module has been reset
 *
 * @param crc        Pointer to the register overlay for the CRC peripheral\
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_CRC_isReset(CRC_Regs *crc)
{
    return ((crc->GPRCM.STAT & CRC_STAT_RESETSTKY_MASK) ==
            CRC_STAT_RESETSTKY_RESET);
}

/**
 * @brief Initializes CRC
 *
 * @param crc          Pointer to the register overlay for the CRC peripheral
 * @param poly         Selects CRC polynomial. One of @ref DL_CRC_POLYNOMIAL.
 * @param bitOrd       Selects CRC bit order. One of @ref DL_CRC_BIT.
 * @param inEndianness Selects CRC input endianess. One of
 *                     @ref DL_CRC_INPUT_ENDIANESS.
 * @param outByteSwap  Selects CRC output byte swap mode. One of
 *                     @ref DL_CRC_OUTPUT_BYTESWAP.
 *
 */
__STATIC_INLINE void DL_CRC_init(CRC_Regs *crc, DL_CRC_POLYNOMIAL poly,
    DL_CRC_BIT bitOrd, DL_CRC_INPUT_ENDIANESS inEndianness,
    DL_CRC_OUTPUT_BYTESWAP outByteSwap)
{
    crc->CRCCTRL = ((uint32_t) poly | (uint32_t) bitOrd |
                    (uint32_t) inEndianness | (uint32_t) outByteSwap);
}

/*!
 *  @brief      Initializes the seed for a 16-bit polynomial CRC calculation
 *  @note       CRC seed is swapped when CRC module is configured in big-endian
 *              mode. For example when calling DL_CRC_setSeed32(CRC, 0xaabb).
 *              The CRC module will be initialized with 0xbbaa. Therefore, the
 *              seed value should be appropriately specified taking endianness
 *              into account. Please refer to the device TRM for additional
 *              detail.
 *
 *  @param[in]  crc    Pointer to the register overlay for the CRC peripheral
 *  @param[in]  seed   The seed for the CRC to start generating a signature from
 */
__STATIC_INLINE void DL_CRC_setSeed16(CRC_Regs *crc, uint16_t seed)
{
    volatile uintptr_t addr;
    volatile uint16_t *pRef;

    addr = (uintptr_t)((volatile uintptr_t *) &crc->CRCSEED);
    pRef = (volatile uint16_t *) addr;

    *pRef = seed;
}

/*!
 *  @brief    Initializes the seed for a 32-bit polynomial CRC calculation
 *  @note     CRC seed is swapped when CRC module is configured in big-endian
 *            mode. For example when calling DL_CRC_setSeed32(CRC, 0xaabbccdd).
 *            The CRC module will be initialized with 0xddccbbaa. Therefore, the
 *            seed value should be appropriately specified taking endianness
 *            into account. Please refer to the device TRM for additional
 *            detail.
 *
 *  @param[in]  crc    Pointer to the register overlay for the CRC peripheral
 *  @param[in]  seed   The seed for the CRC to start generating a signature from
 */
__STATIC_INLINE void DL_CRC_setSeed32(CRC_Regs *crc, uint32_t seed)
{
    crc->CRCSEED = seed;
}

/*!
 *  @brief      Feeds 8-bit data into the CRC calculation
 *
 *  @param[in]  crc         Pointer to the register overlay for the CRC
 *                          peripheral
 *  @param[in]  dataIn      8-bit data value to add to the signature
 *
 */
__STATIC_INLINE void DL_CRC_feedData8(CRC_Regs *crc, uint8_t dataIn)
{
    volatile uint8_t *pRef = (volatile uint8_t *) &crc->CRCIN;
    *pRef                  = dataIn;
}

/*!
 *  @brief      Feeds 16-bit data into the CRC calculation
 *
 *  @param[in]  crc         Pointer to the register overlay for the CRC
 *                          peripheral
 *  @param[in]  dataIn      16-bit data value to add to the signature
 *
 */
__STATIC_INLINE void DL_CRC_feedData16(CRC_Regs *crc, uint16_t dataIn)
{
    volatile uintptr_t addr;
    volatile uint16_t *pRef;

    addr = (uintptr_t)((volatile uintptr_t *) &crc->CRCIN);
    pRef = (volatile uint16_t *) addr;

    *pRef = dataIn;
}

/*!
 *  @brief      Feeds 32-bit data into the CRC calculation
 *
 *  Feeds a 32-bit value into the CRC calculation. 32-bit data can only be used
 *  with the 32-bit polynomial.
 *
 *  @param[in]  crc         Pointer to the register overlay for the CRC
 *                          peripheral
 *  @param[in]  dataIn      32 bit data value to add to the signature
 *
 */
__STATIC_INLINE void DL_CRC_feedData32(CRC_Regs *crc, uint32_t dataIn)
{
    crc->CRCIN = dataIn;
}

/*!
 *  @brief      Returns the result from the 16-bit polynomial calculation
 *
 *  @param[in]  crc  Pointer to the register overlay for the CRC peripheral
 *
 *  @return     The calculation result for the 16-bit polynomial
 */
__STATIC_INLINE uint16_t DL_CRC_getResult16(CRC_Regs *crc)
{
    return ((uint16_t) crc->CRCOUT);
}

/*!
 *  @brief      Returns the result from the 32-bit polynomial calculation
 *
 *  @param[in]  crc  Pointer to the register overlay for the CRC peripheral
 *
 *  @return     The calculation result for the 32-bit polynomial
 */
__STATIC_INLINE uint32_t DL_CRC_getResult32(CRC_Regs *crc)
{
    return (crc->CRCOUT);
}

/*!
 *  @brief      Calculates the CRC over a range of 32-bit values
 *
 *  Uses the 32-bit polynomial to calculate the checksum over a block of
 *  values.
 *
 *  @param[in]  crc   Pointer to the register overlay for the CRC peripheral
 *  @param[in]  seed  The seed for the CRC to start generating a signature from
 *  @param[in]  ptr   A pointer to the block of code to calculate the CRC over
 *  @param[in]  size  The size of the block of uint32_t data
 *
 *  @return     The calculated CRC signature value
 */
extern uint32_t DL_CRC_calculateBlock32(
    CRC_Regs *crc, uint32_t seed, uint32_t *ptr, uint32_t size);

/*!
 *  @brief      Calculates the CRC over a memory range
 *
 *  Calculates the checksum using the 32-bit polynomial over any memory range.
 *
 *  @param[in]  crc       Pointer to the register overlay for the CRC
 *                        peripheral
 *  @param[in]  seed      The seed used to start generating a signature from
 *  @param[in]  ptrStart  A uint32_t pointer to the start of a block of code to
 *                        calculate the CRC over
 *  @param[in]  ptrEnd    A uint32_t pointer to the end of a block of code to
 *                        calculate the CRC over
 *
 *  @return     The calculated CRC signature value
 */
extern uint32_t DL_CRC_calculateMemoryRange32(
    CRC_Regs *crc, uint32_t seed, uint32_t *ptrStart, uint32_t *ptrEnd);

/*!
 *  @brief      Calculates the CRC over a range of 16-bit values
 *
 *  Uses the 16-bit polynomial to calculate the checksum over a block of
 *  values.
 *
 *  @param[in]  crc   Pointer to the register overlay for the CRC peripheral
 *  @param[in]  seed  The seed for the CRC to start generating a signature from
 *  @param[in]  ptr   A pointer to the block of code to calculate the CRC over
 *  @param[in]  size  The size of the block of 16-bit data
 *
 *  @return     The calculated CRC signature value
 */
extern uint16_t DL_CRC_calculateBlock16(
    CRC_Regs *crc, uint16_t seed, uint16_t *ptr, uint16_t size);

/*!
 *  @brief      Calculates the CRC over a memory range
 *
 *  Calculates the checksum using the 16-bit polynomial over any memory range.
 *
 *  @param[in]  crc       Pointer to the register overlay for the CRC
 *                        peripheral
 *  @param[in]  seed      The seed used to start generating a signature from
 *  @param[in]  ptrStart  A uint16_t pointer to the start of a block of code to
 *                        calculate the CRC over
 *  @param[in]  ptrEnd    A uint16_t pointer to the end of a block of code to
 *                        calculate the CRC over
 *
 *  @return     The calculated CRC signature value
 */
extern uint16_t DL_CRC_calculateMemoryRange16(
    CRC_Regs *crc, uint16_t seed, uint16_t *ptrStart, uint16_t *ptrEnd);

/**
 *  @brief Returns the address of the CRC input data register.
 *
 *  This API can be used with @ref DL_DMA_setDestAddr to set the destination
 *  address when using DMA transfers
 *
 *  @param[in]  crc       Pointer to the register overlay for the CRC
 *                        peripheral
 *  @return Address of the CRC input data register
 */
__STATIC_INLINE uintptr_t DL_CRC_getCRCINAddr(CRC_Regs *crc)
{
    return ((uintptr_t) &crc->CRCIN);
}
#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_CRC__ */

#endif /* ti_dl_dl_crc__include */
/** @}*/
