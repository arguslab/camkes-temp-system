/*------------------------------------------------------------------------------
* alarm.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <string.h>

#define RED_LED_PIN       (3*32 + 16)
#define GREEN_LED_PIN     (3*32 + 17)
#define BLUE_LED_PIN      (0*32 + 14)


void action__init()
{
    //gpio_init_pin(49, 0);
    gpio_init_pin(BLUE_LED_PIN, 0); // Blue 24
    gpio_init_pin(GREEN_LED_PIN, 0); // Green 26
    gpio_init_pin(RED_LED_PIN, 0); // Red 28
}

void action_start()
{
  printf("Alarm: started. \r\n");
  gpio_set_pin(RED_LED_PIN, 1);
}

void action_stop()
{
  printf("Alarm: stopped. \r\n");
  gpio_set_pin(RED_LED_PIN, 0);
}
