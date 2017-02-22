/*------------------------------------------------------------------------------
* timer.c
*
* This isn't the best implementation of a Time Server. TODO: convert to a
* single timer setup with a wait queue.
*-----------------------------------------------------------------------------*/

#include <stdio.h>

#include <platsupport/timer.h>
#include <platsupport/plat/timer.h>
#include <sel4platsupport/plat/timer.h>
#include <sel4platsupport/timer.h>
#include <sel4utils/util.h>
#include <sync/sem.h>
#include <camkes.h>

static pstimer_t *timer_drv[NTIMERS];
static volatile void* regs[NTIMERS];
static uint32_t timer2irq_id = DMTIMER2;
static uint32_t timer3irq_id = DMTIMER3;

void irq_callback(void * args)
{
    uint32_t id = *(uint32_t *)args;
    timer_handle_irq(timer_drv[id], dm_timer_irqs[id]);

    /* Wake the sleeping thread. */
    switch(id)
    {
        case DMTIMER2:
            timer2sem_post();
            timer2irq_reg_callback(irq_callback, args);
            break;
        case DMTIMER3:
            timer3sem_post();
            timer3irq_reg_callback(irq_callback, args);
            break;
    }

}

void timer2__init() /* Could be any of these */
{
    timer_config_t config;

    /*
    * Provide hardware info to platsupport.
    */
    regs[DMTIMER2] = timer2reg;
    regs[DMTIMER3] = timer3reg;

    config.vaddr = (void *)timer2reg;
    config.irq = dm_timer_irqs[DMTIMER2];
    timer_drv[DMTIMER2] = ps_get_timer(DMTIMER2, &config);
    assert(timer_drv[DMTIMER2]);

    config.vaddr = (void *)timer3reg;
    config.irq = dm_timer_irqs[DMTIMER3];
    timer_drv[DMTIMER3] = ps_get_timer(DMTIMER3, &config);
    assert(timer_drv[DMTIMER3]);

    timer2irq_reg_callback(irq_callback, &timer2irq_id);
    timer3irq_reg_callback(irq_callback, &timer3irq_id);

    printf("Timer: started.\n");
}


void generic_sleep(uint32_t id, uint32_t nanoseconds)
{
    timer_oneshot_relative(timer_drv[id], nanoseconds);

    switch(id)
    {
        case DMTIMER2:
            timer2sem_wait();
            break;
        case DMTIMER3:
            timer3sem_wait();
    }
}

/*----------------------------------------------------------------------------*/
void timer2_sleep_ns(uint32_t nanoseconds) { generic_sleep(DMTIMER2, nanoseconds); }
void timer3_sleep_ns(uint32_t nanoseconds) { generic_sleep(DMTIMER3, nanoseconds); }


/*----------------------------------------------------------------------------*/
void timer2_sleep_ms(uint32_t milliseconds) { generic_sleep(DMTIMER2, milliseconds * 1000 * 1000); }
void timer3_sleep_ms(uint32_t milliseconds) { generic_sleep(DMTIMER3, milliseconds * 1000 * 1000); }


/*----------------------------------------------------------------------------*/
void timer2_sleep_s(uint32_t seconds) { generic_sleep(DMTIMER2, seconds * 1000 * 1000 * 1000); }
void timer3_sleep_s(uint32_t seconds) { generic_sleep(DMTIMER3, seconds * 1000 * 1000 * 1000); }
