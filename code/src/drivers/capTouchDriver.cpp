#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_i2c.h>
#include <stm32f4xx_rcc.h>
#include "capTouchDriver.h"

CCapTouchDriver::CCapTouchDriver(
                uint32_t      SCL_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SCL_GPIOx,
                uint16_t      SCL_GPIO_Pin_x,
                uint16_t      SCL_GPIO_PinSourcex,

                uint32_t      SDA_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* SDA_GPIOx,
                uint16_t      SDA_GPIO_Pin_x,
                uint16_t      SDA_GPIO_PinSourcex,

                uint32_t      IRQ_RCC_AHB1Periph_GPIOx,
                GPIO_TypeDef* IRQ_GPIOx,
                uint16_t      IRQ_GPIO_Pin_x,
                uint16_t      IRQ_GPIO_PinSourcex,

                uint8_t       GPIO_AF,
                uint32_t      APBxPeriph_I2Cx,
                I2C_TypeDef*  I2Cx)
{
    m_SCL_RCC_AHB1Periph_GPIOx = SCL_RCC_AHB1Periph_GPIOx;
    m_SCL_GPIOx                = SCL_GPIOx;
    m_SCL_GPIO_Pin_x           = SCL_GPIO_Pin_x;
    m_SCL_GPIO_PinSourcex      = SCL_GPIO_PinSourcex;

    m_SDA_RCC_AHB1Periph_GPIOx = SDA_RCC_AHB1Periph_GPIOx;
    m_SDA_GPIOx                = SDA_GPIOx;
    m_SDA_GPIO_Pin_x           = SDA_GPIO_Pin_x;
    m_SDA_GPIO_PinSourcex      = SDA_GPIO_PinSourcex;

    m_IRQ_RCC_AHB1Periph_GPIOx = IRQ_RCC_AHB1Periph_GPIOx;
    m_IRQ_GPIOx                = IRQ_GPIOx;
    m_IRQ_GPIO_Pin_x           = IRQ_GPIO_Pin_x;
    m_IRQ_GPIO_PinSourcex      = IRQ_GPIO_PinSourcex;

    m_GPIO_AF                  = GPIO_AF;
    m_APBxPeriph_I2Cx          = APBxPeriph_I2Cx;
    m_I2Cx                     = I2Cx;
} // end - CCapTouchDriver::CCapTouchDriver

CCapTouchDriver::~CCapTouchDriver(void)
{
}

void CCapTouchDriver::Initialize_Hardware(void)
{
    GPIO_InitTypeDef    GPIO_InitStruct;
    I2C_InitTypeDef     I2C_InitStruct;

    // Init Peripheral clocks
    RCC_AHB1PeriphClockCmd(m_SCL_RCC_AHB1Periph_GPIOx , ENABLE);
    RCC_AHB1PeriphClockCmd(m_SDA_RCC_AHB1Periph_GPIOx , ENABLE);
    RCC_AHB1PeriphClockCmd(m_IRQ_RCC_AHB1Periph_GPIOx , ENABLE);

    // Init GPIO
    GPIO_StructInit(&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_High_Speed;


    // Force the bus to release
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_Pin   = m_SCL_GPIO_Pin_x;
    GPIO_Init(m_SCL_GPIOx, &GPIO_InitStruct);

    for (int cycles = 0; cycles < 10; cycles++)
    {
        GPIO_ToggleBits(m_SCL_GPIOx, m_SCL_GPIO_Pin_x);
        for (int dly = 0x1A9; dly > 0; dly--);
    }


    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF;

    GPIO_InitStruct.GPIO_Pin   = m_SCL_GPIO_Pin_x;
    GPIO_Init(m_SCL_GPIOx, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin   = m_SDA_GPIO_Pin_x;
    GPIO_Init(m_SDA_GPIOx, &GPIO_InitStruct);


    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_Pin   = m_IRQ_GPIO_Pin_x;
    GPIO_Init(m_IRQ_GPIOx, &GPIO_InitStruct);

    GPIO_PinAFConfig(m_SCL_GPIOx, m_SCL_GPIO_PinSourcex, m_GPIO_AF);
    GPIO_PinAFConfig(m_SDA_GPIOx, m_SDA_GPIO_PinSourcex, m_GPIO_AF);

    // Init I2C
    RCC_APB1PeriphClockCmd(m_APBxPeriph_I2Cx, ENABLE);

    I2C_DeInit(m_I2Cx);
    I2C_StructInit(&I2C_InitStruct);

    I2C_InitStruct.I2C_ClockSpeed          = 100000;
    I2C_InitStruct.I2C_Mode                = I2C_Mode_I2C;
    I2C_InitStruct.I2C_DutyCycle           = I2C_DutyCycle_2;
    I2C_InitStruct.I2C_OwnAddress1         = 0;
    I2C_InitStruct.I2C_Ack                 = I2C_Ack_Enable;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Init(m_I2Cx, &I2C_InitStruct);

    I2C_Cmd(m_I2Cx, ENABLE);
} // end - void CCapTouchDriver::Initialize_Hardware(void)

bool CCapTouchDriver::Is_DataReady(void)
{
    if (GPIO_ReadInputDataBit(CAP_IRQ_GPIOx, CAP_IRQ_GPIO_Pin_x) == 1) return false;
    else                                                               return true;
} // end - bool CCapTouchDriver::Is_DataReady(void)

