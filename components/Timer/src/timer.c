/*------------------------------------------------------------------------------
* timer.c
*
*-----------------------------------------------------------------------------*/

#include <stdio.h>

#include <platsupport/timer.h>
#include <platsupport/plat/timer.h>
#include <sel4platsupport/plat/timer.h>
#include <sel4platsupport/timer.h>
#include <sel4utils/util.h>

#include <Timer.h>

pstimer_t *timer_drv = NULL;

void irq_callback(void *_ UNUSED)
{
  timer_handle_irq(timer_drv, DMTIMER2_INTERRUPT);

  /* Signal the RPC interface. */
  sem_post();

  irq_reg_callback(irq_callback, NULL);
}

void action__init()
{
  timer_config_t config;

  /*
   * Provide hardware info to platsupport.
   */
  config.vaddr = (void*)reg;
  config.irq = DMTIMER2_INTERRUPT;

  timer_drv = ps_get_timer(DMTIMER2, &config);
  assert(timer_drv);

  irq_reg_callback(irq_callback, NULL);
}

void action_sleep_ns(int nanoseconds)
{
    timer_oneshot_relative(timer_drv, nanoseconds);

    /* Wait for the timeout interrupt */
    sem_wait();
}

void action_sleep_ms(int milliseconds)
{
    timer_oneshot_relative(timer_drv, milliseconds * 1000 * 1000);

    /* Wait for the timeout interrupt */
    sem_wait();
}

void action_sleep_s(int seconds)
{
    timer_oneshot_relative(timer_drv, seconds * 1000 * 1000 * 1000);

    /* Wait for the timeout interrupt */
    sem_wait();
}
