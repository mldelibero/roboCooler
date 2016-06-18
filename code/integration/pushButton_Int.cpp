#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include "pushButton.h"
#include "pushButtonDriver.h"
#include "pushButton_Int.h"

/**
 * @brief    This test mirrors the push button inputs on output pins.
 * @note     View with an oscilloscope to validate debouncing.
 */
void init_PushButtons_Int(void)
{
    init_PushButton();

    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    RCC_AHB1PeriphClockCmd(PBUP_INT_AHB1Periph_GPIOx,  ENABLE);
    RCC_AHB1PeriphClockCmd(PBDN_INT_AHB1Periph_GPIOx,  ENABLE);

    // Init GPIO
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;

    GPIO_InitStruct.GPIO_Pin   = PBUP_INT_GPIO_PIN_X;
    GPIO_Init(PBUP_INT_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = PBDN_INT_GPIO_PIN_X;
    GPIO_Init(PBDN_INT_GPIOx, &GPIO_InitStruct);
} // end - void init_PushButtons_Int(void)

/**
 * @brief   This mirrors the filtered pushbutton inputs on some output pins
 * @note    Call in main() frequently
 */
void pushButtons_Int(void)
{
    Run_PushButtons();

    GPIO_WriteBit(PBUP_INT_GPIOx, PBUP_INT_GPIO_PIN_X, BitAction(Get_PbUpStatus()));
    GPIO_WriteBit(PBDN_INT_GPIOx, PBDN_INT_GPIO_PIN_X, BitAction(Get_PbDnStatus()));
} // end - void pushButtons_Int(void)

