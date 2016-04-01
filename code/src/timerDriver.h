#ifndef __TIMER_DRIVER_H
#define __TIMER_DRIVER_H

#define TIMER_TIMx                   TIM4
#define TIMER_RCC_APBnPeriphClockCmd RCC_APB1PeriphClockCmd
#define TIMER_RCC_APB1Periph_TIMn    RCC_APB1Periph_TIM4

void init_TimerDriver(void);
#endif // #ifndef __TIMER_DRIVER_H

