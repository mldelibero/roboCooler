#ifndef __STM32F4XX_DMA_MOCK_H
#define __STM32F4XX_DMA_MOCK_H
#include "stm32f4xx.h"

/** @defgroup DMA_flags_definition 
  * @{
  */
#define DMA_FLAG_FEIF0                    ((uint32_t)0x10800001)
#define DMA_FLAG_DMEIF0                   ((uint32_t)0x10800004)
#define DMA_FLAG_TEIF0                    ((uint32_t)0x10000008)
#define DMA_FLAG_HTIF0                    ((uint32_t)0x10000010)
#define DMA_FLAG_TCIF0                    ((uint32_t)0x10000020)
#define DMA_FLAG_FEIF1                    ((uint32_t)0x10000040)
#define DMA_FLAG_DMEIF1                   ((uint32_t)0x10000100)
#define DMA_FLAG_TEIF1                    ((uint32_t)0x10000200)
#define DMA_FLAG_HTIF1                    ((uint32_t)0x10000400)
#define DMA_FLAG_TCIF1                    ((uint32_t)0x10000800)
#define DMA_FLAG_FEIF2                    ((uint32_t)0x10010000)
#define DMA_FLAG_DMEIF2                   ((uint32_t)0x10040000)
#define DMA_FLAG_TEIF2                    ((uint32_t)0x10080000)
#define DMA_FLAG_HTIF2                    ((uint32_t)0x10100000)
#define DMA_FLAG_TCIF2                    ((uint32_t)0x10200000)
#define DMA_FLAG_FEIF3                    ((uint32_t)0x10400000)
#define DMA_FLAG_DMEIF3                   ((uint32_t)0x11000000)
#define DMA_FLAG_TEIF3                    ((uint32_t)0x12000000)
#define DMA_FLAG_HTIF3                    ((uint32_t)0x14000000)
#define DMA_FLAG_TCIF3                    ((uint32_t)0x18000000)
#define DMA_FLAG_FEIF4                    ((uint32_t)0x20000001)
#define DMA_FLAG_DMEIF4                   ((uint32_t)0x20000004)
#define DMA_FLAG_TEIF4                    ((uint32_t)0x20000008)
#define DMA_FLAG_HTIF4                    ((uint32_t)0x20000010)
#define DMA_FLAG_TCIF4                    ((uint32_t)0x20000020)
#define DMA_FLAG_FEIF5                    ((uint32_t)0x20000040)
#define DMA_FLAG_DMEIF5                   ((uint32_t)0x20000100)
#define DMA_FLAG_TEIF5                    ((uint32_t)0x20000200)
#define DMA_FLAG_HTIF5                    ((uint32_t)0x20000400)
#define DMA_FLAG_TCIF5                    ((uint32_t)0x20000800)
#define DMA_FLAG_FEIF6                    ((uint32_t)0x20010000)
#define DMA_FLAG_DMEIF6                   ((uint32_t)0x20040000)
#define DMA_FLAG_TEIF6                    ((uint32_t)0x20080000)
#define DMA_FLAG_HTIF6                    ((uint32_t)0x20100000)
#define DMA_FLAG_TCIF6                    ((uint32_t)0x20200000)
#define DMA_FLAG_FEIF7                    ((uint32_t)0x20400000)
#define DMA_FLAG_DMEIF7                   ((uint32_t)0x21000000)
#define DMA_FLAG_TEIF7                    ((uint32_t)0x22000000)
#define DMA_FLAG_HTIF7                    ((uint32_t)0x24000000)
#define DMA_FLAG_TCIF7                    ((uint32_t)0x28000000)

#define DMA_Channel_0                     ((uint32_t)0x00000000)
#define DMA_Channel_1                     ((uint32_t)0x02000000)
#define DMA_Channel_2                     ((uint32_t)0x04000000)
#define DMA_Channel_3                     ((uint32_t)0x06000000)
#define DMA_Channel_4                     ((uint32_t)0x08000000)
#define DMA_Channel_5                     ((uint32_t)0x0A000000)
#define DMA_Channel_6                     ((uint32_t)0x0C000000)
#define DMA_Channel_7                     ((uint32_t)0x0E000000)

#define DMA_Memory_0                      ((uint32_t)0x00000000)
#define DMA_Memory_1                      ((uint32_t)0x00080000)

typedef struct
{
  uint32_t DMA_Channel;            /*!< Specifies the channel used for the specified stream. 
                                        This parameter can be a value of @ref DMA_channel */
 
  uint32_t DMA_PeripheralBaseAddr; /*!< Specifies the peripheral base address for DMAy Streamx. */

  uint32_t DMA_Memory0BaseAddr;    /*!< Specifies the memory 0 base address for DMAy Streamx. 
                                        This memory is the default memory used when double buffer mode is
                                        not enabled. */

  uint32_t DMA_DIR;                /*!< Specifies if the data will be transferred from memory to peripheral, 
                                        from memory to memory or from peripheral to memory.
                                        This parameter can be a value of @ref DMA_data_transfer_direction */

  uint32_t DMA_BufferSize;         /*!< Specifies the buffer size, in data unit, of the specified Stream. 
                                        The data unit is equal to the configuration set in DMA_PeripheralDataSize
                                        or DMA_MemoryDataSize members depending in the transfer direction. */

  uint32_t DMA_PeripheralInc;      /*!< Specifies whether the Peripheral address register should be incremented or not.
                                        This parameter can be a value of @ref DMA_peripheral_incremented_mode */

  uint32_t DMA_MemoryInc;          /*!< Specifies whether the memory address register should be incremented or not.
                                        This parameter can be a value of @ref DMA_memory_incremented_mode */

  uint32_t DMA_PeripheralDataSize; /*!< Specifies the Peripheral data width.
                                        This parameter can be a value of @ref DMA_peripheral_data_size */

  uint32_t DMA_MemoryDataSize;     /*!< Specifies the Memory data width.
                                        This parameter can be a value of @ref DMA_memory_data_size */

  uint32_t DMA_Mode;               /*!< Specifies the operation mode of the DMAy Streamx.
                                        This parameter can be a value of @ref DMA_circular_normal_mode
                                        @note The circular buffer mode cannot be used if the memory-to-memory
                                              data transfer is configured on the selected Stream */

  uint32_t DMA_Priority;           /*!< Specifies the software priority for the DMAy Streamx.
                                        This parameter can be a value of @ref DMA_priority_level */

  uint32_t DMA_FIFOMode;          /*!< Specifies if the FIFO mode or Direct mode will be used for the specified Stream.
                                        This parameter can be a value of @ref DMA_fifo_direct_mode
                                        @note The Direct mode (FIFO mode disabled) cannot be used if the 
                                               memory-to-memory data transfer is configured on the selected Stream */

  uint32_t DMA_FIFOThreshold;      /*!< Specifies the FIFO threshold level.
                                        This parameter can be a value of @ref DMA_fifo_threshold_level */

  uint32_t DMA_MemoryBurst;        /*!< Specifies the Burst transfer configuration for the memory transfers. 
                                        It specifies the amount of data to be transferred in a single non interruptable 
                                        transaction. This parameter can be a value of @ref DMA_memory_burst 
                                        @note The burst mode is possible only if the address Increment mode is enabled. */

  uint32_t DMA_PeripheralBurst;    /*!< Specifies the Burst transfer configuration for the peripheral transfers. 
                                        It specifies the amount of data to be transferred in a single non interruptable 
                                        transaction. This parameter can be a value of @ref DMA_peripheral_burst
                                        @note The burst mode is possible only if the address Increment mode is enabled. */  
}DMA_InitTypeDef;

void DMA_MemoryTargetConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t MemoryBaseAddr,
                            uint32_t DMA_MemoryTarget);
void DMA_Cmd(DMA_Stream_TypeDef* DMAy_Streamx, FunctionalState NewState);
void DMA_Init(DMA_Stream_TypeDef* DMAy_Streamx, DMA_InitTypeDef* DMA_InitStruct);
#endif /* #ifndef __STM32F4XX_DMA_MOCK_H */
