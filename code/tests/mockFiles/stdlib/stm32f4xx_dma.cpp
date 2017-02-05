#include "stm32f4xx_dma.h"


void DMA_MemoryTargetConfig(DMA_Stream_TypeDef* DMAy_Streamx, uint32_t MemoryBaseAddr, uint32_t DMA_MemoryTarget)
{
    if (DMAy_Streamx == NULL) return;
    if (MemoryBaseAddr)       return;
    if (DMA_MemoryTarget)     return;
}

void DMA_Cmd(DMA_Stream_TypeDef* DMAy_Streamx, FunctionalState NewState)
{
    if (DMAy_Streamx == NULL) return;
    if (NewState)             return;
}

void DMA_Init(DMA_Stream_TypeDef* DMAy_Streamx, DMA_InitTypeDef* DMA_InitStruct)
{;
    if (DMAy_Streamx == NULL)   return;
    if (DMA_InitStruct == NULL) return;
}

