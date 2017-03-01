//#include <misc.h>
#include <stm32f4xx.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_tim.h>

#include "timerDriver.h"

TIM_HandleTypeDef TIM_Handle;

void init_TimerDriver(void)
{
    NVIC_InitTypeDef        NVIC_InitStructure;
    uint16_t                PrescalerValue;

    TIM_Handle.Instance = TIMER_TIMx;

    // Pre Initialization Setup
    HAL_TIM_Base_DeInit(&TIM_Handle);
    TIM_CLK_ENABLE();

    // Timer Setup
    PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / TIMER_CLK - 1);

    TIM_Handle.Init.Prescaler         = PrescalerValue;
    TIM_Handle.Init.CounterMode       = TIM_COUNTERMODE_UP;
    TIM_Handle.Init.Period            = TIMER_PER;
    TIM_Handle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    TIM_Handle.Init.RepetitionCounter = 0;
    HAL_TIM_Base_Init(&TIM_Handle);

    // Interrupt Setup
    NVIC_InitStructure.NVIC_IRQChannel                   = TIMER_TIMx_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    __HAL_TIM_ENABLE_IT(&TIM_Handle, TIM_IT_UPDATE);

    // Enable Timer
    __HAL_TIM_ENABLE(&TIM_Handle);
} // end - void init_TimerDriver(void)

