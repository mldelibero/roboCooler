/**
  ******************************************************************************
  * @file    limitSwitchDriverMock.h
  * @author  Michael DeLibero
  * @brief   Header file for limitSwitchDriverMock.cpp
  ******************************************************************************
  */
#ifndef __LIMIT_SWITCH_DRIVER_MOCK_H
#define __LIMIT_SWITCH_DRIVER_MOCK_H
#include "stm32f4xx_hal.h"
class CLimSwDriverMock : public CLimSwDriver
{
    public:
        CLimSwDriverMock(void);
        ~CLimSwDriverMock(void);

        void Initialize_Hardware(void);
        GPIO_PinState SampleInput(void);
        void Set_MockInput(void);
        void Clear_MockInput(void);

    private:
        GPIO_PinState m_MockInputValue;
};
#endif // #ifndef __LIMIT_SWITCH_DRIVER_MOCK_H

