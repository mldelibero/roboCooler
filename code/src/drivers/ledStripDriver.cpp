#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledStripDriver.h"
#include "stm32f4xx_dma.h"

CLedStripDriver::CLedStripDriver(uint16_t NumLeds, uint32_t RCC_AHB1Periph_DMAX, uint32_t DMA_Channel_X, DMA_Stream_TypeDef* DMAX_StreamX, uint32_t DMA_FLAG_TCIFX)
{
    m_NumLeds     = NumLeds;
    m_DMA_Ptr[0]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_Ptr[1]   = new uint8_t[NumLeds*8+1];
    m_DMA_PtrIndex = 0;
    Set_ComponentPeriod_ms(10);

    m_RCC_AHB1Periph_DMAX = RCC_AHB1Periph_DMAX;
    m_DMA_Channel_X       = DMA_Channel_X;
    m_DMAX_StreamX        = DMAX_StreamX;
    m_DMA_FLAG_TCIFX      = DMA_FLAG_TCIFX;

    CLedObj* Off = new CLedObj[m_NumLeds];
    m_UpdateAvailable = false;
    Update(Off);
    m_UpdateAvailable = true;
    Update(Off);
    m_UpdateAvailable = false;

    delete [] Off;
}

CLedStripDriver::~CLedStripDriver(void)
{
    delete [] m_DMA_Ptr[0];
    delete [] m_DMA_Ptr[1];
}

void CLedStripDriver::Execute(void)
{
    if (m_UpdateAvailable == true)
    { // Point DMA to other buffer
        m_DMA_PtrIndex = (m_DMA_PtrIndex xor 1);
        DMA_MemoryTargetConfig(m_DMAX_StreamX, *(uint32_t*)m_DMA_Ptr[m_DMA_PtrIndex], DMA_Memory_0);
    }

    m_UpdateAvailable = false;
}

void CLedStripDriver::Initialize(void){}

void CLedStripDriver::Initialize_Hardware(void)
{
    //RCC_AHB1PeriphClockCmd(m_RCC_AHB1Periph_DMAx);
    /*
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

    DMA_InitStructure.DMA_Channel            = m_DMA_Channel_x;
    DMA_InitStructure.DMA_DIR                = DMA_DIR_MemoryToPeripheral ;
    DMA_InitStructure.DMA_Memory0BaseAddr    =( uint32_t)aTxBuffer ;
    DMA_Init(m_DmaX_StreamX,&DMA_InitStructure);

    USART_Cmd(LED_USARTx, ENABLE);

    // Loop Sending out GRB
//    while(1)
//    {
//    DMA_MemoryTargetConfig(m_DmaX_StreamX, (uint32_t)&binLeds[0], DMA_Memory_0);

    DMA_Cmd(m_DmaX_StreamX,ENABLE);
    USART_DMACmd(LED_USARTx, USART_DMAReq_Tx, ENABLE);

    while (USART_GetFlagStatus(LED_USARTx,USART_FLAG_TC)==RESET);    
    while (DMA_GetFlagStatus(m_DmaX_StreamX,m_DMA_FLAG_TCIFX)==RESET);
    for (int dly = 0xFFFAAA; dly > 0; dly--);
    DMA_ClearFlag(m_DmaX_StreamX,m_DMA_FLAG_TCIFX);
    USART_ClearFlag(LED_USARTx,USART_FLAG_TC);  
    */
}

void CLedStripDriver::Update(CLedObj* LedObjArray)
{
    m_UpdateAvailable = true;
//    if (LedObjArray == NULL) return;
    uint8_t* WrPtr = m_DMA_Ptr[m_DMA_PtrIndex xor 1];
    for (uint8_t led = 0; led < m_NumLeds; led++)
    {
        UpdateSingleLed(LedObjArray, (uint8_t*)(WrPtr + 8*led), led);
    }

    uint8_t resIndex = uint8_t(m_NumLeds*8);
    UpdatePartialLedValue(WrPtr, resIndex, BIT_LOW, BIT_LOW, BIT_LOW);
}

inline void CLedStripDriver::UpdateSingleLed(CLedObj* LedObjArray, uint8_t* WritePointer, uint8_t LedIndex)
{

    uint8_t GreenLevel = uint8_t(0.5f + (LedObjArray[LedIndex].Get_Green_PercentOn() / 100.0 * 255));
    uint8_t RedLevel   = uint8_t(0.5f + (LedObjArray[LedIndex].Get_Red_PercentOn()   / 100.0 * 255));
    uint8_t BlueLevel  = uint8_t(0.5f + (LedObjArray[LedIndex].Get_Blue_PercentOn()  / 100.0 * 255));

    uint8_t G7 = ((GreenLevel & 0x80) == 0x80) ? BIT_HI : BIT_LOW;
    uint8_t G6 = ((GreenLevel & 0x40) == 0x40) ? BIT_HI : BIT_LOW;
    uint8_t G5 = ((GreenLevel & 0x20) == 0x20) ? BIT_HI : BIT_LOW;

    uint8_t G4 = ((GreenLevel & 0x10) == 0x10) ? BIT_HI : BIT_LOW;
    uint8_t G3 = ((GreenLevel & 0x08) == 0x08) ? BIT_HI : BIT_LOW;
    uint8_t G2 = ((GreenLevel & 0x04) == 0x04) ? BIT_HI : BIT_LOW;

    uint8_t G1 = ((GreenLevel & 0x02) == 0x02) ? BIT_HI : BIT_LOW;
    uint8_t G0 = ((GreenLevel & 0x01) == 0x01) ? BIT_HI : BIT_LOW;
    uint8_t R7 = ((RedLevel   & 0x80) == 0x80) ? BIT_HI : BIT_LOW;

    uint8_t R6 = ((RedLevel   & 0x40) == 0x40) ? BIT_HI : BIT_LOW;
    uint8_t R5 = ((RedLevel   & 0x20) == 0x20) ? BIT_HI : BIT_LOW;
    uint8_t R4 = ((RedLevel   & 0x10) == 0x10) ? BIT_HI : BIT_LOW;

    uint8_t R3 = ((RedLevel   & 0x08) == 0x08) ? BIT_HI : BIT_LOW;
    uint8_t R2 = ((RedLevel   & 0x04) == 0x04) ? BIT_HI : BIT_LOW;
    uint8_t R1 = ((RedLevel   & 0x02) == 0x02) ? BIT_HI : BIT_LOW;

    uint8_t R0 = ((RedLevel   & 0x01) == 0x01) ? BIT_HI : BIT_LOW;
    uint8_t B7 = ((BlueLevel  & 0x80) == 0x80) ? BIT_HI : BIT_LOW;
    uint8_t B6 = ((BlueLevel  & 0x40) == 0x40) ? BIT_HI : BIT_LOW;

    uint8_t B5 = ((BlueLevel  & 0x20) == 0x20) ? BIT_HI : BIT_LOW;
    uint8_t B4 = ((BlueLevel  & 0x10) == 0x10) ? BIT_HI : BIT_LOW;
    uint8_t B3 = ((BlueLevel  & 0x08) == 0x08) ? BIT_HI : BIT_LOW;

    uint8_t B2 = ((BlueLevel  & 0x04) == 0x04) ? BIT_HI : BIT_LOW;
    uint8_t B1 = ((BlueLevel  & 0x02) == 0x02) ? BIT_HI : BIT_LOW;
    uint8_t B0 = ((BlueLevel  & 0x01) == 0x01) ? BIT_HI : BIT_LOW;

    UpdatePartialLedValue(WritePointer, 0, G5, G6, G7);
    UpdatePartialLedValue(WritePointer, 1, G2, G3, G4);
    UpdatePartialLedValue(WritePointer, 2, R7, G0, G1);
    UpdatePartialLedValue(WritePointer, 3, R4, R5, R6);
    UpdatePartialLedValue(WritePointer, 4, R1, R2, R3);
    UpdatePartialLedValue(WritePointer, 5, B6, B7, R0);
    UpdatePartialLedValue(WritePointer, 6, B3, B4, B5);
    UpdatePartialLedValue(WritePointer, 7, B0, B1, B2);
}

inline void CLedStripDriver::UpdatePartialLedValue(uint8_t* WritePointer, uint8_t Index, uint8_t HiBits, uint8_t MedBits, uint8_t LoBits)
{
    WritePointer[Index] = uint8_t(HiBits << 5);
    WritePointer[Index] = WritePointer[Index] | uint8_t(MedBits << 2);
    WritePointer[Index] = uint8_t(WritePointer[Index] | uint8_t(LoBits >> 1));
}

