#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "ledDriver.h"

void init_ledDriver(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    RCC_AHB2PeriphClockCmd(LED0_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED1_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED2_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED3_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED4_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED5_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED6_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(LED7_AHB1Periph_GPIOx,  ENABLE);

    // Init GPIO
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;

    GPIO_InitStruct.GPIO_Pin   = LED0_GPIO_PIN_X;
    GPIO_Init(LED0_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED1_GPIO_PIN_X;
    GPIO_Init(LED1_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED2_GPIO_PIN_X;
    GPIO_Init(LED2_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED3_GPIO_PIN_X;
    GPIO_Init(LED3_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED4_GPIO_PIN_X;
    GPIO_Init(LED4_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED5_GPIO_PIN_X;
    GPIO_Init(LED5_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED6_GPIO_PIN_X;
    GPIO_Init(LED6_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = LED7_GPIO_PIN_X;
    GPIO_Init(LED7_GPIOx, &GPIO_InitStruct);

    // Turn off all LEDs
    GPIO_ResetBits(LED0_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED1_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED2_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED3_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED4_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED5_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED6_GPIOx, LED7_GPIO_PIN_X);
    GPIO_ResetBits(LED7_GPIOx, LED7_GPIO_PIN_X);
} // end - void init_ledDriver(void)

