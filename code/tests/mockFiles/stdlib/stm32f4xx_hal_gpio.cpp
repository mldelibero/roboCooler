#include "stm32f4xx_hal.h"

void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    GPIOx->pinStates &= (GPIOx->pinStates & GPIO_Pin) ^ 1;
}

void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
    GPIOx->pinStates = 0;
    if (GPIO_Init == NULL) return;
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    return GPIO_PinState((GPIOx->pinStates & GPIO_Pin) > 1);
}

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    if (PinState == GPIO_PIN_SET) GPIOx->pinStates |= GPIO_Pin;
    else                          GPIOx->pinStates &= uint16_t(~GPIO_Pin);
}

