/*------------------------------------------------------------------------------
* controller.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

int data = 999; /* arbitrary unique */
char alarm_started = 0;
char heater_started = 0;
char time_since_heater_started = 0;
char timeout_alarm_s = 15;

int run()
{
    printf("Controller: started.\n");

    while(1)
    {
        timer_sleep_s(1);
        data = sensor_read()/10;
        printf("Controller: sensor reads %i degrees. \r\n",  data);

        if(heater_started)
        {
            time_since_heater_started += 1;

            if(time_since_heater_started >= timeout_alarm_s && !alarm_started)
            {
                alarm_start();
                alarm_started = 1;
            }
        }

        if(!heater_started&& data >= *((int *)settings))
        {
            time_since_heater_started = 0;
            heater_started = 1;
            heater_set_speed(1);
        }
        else if(heater_started && data < *((int *)settings))
        {
            heater_started = 0;
            heater_set_speed(0);

            if(alarm_started)
            {
                alarm_stop();
            }

        }
    }

  return 0;
}

int data_read()
{
  return data;
}
