#include <misc.h>
#include <stm32f4xx.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>

#include "timerDriver.h"

void init_TimerDriver(void)
{
    NVIC_InitTypeDef        NVIC_InitStructure;
    uint16_t                PrescalerValue;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;

    // Pre Initialization Setup
    TIM_DeInit(TIMER_TIMx);
    TIMER_RCC_APBnPeriphClockCmd(TIMER_RCC_APB1Periph_TIMn, ENABLE);

    // Timer Setup
    PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / TIMER_CLK - 1);

    TIM_TimeBaseInitStruct.TIM_Prescaler         = PrescalerValue;
    TIM_TimeBaseInitStruct.TIM_CounterMode       = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Period            = TIMER_PER;
    TIM_TimeBaseInitStruct.TIM_ClockDivision     = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIMER_TIMx, &TIM_TimeBaseInitStruct);

    // Interrupt Setup
    NVIC_InitStructure.NVIC_IRQChannel                   = TIMER_TIMx_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_ITConfig(TIMER_TIMx, TIM_IT_Update, ENABLE);

    // Enable Timer
    TIM_Cmd(TIMER_TIMx, ENABLE);
} // end - void init_TimerDriver(void)

