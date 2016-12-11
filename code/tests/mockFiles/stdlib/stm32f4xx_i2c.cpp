#include <CppUTestExt/MockSupport.h>
#include "stm32f4xx.h"
#include "stm32f4xx_i2c.h"

void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
    mock().actualCall("I2C_Cmd");
    if (I2Cx)     return;
    if (NewState) return;
}

void I2C_DeInit(I2C_TypeDef* I2Cx)
{
    mock().actualCall("I2C_DeInit");
    if (I2Cx) return;
}

void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct)
{
    mock().actualCall("I2C_Init");
    if (I2Cx)           return;
    if (I2C_InitStruct) return;
}

void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{
    mock().actualCall("I2C_StructInit");
    if (I2C_InitStruct) return;
}

