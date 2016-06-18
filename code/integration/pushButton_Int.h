#ifndef __PUSHBUTTON_INT_H
#define __PUSHBUTTON_INT_H
#include <stm32f4xx_gpio.h>
#include "timerDriver.h"

// PE11
#define PBUP_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define PBUP_INT_GPIOx                    GPIOE
#define PBUP_INT_GPIO_PIN_X               GPIO_Pin_11

// PE13
#define PBDN_INT_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define PBDN_INT_GPIOx                    GPIOE
#define PBDN_INT_GPIO_PIN_X               GPIO_Pin_13

void init_PushButtons_Int(void);
void pushButtons_Int(void);
#endif // #ifndef __PUSHBUTTON_INT_H
