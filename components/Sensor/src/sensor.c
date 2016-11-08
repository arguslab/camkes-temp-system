/*------------------------------------------------------------------------------
* sensor.c
*
*-----------------------------------------------------------------------------*/


#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>

static int current_temp = 72;
static int temp_swing = 1;

int data_read()
{
  return current_temp;
}

int run()
{
  while(1)
  {
    hello_sleep(1);

    if(current_temp >= 90)
    {
      temp_swing = -1;
    }
    else if(current_temp <= 60)
    {
      temp_swing = 1;
    }

    current_temp += temp_swing;

  }

  return 0;
}
