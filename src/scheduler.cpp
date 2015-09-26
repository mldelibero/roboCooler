#include "scheduler.h"
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"

void init_scheduler(void)
{
#define SCHED_TIMx  TIM1
    NVIC_InitTypeDef NVIC_InitStructure;

#define SCHED_TIMx_IRQn     TIM1_IRQn
    NVIC_InitStructure.NVIC_IRQChannel                   = SCHED_TIMx_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_DeInit(SCHED_TIMx);
#define SCHED_RCC_APBxPeriphClockCmd  RCC_APB1PeriphClockCmd
    RCC_APB1PeriphClockCmd(SCHED_RCC_APBxPeriphClockCmd, ENABLE);


    TIM_TimeBaseInit(SCHED_TIMx, 
            }

