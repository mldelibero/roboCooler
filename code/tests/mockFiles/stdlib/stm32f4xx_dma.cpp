#include "stm32f4xx_dma.h"


void DMA_MemoryTargetConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t MemoryBaseAddr, uint32_t DMA_MemoryTarget)
{
    if (DMAy_Streamx == NULL) return;
    if (MemoryBaseAddr)       return;
    if (DMA_MemoryTarget)     return;
}

