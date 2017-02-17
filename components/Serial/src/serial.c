/*------------------------------------------------------------------------------
* timer.c
*
*-----------------------------------------------------------------------------*/

#include <stdio.h>

#include <platsupport/i2c.h>
#include <platsupport/plat/i2c.h>
#include <sel4utils/util.h>

i2c_bus_t *i2c_bus = NULL;

void irq_callback(void *_ UNUSED)
{
  i2c_handle_irq(i2c_bus);

  /* Signal the RPC interface. */
  //sem_post();

  irq_reg_callback(irq_callback, NULL);
}

void action__init()
{
}
