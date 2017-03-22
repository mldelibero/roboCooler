#ifndef __STM32F4xx_HAL_TIM_H
#define __STM32F4xx_HAL_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

///* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal_def.h"

typedef struct
{
  TIM_TypeDef                 *Instance;     /*!< Register base address             */
//  TIM_Base_InitTypeDef        Init;          /*!< TIM Time Base required parameters */
//  HAL_TIM_ActiveChannel       Channel;       /*!< Active channel                    */
  DMA_HandleTypeDef           *hdma[7];      /*!< DMA Handlers array
//                                             This array is accessed by a @ref DMA_Handle_index */
//  HAL_LockTypeDef             Lock;          /*!< Locking object                    */
//  __IO HAL_TIM_StateTypeDef   State;         /*!< TIM operation state               */
} TIM_HandleTypeDef;

HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif
#endif

