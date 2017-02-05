#ifndef __STM32F4XX_RCC_MOCK_H
#define __STM32F4XX_RCC_MOCK_H
#include "stm32f4xx.h"

#define RCC_AHB1Periph_GPIOA             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOB             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOC             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOD             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_GPIOE             ((uint32_t)0x00000002)
#define RCC_AHB1Periph_DMA1              ((uint32_t)0x00200000)
#define RCC_APB1Periph_I2C1              ((uint32_t)0x00200000)
#define RCC_APB1Periph_USART2            ((uint32_t)0x00020000)

void RCC_AHB1PeriphClockCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState);
void RCC_AHB2PeriphClockCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
extern uint32_t RCC_APB1Periph_TIM4;

#endif /* #ifndef __STM32F4XX_RCC_MOCK_H */
