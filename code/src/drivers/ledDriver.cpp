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

void SetLeds(uint8_t ledValues)
{
    GPIO_WriteBit(LED0_GPIOx, LED0_GPIO_PIN_X, (BitAction((ledValues & 1<<0) > 0)));
    GPIO_WriteBit(LED1_GPIOx, LED1_GPIO_PIN_X, (BitAction((ledValues & 1<<1) > 0)));
    GPIO_WriteBit(LED2_GPIOx, LED2_GPIO_PIN_X, (BitAction((ledValues & 1<<2) > 0)));
    GPIO_WriteBit(LED3_GPIOx, LED3_GPIO_PIN_X, (BitAction((ledValues & 1<<3) > 0)));
    GPIO_WriteBit(LED4_GPIOx, LED4_GPIO_PIN_X, (BitAction((ledValues & 1<<4) > 0)));
    GPIO_WriteBit(LED5_GPIOx, LED5_GPIO_PIN_X, (BitAction((ledValues & 1<<5) > 0)));
    GPIO_WriteBit(LED6_GPIOx, LED6_GPIO_PIN_X, (BitAction((ledValues & 1<<6) > 0)));
    GPIO_WriteBit(LED7_GPIOx, LED7_GPIO_PIN_X, (BitAction((ledValues & 1<<7) > 0)));
}

uint8_t Get_LedStates(void)
{
    uint8_t ledState = 0;
    if (GPIO_ReadInputDataBit(LED0_GPIOx, LED0_GPIO_PIN_X)) ledState |= 1 << 0;
    if (GPIO_ReadInputDataBit(LED1_GPIOx, LED1_GPIO_PIN_X)) ledState |= 1 << 1;
    if (GPIO_ReadInputDataBit(LED2_GPIOx, LED2_GPIO_PIN_X)) ledState |= 1 << 2;
    if (GPIO_ReadInputDataBit(LED3_GPIOx, LED3_GPIO_PIN_X)) ledState |= 1 << 3;
    if (GPIO_ReadInputDataBit(LED4_GPIOx, LED4_GPIO_PIN_X)) ledState |= 1 << 4;
    if (GPIO_ReadInputDataBit(LED5_GPIOx, LED5_GPIO_PIN_X)) ledState |= 1 << 5;
    if (GPIO_ReadInputDataBit(LED6_GPIOx, LED6_GPIO_PIN_X)) ledState |= 1 << 6;
    if (GPIO_ReadInputDataBit(LED7_GPIOx, LED7_GPIO_PIN_X)) ledState |= 1 << 7;

    return ledState;
}
