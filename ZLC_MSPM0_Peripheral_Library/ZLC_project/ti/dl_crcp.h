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
 *  @file       dl_crcp.h
 *  @brief      Cyclic Redundancy Check with Configurable Polynomial (CRCP) Driver Library
 *  @defgroup   CRCP Cyclic Redundancy Check with Configurable Polynomial (CRCP)
 *
 *  @anchor ti_dl_dl_crcp_Overview
 *  # Overview
 *
 *  The CRCP DriverLib allows full configuration of the MSPM0 CRCP module.
 *  The cyclic redundancy check (CRC) accelerator generates signatures for a
 *  given data sequence based on a user-configured polynomial, allowing for
 *  support of any 16-bit or 32-bit polynomial including but not limited to:
 *      * CRC32-IS03309
 *      * CRC16-ITT
 *      * CRC-32C
 *      * CRC-32K
 *      * CRC-16-Profibus
 *
 *  <hr>
 ******************************************************************************
 */
/** @addtogroup CRCP
 * @{
 */
#ifndef ti_dl_dl_crcp__include
#define ti_dl_dl_crcp__include

#include <stdbool.h>
#include <stdint.h>

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/dl_common.h>

#ifdef __MSPM0_HAS_CRCP__

#ifdef __cplusplus
extern "C" {
#endif

/*! @enum DL_CRCP_POLYNOMIAL_SIZE */
typedef enum {
    /*! Use lower 16-bit value of CRCPOLY as polynomial for calculation.
     * Upon reset, user will need to update polynomial value for 16-bits,
     * such as the CRC-16-CCITT standard of 0x1021. */
    DL_CRCP_POLYNOMIAL_SIZE_16 = CRCP_CRCCTRL_POLYSIZE_CRC16,
    /*! Use 32-bit polynomial value of CRCPOLY as polynomial for calculation.
     * Defaults to the CRC32-ISO3309 standard value of 0x04C11DB7. */
    DL_CRCP_POLYNOMIAL_SIZE_32 = CRCP_CRCCTRL_POLYSIZE_CRC32
} DL_CRCP_POLYNOMIAL_SIZE;

/*! @enum DL_CRCP_BIT */
typedef enum {
    /*! CRCP Bit Input and output bit orders are reversed */
    DL_CRCP_BIT_REVERSED = CRCP_CRCCTRL_BITREVERSE_REVERSED,
    /*! CRCP Bit Input and output are not reversed */
    DL_CRCP_BIT_NOT_REVERSED = CRCP_CRCCTRL_BITREVERSE_NOT_REVERSED
} DL_CRCP_BIT;

/*! @enum DL_CRCP_INPUT_ENDIANESS */
typedef enum {
    /*! CRCP Input is proccessed in little endian.
     *  LSB is lowest memory address and first to be processed. */
    DL_CRCP_INPUT_ENDIANESS_LITTLE_ENDIAN =
        CRCP_CRCCTRL_INPUT_ENDIANNESS_LITTLE_ENDIAN,
    /*! CRCP Input is proccessed in big endian.
     *  LSB is highest memory address and last to be processed. */
    DL_CRCP_INPUT_ENDIANESS_BIG_ENDIAN =
        CRCP_CRCCTRL_INPUT_ENDIANNESS_BIG_ENDIAN
} DL_CRCP_INPUT_ENDIANESS;

/*! @enum DL_CRCP_OUTPUT_BYTESWAP */
typedef enum {
    /*! CRCP output byteswap is enabled */
    DL_CRCP_OUTPUT_BYTESWAP_ENABLED = CRCP_CRCCTRL_OUTPUT_BYTESWAP_ENABLE,
    /*! CRCP output byteswap is disabled */
    DL_CRCP_OUTPUT_BYTESWAP_DISABLED = CRCP_CRCCTRL_OUTPUT_BYTESWAP_DISABLE
} DL_CRCP_OUTPUT_BYTESWAP;

/*! @enum DL_CRCP_CRCPOLY_POLYNOMIAL
 *
 *  @brief commonly used pre-defined polynomials to be used by CRCP
 *         as mentioned by the website
 *         http://www.sunshine2k.de/coding/javascript/crc/crc_js.html.
 *         Custom polynomials can also be used in lieu of the follwoing.
 */
typedef enum {

    /*! CRCP commonly used polynomial CRC32_MPEG2. To match online output,
     *  seed value must be set to 0xFFFFFFFF */
    DL_CRCP_CRCPOLY_POLYNOMIAL_32_MPEG2 = 0x04C11DB7,
    /*! CRCP commonly used polynomial CRC32_Q. To match online output,
     *  seed value must be set to 0x00000000 */
    DL_CRCP_CRCPOLY_POLYNOMIAL_32_Q = 0x814141AB,
    /*! CRCP commonly used polynomial CRC32_JAMCRC. To match online output,
     *  seed value must be set to 0xFFFFFFFF and bit order reversed */
    DL_CRCP_CRCPOLY_POLYNOMIAL_32_JAMCRC = 0x04C11DB7,
    /*! CRCP commonly used polynomial CRC32_XFER. To match online output,
     *  seed value must be set to 0x00000000 */
    DL_CRCP_CRCPOLY_POLYNOMIAL_32_XFER = 0x000000AF,
    /*! CRCP commonly used polynomial CRC16_CCIT_ZERO. To match online
     *  output, seed value must be set to 0x0000 */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_CCIT_ZERO = 0x00001021,
    /*! CRCP commonly used polynomial CRC16_ARC. To match online output,
     *  seed value must be set to 0x0000 and bit order reversed */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_ARC = 0x00001DCF,
    /*! CRCP commonly used polynomial CRC16_AUG_CCIT. To match online output,
     *  seed value must be set to 0x1D0F */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_AUG_CCIT = 0x00001021,
    /*! CRCP commonly used polynomial CRC16_BUYPASS. To match online output,
     *  seed value must be set to 0x0000 */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_BUYPASS = 0x00008005,
    /*! CRCP commonly used polynomial CRC16_CCIT_FALSE. To match online output,
     *  seed value must be set to 0xFFFF */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_CCIT_FALSE = 0x00001021,
    /*! CRCP commonly used polynomial CRC16_CDMA2000. To match online output,
     *  seed value must be set to 0xFFFF */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_CDMA2000 = 0x0000C867,
    /*! CRCP commonly used polynomial CRC16_MODBUS. To match online output,
     *  seed value must be set to 0xFFFF and bit order reversed */
    DL_CRCP_CRCPOLY_POLYNOMIAL_16_MODBUS = 0x00001DCF,

} DL_CRCP_CRCPOLY_POLYNOMIAL;

/*! @enum DL_CRCP_CRCSEED_SEED
 *
 *  @brief seeds for commonly used pre-defined polynomials to be used
 *         by CRCP as mentioned by the website
 *         http://www.sunshine2k.de/coding/javascript/crc/crc_js.html.
 *         Custom polynomials can also be used in lieu of the follwoing.
 */
typedef enum {

    /*! CRCP commonly used polynomial CRC32_MPEG2. To match online output,
     *  polynomial must be set to 0x04C11DB7 */
    DL_CRCP_CRCSEED_SEED_32_MPEG2 = 0xFFFFFFFF,
    /*! CRCP commonly used polynomial CRC32_Q. To match online output,
     *  polynomial must be set to 0x814141AB */
    DL_CRCP_CRCSEED_SEED_32_Q = 0x00000000,
    /*! CRCP commonly used polynomial CRC32_JAMCRC. To match online output,
     *  polynomial must be set to 0x04C11DB7 and bit order reversed */
    DL_CRCP_CRCSEED_SEED_32_JAMCRC = 0xFFFFFFFF,
    /*! CRCP commonly used polynomial CRC32_XFER. To match online output,
     *  polynomial must be set to 0x000000AF */
    DL_CRCP_CRCSEED_SEED_32_XFER = 0x00000000,
    /*! CRCP commonly used polynomial CRC16_CCIT_ZERO. To match online
     *  output, polynomial must be set to 0x00001021 */
    DL_CRCP_CRCSEED_SEED_16_CCIT_ZERO = 0x0000,
    /*! CRCP commonly used polynomial CRC16_ARC. To match online output,
     *  polynomial must be set to 0x00001DCF and bit order reversed */
    DL_CRCP_CRCSEED_SEED_16_ARC = 0x0000,
    /*! CRCP commonly used polynomial CRC16_AUG_CCIT. To match online output,
     *  polynomial must be set to 0x00001021 */
    DL_CRCP_CRCSEED_SEED_16_AUG_CCIT = 0x1D0F,
    /*! CRCP commonly used polynomial CRC16_BUYPASS. To match online output,
     *  polynomial must be set to 0x00008005 */
    DL_CRCP_CRCSEED_SEED_16_BUYPASS = 0x0000,
    /*! CRCP commonly used polynomial CRC16_CCIT_FALSE. To match online output,
     *  polynomial must be set to 0x00001021 */
    DL_CRCP_CRCSEED_SEED_16_CCIT_FALSE = 0xFFFF,
    /*! CRCP commonly used polynomial CRC16_CDMA2000. To match online output,
     *  polynomial must be set to 0x0000C867 */
    DL_CRCP_CRCSEED_SEED_16_CDMA2000 = 0xFFFF,
    /*! CRCP commonly used polynomial CRC16_MODBUS. To match online output,
     *  polynomial must be set to 0x00001DCF and bit order reversed */
    DL_CRCP_CRCSEED_SEED_16_MODBUS = 0xFFFF,

} DL_CRCP_CRCSEED_SEED;

/**
 * @brief Enables power on CRCP module
 *
 * @param crcp         Pointer to the register overlay for the CRCP peripheral
 */
__STATIC_INLINE void DL_CRCP_enablePower(CRCP_Regs *crcp)
{
    crcp->GPRCM.PWREN = (CRCP_PWREN_KEY_UNLOCK_W | CRCP_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Disables power on CRCP module
 *
 * @param crcp         Pointer to the register overlay for the CRCP peripheral
 */
__STATIC_INLINE void DL_CRCP_disablePower(CRCP_Regs *crcp)
{
    crcp->GPRCM.PWREN = (CRCP_PWREN_KEY_UNLOCK_W | CRCP_PWREN_ENABLE_DISABLE);
}

/**
 * @brief Returns if power on CRCP module is enabled
 *
 * @param crcp         Pointer to the register overlay for the CRCP peripheral
 *
 * @return true if power is enabled
 * @return false if power is disabled
 *
 */
__STATIC_INLINE bool DL_CRCP_isPowerEnabled(CRCP_Regs *crcp)
{
    return ((crcp->GPRCM.PWREN & CRCP_PWREN_ENABLE_MASK) ==
            CRCP_PWREN_ENABLE_ENABLE);
}

/**
 * @brief Resets CRCP peripheral
 *
 * @param crcp         Pointer to the register overlay for the CRCP peripheral
 */
__STATIC_INLINE void DL_CRCP_reset(CRCP_Regs *crcp)
{
    crcp->GPRCM.RSTCTL =
        (CRCP_RSTCTL_KEY_UNLOCK_W | CRCP_RSTCTL_RESETSTKYCLR_CLR |
            CRCP_RSTCTL_RESETASSERT_ASSERT);
}

/**
 * @brief Returns if CRCP module has been reset
 *
 * @param crcp         Pointer to the register overlay for the CRCP peripheral
 *
 * @return true if peripheral was reset
 * @return false if peripheral wasn't reset
 *
 */
__STATIC_INLINE bool DL_CRCP_isReset(CRCP_Regs *crcp)
{
    return ((crcp->GPRCM.STAT & CRCP_STAT_RESETSTKY_MASK) ==
            CRCP_STAT_RESETSTKY_RESET);
}

/**
 * @brief Initializes the CRCP peripheral
 *
 * @param crcp         Pointer to the register overlay for the CRCP peripheral.
 * @param polySize     Selects CRC polynomial size. One of
 *                     @ref DL_CRCP_POLYNOMIAL_SIZE.
 * @param bitOrd       Selects CRC bit order. One of @ref DL_CRCP_BIT.
 * @param inEndianness Selects CRC input endianess. One of
 *                     @ref DL_CRCP_INPUT_ENDIANESS.
 * @param outByteSwap  Selects CRC output byte swap mode. One of
 *                     @ref DL_CRCP_OUTPUT_BYTESWAP.
 *
 */
__STATIC_INLINE void DL_CRCP_init(CRCP_Regs *crcp,
    DL_CRCP_POLYNOMIAL_SIZE polySize, DL_CRCP_BIT bitOrd,
    DL_CRCP_INPUT_ENDIANESS inEndianness, DL_CRCP_OUTPUT_BYTESWAP outByteSwap)
{
    crcp->CRCCTRL = ((uint32_t) polySize | (uint32_t) bitOrd |
                     (uint32_t) inEndianness | (uint32_t) outByteSwap);
}

/*!
 *  @brief      Initializes the seed for a 16-bit polynomial CRC calculation
 *  @note       CRC seed is swapped when CRCP module is configured in big-endian
 *              mode. For example when calling DL_CRCP_setSeed32(CRC, 0xaabb).
 *              The CRCP module will be initialized with 0xbbaa. Therefore, the
 *              seed value should be appropriately specified taking endianness
 *              into account. Please refer to the device TRM for additional
 *              detail.
 *
 *  Sets the inital seed for a 16-bit CRC calculation. can be any value,
 *  or cast one of the common seeds in @ref DL_CRCP_CRCSEED_SEED.
 *
 *  @param[in]  crcp   Pointer to the register overlay for the CRCP peripheral
 *  @param[in]  seed   The seed from which to start generating a signature
 */
__STATIC_INLINE void DL_CRCP_setSeed16(CRCP_Regs *crcp, uint16_t seed)
{
    volatile uintptr_t addr;
    volatile uint16_t *pRef;

    addr = (uintptr_t)((volatile uintptr_t *) &crcp->CRCSEED);
    pRef = (volatile uint16_t *) addr;

    *pRef = seed;
}

/*!
 *  @brief    Initializes the seed for a 32-bit polynomial CRC calculation
 *  @note     CRC seed is swapped when CRCP module is configured in big-endian
 *            mode. For example when calling DL_CRCP_setSeed32(CRC, 0xaabbccdd).
 *            The CRCP module will be initialized with 0xddccbbaa. Therefore,
 *            the seed value should be appropriately specified taking endianness
 *            into account. Please refer to the device TRM for additional
 *            detail.
 *
 *  Sets the inital seed for a 32-bit CRC calculation. can be any value,
 *  or cast one of the common seeds in @ref DL_CRCP_CRCSEED_SEED.
 *
 *  @param[in]  crcp   Pointer to the register overlay for the CRCP peripheral
 *  @param[in]  seed   The seed from which to start generating a signature
 */
__STATIC_INLINE void DL_CRCP_setSeed32(CRCP_Regs *crcp, uint32_t seed)
{
    crcp->CRCSEED = seed;
}

/*!
 *  @brief      Feeds 8-bit data into the CRC calculation
 *
 *  @param[in]  crcp        Pointer to the register overlay for the CRCP
 *                          peripheral
 *  @param[in]  dataIn      8-bit data value to add to the signature
 *
 */
__STATIC_INLINE void DL_CRCP_feedData8(CRCP_Regs *crcp, uint8_t dataIn)
{
    volatile uint8_t *pRef = (volatile uint8_t *) &crcp->CRCIN;
    *pRef                  = dataIn;
}

/*!
 *  @brief      Feeds 16-bit data into the CRC calculation
 *
 *  @param[in]  crcp        Pointer to the register overlay for the CRCP
 *                          peripheral
 *  @param[in]  dataIn      16-bit data value to add to the signature
 *
 */
__STATIC_INLINE void DL_CRCP_feedData16(CRCP_Regs *crcp, uint16_t dataIn)
{
    volatile uintptr_t addr;
    volatile uint16_t *pRef;

    addr = (uintptr_t)((volatile uintptr_t *) &crcp->CRCIN);
    pRef = (volatile uint16_t *) addr;

    *pRef = dataIn;
}

/*!
 *  @brief      Feeds 32-bit data into the CRC calculation
 *
 *  Feeds a 32-bit value into the CRC calculation. 32-bit data can only be used
 *  with the 32-bit polynomial.
 *
 *  @param[in]  crcp        Pointer to the register overlay for the CRCP
 *                          peripheral
 *  @param[in]  dataIn      32 bit data value to add to the signature
 *
 */
__STATIC_INLINE void DL_CRCP_feedData32(CRCP_Regs *crcp, uint32_t dataIn)
{
    crcp->CRCIN = dataIn;
}

/*!
 *  @brief      Returns the result from the 16-bit polynomial calculation
 *
 *  @note       CRC Output will be swapped if the CRCP module is configured
 *              in byte-swap mode. For example, if enabled and CRCOUT register
 *              has the value 0xaabbccdd, DL_CRCP_getResult16 would return
 *              0xddcc. Please refer to the TRM for more information.
 *
 *  @param[in]  crcp Pointer to the register overlay for the CRCP peripheral
 *
 *  @return     The calculation result for the 16-bit polynomial
 */
__STATIC_INLINE uint16_t DL_CRCP_getResult16(CRCP_Regs *crcp)
{
    return ((uint16_t) crcp->CRCOUT);
}

/*!
 *  @brief      Returns the result from the 32-bit polynomial calculation
 *
 *  @note       CRC Output will be swapped if the CRCP module is configured
 *              in byte-swap mode. For example, if enabled and CRCOUT register
 *              has value 0xaabbccdd, DL_CRCP_getResult32 would return
 *              0xddccbbaa in the 32-bit case, and 0x0000ddcc. In the 16-bit
 *              case. Additionally, if byte-swap is disabled, the 16-bit size
 *              would return 0x0000ccdd. Please refer to the TRM for more
 *              information.
 *
 *  @param[in]  crcp  Pointer to the register overlay for the CRCP peripheral
 *
 *  @return     The calculation result for the 32-bit polynomial
 */
__STATIC_INLINE uint32_t DL_CRCP_getResult32(CRCP_Regs *crcp)
{
    return (crcp->CRCOUT);
}

/*!
 *  @brief      Sets the active polynomial terms for the CRC calculation
 *
 *  The polynomial can be any value represented with MSB first. Thus, in a
 *  16-bit polynomial (where the 16th power is always present), the nth bit
 *  corresponds to the inclusion of the nth term of the polynomial. For example,
 *  The 16-bit polynomial CCIT x^16 + x^12 + x^5 + 1 is represented as 0x1021.
 *  One can craft a custom polynomial, use an existing polynomial,
 *  or cast one of the common polynomials in @ref DL_CRCP_CRCPOLY_POLYNOMIAL. If
 *  the polynomial size is configured as 16-bit, the upper 16-bits are ignored.
 *
 *  @param[in]  crcp  Pointer to the register overlay for the CRCP peripheral
 *  @param[in]  poly  Polynomial to implement (normal representation)
 */
__STATIC_INLINE void DL_CRCP_setPolynomial(CRCP_Regs *crcp, uint32_t poly)
{
    crcp->CRCPOLY = poly;
}

/*!
 *  @brief      Gets the active polynomial terms for the CRC calculation
 *
 *  The polynomial can be any value represented as with MSB first. Thus, in a
 *  16-bit polynomial (where the 16th power is always present), the nth bit
 *  corresponds to the inclusion of the nth term of the polynomial. For example,
 *  The 16-bit polynomial CCIT x^16 + x^12 + x^5 + 1 is represented as 0x1021.
 *  If the polynomial size is configured as 16-bit, the upper 16-bits are ignored.
 *
 *  @param[in]  crcp  Pointer to the register overlay for the CRCP peripheral
 *
 *  @returns    Active polynomial (normal representation)
 */
__STATIC_INLINE uint32_t DL_CRCP_getPolynomial(CRCP_Regs *crcp)
{
    return (crcp->CRCPOLY);
}

/*!
 *  @brief      Calculates the CRC over a range of 32-bit values
 *
 *  Uses the 32-bit polynomial to calculate the checksum over a block of
 *  values.
 *
 *  @param[in]  crcp  Pointer to the register overlay for the CRCP peripheral
 *  @param[in]  seed  The seed for the CRC to start generating a signature from
 *  @param[in]  ptr   A pointer to the block of code to calculate the CRC over
 *  @param[in]  size  The size of the block of uint32_t data
 *
 *  @return     The calculated CRC signature value
 */
extern uint32_t DL_CRCP_calculateBlock32(
    CRCP_Regs *crcp, uint32_t seed, uint32_t *ptr, uint32_t size);

/*!
 *  @brief      Calculates the CRC over a memory range
 *
 *  Calculates the checksum using the 32-bit polynomial over any memory range.
 *
 *  @param[in]  crcp      Pointer to the register overlay for the CRC
 *                        peripheral
 *  @param[in]  seed      The seed used to start generating a signature from
 *  @param[in]  ptrStart  A uint32_t pointer to the start of a block of code to
 *                        calculate the CRC over
 *  @param[in]  ptrEnd    A uint32_t pointer to the end of a block of code to
 *                        calculate the CRC over
 *
 *  @return     The calculated CRC signature value
 */
extern uint32_t DL_CRCP_calculateMemoryRange32(
    CRCP_Regs *crcp, uint32_t seed, uint32_t *ptrStart, uint32_t *ptrEnd);

/*!
 *  @brief      Calculates the CRC over a range of 16-bit values
 *
 *  Uses the 16-bit polynomial to calculate the checksum over a block of
 *  values.
 *
 *  @param[in]  crcp  Pointer to the register overlay for the CRCP peripheral
 *  @param[in]  seed  The seed for the CRCP to start generating a signature from
 *  @param[in]  ptr   A pointer to the block of code to calculate the CRC over
 *  @param[in]  size  The size of the block of 16-bit data
 *
 *  @return     The calculated CRC signature value
 */
extern uint16_t DL_CRCP_calculateBlock16(
    CRCP_Regs *crcp, uint16_t seed, uint16_t *ptr, uint16_t size);

/*!
 *  @brief      Calculates the CRC over a memory range
 *
 *  Calculates the checksum using the 16-bit polynomial over any memory range.
 *
 *  @param[in]  crcp      Pointer to the register overlay for the CRC
 *                        peripheral
 *  @param[in]  seed      The seed used to start generating a signature from
 *  @param[in]  ptrStart  A uint16_t pointer to the start of a block of code to
 *                        calculate the CRC over
 *  @param[in]  ptrEnd    A uint16_t pointer to the end of a block of code to
 *                        calculate the CRC over
 *
 *  @return     The calculated CRC signature value
 */
extern uint16_t DL_CRCP_calculateMemoryRange16(
    CRCP_Regs *crcp, uint16_t seed, uint16_t *ptrStart, uint16_t *ptrEnd);

/**
 *  @brief Returns the address of the CRC input data register.
 *
 *  This API can be used with @ref DL_DMA_setDestAddr to set the destination
 *  address when using DMA transfers
 *
 *  @param[in]  crcp      Pointer to the register overlay for the CRC
 *                        peripheral
 *  @return Address of the CRC input data register
 */
__STATIC_INLINE uintptr_t DL_CRCP_getCRCINAddr(CRCP_Regs *crcp)
{
    return ((uintptr_t) &crcp->CRCIN);
}
#ifdef __cplusplus
}
#endif

#endif /* __MSPM0_HAS_CRCP__ */

#endif /* ti_dl_DL_CRCP__include */
/** @}*/
