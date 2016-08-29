#include <CppUTestExt/MockSupport.h>
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"

uint8_t pinStates = 0; // Internally keeps track of pin states

void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
    mock().actualCall("GPIO_Init");
    if (GPIOx          ) return;
    if (GPIO_InitStruct) return;
}

void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
{
    mock().actualCall("GPIO_PinAFConfig");
    if (GPIOx         ) return;
    if (GPIO_PinSource) return;
    if (GPIO_AF       ) return;
}

void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
    mock().actualCall("GPIO_StructInit");
    if (GPIO_InitStruct) return;
}

void GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    mock().actualCall("GPIO_ToggleBits"       )
        .withParameter("GPIOx"   , GPIOx)
        .withParameter("GPIO_Pin", GPIO_Pin);
}

uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    mock().actualCall("GPIO_ReadInputDataBit" )
        .withParameter("GPIOx"   , GPIOx)
        .withParameter("GPIO_Pin", GPIO_Pin);

    return pinStates;
}

void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    mock().actualCall("GPIO_ResetBits" )
        .withParameter("GPIOx"   , GPIOx)
        .withParameter("GPIO_Pin", GPIO_Pin);
}

void    GPIO_SetPinInputValue(uint8_t val)
{
    pinStates = val;
}
