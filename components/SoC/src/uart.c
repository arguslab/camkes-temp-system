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
#include <platsupport/chardev.h>
#include <platsupport/serial.h>
#include <platsupport/plat/serial.h>

ps_chardevice_t uart_driver[3];


void uart__init()
{
    //
    // am335x_serial_init(0, uart0, &uart_driver[0]);
    // am335x_serial_init(1, uart1, &uart_driver[1]);
    // am335x_serial_init(2, uart2, &uart_driver[2]);
}

void uart_write32(int data)
{
    // uart_write(&uart_driver[0], &data, 4, NULL, NULL);
}

int uart_read32()
{
    // uint32_t ret = 0;
    // return uart_read(&uart_driver[0], &ret, 4, NULL, NULL);
    // return ret;
}
