#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>


int run() {
  printf("Webserver Started\n");
  printf("-------------------\n");

  printf("Sensor data: 0x%08x", sensor_read());

  return 0;
}
