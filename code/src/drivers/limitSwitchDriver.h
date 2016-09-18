#ifndef __LIMIT_SWITCH_DRIVER_H
#define __LIMIT_SWITCH_DRIVER_H
#include <stm32f4xx_gpio.h>

// PE6
#define OPEN_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define OPEN_LIMSW_GPIOx                     GPIOE
#define OPEN_LIMSW_GPIO_PIN_X                GPIO_Pin_6

// PE4
#define CLOSE_LIMSW_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define CLOSE_LIMSW_GPIOx                    GPIOE
#define CLOSE_LIMSW_GPIO_PIN_X               GPIO_Pin_5

void init_LimSwDriver(void);
uint8_t OpenedLimSwitch_SampleInput(void);
uint8_t ClosedLimSwitch_SampleInput(void);

#endif //#ifndef __LIMIT_SWITCH_DRIVER_H

