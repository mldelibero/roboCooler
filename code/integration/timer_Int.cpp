#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include "timerDriver.h"
#include "timerDriver_Int.h"

/*
 * brief    This test verifies the frequency of the system timer.
 * brief    Look at the gpio pin with an oscilloscope
 * brief    You should measure a square wave with a frency of TIMER_FREQ / 2
 */
void init_TimerDriver_Int(void) {
    GPIO_InitTypeDef        GPIO_InitStruct;
    TIM_OCInitTypeDef       TIM_OCInitStruct;

    // Init Peripheral clocks
    RCC_AHB1PeriphClockCmd(TIMER_INT_AHB1Periph_GPIOx,  ENABLE);

    // Init GPIO
    GPIO_PinAFConfig(TIMER_INT_GPIOx, TIMER_INT_GPIO_PinSourcex, TIMER_GPIO_AF);

    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Pin   = TIMER_INT_GPIO_PIN_X;
    GPIO_Init(TIMER_INT_GPIOx,&GPIO_InitStruct);

    // Init timer
    TIM_OCInitStruct.TIM_OutputState  = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Disable;
    TIM_OCInitStruct.TIM_Pulse        = TIMER_PER / 2;
    TIM_OCInitStruct.TIM_OCPolarity   = TIM_OCPolarity_High;
    TIM_OCInitStruct.TIM_OCIdleState  = TIM_OCIdleState_Set;

    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_Toggle;

    TIMER_INT_OCxInit(TIMER_TIMx, &TIM_OCInitStruct);
} // end - void init_TimerDriver_Int(void)

