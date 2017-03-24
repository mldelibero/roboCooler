#include <stm32f4xx_hal.h>
#include "capTouchDriver.h"

#define CS_I2C_ADDR_RE     0xB5

CCapTouchDriver::CCapTouchDriver(
                GPIO_TypeDef* SCL_GPIOx,
                uint16_t      SCL_GPIO_PIN_x,

                GPIO_TypeDef* SDA_GPIOx,
                uint16_t      SDA_GPIO_PIN_x,

                GPIO_TypeDef* IRQ_GPIOx,
                uint16_t      IRQ_GPIO_PIN_x,

                uint8_t       GPIO_AF,
                I2C_TypeDef*  I2Cx)
{
    m_I2C_Handle.Instance      = I2Cx;
    m_SCL_GPIOx                = SCL_GPIOx;
    m_SCL_GPIO_PIN_x           = SCL_GPIO_PIN_x;

    m_SDA_GPIOx                = SDA_GPIOx;
    m_SDA_GPIO_PIN_x           = SDA_GPIO_PIN_x;

    m_IRQ_GPIOx                = IRQ_GPIOx;
    m_IRQ_GPIO_PIN_x           = IRQ_GPIO_PIN_x;

    m_GPIO_AF                  = GPIO_AF;
} // end - CCapTouchDriver::CCapTouchDriver

CCapTouchDriver::~CCapTouchDriver(void)
{
}

void CCapTouchDriver::Initialize_Hardware(void)
{
    GPIO_InitTypeDef    GPIO_InitStruct;

    // Init Peripheral clocks
    InitializeGPIOClock(m_SCL_GPIOx);
    InitializeGPIOClock(m_SDA_GPIOx);
    InitializeGPIOClock(m_IRQ_GPIOx);

    // Init GPIO
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin   = m_SCL_GPIO_PIN_x;
    HAL_GPIO_Init(m_SCL_GPIOx, &GPIO_InitStruct);

    // Force the bus to release
    for (int cycles = 0; cycles < 10; cycles++)
    {
        HAL_GPIO_TogglePin(m_SCL_GPIOx, m_SCL_GPIO_PIN_x);
        for (int dly = 0x1A9; dly > 0; dly--);
    }

    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Alternate = m_GPIO_AF;

    GPIO_InitStruct.Pin   = m_SCL_GPIO_PIN_x;
    HAL_GPIO_Init(m_SCL_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Pin   = m_SDA_GPIO_PIN_x;
    HAL_GPIO_Init(m_SDA_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pin   = m_IRQ_GPIO_PIN_x;
    HAL_GPIO_Init(m_IRQ_GPIOx, &GPIO_InitStruct);

    // Init I2C
    if      (m_I2Cx == I2C1) __HAL_RCC_FMPI2C1_CLK_ENABLE();
    else if (m_I2Cx == I2C3) __HAL_RCC_I2C3_CLK_ENABLE();

    HAL_I2C_DeInit(&m_I2C_Handle);

    m_I2C_Handle.Init.ClockSpeed      = 100000;
    m_I2C_Handle.Init.DutyCycle       = I2C_DUTYCYCLE_2;
    m_I2C_Handle.Init.OwnAddress1     = 0;
    m_I2C_Handle.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    m_I2C_Handle.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    m_I2C_Handle.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    m_I2C_Handle.Init.NoStretchMode   = I2C_NOSTRETCH_ENABLE;

    HAL_I2C_Init(&m_I2C_Handle);

    __HAL_I2C_ENABLE(&m_I2C_Handle);
} // end - void CCapTouchDriver::Initialize_Hardware(void)

bool CCapTouchDriver::Is_DataReady(void)
{
    if (HAL_GPIO_ReadPin(m_IRQ_GPIOx, m_IRQ_GPIO_PIN_x) == GPIO_PIN_SET) return false;
    else                                                                 return true;
} // end - bool CCapTouchDriver::Is_DataReady(void)

void CCapTouchDriver::Write(unsigned char address, unsigned char data)
{
    /*
    I2C_GenerateSTART(m_I2Cx, ENABLE);
    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_MODE_SELECT) == ERROR);

    I2C_Send7bitAddress(m_I2Cx, CS_I2C_ADDR_RE, I2C_Direction_Transmitter);
    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == ERROR);

    I2C_SendData(m_I2Cx, address);
    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTING) == ERROR);

    I2C_SendData(m_I2Cx, data);
    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED) == ERROR);

    I2C_GenerateSTOP(m_I2Cx, ENABLE);
    */
} // end - void CCapTouchDriver::Write(unsigned char address, unsigned char data)

uint16_t CCapTouchDriver::Read(unsigned char address)
{
    /*
    uint16_t data;

    // Restart
    m_I2Cx->CR1 |= I2C_Ack_Enable; // Set ACK for single byte reception
    I2C_GenerateSTART(m_I2Cx, ENABLE);
    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_MODE_SELECT) == ERROR);

    // Address Write
    I2C_Send7bitAddress(m_I2Cx, CS_I2C_ADDR_RE, I2C_Direction_Receiver);
    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) == ERROR);

    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED) == ERROR);
    data = I2C_ReceiveData(m_I2Cx);
    m_I2Cx->CR1 &= uint16_t(~I2C_Ack_Enable); // Set NACK for single byte reception

    while (I2C_CheckEvent(m_I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED) == ERROR);

    uint16_t temp = uint16_t(I2C_ReceiveData(m_I2Cx) << 8);
    data |= temp;

    // Stop Condition
    I2C_GenerateSTOP(m_I2Cx, ENABLE);

    if (address) return data; // Need to expand function to read from any address
    return data;
    */
    return 0;
} // end - uint16_t CCapTouchDriver::Read(unsigned char address)

