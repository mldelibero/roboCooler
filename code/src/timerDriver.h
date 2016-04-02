#ifndef __TIMER_DRIVER_H
#define __TIMER_DRIVER_H

#define TIMER_CLK                     10000
#define TIMER_FREQ                    1000
#define TIMER_PER                     (TIMER_CLK / TIMER_FREQ - 1)
#define TIMER_TIMx_IRQn               TIM4_IRQn
#define TIMER_IRQHandler              TIM4_IRQ_Handler

#define TIMER_TIMx                    TIM4
#define TIMER_RCC_APBnPeriphClockCmd  RCC_APB1PeriphClockCmd
#define TIMER_RCC_APB1Periph_TIMn     RCC_APB1Periph_TIM4

#define TIMER_GPIO_AF                 GPIO_AF_TIM4 // Used by integration tester

void init_TimerDriver(void);

extern "C"
{
    void TIMER_IRQHandler(void);
}
#endif // #ifndef __TIMER_DRIVER_H
