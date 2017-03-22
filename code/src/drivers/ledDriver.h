#ifndef __LEDDRIVER_H
#define __LEDDRIVER_H
#include "stm32f4xx_hal.h"
#include <stm32f4xx.h>

// PC1
#define LED0_CLK_ENABLE                __HAL_RCC_GPIOC_CLK_ENABLE
#define LED0_GPIOx                     GPIOC
#define LED0_GPIO_PIN_X                GPIO_PIN_1

// PA1
#define LED1_CLK_ENABLE                __HAL_RCC_GPIOA_CLK_ENABLE
#define LED1_GPIOx                     GPIOA
#define LED1_GPIO_PIN_X                GPIO_PIN_1

// PA3
#define LED2_CLK_ENABLE                __HAL_RCC_GPIOA_CLK_ENABLE
#define LED2_GPIOx                     GPIOA
#define LED2_GPIO_PIN_X                GPIO_PIN_3

// PA7
#define LED3_CLK_ENABLE                __HAL_RCC_GPIOA_CLK_ENABLE
#define LED3_GPIOx                     GPIOA
#define LED3_GPIO_PIN_X                GPIO_PIN_7

// PC5
#define LED4_CLK_ENABLE                __HAL_RCC_GPIOC_CLK_ENABLE
#define LED4_GPIOx                     GPIOC
#define LED4_GPIO_PIN_X                GPIO_PIN_5

// PB1
#define LED5_CLK_ENABLE                __HAL_RCC_GPIOB_CLK_ENABLE
#define LED5_GPIOx                     GPIOB
#define LED5_GPIO_PIN_X                GPIO_PIN_1

// PE7
#define LED6_CLK_ENABLE                __HAL_RCC_GPIOE_CLK_ENABLE
#define LED6_GPIOx                     GPIOE
#define LED6_GPIO_PIN_X                GPIO_PIN_7

// PE9
#define LED7_CLK_ENABLE                __HAL_RCC_GPIOE_CLK_ENABLE
#define LED7_GPIOx                     GPIOE
#define LED7_GPIO_PIN_X                GPIO_PIN_9

#define TIMER_INT_GPIOx                LED0_GPIOx
#define TIMER_GPIO_PIN_X               LED0_GPIO_PIN_X

void init_ledDriver(void);
void SetLeds(uint8_t ledValues);
uint8_t Get_LedStates(void);
#endif // #ifndef __LEDDRIVER_H

