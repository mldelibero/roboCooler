#include "stm32f4xx_hal.h"

void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    if (GPIOx == NULL) return;
    if (GPIO_Pin)      return;
}
