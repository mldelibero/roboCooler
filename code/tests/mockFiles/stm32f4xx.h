#ifndef _STM32F4XX__H
#define _STM32F4XX__H

#include <stdint.h>

typedef struct
{
} TIM_TypeDef;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

extern TIM_TypeDef  TIMn;
extern TIM_TypeDef* TIM4;

#endif /* ifndef _STM32F4XX__H */
