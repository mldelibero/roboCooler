#include <stm32f4xx_hal.h>
#include "capTouchDriver.h"

#define CS_I2C_ADDR_RE     0xB5

CCapTouchDriver::CCapTouchDriver(GPIO_TypeDef* IRQ_GPIOx, uint16_t IRQ_GPIO_PIN_x, ARM_DRIVER_I2C* Driver_I2Cn)
{
    m_Driver_I2Cn    = Driver_I2Cn;
    m_IRQ_GPIOx      = IRQ_GPIOx;
    m_IRQ_GPIO_PIN_x = IRQ_GPIO_PIN_x;
    m_SlaveAddr      = 0x5B;
} // end - CCapTouchDriver::CCapTouchDriver

CCapTouchDriver::~CCapTouchDriver(void)
{
}

void CCapTouchDriver::Initialize_Hardware(void)
{
    m_Driver_I2Cn->Initialize(NULL);
    m_Driver_I2Cn->PowerControl(ARM_POWER_FULL);
    m_Driver_I2Cn->Control(ARM_I2C_BUS_SPEED_STANDARD | ARM_I2C_OWN_ADDRESS | ARM_I2C_BUS_CLEAR, 0);

    GPIO_InitTypeDef    GPIO_InitStruct;

    // Init Peripheral clocks
    InitializeGPIOClock(m_IRQ_GPIOx);

    // Init GPIO
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pin   = m_IRQ_GPIO_PIN_x;
    HAL_GPIO_Init(m_IRQ_GPIOx, &GPIO_InitStruct);
    /*
    m_I2C_Handle.Init.DutyCycle       = I2C_DUTYCYCLE_2;
    m_I2C_Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    m_I2C_Handle.Init.NoStretchMode   = I2C_NOSTRETCH_ENABLE;
    */
} // end - void CCapTouchDriver::Initialize_Hardware(void)

bool CCapTouchDriver::Is_DataReady(void)
{
    if (HAL_GPIO_ReadPin(m_IRQ_GPIOx, m_IRQ_GPIO_PIN_x) == GPIO_PIN_SET) return false;
    else                                                                 return true;
} // end - bool CCapTouchDriver::Is_DataReady(void)

void CCapTouchDriver::Write(uint8_t reg, uint8_t val)
{
    uint8_t data[2]; // Might need to make this a member variable
    data[0] = reg;
    data[1] = val;

    m_Driver_I2Cn->MasterTransmit(m_SlaveAddr, &data[0], sizeof(data), false);
} // end - void CCapTouchDriver::Write(unsigned char address, unsigned char data)

uint8_t CCapTouchDriver::Read(uint8_t reg)
{
    uint8_t data = 0;
    m_Driver_I2Cn->MasterReceive(m_SlaveAddr, &data, 1, false);
    return data;
} // end - uint16_t CCapTouchDriver::Read(unsigned char address)

