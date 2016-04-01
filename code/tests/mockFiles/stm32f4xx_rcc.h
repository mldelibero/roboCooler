#ifndef __STM32F4XX_RCC_MOCK_H
#define __STM32F4XX_RCC_MOCK_H
#include "stm32f4xx.h"
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
extern uint32_t RCC_APB1Periph_TIM4;

#endif /* #ifndef __STM32F4XX_RCC_MOCK_H */
