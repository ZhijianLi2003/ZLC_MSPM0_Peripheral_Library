/*
 *  Copyright (c) 2019-2020, Arm Limited. All rights reserved.
 *
 *  SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SECURITY_CNT_H__
#define __SECURITY_CNT_H__

/**
 * @file security_cnt.h
 *
 * @note The interface must be implemented in a fail-safe way that is
 *       resistant to asynchronous power failures or it can use hardware
 *       counters that have this capability, if supported by the platform.
 *       When a counter incrementation was interrupted it must be able to
 *       continue the incrementation process or recover the previous consistent
 *       status of the counters. If the counters have reached a stable status
 *       (every counter incrementation operation has finished), from that point
 *       their value cannot decrease due to any kind of power failure.
 *
 * @note A security counter might be implemented using non-volatile OTP memory
 *       (i.e. fuses) in which case it is the responsibility of the platform
 *       code to map each possible security counter values onto the fuse bits
 *       as the direct usage of counter values can be costly / impractical.
 */

#include <stdint.h>
#include "bootutil/fault_injection_hardening.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BIM_INFO_PAGE_MAGIC        0x96fa
#define BIM_INFO_PAGE_ERASED       0xFFFF
#define BIM_INFO_MAGIC_SZ          2
#define BIM_ITEM_SZ                10
#define BIMINFO_SUCCESS            0
#define BIMINFO_FAIL               22
#define BIMINFO_FULL               0xFF

/* each item consists of status (2 bytes) + image id (4 bytes) + security counter (4 bytes) + item id (2 bytes) */
#define SC_ITEM_ID                 0x9373
#define SC_STATUS_EMPTY            0xFFFF
#define SC_STATUS_VALID            0xFCFC
#define SC_STATUS_INVALID          0xF0F0


typedef struct sc_page_head {
    uint16_t sc_page_id;
}sc_page_head_t;

typedef struct sc_item {
    uint16_t sc_status;
    uint16_t image_id;
    uint32_t security_counter;
    uint16_t item_id;
}sc_item_t;



/**
 * Initialises the security counters.
 *
 * @return                  FIH_SUCCESS on success
 */
fih_int boot_nv_security_counter_init(void);

/**
 * Reads the stored value of a given image's security counter.
 *
 * @param image_id          Index of the image (from 0).
 * @param security_cnt      Pointer to store the security counter value.
 *
 * @return                  FIH_SUCCESS on success
 */
fih_int boot_nv_security_counter_get(uint32_t image_id, fih_int *security_cnt);

/**
 * Updates the stored value of a given image's security counter with a new
 * security counter value if the new one is greater.
 *
 * @param image_id          Index of the image (from 0).
 * @param img_security_cnt  New security counter value. The new value must be
 *                          between 0 and UINT32_MAX and it must be greater than
 *                          or equal to the current security counter value.
 *
 * @return                  0 on success; nonzero on failure.
 */
int32_t boot_nv_security_counter_update(uint32_t image_id,
                                        uint32_t img_security_cnt);

/**
 * Lock the BIM INFO sector
 */
void lockBimSector(void);

#ifdef __cplusplus
}
#endif

#endif /* __SECURITY_CNT_H__ */
