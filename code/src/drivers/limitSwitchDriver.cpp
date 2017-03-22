#include "limitSwitchDriver.h"

CLimSwDriver::CLimSwDriver(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_x)
{
    m_GPIOx      = GPIOx;
    m_GPIO_Pin_x = GPIO_Pin_x;
}

CLimSwDriver::~CLimSwDriver(void)
{
}

void CLimSwDriver::Initialize_Hardware(void)
{
    GPIO_InitTypeDef        GPIO_InitStruct;

    // Init Peripheral clocks
    InitializeGPIOClock(m_GPIOx);

    // Config PINs
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    GPIO_InitStruct.Pin   = m_GPIO_Pin_x;
    HAL_GPIO_Init(m_GPIOx, &GPIO_InitStruct);
} // end - void CLimSwDriver::Initialize_Hardware(void)

GPIO_PinState CLimSwDriver::SampleInput(void)
{
    return HAL_GPIO_ReadPin(m_GPIOx, m_GPIO_Pin_x);
}

