/*------------------------------------------------------------------------------
* controller.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

int data = 999; /* arbitrary unique */
char alarm_started = 0;


int run()
{
  printf("Controller: started.\n");

  while(1)
  {
    timer_sleep_s(1);
    data = sensor_read();
    printf("Controller: sensor reads %i degrees. \r\n",  data);

    heater_set_speed(data*10);

    if(!alarm_started && data/10 >= *(int *)settings)
    {
      alarm_start();
      alarm_started = 1;
    }
    else if(alarm_started && data/10 < *(int *)settings)
    {
      alarm_stop();
      alarm_started = 0;
    }
  }

  return 0;
}

int data_read()
{
  return data;
}
