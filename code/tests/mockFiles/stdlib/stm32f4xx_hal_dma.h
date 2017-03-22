/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_DMA_H
#define __STM32F4xx_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/**
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
//  DMA_Stream_TypeDef         *Instance;                                                    /*!< Register base address                  */
//
//  DMA_InitTypeDef            Init;                                                         /*!< DMA communication parameters           */ 
//
//  HAL_LockTypeDef            Lock;                                                         /*!< DMA locking object                     */  
//
//  __IO HAL_DMA_StateTypeDef  State;                                                        /*!< DMA transfer state                     */
//
//  void                       *Parent;                                                      /*!< Parent object state                    */ 
//
//  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA transfer complete callback         */
//
//  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma); /*!< DMA Half transfer complete callback    */
//
//  void                       (* XferM1CpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA transfer complete Memory1 callback */
//  
//  void                       (* XferM1HalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);   /*!< DMA transfer Half complete Memory1 callback */
//  
//  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA transfer error callback            */
//  
//  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA transfer Abort callback            */  
//
// __IO uint32_t               ErrorCode;                                                    /*!< DMA Error code                          */
//  
// uint32_t                    StreamBaseAddress;                                            /*!< DMA Stream Base Address                */
//
// uint32_t                    StreamIndex;                                                  /*!< DMA Stream Index                       */
// 
}DMA_HandleTypeDef;

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_DMA_H */
