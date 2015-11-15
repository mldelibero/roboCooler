#include "capsense.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"

// PB8
#define CS_SCL_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_SCL_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_SCL_GPIOx                    GPIOB
#define CS_SCL_GPIO_PinSourcex          GPIO_PinSource8
#define CS_SCL_GPIO_AF                  GPIO_AF_I2C1
#define CS_SCL_GPIO_PIN_X               GPIO_Pin_8
#define CS_SCL_GPIO_MODE                GPIO_Mode_AF
#define CS_SCL_GPIO_SPEED               GPIO_High_Speed

// PB7
#define CS_SDA_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_SDA_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_SDA_GPIOx                    GPIOB
#define CS_SDA_GPIO_PinSourcex          GPIO_PinSource7
#define CS_SDA_GPIO_AF                  GPIO_AF_I2C1
#define CS_SDA_GPIO_PIN_X               GPIO_Pin_7
#define CS_SDA_GPIO_MODE                GPIO_Mode_AF
#define CS_SDA_GPIO_SPEED               GPIO_High_Speed

// PB9
#define CS_IRQ_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_IRQ_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_IRQ_GPIOx                    GPIOB
#define CS_IRQ_GPIO_PinSourcex          GPIO_PinSource9
#define CS_IRQ_GPIO_PIN_X               GPIO_Pin_9
#define CS_IRQ_GPIO_MODE                GPIO_Mode_IN
#define CS_IRQ_GPIO_SPEED               GPIO_High_Speed

// PB5
#define CS_ADD_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define CS_ADD_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define CS_ADD_GPIOx                    GPIOB
#define CS_ADD_GPIO_PinSourcex          GPIO_PinSource5
#define CS_ADD_GPIO_PIN_X               GPIO_Pin_5
#define CS_ADD_GPIO_MODE                GPIO_Mode_IN
#define CS_ADD_GPIO_SPEED               GPIO_High_Speed

#define CS_RCC_APBxPeriphClockCmd       RCC_APB2PeriphClockCmd
#define CS_APBxPeriph_I2Cx              RCC_APB2Periph_I2C1
#define CS_I2Cx                         I2C1

void init_cs(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    I2C_InitTypeDef  I2C_InitStruct;

    // Init Peripheral clocks
    CS_SCL_GPIO_AHBxPeriphClockCmd(CS_SCL_AHBxPeriph_GPIOx,  ENABLE);
    CS_SDA_GPIO_AHBxPeriphClockCmd(CS_SDA_AHBxPeriph_GPIOx,  ENABLE);
    CS_IRQ_GPIO_AHBxPeriphClockCmd(CS_IRQ_AHBxPeriph_GPIOx,  ENABLE);
    CS_ADD_GPIO_AHBxPeriphClockCmd(CS_ADD_AHBxPeriph_GPIOx,  ENABLE);

    CS_ADD_GPIO_AHBxPeriphClockCmd(CS_ADD_AHBxPeriph_GPIOx,  ENABLE);

    // Init GPIO
    GPIO_PinAFConfig(CS_SCL_GPIOx, CS_SCL_GPIO_PinSourcex, CS_SCL_GPIO_AF);
    GPIO_PinAFConfig(CS_SDA_GPIOx, CS_SDA_GPIO_PinSourcex, CS_SDA_GPIO_AF);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

    GPIO_InitStruct.GPIO_Mode  = CS_SCL_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_SCL_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_SCL_GPIO_PIN_X;
    GPIO_Init(CS_SCL_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = CS_SDA_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_SDA_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_SDA_GPIO_PIN_X;
    GPIO_Init(CS_SDA_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = CS_IRQ_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_IRQ_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_IRQ_GPIO_PIN_X;
    GPIO_Init(CS_IRQ_GPIOx,&GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode  = CS_ADD_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = CS_ADD_GPIO_SPEED;
    GPIO_InitStruct.GPIO_Pin   = CS_ADD_GPIO_PIN_X;
    GPIO_Init(CS_ADD_GPIOx,&GPIO_InitStruct);

    // Init I2C Peripheral
    I2C_DeInit(CS_I2Cx);
    I2C_StructInit(&I2C_InitStruct);

    I2C_InitStruct.I2C_ClockSpeed          = 100000;
    I2C_InitStruct.I2C_Mode                = I2C_Mode_I2C;
    I2C_InitStruct.I2C_DutyCycle           = I2C_DutyCycle_2;
    I2C_InitStruct.I2C_OwnAddress1         = 0;
    I2C_InitStruct.I2C_Ack                 = I2C_Ack_Enable;
    I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Init(CS_I2Cx, &I2C_InitStruct);

    I2C_Cmd(CS_I2Cx, ENABLE);
} // end - void init_cs(void)

