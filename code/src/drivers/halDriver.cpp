#include "halDriver.h"
#include "stm32f4xx_hal.h"
#include <string.h>

CHalDriver::CHalDriver(GPIO_TypeDef* GPIOn, uint16_t m_GPIO_PIN_n)
{
    m_GPIOn        = GPIOn;
    m_GPIO_PIN_n   = GPIO_PIN_n;
}

CHalDriver::~CHalDriver(void) {}

void CHalDriver::Initialize_Hardware(void)
{
    GPIO_InitTypeDef               GPIO_InitStruct;
    memset(&GPIO_InitStruct, 0 , sizeof(GPIO_InitStruct));

    /// @bug Shouldn't know the port
    __HAL_RCC_GPIOE_CLK_ENABLE();

    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;

    GPIO_InitStruct.Pin       = m_GPIO_PIN_n;
    HAL_GPIO_Init(m_GPIOn, &GPIO_InitStruct);
}

GPIO_PinState CHalDriver::Is_Triggered(void)
{
    return HAL_GPIO_ReadPin(m_GPIOn, m_GPIO_PIN_n);
}

