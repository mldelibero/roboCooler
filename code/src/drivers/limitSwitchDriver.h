/**
 ******************************************************************************
 * @file    limitSwitchDriver.h
 * @author  Michael DeLibero
 * @brief   Header file for limitSwitchDriver.cpp
 ******************************************************************************
 */
#ifndef __LIMIT_SWITCH_DRIVER_H
#define __LIMIT_SWITCH_DRIVER_H
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_rcc.h>
#include "CDriver.h"

class CLimSwDriver : CDriver
{
    public:
        CLimSwDriver(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x);
        virtual ~CLimSwDriver(void);

        virtual void          Initialize_Hardware(void);
        virtual GPIO_PinState SampleInput(void);

    protected:
        uint16_t      m_GPIO_Pin_x;
        GPIO_TypeDef* m_GPIOx;
}; // end -- class CLimSwDriver

#endif //#ifndef __LIMIT_SWITCH_DRIVER_H

