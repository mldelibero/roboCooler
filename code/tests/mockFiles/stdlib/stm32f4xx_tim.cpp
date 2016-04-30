#include <CppUTestExt/MockSupport.h>
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"

uint16_t TIM_IT_Update;

void TIM_DeInit(TIM_TypeDef* TIMx)
{
    mock().actualCall("TIM_DeInit");
    if (TIMx == 0)          return;
}

void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT)
{
    if (TIMx)   return;
    if (TIM_IT) return;
}

void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState)
{
    mock().actualCall("TIM_Cmd");

    if (NewState == ENABLE) return;
    if (TIMx == 0)          return;
}

void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState)
{
    mock().actualCall("TIM_ITConfig");

    if (TIMx    ) return;
    if (TIM_IT  ) return;
    if (NewState) return;
}

void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct)
{
    mock().actualCall("TIM_OC2Init");
    if (TIMx            ) return;
    if (TIM_OCInitStruct) return;
}

void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct)
{
    mock().actualCall("TIM_TimeBaseInit");

    if (TIM_TimeBaseInitStruct) return;
    if (TIMx == 0)              return;
}

