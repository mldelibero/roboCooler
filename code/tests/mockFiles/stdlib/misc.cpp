#include <CppUTestExt/MockSupport.h>
#include "stm32f4xx.h"
#include "misc.h"

void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
{
    mock().actualCall("NVIC_Init");
    if (NVIC_InitStruct == 0) return;
}
