#ifndef __STM32F4XX_RCC_MOCK_H
#define __STM32F4XX_RCC_MOCK_H
#include "stm32f4xx.h"

#define RCC_AHB1Periph_GPIOB             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOE             ((uint32_t)0x00000002)

void RCC_AHB1PeriphClockCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
extern uint32_t RCC_APB1Periph_TIM4;

#endif /* #ifndef __STM32F4XX_RCC_MOCK_H */
