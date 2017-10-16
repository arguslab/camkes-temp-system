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
    sprintf(output, GRN "Controller: " RESET "%s   ", text);
    printToCoordinates(0, 5, output);
}

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
    prettyPrint("started.");

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

    static char buf[100];
    sprintf(buf, "Sensor reads %d.%01d degrees.",  data/10, data % 10);
    prettyPrint(buf);

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
