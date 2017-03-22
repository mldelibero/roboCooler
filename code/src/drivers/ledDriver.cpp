#include "ledDriver.h"

void init_ledDriver(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    LED0_CLK_ENABLE();
    LED1_CLK_ENABLE();
    LED2_CLK_ENABLE();
    LED3_CLK_ENABLE();
    LED4_CLK_ENABLE();
    LED5_CLK_ENABLE();
    LED6_CLK_ENABLE();
    LED7_CLK_ENABLE();

    // Init GPIO
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;

    GPIO_InitStruct.Pin   = LED0_GPIO_PIN_X;
    HAL_GPIO_Init(LED0_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED1_GPIO_PIN_X;
    HAL_GPIO_Init(LED1_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED2_GPIO_PIN_X;
    HAL_GPIO_Init(LED2_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED3_GPIO_PIN_X;
    HAL_GPIO_Init(LED3_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED4_GPIO_PIN_X;
    HAL_GPIO_Init(LED4_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED5_GPIO_PIN_X;
    HAL_GPIO_Init(LED5_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED6_GPIO_PIN_X;
    HAL_GPIO_Init(LED6_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = LED7_GPIO_PIN_X;
    HAL_GPIO_Init(LED7_GPIOx, &GPIO_InitStruct);

    // Turn off all LEDs
    HAL_GPIO_WritePin(LED0_GPIOx, LED0_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED1_GPIOx, LED1_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED2_GPIOx, LED2_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED3_GPIOx, LED3_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED4_GPIOx, LED4_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED5_GPIOx, LED5_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED6_GPIOx, LED6_GPIO_PIN_X, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED7_GPIOx, LED7_GPIO_PIN_X, GPIO_PIN_RESET);
} // end - void init_ledDriver(void)

void SetLeds(uint8_t ledValues)
{

    HAL_GPIO_WritePin(LED0_GPIOx, LED0_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<0) > 0)));
    HAL_GPIO_WritePin(LED1_GPIOx, LED1_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<1) > 0)));
    HAL_GPIO_WritePin(LED2_GPIOx, LED2_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<2) > 0)));
    HAL_GPIO_WritePin(LED3_GPIOx, LED3_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<3) > 0)));
    HAL_GPIO_WritePin(LED4_GPIOx, LED4_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<4) > 0)));
    HAL_GPIO_WritePin(LED5_GPIOx, LED5_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<5) > 0)));
    HAL_GPIO_WritePin(LED6_GPIOx, LED6_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<6) > 0)));
    HAL_GPIO_WritePin(LED7_GPIOx, LED7_GPIO_PIN_X, (GPIO_PinState((ledValues & 1<<7) > 0)));
}

uint8_t Get_LedStates(void)
{
    uint8_t ledState = 0;

    if (HAL_GPIO_ReadPin(LED0_GPIOx, LED0_GPIO_PIN_X)) ledState |= 1 << 0;
    if (HAL_GPIO_ReadPin(LED1_GPIOx, LED1_GPIO_PIN_X)) ledState |= 1 << 1;
    if (HAL_GPIO_ReadPin(LED2_GPIOx, LED2_GPIO_PIN_X)) ledState |= 1 << 2;
    if (HAL_GPIO_ReadPin(LED3_GPIOx, LED3_GPIO_PIN_X)) ledState |= 1 << 3;
    if (HAL_GPIO_ReadPin(LED4_GPIOx, LED4_GPIO_PIN_X)) ledState |= 1 << 4;
    if (HAL_GPIO_ReadPin(LED5_GPIOx, LED5_GPIO_PIN_X)) ledState |= 1 << 5;
    if (HAL_GPIO_ReadPin(LED6_GPIOx, LED6_GPIO_PIN_X)) ledState |= 1 << 6;
    if (HAL_GPIO_ReadPin(LED7_GPIOx, LED7_GPIO_PIN_X)) ledState |= 1 << 7;

    return ledState;
}

