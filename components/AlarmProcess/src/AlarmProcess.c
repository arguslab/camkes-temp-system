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
    sprintf(output, YEL "Alarm: " RESET "%s   ", text);
    printToCoordinates(0, 6, output);
}



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
  alarm_state = (alarm_state == ALARM_OFF) ? ALARM_ON : ALARM_OFF;

  if(alarm_state == ALARM_ON)
  {
       prettyPrint("TURNED ON!");
  }
  else
  {
      prettyPrint("turned off.");
  }

  gpio_set_pin(RED_LED_PIN, alarm_state);
  gpio_set_pin(GREEN_LED_PIN, alarm_state);
  gpio_set_pin(BLUE_LED_PIN, alarm_state);
  return alarm_state;
}
