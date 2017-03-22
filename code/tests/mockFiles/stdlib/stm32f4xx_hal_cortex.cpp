#include "stm32f4xx_hal_cortex.h"

void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{
    if (IRQn           ) return;
    if (PreemptPriority) return;
    if (SubPriority    ) return;
}

void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
    if (IRQn) return;
}

