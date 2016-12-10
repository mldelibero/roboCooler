#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "capTouchDriver.h"

CCapTouchDriver::CCapTouchDriver(
                uint32_t      SCL_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SCL_GPIOx,
                uint16_t      SCL_GPIO_Pin_x,
                uint32_t      SDA_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SDA_GPIOx,
                uint16_t      SDA_GPIO_Pin_x,
                uint32_t      IRQ_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* IRQ_GPIOx,
                uint16_t      IRQ_GPIO_Pin_x)
{
    m_SCL_RCC_AHB1Periph_GPIOx = SCL_RCC_AHB1Periph_GPIOx;
    m_SCL_GPIOx                = SCL_GPIOx;
    m_SCL_GPIO_Pin_x           = SCL_GPIO_Pin_x;

    m_SDA_RCC_AHB1Periph_GPIOx = SDA_RCC_AHB1Periph_GPIOx;
    m_SDA_GPIOx                = SDA_GPIOx;
    m_SDA_GPIO_Pin_x           = SDA_GPIO_Pin_x;

    m_IRQ_RCC_AHB1Periph_GPIOx = IRQ_RCC_AHB1Periph_GPIOx;
    m_IRQ_GPIOx                = IRQ_GPIOx;
    m_IRQ_GPIO_Pin_x           = IRQ_GPIO_Pin_x;
}

CCapTouchDriver::~CCapTouchDriver(void)
{
}
    /*
       void CCapTouchDriver::Initialize_Hardware(void)
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

    BitAction CCapTouchDriver::SampleInput(void)
    {
    return (BitAction)GPIO_ReadInputDataBit(m_GPIOx, m_GPIO_Pin_x);
    }
    */

