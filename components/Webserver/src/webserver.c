#include <camkes.h>
#include <stdio.h>
#include <stdlib.h>


int run()
{
  printf("Webserver: started.\n");

  *(int *)settings = 80;

  return 0;
}
