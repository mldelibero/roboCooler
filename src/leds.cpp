#include "leds.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"


#define LED_GPIO_AHBxPeriphClockCmd  RCC_AHB1PeriphClockCmd
#define LED_AHBxPeriph_GPIOx         RCC_AHB1Periph_GPIOB

// PB6
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

#define BUFFERSIZE  56
#define BITS_000    0xDB
#define BITS_001    0x9B
#define BITS_010    0xD3
#define BITS_011    0x93
#define BITS_100    0xDA
#define BITS_101    0x9A
#define BITS_110    0xD2
#define BITS_111    0x92

// Set the LEDs to Green Red Blue
uint8_t aTxBuffer[BUFFERSIZE] = {BITS_100, BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, // G
                                 BITS_000, BITS_000, BITS_001, BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, // R
                                 BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, BITS_010, BITS_000, BITS_000, // B
                                 BITS_100, BITS_000, BITS_001, BITS_000, BITS_000, BITS_000, BITS_000, BITS_000, // GR
                                 BITS_100, BITS_000, BITS_000, BITS_000, BITS_000, BITS_010, BITS_000, BITS_000, // GB
                                 BITS_000, BITS_000, BITS_001, BITS_000, BITS_000, BITS_010, BITS_000, BITS_000, // RB
                                 BITS_100, BITS_000, BITS_001, BITS_000, BITS_000, BITS_010, BITS_000, BITS_000};// GBR

uint8_t colors[8] = {0,1,2,3,4,5,6,7};
uint8_t msbs[8];
uint8_t lsbs[8];
uint8_t nums[8];

typedef enum
{
    BLUE ,
    RED  ,
    GREEN
} ledColors_t;

#define NUM_LEDS        7

typedef struct
{ 
    uint8_t color[3];
} led_t; 

led_t leds[NUM_LEDS]; 

typedef struct
{ 
    uint8_t data[8];
} binaryLed_t;

binaryLed_t binLeds[NUM_LEDS];

void init_Colors(void)
{
    leds[0].color[GREEN] = 0x80;
    leds[1].color[RED]   = 0x80;
    leds[2].color[BLUE]  = 0x80;
    leds[3].color[GREEN] = 0x80;
    leds[3].color[RED]   = 0x80;
    leds[4].color[GREEN] = 0x80;
    leds[4].color[BLUE]  = 0x80;
    leds[5].color[RED]   = 0x80;
    leds[5].color[BLUE]  = 0x80;
    leds[6].color[GREEN] = 0x80;
    leds[6].color[RED]   = 0x80;
    leds[6].color[BLUE]  = 0x80;
}

uint8_t ledConv(uint8_t bData)
{
    uint8_t msb, lsb;
        msb = 0x90 | (0x40 ^ (bData % 2) << 6);
        lsb = ((bData & 0x2)^0x2) << 2 | 0x2 | bData < 4;
        

        //msb = 0x90 | ((bData < 4) << 6);
//        lsb = 0x02 | (bData & 1) ^ 1 | ((bData & 2) ^ 1) << 3;
        return msb | lsb;
}
void populateBinLeds(void)
{
    for (int led = 0; led < NUM_LEDS; led++)
    {
        binLeds[led].data[7] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 0))  >> 0);  // B0B1B2
        binLeds[led].data[6] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 3))  >> 3);  // B3B4B5
        binLeds[led].data[5] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 6))  >> 6);  // B6B7R0
        binLeds[led].data[4] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 9))  >> 9);  // R1R2R3
        binLeds[led].data[3] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 12)) >> 12); // R4R5R6
        binLeds[led].data[2] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 15)) >> 15); // R7G0G1
        binLeds[led].data[1] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 18)) >> 18); // G2G3G4
        binLeds[led].data[0] =  ledConv((*(uint32_t*)&leds[led] & (0x7 << 21)) >> 21); // G5G6G7
    } // end - for (int led = 0; led < NUM_LEDS; led++)
} // end - void populateBinLeds(void)

void init_leds(void)
{
    init_Colors();
    populateBinLeds();

    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
    DMA_InitTypeDef  DMA_InitStructure;

    // Init Peripheral clocks
    LED_GPIO_AHBxPeriphClockCmd(LED_AHBxPeriph_GPIOx,  ENABLE);
    LED_RCC_APBxPeriphClockCmd (LED_APBxPeriph_USARTx, ENABLE);
    LED_DMA_AHBxPeriphClockCmd (LED_AHBxPeriph_DMAx,   ENABLE);


    // Init GPIO

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
//    while(1)
//    {
//    DMA_MemoryTargetConfig(USARTx_TX_DMA_STREAM, (uint32_t)&binLeds[0], DMA_Memory_0);

    DMA_Cmd(USARTx_TX_DMA_STREAM,ENABLE);
    USART_DMACmd(LED_USARTx, USART_DMAReq_Tx, ENABLE);

    while (USART_GetFlagStatus(LED_USARTx,USART_FLAG_TC)==RESET);    
    while (DMA_GetFlagStatus(USARTx_TX_DMA_STREAM,USARTx_TX_DMA_FLAG_TCIF)==RESET);
    for (int dly = 0xFFFAAA; dly > 0; dly--);
    DMA_ClearFlag(USARTx_TX_DMA_STREAM,USARTx_TX_DMA_FLAG_TCIF);
    USART_ClearFlag(LED_USARTx,USART_FLAG_TC);  

    //} // end - while(1)
    while(1);
} // end - void init_leds(void)

