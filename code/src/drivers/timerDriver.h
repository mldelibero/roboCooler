/**
  ******************************************************************************
  * @file    timerDriver.h
  * @author  Michael DeLibero
  * @brief   Header file for timerDriver.cpp
  ******************************************************************************
  */
#ifndef __TIMER_DRIVER_H
#define __TIMER_DRIVER_H
#include "stm32f4xx_hal.h"

#define TIMER_CLK                     10000
#define TIMER_FREQ                    1000
#define TIMER_PER                     (TIMER_CLK / TIMER_FREQ - 1)
#define TIMER_TIMx_IRQn               TIM4_IRQn
#define TIMER_IRQHandler              TIM4_IRQ_Handler

#define TIMER_1MS                     1

#define TIMER_TIMx                    TIM4
#define TIMER_TIMx_IRQn               TIM4_IRQn
#define TIM_CLK_ENABLE                __TIM4_CLK_ENABLE
#define TIMER_TIMx_IRQHandler         TIM4_IRQHandler
#define TIMER_GPIO_AF                 GPIO_AF_TIM4 // Used by integration tester

void init_TimerDriver(void);
extern TIM_HandleTypeDef TIM_Handle;
#endif // #ifndef __TIMER_DRIVER_H

