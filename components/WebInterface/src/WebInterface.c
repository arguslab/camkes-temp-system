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
    printf("WebInterface:: started.\n");

    /* Arbirary low value, so that the fan automatically starts */
    desired_temp_publish(150);



    timer_sleep_s(2);
    timer_sleep_s(2);
    timer_sleep_s(2);

    /* sensor data is routed through the controller to match minix implementation. */
    printf("WebInterface:: read data %i\n", status_get());


    #ifdef DEMO_ATTACK

    timer_sleep_s(2);
    timer_sleep_s(2);
    timer_sleep_s(2);

    fflush(stdout);
    printf("Compromised WebInterface:\n"
    "████████╗██████╗ ██╗   ██╗██╗███╗   ██╗ ██████╗     ██╗  ██╗ █████╗  ██████╗██╗  ██╗\n"
    "╚══██╔══╝██╔══██╗╚██╗ ██╔╝██║████╗  ██║██╔════╝     ██║  ██║██╔══██╗██╔════╝██║ ██╔╝\n"
    "   ██║   ██████╔╝ ╚████╔╝ ██║██╔██╗ ██║██║  ███╗    ███████║███████║██║     █████╔╝\n"
    "   ██║   ██╔══██╗  ╚██╔╝  ██║██║╚██╗██║██║   ██║    ██╔══██║██╔══██║██║     ██╔═██╗\n"
    "   ██║   ██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝    ██║  ██║██║  ██║╚██████╗██║  ██╗██╗██╗██╗\n"
    "   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝╚═╝╚═╝\n\n");


    /* Exhaust capability space looking for misconfigurations.
    As a compromised application in seL4, if the capabilities are distributed correctly there isn't any
    risk that an adversary program could gain additional capabilities. It can't even generate a valid
    cabability address to try and spoof data, or kill other processes. The best it can do is use the
    capabilities it is given looking for potential IPC vulnerabilities. */

    int futile_attempt = 20; /* this is an arbitrary number. just for the demo I am looking to generate some example faults */
    while(1)
    {
        /* Attempt to max out priotity (to starve other processes). */
        seL4_TCB_SetPriority(1, 254);

        timer_sleep_s(2);

        /* Spoof attempt */
        void * _camkes_buffer_base_403 UNUSED = (void*)(((void*)&seL4_GetIPCBuffer()->msg[0]));
        memset(_camkes_buffer_base_403, 0, sizeof(uint8_t));

        seL4_MessageInfo_t heater_spoof = seL4_MessageInfo_new(0, 0, 0, sizeof(uint8_t));
        seL4_NBSend(futile_attempt++, heater_spoof);

        timer_sleep_s(2);

        /* "Kill" attempt */
        seL4_TCB_Suspend(futile_attempt++);

        timer_sleep_s(2);

    }

    #endif





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


    return 0;
}
