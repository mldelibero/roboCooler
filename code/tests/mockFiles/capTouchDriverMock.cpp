#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>
#include "capTouchDriver.h"
#include "capTouchDriverMock.h"

#define MOCK_SCL_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define MOCK_SCL_GPIOx                      GPIOA
#define MOCK_SCL_GPIO_Pin_x                 GPIO_Pin_1

#define MOCK_SDA_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define MOCK_SDA_GPIOx                      GPIOA
#define MOCK_SDA_GPIO_Pin_x                 GPIO_Pin_1

#define MOCK_IRQ_RCC_AHB1Periph_GPIOx       RCC_AHB1Periph_GPIOA
#define MOCK_IRQ_GPIOx                      GPIOA
#define MOCK_IRQ_GPIO_Pin_x                 GPIO_Pin_1

// --- Mock to compile capTouchDriver
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
    if(SCL_RCC_AHB1Periph_GPIOx) return;
    if(SCL_GPIOx)                return;
    if(SCL_GPIO_Pin_x)           return;
    if(SDA_RCC_AHB1Periph_GPIOx) return;
    if(SDA_GPIOx)                return;
    if(SDA_GPIO_Pin_x)           return;
    if(IRQ_RCC_AHB1Periph_GPIOx) return;
    if(IRQ_GPIOx)                return;
    if(IRQ_GPIO_Pin_x)           return;
}

CCapTouchDriver::~CCapTouchDriver(void)
{
}

void CCapTouchDriver::Initialize_Hardware(void)
{
    mock().actualCall("CCapTouchDriver::Initialize_Hardware");
}
/*

BitAction CCapTouchDriver::SampleInput(void)
{
    return Bit_SET;
}
*/
// -- Mock that abstracts capTouchDriver and allows input control
CCapTouchDriverMock::CCapTouchDriverMock() : CCapTouchDriver(
    MOCK_SCL_RCC_AHB1Periph_GPIOx, MOCK_SCL_GPIOx, MOCK_SCL_GPIO_Pin_x,
    MOCK_SDA_RCC_AHB1Periph_GPIOx, MOCK_SDA_GPIOx, MOCK_SDA_GPIO_Pin_x,
    MOCK_IRQ_RCC_AHB1Periph_GPIOx, MOCK_IRQ_GPIOx, MOCK_IRQ_GPIO_Pin_x)
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

/*

BitAction CCapTouchDriverMock::SampleInput(void)
{
    mock().actualCall("CCapTouchDriver::SampleInput");
    return m_MockInputValue;
}

void CCapTouchDriverMock::Set_MockInput(void)
{
    m_MockInputValue = Bit_SET;
}

void CCapTouchDriverMock::Clear_MockInput(void)
{
    m_MockInputValue = Bit_RESET;
}
*/
