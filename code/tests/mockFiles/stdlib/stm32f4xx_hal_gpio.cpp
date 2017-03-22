#include "stm32f4xx_hal.h"

void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    if (GPIOx == NULL) return;
    if (GPIO_Pin)      return;
}

void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
    if (GPIOx == NULL) return;
    if (GPIO_Init    ) return;
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    if (GPIOx == NULL) return GPIO_PIN_SET;
    if (GPIO_Pin     ) return GPIO_PIN_SET;
    return GPIO_PIN_SET;
}

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (GPIOx == NULL) return;
    if (GPIO_Pin     ) return;
    if (PinState     ) return;
}

