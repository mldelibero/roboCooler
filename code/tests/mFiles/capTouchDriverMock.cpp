#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_i2c.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "capTouchDriver.h"
#include "capTouchDriverMock.h"

#define MOCK_SCL_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define MOCK_SCL_GPIOx                      GPIOA
#define MOCK_SCL_GPIO_Pin_x                 GPIO_Pin_1
#define MOCK_SCL_GPIO_PinSourcex            GPIO_PinSource1

#define MOCK_SDA_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define MOCK_SDA_GPIOx                      GPIOA
#define MOCK_SDA_GPIO_Pin_x                 GPIO_Pin_1
#define MOCK_SDA_GPIO_PinSourcex            GPIO_PinSource1

#define MOCK_IRQ_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define MOCK_IRQ_GPIOx                      GPIOA
#define MOCK_IRQ_GPIO_Pin_x                 GPIO_Pin_1
#define MOCK_IRQ_GPIO_PinSourcex            GPIO_PinSource1

#define MOCK_GPIO_AF                        GPIO_AF_I2C1
#define MOCK_APBxPeriph_I2Cx                RCC_APB1Periph_I2C1
#define MOCK_I2Cx                           I2C1

// --- Mock to compile capTouchDriver
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
    if(SCL_RCC_AHB1Periph_GPIOx) return;
    if(SCL_GPIOx)                return;
    if(SCL_GPIO_Pin_x)           return;
    if(SCL_GPIO_PinSourcex)      return;

    if(SDA_RCC_AHB1Periph_GPIOx) return;
    if(SDA_GPIOx)                return;
    if(SDA_GPIO_Pin_x)           return;
    if(SDA_GPIO_PinSourcex)      return;

    if(IRQ_RCC_AHB1Periph_GPIOx) return;
    if(IRQ_GPIOx)                return;
    if(IRQ_GPIO_Pin_x)           return;
    if(IRQ_GPIO_PinSourcex)      return;

    if(GPIO_AF)                  return;
    if(APBxPeriph_I2Cx)          return;
    if(I2Cx)                     return;
}

CCapTouchDriver::~CCapTouchDriver(void)
{
}

void CCapTouchDriver::Initialize_Hardware(void)
{
    mock().actualCall("CCapTouchDriver::Initialize_Hardware");
}

bool CCapTouchDriver::Is_DataReady(void)
{
    mock().actualCall("CCapTouchDriver::Is_DataReady");
    return 0;
}


uint16_t CCapTouchDriver::Read(unsigned char address)
{
    mock().actualCall("CCapTouchDriver::Read");
    if (address) return 0;
    return 0;
}

void CCapTouchDriver::Write(unsigned char address, unsigned char data)
{
    mock().actualCall("CCapTouchDriver::Write");
    if (address) return;
    if (data)    return;
}

// -- Mock that abstracts capTouchDriver and allows input control
CCapTouchDriverMock::CCapTouchDriverMock() : CCapTouchDriver(
    MOCK_SCL_RCC_AHB1Periph_GPIOx, MOCK_SCL_GPIOx, MOCK_SCL_GPIO_Pin_x, MOCK_SCL_GPIO_PinSourcex,
    MOCK_SDA_RCC_AHB1Periph_GPIOx, MOCK_SDA_GPIOx, MOCK_SDA_GPIO_Pin_x, MOCK_SDA_GPIO_PinSourcex,
    MOCK_IRQ_RCC_AHB1Periph_GPIOx, MOCK_IRQ_GPIOx, MOCK_IRQ_GPIO_Pin_x, MOCK_IRQ_GPIO_PinSourcex,
    MOCK_GPIO_AF, MOCK_APBxPeriph_I2Cx, MOCK_I2Cx)
{
    m_MockInputValue = Bit_RESET;
}

CCapTouchDriverMock::~CCapTouchDriverMock(void)
{
}

void CCapTouchDriverMock::Initialize_Hardware(void)
{
    m_MockInputValue = Bit_RESET;
    mock().actualCall("CCapTouchDriver::Initialize_Hardware");
}


void CCapTouchDriverMock::Clear_MockDataReady(void)
{
    m_Mock_DataReady = false;
}

void CCapTouchDriverMock::Set_MockDataReady(void)
{
    m_Mock_DataReady = true;
}

bool CCapTouchDriverMock::Is_DataReady(void)
{
    mock().actualCall("CCapTouchDriver::Is_DataReady");
    return m_Mock_DataReady;
}


void CCapTouchDriverMock::Clear_MockTouchDetected(void)
{
    m_Mock_TouchDetected = false;
}

void CCapTouchDriverMock::Set_MockTouchDetected(void)
{
    m_Mock_TouchDetected = true;
}

uint16_t CCapTouchDriverMock::Read(unsigned char address)
{
    mock().actualCall("CCapTouchDriver::Read");
    if (m_Mock_TouchDetected) return PROX_STATUS_BIT;
    if (address)              return 0;
    else                      return 0;
}

