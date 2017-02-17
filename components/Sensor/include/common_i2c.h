/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _COMMON_I2C_H_
#define _COMMON_I2C_H_

#define I2C_MESSAGE_LEN_MAX     (32)
#define I2C_ADDR_LEN_MAX        (32)

typedef struct {
    unsigned char buf[I2C_MESSAGE_LEN_MAX];
    unsigned char len;
} i2c_data_t;

typedef struct {
    int addr[I2C_ADDR_LEN_MAX];
    unsigned char len;
} i2c_scan_addr_t;

#endif
