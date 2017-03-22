/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_USART_H
#define __STM32F4xx_HAL_USART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"

#define USART_WORDLENGTH_8B                  ((uint32_t)0x00000000U)
#define USART_STOPBITS_0_5                   ((uint32_t)USART_CR2_STOP_0)
#define USART_PARITY_NONE                    ((uint32_t)0x00000000U)
#define USART_MODE_TX                        ((uint32_t)USART_CR1_TE)
#define USART_POLARITY_HIGH                  ((uint32_t)USART_CR2_CPOL)
#define USART_PHASE_1EDGE                    ((uint32_t)0x00000000U)
#define USART_LASTBIT_DISABLE                ((uint32_t)0x00000000U)

/** 
  * @brief HAL State structures definition  
  */ 
typedef enum
{
  HAL_USART_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized   */
  HAL_USART_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use */
  HAL_USART_STATE_BUSY              = 0x02U,    /*!< an internal process is ongoing */   
  HAL_USART_STATE_BUSY_TX           = 0x12U,    /*!< Data Transmission process is ongoing */ 
  HAL_USART_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing */
  HAL_USART_STATE_BUSY_TX_RX        = 0x32U,    /*!< Data Transmission Reception process is ongoing */
  HAL_USART_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state */
  HAL_USART_STATE_ERROR             = 0x04U     /*!< Error */      
}HAL_USART_StateTypeDef;

/** 
  * @brief USART Init Structure definition  
  */ 
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the Usart communication baud rate.
                                           The baud rate is computed using the following formula:
                                           - IntegerDivider = ((PCLKx) / (8 * (husart->Init.BaudRate)))
                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 8) + 0.5 */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref USART_Word_Length */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref USART_Stop_Bits */

  uint32_t Parity;                   /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref USART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */
 
  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref USART_Mode */

  uint32_t CLKPolarity;               /*!< Specifies the steady state of the serial clock.
                                           This parameter can be a value of @ref USART_Clock_Polarity */

  uint32_t CLKPhase;                  /*!< Specifies the clock transition on which the bit capture is made.
                                           This parameter can be a value of @ref USART_Clock_Phase */

  uint32_t CLKLastBit;                /*!< Specifies whether the clock pulse corresponding to the last transmitted
                                           data bit (MSB) has to be output on the SCLK pin in synchronous mode.
                                           This parameter can be a value of @ref USART_Last_Bit */
}USART_InitTypeDef;

/** 
  * @brief  USART handle Structure definition  
  */  
typedef struct
{
  USART_TypeDef                 *Instance;        /* USART registers base address        */
  
  USART_InitTypeDef             Init;             /* Usart communication parameters      */
  
  uint8_t                       *pTxBuffPtr;      /* Pointer to Usart Tx transfer Buffer */
  
  uint16_t                      TxXferSize;       /* Usart Tx Transfer size              */
  
  __IO uint16_t                 TxXferCount;      /* Usart Tx Transfer Counter           */
  
  uint8_t                       *pRxBuffPtr;      /* Pointer to Usart Rx transfer Buffer */
  
  uint16_t                      RxXferSize;       /* Usart Rx Transfer size              */
  
  __IO uint16_t                 RxXferCount;      /* Usart Rx Transfer Counter           */  
  
  DMA_HandleTypeDef             *hdmatx;          /* Usart Tx DMA Handle parameters      */
    
  DMA_HandleTypeDef             *hdmarx;          /* Usart Rx DMA Handle parameters      */
  
  HAL_LockTypeDef                Lock;            /* Locking object                      */
  
  __IO HAL_USART_StateTypeDef    State;           /* Usart communication state           */
  
  __IO uint32_t                  ErrorCode;       /* USART Error code                    */

}USART_HandleTypeDef;

HAL_StatusTypeDef HAL_USART_DeInit(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_Init(USART_HandleTypeDef *husart);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_USART_H */
