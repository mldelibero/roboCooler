
#include <stm32f4xx_hal.h>
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct)
{
    if (RCC_OscInitStruct == NULL) return HAL_OK;
    else                           return HAL_OK;
}

HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency)
{
 if (RCC_ClkInitStruct == NULL) return HAL_OK;
 if (FLatency)                  return HAL_OK;
 else                           return HAL_OK;
}

