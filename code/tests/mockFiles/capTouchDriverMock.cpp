#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_hal.h>
#include "capTouchDriver.h"
#include "capTouchDriverMock.h"
#include "roboCooler.h"

#define MOCK_SCL_GPIOx                      GPIOA
#define MOCK_SCL_GPIO_PIN_x                 GPIO_PIN_1
#define MOCK_SDA_GPIOx                      GPIOA
#define MOCK_SDA_GPIO_PIN_x                 GPIO_PIN_1
#define MOCK_IRQ_GPIOx                      GPIOA
#define MOCK_IRQ_GPIO_PIN_x                 GPIO_PIN_1

#define MOCK_GPIO_AF                        CAP_GPIO_AF
#define MOCK_I2Cx                           I2C1

// --- Mock to compile capTouchDriver
CCapTouchDriver::CCapTouchDriver(
                GPIO_TypeDef* SCL_GPIOx, uint16_t      SCL_GPIO_PIN_x,
                GPIO_TypeDef* SDA_GPIOx, uint16_t      SDA_GPIO_PIN_x,
                GPIO_TypeDef* IRQ_GPIOx, uint16_t      IRQ_GPIO_PIN_x,
                uint8_t       GPIO_AF  , I2C_TypeDef*  I2Cx)
{
    if(SCL_GPIOx)                return;
    if(SCL_GPIO_PIN_x)           return;
    if(SDA_GPIOx)                return;
    if(SDA_GPIO_PIN_x)           return;
    if(IRQ_GPIOx)                return;
    if(IRQ_GPIO_PIN_x)           return;
    if(GPIO_AF)                  return;
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
    MOCK_SCL_GPIOx, MOCK_SCL_GPIO_PIN_x,
    MOCK_SDA_GPIOx, MOCK_SDA_GPIO_PIN_x,
    MOCK_IRQ_GPIOx, MOCK_IRQ_GPIO_PIN_x,
    MOCK_GPIO_AF  , MOCK_I2Cx)
{
    m_MockInputValue = GPIO_PIN_RESET;
}

CCapTouchDriverMock::~CCapTouchDriverMock(void)
{
}

void CCapTouchDriverMock::Initialize_Hardware(void)
{
    m_MockInputValue = GPIO_PIN_RESET;
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

