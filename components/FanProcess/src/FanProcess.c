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

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

static void printToCoordinates(int x, int y, char* text)
{
    printf("\033[%d;%dH%s\n", y, x, text);
}

static char output[100];
static void prettyPrint(char* text)
{
    sprintf(output, CYN "Fan: " RESET "%s   ", text);
    printToCoordinates(0, 7, output);
}

void fan__init()
{
    gpio_init_pin(FAN_PIN, 0);
}

void fan_cmd(int v)
{
    /* right now this is just an on/off function, in the future we may be able to control speed. */
    if(v)
    {
        prettyPrint("Fan set to ON.");
        gpio_set_pin(FAN_PIN, 1);
    }
    else
    {
        prettyPrint("Fan set to OFF.");
        gpio_set_pin(FAN_PIN, 0);
    }
}
