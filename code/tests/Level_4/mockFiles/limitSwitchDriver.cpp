#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "limitSwitchDriver.h"

CLimSwDriver::CLimSwDriver(uint32_t RCC_AHB1Periph_GPIOx, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{
    if (RCC_AHB1Periph_GPIOx) return;
    if (GPIOx)                return;
    if (GPIO_Pin_x)           return;
}

CLimSwDriver::~CLimSwDriver(void)
{}

void CLimSwDriver::Initialize_Hardware(void)
{
    mock().actualCall("CLimSwDriver::Initialize_Hardware");
}

