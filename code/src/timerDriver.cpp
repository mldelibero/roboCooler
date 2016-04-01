#include <misc.h>
#include <stm32f4xx.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>

#include "timerDriver.h"

TIM_TypeDef a;

void init_TimerDriver(void)
{
    NVIC_InitTypeDef        NVIC_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;

    TIM_DeInit(TIMER_TIMx);
    TIMER_RCC_APBnPeriphClockCmd(TIMER_RCC_APB1Periph_TIMn, ENABLE);
    TIM_TimeBaseInit(TIMER_TIMx, &TIM_TimeBaseInitStruct);
    NVIC_Init(&NVIC_InitStructure);
    TIM_ITConfig(TIMER_TIMx, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIMER_TIMx, ENABLE);
} // end - void init_TimerDriver(void)
