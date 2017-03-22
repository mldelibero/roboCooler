#include "CDriver.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_rcc_ex.h"
#include "stm32f407xx.h"

CDriver::CDriver(void)
{
}

CDriver::~CDriver(void)
{
}

void CDriver::InitializeGPIOClock(GPIO_TypeDef* GPIOx)
{
    if (GPIOx == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
    if (GPIOx == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
    if (GPIOx == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
    if (GPIOx == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
    if (GPIOx == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
    if (GPIOx == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE();
    if (GPIOx == GPIOG) __HAL_RCC_GPIOG_CLK_ENABLE();
    if (GPIOx == GPIOH) __HAL_RCC_GPIOH_CLK_ENABLE();
    if (GPIOx == GPIOI) __HAL_RCC_GPIOI_CLK_ENABLE();
} // end -- void CDriver::InitializeGPIOClock(GPIO_TypeDef* GPIOx)

