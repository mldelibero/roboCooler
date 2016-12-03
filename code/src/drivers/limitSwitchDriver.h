#ifndef __LIMIT_SWITCH_DRIVER_H
#define __LIMIT_SWITCH_DRIVER_H
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "CDriver.h"

// PE6
#define OPEN_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOE
#define OPEN_LIMSW_GPIOx                     GPIOE
#define OPEN_LIMSW_GPIO_PIN_X                GPIO_Pin_6

// PE4
#define CLOSE_LIMSW_AHB1Periph_GPIOx         RCC_AHB1Periph_GPIOE
#define CLOSE_LIMSW_GPIOx                    GPIOE
#define CLOSE_LIMSW_GPIO_PIN_X               GPIO_Pin_5

class CLimSwDriver : CDriver
{
    public:
        CLimSwDriver(
                uint32_t      RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* GPIOx,
                uint16_t      GPIO_Pin_x);
        virtual ~CLimSwDriver(void);

        void Initialize_Hardware(void);
        virtual BitAction SampleInput(void);

    protected:
        uint32_t      m_RCC_AHB1Periph_GPIOx;
        uint16_t      m_GPIO_Pin_x;
        GPIO_TypeDef* m_GPIOx;
}; // end -- class CLimSwDriver

#endif //#ifndef __LIMIT_SWITCH_DRIVER_H

