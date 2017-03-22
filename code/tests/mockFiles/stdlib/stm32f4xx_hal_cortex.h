/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_CORTEX_H
#define __STM32F4xx_HAL_CORTEX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"

void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_CORTEX_H */
