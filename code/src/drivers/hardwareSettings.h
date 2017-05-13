#ifndef __HARDWARESETTINGS_H
#define __HARDWARESETTINGS_H

#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_usart.h"

typedef struct
{
    GPIO_TypeDef* GPIOX;                // Where X is the Port letter (A,B...)
    uint8_t       GPIO_AF;              // Where PER is the Peripheral type and X is the Peripheral number
    uint16_t      Pin_N;                // Where N is the Pin number  (1,2...)
} GPIO_Settings_t;
#endif //#ifndef __HARDWARESETTINGS_H

