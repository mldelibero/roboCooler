#include <CppUTestExt/MockSupport.h>
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"

uint32_t RCC_APB1Periph_TIM4;

void RCC_AHB1PeriphClockCmd(uint32_t RCC_AHB1Periph, FunctionalState NewState)
{
    mock().actualCall("RCC_AHB1PeriphClockCmd");
    if (RCC_AHB1Periph) return;
    if (NewState      ) return;
}

void RCC_AHB2PeriphClockCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState)
{
    mock().actualCall("RCC_AHB2PeriphClockCmd");
    if (RCC_AHB2Periph) return;
    if (NewState      ) return;
}

void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState)
{
    mock().actualCall("RCC_APB1PeriphClockCmd");
    if (RCC_APB1Periph == 0) return;
    if (NewState == ENABLE ) return;
}
