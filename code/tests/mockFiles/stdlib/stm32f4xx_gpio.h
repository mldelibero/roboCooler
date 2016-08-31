#ifndef __STM32F4XX_GPIO_MOCK_H
#define __STM32F4XX_GPIO_MOCK_H
#include "stm32f4xx.h"

#define GPIO_PinSource0            ((uint8_t )0x07  )
#define GPIO_PinSource1            ((uint8_t )0x07  )
#define GPIO_PinSource2            ((uint8_t )0x07  )
#define GPIO_PinSource3            ((uint8_t )0x07  )
#define GPIO_PinSource4            ((uint8_t )0x07  )
#define GPIO_PinSource5            ((uint8_t )0x07  )
#define GPIO_PinSource6            ((uint8_t )0x07  )
#define GPIO_PinSource7            ((uint8_t )0x07  )
#define GPIO_PinSource8            ((uint8_t )0x07  )
#define GPIO_PinSource9            ((uint8_t )0x07  )
#define GPIO_PinSource10           ((uint8_t )0x07  )
#define GPIO_PinSource11           ((uint8_t )0x07  )
#define GPIO_PinSource12           ((uint8_t )0x07  )
#define GPIO_PinSource13           ((uint8_t )0x07  )
#define GPIO_PinSource14           ((uint8_t )0x07  )
#define GPIO_PinSource15           ((uint8_t )0x0F  )
#define GPIO_AF_TIM4               ((uint8_t )0x02  )  /* TIM4 Alternate Function mapping */
#define GPIO_Pin_0                 ((uint16_t)0x0080)  /* Pin 0  selected */
#define GPIO_Pin_1                 ((uint16_t)0x0080)  /* Pin 1  selected */
#define GPIO_Pin_2                 ((uint16_t)0x0080)  /* Pin 2  selected */
#define GPIO_Pin_3                 ((uint16_t)0x0080)  /* Pin 3  selected */
#define GPIO_Pin_4                 ((uint16_t)0x0080)  /* Pin 4  selected */
#define GPIO_Pin_5                 ((uint16_t)0x0080)  /* Pin 5  selected */
#define GPIO_Pin_6                 ((uint16_t)0x0080)  /* Pin 6  selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /* Pin 7  selected */
#define GPIO_Pin_8                 ((uint16_t)0x0080)  /* Pin 8  selected */
#define GPIO_Pin_9                 ((uint16_t)0x0080)  /* Pin 9  selected */
#define GPIO_Pin_10                ((uint16_t)0x0080)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0080)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x0080)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x0080)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x0080)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x0080)  /* Pin 15 selected */

typedef enum
{ 
  GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode */
  GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode */
  GPIO_Mode_AF   = 0x02, /*!< GPIO Alternate function Mode */
  GPIO_Mode_AN   = 0x03  /*!< GPIO Analog Mode */
}GPIOMode_TypeDef;

typedef enum
{ 
  GPIO_Low_Speed     = 0x00, /*!< Low speed    */
  GPIO_Medium_Speed  = 0x01, /*!< Medium speed */
  GPIO_Fast_Speed    = 0x02, /*!< Fast speed   */
  GPIO_High_Speed    = 0x03  /*!< High speed   */
}GPIOSpeed_TypeDef;

typedef enum
{ 
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
}GPIOOType_TypeDef;

typedef enum
{ 
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
}GPIOPuPd_TypeDef;

typedef struct
{
  uint32_t GPIO_Pin;              /*!< Specifies the GPIO pins to be configured.
                                       This parameter can be any value of @ref GPIO_pins_define */

  GPIOMode_TypeDef GPIO_Mode;     /*!< Specifies the operating mode for the selected pins.
                                       This parameter can be a value of @ref GPIOMode_TypeDef */

  GPIOSpeed_TypeDef GPIO_Speed;   /*!< Specifies the speed for the selected pins.
                                       This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOOType_TypeDef GPIO_OType;   /*!< Specifies the operating output type for the selected pins.
                                       This parameter can be a value of @ref GPIOOType_TypeDef */

  GPIOPuPd_TypeDef GPIO_PuPd;     /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                       This parameter can be a value of @ref GPIOPuPd_TypeDef */
}GPIO_InitTypeDef;

typedef enum
{ 
  Bit_RESET = 0,
  Bit_SET
}BitAction;

void    GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void    GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void    GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void    GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
void    GPIO_ToggleBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void    GPIO_SetPinInputValue(uint8_t val);
void    GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);

#endif /* #ifndef __STM32F4XX_GPIO_MOCK_H */
