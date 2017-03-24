/**
 ******************************************************************************
 * @file    limitSwitchDriverMock.cpp
 * @author  Michael DeLibero
 * @brief   ....
 ******************************************************************************
 */
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "limitSwitchDriver.h"
#include "limitSwitchDriverMock.h"
#include "stm32f4xx_hal_gpio.h"

GPIO_TypeDef* Mock_GPIOx;
uint16_t      Mock_GPIO_Pin_x;

// --- Mock to compile limitSwitchDriver
CLimSwDriver::CLimSwDriver(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{
    if (GPIOx)                return;
    if (GPIO_Pin_x)           return;
}

CLimSwDriver::~CLimSwDriver(void)
{
}

void CLimSwDriver::Initialize_Hardware(void)
{
    mock().actualCall("CLimSwDriver::Initialize_Hardware");
}

GPIO_PinState CLimSwDriver::SampleInput(void)
{
    return GPIO_PIN_SET;
}

// -- Mock that abstracts limitSwitchDriver and allows input control
CLimSwDriverMock::CLimSwDriverMock() : CLimSwDriver(Mock_GPIOx, Mock_GPIO_Pin_x)
{
    m_MockInputValue = GPIO_PIN_RESET;
}

CLimSwDriverMock::~CLimSwDriverMock(void)
{
}

void CLimSwDriverMock::Initialize_Hardware(void)
{
    m_MockInputValue = GPIO_PIN_RESET;
    mock().actualCall("CLimSwDriver::Initialize_Hardware");
}

GPIO_PinState CLimSwDriverMock::SampleInput(void)
{
    mock().actualCall("CLimSwDriver::SampleInput");
    return m_MockInputValue;
}

void CLimSwDriverMock::Set_MockInput(void)
{
    m_MockInputValue = GPIO_PIN_SET;
}

void CLimSwDriverMock::Clear_MockInput(void)
{
    m_MockInputValue = GPIO_PIN_RESET;
}

