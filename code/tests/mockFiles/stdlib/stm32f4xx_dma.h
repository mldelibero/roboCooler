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

void DMA_MemoryTargetConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t MemoryBaseAddr,
                            uint32_t DMA_MemoryTarget);

#endif /* #ifndef __STM32F4XX_DMA_MOCK_H */
