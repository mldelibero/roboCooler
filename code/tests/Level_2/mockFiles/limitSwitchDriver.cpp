#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "limitSwitchDriver.h"

CLimSwDriver::CLimSwDriver(
        uint32_t      RCC_AHB1Periph_GPIOx,
        GPIO_TypeDef* GPIOx,
        uint16_t      GPIO_Pin_x)
{
    m_RCC_AHB1Periph_GPIOx = RCC_AHB1Periph_GPIOx;
    m_GPIOx                = GPIOx;
    m_GPIO_Pin_x           = GPIO_Pin_x;
}

CLimSwDriver::~CLimSwDriver(void)
{
}

void CLimSwDriver::Initialize_Hardware(void)
{
    mock().actualCall("CLimSwDriver::Initialize_Hardware");
}

BitAction CLimSwDriver::SampleInput(void)
{
    mock().actualCall("CLimSwDriver::SampleInput");
    return (BitAction)GPIO_ReadInputDataBit(m_GPIOx, m_GPIO_Pin_x);
    //return Bit_SET;
}

