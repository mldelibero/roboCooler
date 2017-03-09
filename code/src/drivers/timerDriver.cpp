#include <stm32f4xx.h>
#include <stm32f4xx_hal.h>
#include "timerDriver.h"

TIM_HandleTypeDef TIM_Handle;

void init_TimerDriver(void)
{
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

    __HAL_TIM_ENABLE_IT(&TIM_Handle, TIM_IT_UPDATE);

    // Enable Timer
    HAL_TIM_Base_Start(&TIM_Handle);

    HAL_NVIC_SetPriority(TIMER_TIMx_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIMER_TIMx_IRQn);
} // end - void init_TimerDriver(void)

extern "C" void TIMER_TIMx_IRQHandler()
{
    HAL_TIM_IRQHandler(&TIM_Handle);
}

