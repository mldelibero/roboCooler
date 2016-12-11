#ifndef __STM32F4XX_I2C_MOCK_H
#define __STM32F4XX_I2C_MOCK_H
#include "stm32f4xx.h"

typedef struct
{
  uint32_t I2C_ClockSpeed;          /*!< Specifies the clock frequency.
                                         This parameter must be set to a value lower than 400kHz */

  uint16_t I2C_Mode;                /*!< Specifies the I2C mode.
                                         This parameter can be a value of @ref I2C_mode */

  uint16_t I2C_DutyCycle;           /*!< Specifies the I2C fast mode duty cycle.
                                         This parameter can be a value of @ref I2C_duty_cycle_in_fast_mode */

  uint16_t I2C_OwnAddress1;         /*!< Specifies the first device own address.
                                         This parameter can be a 7-bit or 10-bit address. */

  uint16_t I2C_Ack;                 /*!< Enables or disables the acknowledgement.
                                         This parameter can be a value of @ref I2C_acknowledgement */

  uint16_t I2C_AcknowledgedAddress; /*!< Specifies if 7-bit or 10-bit address is acknowledged.
                                         This parameter can be a value of @ref I2C_acknowledged_address */
}I2C_InitTypeDef;

#define I2C_AcknowledgedAddress_7bit    ((uint16_t)0x4000)
#define I2C_Ack_Enable                  ((uint16_t)0x0400)
#define I2C_Ack_Disable                 ((uint16_t)0x0000)
#define I2C_DutyCycle_16_9              ((uint16_t)0x4000)
#define I2C_DutyCycle_2                 ((uint16_t)0xBFFF)
#define I2C_Mode_I2C                    ((uint16_t)0x0000)
#define GPIO_AF_I2C1                    ((uint8_t)0x04)

void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DeInit(I2C_TypeDef* I2Cx);
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);

#endif /* #ifndef __STM32F4XX_I2C_MOCK_H */
