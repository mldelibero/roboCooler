#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>

#include "pushButtonDriver.h"

void init_PushButtonDriver(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    RCC_AHB1PeriphClockCmd(PBUP_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(PBDN_AHB1Periph_GPIOx,  ENABLE);

    // Init GPIO
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;

    GPIO_InitStruct.GPIO_Pin   = PBUP_GPIO_PIN_X;
    GPIO_Init(PBUP_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = PBDN_GPIO_PIN_X;
    GPIO_Init(PBDN_GPIOx, &GPIO_InitStruct);
} // end - void init_PushButtonDriver(void)
