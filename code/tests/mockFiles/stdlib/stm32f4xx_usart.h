#ifndef __STM32F4xx_USART_MOCK_H
#define __STM32F4xx_USART_MOCK_H
#include "stm32f4xx.h"
#define DMA_Mode_Normal                   ((uint32_t)0x00000000)
#define DMA_PeripheralBurst_Single        ((uint32_t)0x00000000)
#define DMA_PeripheralDataSize_Byte       ((uint32_t)0x00000000)
#define DMA_FIFOMode_Disable              ((uint32_t)0x00000000)
#define DMA_MemoryDataSize_Byte           ((uint32_t)0x00000000) 
#define DMA_MemoryInc_Enable              ((uint32_t)0x00000400)
#define DMA_FIFOThreshold_1QuarterFull    ((uint32_t)0x00000000)
#define DMA_PeripheralInc_Disable         ((uint32_t)0x00000000)
#define USART_StopBits_0_5                ((uint16_t)0x1000)
#define USART_WordLength_8b               ((uint16_t)0x0000)
#define USART_Parity_No                   ((uint16_t)0x0000)
#define DMA_MemoryBurst_Single            ((uint32_t)0x00000000)
#define DMA_Priority_High                 ((uint32_t)0x00020000)
#define DMA_DIR_MemoryToPeripheral        ((uint32_t)0x00000040) 
#define USART_HardwareFlowControl_None    ((uint16_t)0x0000)
#define USART_DMAReq_Tx                   ((uint16_t)0x0080)
#define USART_Mode_Tx                     ((uint16_t)0x0008)

typedef struct
{
  uint32_t USART_BaudRate;            /*!< This member configures the USART communication baud rate.
                                           The baud rate is computed using the following formula:
                                            - IntegerDivider = ((PCLKx) / (8 * (OVR8+1) * (USART_InitStruct->USART_BaudRate)))
                                            - FractionalDivider = ((IntegerDivider - ((u32) IntegerDivider)) * 8 * (OVR8+1)) + 0.5 
                                           Where OVR8 is the "oversampling by 8 mode" configuration bit in the CR1 register. */

  uint16_t USART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_Word_Length */

  uint16_t USART_StopBits;            /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_Stop_Bits */

  uint16_t USART_Parity;              /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */
 
  uint16_t USART_Mode;                /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_Mode */

  uint16_t USART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
                                           or disabled.
                                           This parameter can be a value of @ref USART_Hardware_Flow_Control */
} USART_InitTypeDef;

void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_DeInit(USART_TypeDef* USARTx);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
#endif // end - #ifndef __STM32F4xx_USART_MOCK_H

