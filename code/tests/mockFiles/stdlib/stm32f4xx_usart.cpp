#include "stm32f4xx_usart.h"

void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)
{
    if (USARTx == NULL)           return;
    if (USART_InitStruct == NULL) return;
}

void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState)
{
    if (USARTx == NULL) return;
    if (USART_DMAReq)   return;
    if (NewState)       return;
}

void USART_DeInit(USART_TypeDef* USARTx)
{
    if (USARTx == NULL) return;
}

void USART_StructInit(USART_InitTypeDef* USART_InitStruct)
{
    if (USART_InitStruct == NULL) return;
}

void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
    if (USARTx == NULL) return;
    if (NewState)       return;
}
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
    if (USARTx == NULL) return;
    if (NewState)       return;
}

