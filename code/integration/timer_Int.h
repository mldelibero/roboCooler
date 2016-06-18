#ifndef __TIMER_INT_H
#define __TIMER_INT_H
#include <stm32f4xx_gpio.h>
#include "timerDriver.h"

// PB7
#define TIMERDRIVER_INT_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOB
#define TIMERDRIVER_INT_GPIOx                  GPIOB
#define TIMERDRIVER_INT_GPIO_PinSourcex        GPIO_PinSource7
#define TIMERDRIVER_INT_GPIO_PIN_X             GPIO_Pin_7
#define TIMERDRIVER_INT_OCxInit                TIM_OC2Init

// PE14
#define TIMER_INT_AHB1Periph_GPIOx             RCC_AHB1Periph_GPIOE
#define TIMER_INT_GPIOx                        GPIOE
#define TIMER_INT_GPIO_PinSourcex              GPIO_PinSource14
#define TIMER_INT_GPIO_PIN_X                   GPIO_Pin_14

#define TIMER_INT_FREQ                         50 * TIMER_1MS

void init_TimerDriver_Int(void);
void init_Timer_Int(void);
void timer_Int(void);
#endif // ifndef __TIMER_INT_H

