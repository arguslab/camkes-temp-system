/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */
#ifndef _LOCAL_SOC_H
#define _LOCAL_SOC_H

#include <platsupport/gpio.h>
#include <platsupport/plat/gpio.h>

extern gpio_sys_t gpio_driver;
extern gpio_t pins[32*4];

#endif
