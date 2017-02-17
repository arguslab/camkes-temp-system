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


void action__init()
{
    //gpio_init_pin(49, 0);
}

void action_set_speed(int v)
{
    static int state = 0;
    printf("Heater: fan set to %i RPM.\n", v);
    //gpio_set_pin(49, state);
    state = ~state;
}
