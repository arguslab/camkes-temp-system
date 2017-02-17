/*------------------------------------------------------------------------------
* alarm.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <string.h>

void action__init()
{
    gpio_init_pin(49, 0);
}

void action_start()
{
  printf("Alarm: started. \r\n");
  gpio_set_pin(49, 1);
}

void action_stop()
{
  printf("Alarm: stopped. \r\n");
  gpio_set_pin(49, 0);
}
