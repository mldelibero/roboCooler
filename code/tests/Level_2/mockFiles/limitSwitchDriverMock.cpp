#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "limitSwitchDriver.h"
#include "limitSwitchDriverMock.h"

uint32_t      Mock_RCC_AHB1Periph_GPIOx;
GPIO_TypeDef* Mock_GPIOx;
uint16_t      Mock_GPIO_Pin_x;

CLimSwDriverMock::CLimSwDriverMock() : CLimSwDriver(Mock_RCC_AHB1Periph_GPIOx, Mock_GPIOx, Mock_GPIO_Pin_x)
{
    m_MockInputValue = Bit_RESET;
}

CLimSwDriverMock::~CLimSwDriverMock(void)
{
}

void CLimSwDriverMock::Initialize_Hardware(void)
{
    m_MockInputValue = Bit_RESET;
    mock().actualCall("CLimSwDriver::Initialize_Hardware");
}

BitAction CLimSwDriverMock::SampleInput(void)
{
    mock().actualCall("CLimSwDriver::SampleInput");
    return m_MockInputValue;
}

void CLimSwDriverMock::Set_MockInput(void)
{
    m_MockInputValue = Bit_SET;
}

void CLimSwDriverMock::Clear_MockInput(void)
{
    m_MockInputValue = Bit_RESET;
}

