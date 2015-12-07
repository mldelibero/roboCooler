#ifndef __SCHEDULER_H
#define __SCHEDULER_H
#define SCHED_IRQHandler   TIM4_IRQ_Handler

void init_scheduler(void);
extern "C"
{
    void SCHED_IRQHandler(void);
}
#endif // __SCHEDULER_H

