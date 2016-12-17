#include <CppUTestExt/MockSupport.h>
#include "stm32f4xx.h"
#include "stm32f4xx_i2c.h"

ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT)
{
    mock().actualCall("I2C_CheckEvent");
    if (I2Cx)      return SUCCESS;
    if (I2C_EVENT) return SUCCESS;
    return SUCCESS;
}

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

void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
    mock().actualCall("I2C_GenerateSTART");
    if (I2Cx)     return;
    if (NewState) return;

}

void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
    mock().actualCall("I2C_GenerateSTOP");
    if (I2Cx)     return;
    if (NewState) return;
}

void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct)
{
    mock().actualCall("I2C_Init");
    if (I2Cx)           return;
    if (I2C_InitStruct) return;
}

uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx)
{
    mock().actualCall("I2C_ReceiveData");
    if (I2Cx) return 0;
    return 0;
}

void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data)
{
    mock().actualCall("I2C_SendData");
    if (I2Cx) return;
    if (Data) return;
}

void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction)
{
    mock().actualCall("I2C_Send7bitAddress");
    if (I2Cx)          return;
    if (Address)       return;
    if (I2C_Direction) return;
}

void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{
    mock().actualCall("I2C_StructInit");
    if (I2C_InitStruct) return;
}

