/*------------------------------------------------------------------------------
* controller.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

char alarm_started = 0;

int run()
{
  printf("Controller: started.\n");

  while(1)
  {
    hello_sleep(1);
    int data = sensor_read();
    printf("Controller: sensor reads %i degrees. \r\n",  data);

    heater_set_speed((100-data)*100);

    if(!alarm_started && data >= *(int *)settings)
    {
      alarm_start();
      alarm_started = 1;
    }
    else if(alarm_started && data < *(int *)settings)
    {
      alarm_stop();
      alarm_started = 0;
    }
  }

  return 0;
}
