#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sel4/sel4.h>

//#define DEADLOCK_ATTACK
//#define BRUTEFORCE_ATTACK
#define DEMO_ATTACK

int run()
{
  printf("Webserver: started.\n");

  *(int *)settings = 217;



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


    timer_sleep_s(5);
    /* sensor data is routed through the controller to match minix implementation. */
    printf("Webserver: read data %i\n", controller_read());



#ifdef DEMO_ATTACK

    while(1)
    {
        timer_sleep_s(5);

        void * _camkes_buffer_base_403 UNUSED = (void*)(((void*)&seL4_GetIPCBuffer()->msg[0]));
        memset(_camkes_buffer_base_403, 0, sizeof(uint8_t));

        seL4_MessageInfo_t heater_spoof = seL4_MessageInfo_new(0, 0, 0, sizeof(uint8_t));
        seL4_NBSend(20, heater_spoof);

        timer_sleep_s(5);

        _camkes_buffer_base_403 = (void*)(((void*)&seL4_GetIPCBuffer()->msg[0]));
        seL4_MessageInfo_t alarm_kill = seL4_MessageInfo_new(0, 0, 0, sizeof(uint8_t));
        memset(_camkes_buffer_base_403, 0, sizeof(uint8_t));
        seL4_NBSend(21, alarm_kill);
    }

#endif


    // demoinput_write32('a');
    // int b = demoinput_read();
    //
    // while(1)
    // {
    //     demoinput_write32('A');
    // }

    return 0;
}
