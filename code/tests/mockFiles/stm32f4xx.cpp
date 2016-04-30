#include "stm32f4xx.h"

uint32_t SystemCoreClock = 168000000;

TIM_TypeDef  TIMx;         // Actual memory location for timers
TIM_TypeDef* TIM4 = &TIMx; // pointer for timer4

GPIO_TypeDef GPIOx; // Actual memory location for GPIO
GPIO_TypeDef* GPIOB = &GPIOx;
GPIO_TypeDef* GPIOE = &GPIOx;

