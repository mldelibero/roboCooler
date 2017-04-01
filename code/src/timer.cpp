/**
 ******************************************************************************
 * @file    timer.cpp
 * @author  Michael DeLibero
 * @brief   The timer module will subtract one from an array of timers at a fixed interval inside of an interrupt. It will not lower a timer below zero. It will have no knowlede of the meaning of any of the timers. Resetting the timers will be the responsibility of the client.
 * @bug     Update timer module to automatically reset timers and to set a flag (update and overrun) when the timers expire
 ******************************************************************************
 */
#include <stm32f4xx_hal.h>
#include "timer.h"
#include "timerDriver.h"
#include "ledDriver.h"

static int32_t timers[NUM_TIMERS];
static uint32_t numTimersAllocated = 0;

uint32_t Get_NumTimersAllocated(void)
{
    return numTimersAllocated;
}

uint32_t Init_Timers(void)
{
    init_TimerDriver();
    numTimersAllocated = 0;
    for (int i = 0; i < NUM_TIMERS; i++)
    {
        timers[i] = 0;
    }
    return numTimersAllocated;
}

int32_t AllocateTimer(void)
{
    if (numTimersAllocated < NUM_TIMERS) return (int32_t)numTimersAllocated++;
    else                                 return -1;
}

Bool     IsTimerExpired(int32_t timer)
{
    if (timer > -1 && timer < NUM_TIMERS && timers[timer] == 0) return true;
    else                                                        return false;
}

void  Set_TimerValue(int32_t timer, int32_t timerValue)
{
    if (timer >= 0 && timer < NUM_TIMERS) timers[timer] = timerValue;
}

int32_t Get_TimerValue(int32_t timer)
{
    return timers[timer];
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    HAL_GPIO_TogglePin(TIMER_INT_GPIOx, TIMER_GPIO_PIN_X);

    for (int timer = 0; timer < NUM_TIMERS; timer++)
    {
        if (timers[timer] > 0) timers[timer]--;
    }
    if (htim == NULL) return;
} // end - void TIMER_IRQHandler(void)

