/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_DMA_H
#define __STM32F4xx_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

#define DMA_CHANNEL_4        ((uint32_t)0x08000000U)  /*!< DMA Channel 4 */
#define DMA_MEMORY_TO_PERIPH         ((uint32_t)DMA_SxCR_DIR_0)  /*!< Memory to peripheral direction */
#define DMA_PINC_DISABLE       ((uint32_t)0x00000000U)     /*!< Peripheral increment mode disable */
#define DMA_MINC_ENABLE         ((uint32_t)DMA_SxCR_MINC)  /*!< Memory increment mode enable  */
#define DMA_PDATAALIGN_BYTE          ((uint32_t)0x00000000U)        /*!< Peripheral data alignment: Byte     */
#define DMA_MDATAALIGN_BYTE          ((uint32_t)0x00000000U)        /*!< Memory data alignment: Byte     */
#define DMA_CIRCULAR       ((uint32_t)DMA_SxCR_CIRC)    /*!< Circular mode                */
#define DMA_PRIORITY_HIGH            ((uint32_t)DMA_SxCR_PL_1)  /*!< Priority level: High      */
#define DMA_FIFOMODE_DISABLE        ((uint32_t)0x00000000U)       /*!< FIFO mode disable */
#define DMA_FIFO_THRESHOLD_1QUARTERFULL       ((uint32_t)0x00000000U)       /*!< FIFO threshold 1 quart full configuration  */
#define DMA_MBURST_SINGLE       ((uint32_t)0x00000000U)  
#define DMA_PBURST_SINGLE       ((uint32_t)0x00000000U)
/** 
  * @brief  DMA Configuration Structure definition
  */
typedef struct
{
  uint32_t Channel;              /*!< Specifies the channel used for the specified stream. 
                                      This parameter can be a value of @ref DMA_Channel_selection                    */

  uint32_t Direction;            /*!< Specifies if the data will be transferred from memory to peripheral, 
                                      from memory to memory or from peripheral to memory.
                                      This parameter can be a value of @ref DMA_Data_transfer_direction              */

  uint32_t PeriphInc;            /*!< Specifies whether the Peripheral address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Peripheral_incremented_mode          */

  uint32_t MemInc;               /*!< Specifies whether the memory address register should be incremented or not.
                                      This parameter can be a value of @ref DMA_Memory_incremented_mode              */

  uint32_t PeriphDataAlignment;  /*!< Specifies the Peripheral data width.
                                      This parameter can be a value of @ref DMA_Peripheral_data_size                 */

  uint32_t MemDataAlignment;     /*!< Specifies the Memory data width.
                                      This parameter can be a value of @ref DMA_Memory_data_size                     */

  uint32_t Mode;                 /*!< Specifies the operation mode of the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_mode
                                      @note The circular buffer mode cannot be used if the memory-to-memory
                                            data transfer is configured on the selected Stream                        */

  uint32_t Priority;             /*!< Specifies the software priority for the DMAy Streamx.
                                      This parameter can be a value of @ref DMA_Priority_level                       */

  uint32_t FIFOMode;             /*!< Specifies if the FIFO mode or Direct mode will be used for the specified stream.
                                      This parameter can be a value of @ref DMA_FIFO_direct_mode
                                      @note The Direct mode (FIFO mode disabled) cannot be used if the 
                                            memory-to-memory data transfer is configured on the selected stream       */

  uint32_t FIFOThreshold;        /*!< Specifies the FIFO threshold level.
                                      This parameter can be a value of @ref DMA_FIFO_threshold_level                  */

  uint32_t MemBurst;             /*!< Specifies the Burst transfer configuration for the memory transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible
                                      transaction.
                                      This parameter can be a value of @ref DMA_Memory_burst 
                                      @note The burst mode is possible only if the address Increment mode is enabled. */

  uint32_t PeriphBurst;          /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
                                      It specifies the amount of data to be transferred in a single non interruptible 
                                      transaction. 
                                      This parameter can be a value of @ref DMA_Peripheral_burst
                                      @note The burst mode is possible only if the address Increment mode is enabled. */
}DMA_InitTypeDef;

/**
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
    DMA_Stream_TypeDef         *Instance;                                                    /*!< Register base address                  */

    DMA_InitTypeDef            Init;                                                         /*!< DMA communication parameters           */ 

//  HAL_LockTypeDef            Lock;                                                         /*!< DMA locking object                     */  

//  __IO HAL_DMA_StateTypeDef  State;                                                        /*!< DMA transfer state                     */

//  void                       *Parent;                                                      /*!< Parent object state                    */ 

//  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA transfer complete callback         */

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

HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma); 
#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_HAL_DMA_H */
