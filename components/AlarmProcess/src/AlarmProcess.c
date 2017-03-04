/*------------------------------------------------------------------------------
* alarm.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <string.h>

#define RED_LED_PIN       (3*32 + 16)
#define GREEN_LED_PIN     (3*32 + 17)
#define BLUE_LED_PIN      (0*32 + 14)
#define ALARM_ON          (1)
#define ALARM_OFF         (0)

static int alarm_state;

void alarm__init()
{
    gpio_init_pin(BLUE_LED_PIN, 0); // Blue 24
    gpio_init_pin(GREEN_LED_PIN, 0); // Green 26
    gpio_init_pin(RED_LED_PIN, 0); // Red 28

    alarm_state = ALARM_OFF;
    gpio_set_pin(RED_LED_PIN, alarm_state);
}

int alarm_cmd()
{
  printf("Alarm: started. \r\n");
  alarm_state = (alarm_state == ALARM_OFF) ? ALARM_ON : ALARM_OFF;
  gpio_set_pin(RED_LED_PIN, alarm_state);
  return alarm_state;
}
