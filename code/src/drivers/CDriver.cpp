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
    switch (GPIOx)
    {
        case GPIO_A:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;

        case GPIO_B:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;

        case GPIO_C:
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;

        case GPIO_D:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;

        case GPIO_E:
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;

        case GPIO_F:
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;

        case GPIO_G:
            __HAL_RCC_GPIOG_CLK_ENABLE();
            break;

        case GPIO_H:
            __HAL_RCC_GPIOH_CLK_ENABLE();
            break;

        case GPIO_I:
            __HAL_RCC_GPIOI_CLK_ENABLE();
            break;

        default:
        break;
    } // end - switch (GPIOx)
} // end -- void CDriver::InitializeGPIOClock(GPIO_TypeDef* GPIOx)

