#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sel4/sel4.h>

//#define DEADLOCK_ATTACK
//#define BRUTEFORCE_ATTACK

int run()
{
  printf("Webserver: started.\n");

  *(int *)settings = 21;

  /* sensor data is routed through the controller to match minix implementation. */
  printf("Webserver: read data %i\n", controller_read());




#ifdef DEADLOCK_ATTACK
  seL4_MessageInfo_t sensor_data_req = seL4_MessageInfo_new(0, 0, 0, 0);

  seL4_Send(7, sensor_data_req);
  /* Now we never reply
  _camkes_info_313 = seL4_Recv(7, NULL);
  */

#endif

#ifdef BRUTEFORCE_ATTACK
  void * _camkes_buffer_base_403 UNUSED = (void*)(((void*)&seL4_GetIPCBuffer()->msg[0]));
  memset(_camkes_buffer_base_403, 0, sizeof(uint8_t));

  seL4_MessageInfo_t alarm_start_req = seL4_MessageInfo_new(0, 0, 0, sizeof(uint8_t));
  for(uint32_t i = 0; i < 100; i++)
  {
    seL4_NBSend(i, alarm_start_req);
  }


#endif


    while(1)
    {
        printf("Webserver: input temp setpoint:");
        scanf("%i", (int *)settings);
    }

    return 0;
}
