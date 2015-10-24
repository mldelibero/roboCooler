#include "leds.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"


#define LED_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define LED_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB
#define LED_GPIOx                    GPIOB
#define LED_GPIO_PinSourcex          GPIO_PinSource6
#define LED_GPIO_AF_USARTx           GPIO_AF_USART1
#define LED_GPIO_PIN_X               GPIO_Pin_6
#define LED_GPIO_MODE                GPIO_Mode_AF
#define LED_GPIO_SPEED               GPIO_High_Speed

#define LED_RCC_APBxPeriphClockCmd   RCC_APB2PeriphClockCmd
#define LED_APBxPeriph_USARTx        RCC_APB2Periph_USART1
#define LED_USARTx                   USART1
#define BAUD_RATE                    2700000

#define LED_DMA_AHBxPeriphClockCmd   RCC_AHB1PeriphClockCmd
#define LED_AHBxPeriph_DMAx          RCC_AHB1Periph_DMA2
#define USARTx_TX_DMA_CHANNEL        DMA_Channel_4
#define USARTx_TX_DMA_STREAM         DMA2_Stream7
#define USARTx_TX_DMA_FLAG_TCIF      DMA_FLAG_TCIF7

#define BUFFERSIZE  24
#define BITS_000    0xDB
#define BITS_001    0x9B
#define BITS_010    0xD3
#define BITS_011    0x93
#define BITS_100    0xDA
#define BITS_101    0x9A
#define BITS_110    0xD2
#define BITS_111    0x92

// Set the LEDs to Green Red Blue
uint8_t aTxBuffer[BUFFERSIZE] = {BITS_111, BITS_111, BITS_110, BITS_000, BITS_000, BITS_000, BITS_000, BITS_000,
                                 BITS_000, BITS_000, BITS_001, BITS_111, BITS_111, BITS_100, BITS_000, BITS_000,
                                 BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, BITS_011, BITS_111, BITS_111};

void init_leds(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
    DMA_InitTypeDef  DMA_InitStructure;

    // Init Peripheral clocks
    LED_GPIO_AHBxPeriphClockCmd(LED_AHBxPeriph_GPIOx,  ENABLE);
    LED_RCC_APBxPeriphClockCmd (LED_APBxPeriph_USARTx, ENABLE);
    LED_DMA_AHBxPeriphClockCmd (LED_AHBxPeriph_DMAx,   ENABLE);


    // Init GPIO
    GPIO_DeInit(LED_GPIOx);

    GPIO_PinAFConfig(LED_GPIOx, LED_GPIO_PinSourcex, LED_GPIO_AF_USARTx);

    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin   = LED_GPIO_PIN_X;
    GPIO_InitStruct.GPIO_Mode  = LED_GPIO_MODE;
    GPIO_InitStruct.GPIO_Speed = LED_GPIO_SPEED;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_DOWN;

    GPIO_Init(LED_GPIOx,&GPIO_InitStruct);


    // Init USART
    USART_DeInit(LED_USARTx);
    USART_StructInit(&USART_InitStruct);
    USART_OverSampling8Cmd(LED_USARTx, ENABLE);  

    USART_InitStruct.USART_BaudRate            = BAUD_RATE;
    USART_InitStruct.USART_WordLength          = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits            = USART_StopBits_0_5;
    USART_InitStruct.USART_Parity              = USART_Parity_No;
    USART_InitStruct.USART_Mode                = USART_Mode_Tx;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

    USART_Init(LED_USARTx, &USART_InitStruct);


    // Init DMA
    DMA_InitStructure.DMA_BufferSize         = BUFFERSIZE ;
    DMA_InitStructure.DMA_FIFOMode           = DMA_FIFOMode_Disable ;
    DMA_InitStructure.DMA_FIFOThreshold      = DMA_FIFOThreshold_1QuarterFull ;
    DMA_InitStructure.DMA_MemoryBurst        = DMA_MemoryBurst_Single ;
    DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;
    DMA_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) (&(LED_USARTx->DR)) ;
    DMA_InitStructure.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_Priority           = DMA_Priority_High;

    DMA_InitStructure.DMA_Channel            = USARTx_TX_DMA_CHANNEL ;
    DMA_InitStructure.DMA_DIR                = DMA_DIR_MemoryToPeripheral ;
    DMA_InitStructure.DMA_Memory0BaseAddr    =( uint32_t)aTxBuffer ;
    DMA_Init(USARTx_TX_DMA_STREAM,&DMA_InitStructure);

    USART_Cmd(LED_USARTx, ENABLE);

    // Loop Sending out GRB
    while(1)
    {
        DMA_Cmd(USARTx_TX_DMA_STREAM,ENABLE);
        USART_DMACmd(LED_USARTx, USART_DMAReq_Tx, ENABLE);

        while (USART_GetFlagStatus(LED_USARTx,USART_FLAG_TC)==RESET);    
        while (DMA_GetFlagStatus(USARTx_TX_DMA_STREAM,USARTx_TX_DMA_FLAG_TCIF)==RESET);
        for (int dly = 0xAAA; dly > 0; dly--);
        DMA_ClearFlag(USARTx_TX_DMA_STREAM,USARTx_TX_DMA_FLAG_TCIF);
        USART_ClearFlag(LED_USARTx,USART_FLAG_TC);  
    } // end - while(1)
} // end - void init_leds(void)

