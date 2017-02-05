#ifndef __HARDWARESETTINGS_H
#define __HARDWARESETTINGS_H

#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"

typedef struct
{
    uint32_t      RCC_AHB1Periph_GPIOX; // Where X is the Port letter (A,B...)
    GPIO_TypeDef* GPIOX;                // Where X is the Port letter (A,B...)
    uint8_t       PinSourceN;           // Where N is the Pin number  (1,2...)
    uint8_t       GPIO_AF_PERN;         // Where PER is the Peripheral type and X is the Peripheral number
    uint16_t      Pin_N;                // Where N is the Pin number  (1,2...)
} GPIO_Settings_t;

typedef struct
{
    uint32_t RCC_APBNPeriph_USARTN;   // Where N is the Peripheral number  (1,2...)
    USART_TypeDef* USARTN;
} UART_Settings_t;

typedef struct
{
    uint32_t DMA_Channel_N;
    DMA_Stream_TypeDef* DMAN_StreamN;
} DMA_Settings_t;
#endif //#ifndef __HARDWARESETTINGS_H

