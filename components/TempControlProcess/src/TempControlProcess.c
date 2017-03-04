/*------------------------------------------------------------------------------
* controller.c
*
*-----------------------------------------------------------------------------*/

#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

const char timeout_alarm_s = 15;

int data;
char alarm_started;
char fan_started;
char time_since_fan_started;
int setpoint;

int status_get()
{
  return data;
}

void desired_temp_publish(int settings)
{
    setpoint = settings;
}

void current_temp__init()
{
    printf("Controller: started.\n");

    data = 0;
    alarm_started = 0;
    fan_started = 0;
    time_since_fan_started = 0;
    setpoint = 0;

    /* Configure alarm to OFF on start */
    alarm_started = alarm_cmd();
    if(alarm_started)
    {
        alarm_started = alarm_cmd();
    }
}

void current_temp_send(int temp)
{
    data = temp;

    printf("Controller: sensor reads %d.%01d degrees. \r\n",  data/10, data % 10);

    if(fan_started)
    {
        time_since_fan_started += 1;

        if(time_since_fan_started >= timeout_alarm_s && !alarm_started)
        {
            alarm_started = alarm_cmd();
        }
    }

    if(!fan_started&& data >= setpoint)
    {
        time_since_fan_started = 0;
        fan_started = 1;
        fan_cmd(1);
    }
    else if(fan_started && data < setpoint)
    {
        fan_started = 0;
        fan_cmd(0);

        if(alarm_started)
        {
            alarm_started = alarm_cmd();
        }

    }
}
