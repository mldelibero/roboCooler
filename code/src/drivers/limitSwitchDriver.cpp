#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
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
    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    RCC_AHB1PeriphClockCmd(m_RCC_AHB1Periph_GPIOx , ENABLE);

    // Init GPIO
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;

    GPIO_InitStruct.GPIO_Pin   = m_GPIO_Pin_x;
    GPIO_Init(m_GPIOx, &GPIO_InitStruct);
}

BitAction CLimSwDriver::SampleInput(void)
{
    return (BitAction)GPIO_ReadInputDataBit(m_GPIOx, m_GPIO_Pin_x);
}

