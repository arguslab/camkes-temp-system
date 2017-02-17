/*------------------------------------------------------------------------------
* gpio.c
*
*-----------------------------------------------------------------------------*/
#include <camkes.h>
#include <SoC.h>

#include <local_soc.h>

#include <stdio.h>
#include <stdlib.h>

#include <sel4utils/util.h>


gpio_sys_t gpio_driver;
gpio_t pins[32*4];


void gpio__init()
{
    printf("GPIO: started.\n");
    am335x_gpio_sys_init(
        (void*)gpio0,
        (void*)gpio1,
        (void*)gpio2,
        (void*)gpio3,
        &gpio_driver);
}

void gpio_init_pin(int pin, int direction)
{
    if(pin >= 0 && pin < sizeof(pins)/sizeof(pins[0]))
    {
        printf("GPIO: Init Pin %i.\n", pin);
        /* todo handle ret */
        gpio_new(&gpio_driver, pin, (enum gpio_dir)direction, &pins[pin]);
    }
}

void gpio_set_pin(int pin, int value)
{
    if(pin >= 0 && pin < (sizeof(pins)/sizeof(pins[0])))
    {
        if(value)
        {
            printf("GPIO: Set Pin %i.\n", pin);
            gpio_set(&pins[pin]);
        }
        else
        {
            printf("GPIO: Clear Pin %i.\n", pin);
            gpio_clr(&pins[pin]);
        }

    }
}

int gpio_read_pin(int pin)
{
    if(pin >= 0 && pin < (sizeof(pins)/sizeof(pins[0])))
    {
        return gpio_get(&pins[pin]);
    }

    return -1;
}
