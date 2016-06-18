#ifndef __TIMER_INT_H
#define __TIMER_INT_H
#include <stm32f4xx_gpio.h>
#include "timerDriver.h"

// PE11
#define PBUP_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define PBUP_INT_GPIOx                    GPIOE
#define PBUP_INT_GPIO_PinSourcex          GPIO_PinSource11
#define PBUP_INT_GPIO_PIN_X               GPIO_Pin_11

// PE13
#define PBDN_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define PBDN_INT_GPIOx                    GPIOE
#define PBDN_INT_GPIO_PinSourcex          GPIO_PinSource13
#define PBDN_INT_GPIO_PIN_X               GPIO_Pin_13
#define TIMER_INT_FREQ                    50 * TIMER_1MS

void init_TimerDriver_Int(void);
void init_Timer_Int(void);
void timer_Int(void);
#endif // ifndef __TIMER_INT_H

