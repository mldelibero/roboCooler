#include "stm32f4xx.h"

TIM_TypeDef  TIMx;         // Actual memory location for timers
TIM_TypeDef* TIM4 = &TIMx; // pointer for timer4
