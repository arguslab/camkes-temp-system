/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <camkes.h>
#include <string.h>

#define FAN_PIN (115)

void action__init()
{
    gpio_init_pin(FAN_PIN, 0);
}

void action_set_speed(int v)
{
    /* right now this is just an on/off function, in the future we may be able to control speed. */
    if(v)
    {
        printf("Heater: fan set to ON.\n");
        gpio_set_pin(FAN_PIN, 1);
    }
    else
    {
        printf("Heater: fan set to OFF.\n");
        gpio_set_pin(FAN_PIN, 0);
    }
}
