#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_rcc.h>

#include "pushButtonDriver.h"
#include "robocooler.h"

void init_PushButtonDriver(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    PBUP_CLK_ENABLE();
    PBDN_CLK_ENABLE();

    // Init GPIO
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;

    GPIO_InitStruct.Pin   = PBUP_GPIO_PIN_X;
    HAL_GPIO_Init(PBUP_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = PBDN_GPIO_PIN_X;
    HAL_GPIO_Init(PBDN_GPIOx, &GPIO_InitStruct);
} // end - void init_PushButtonDriver(void)

