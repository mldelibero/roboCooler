#include "ledStripDriver.h"
#include "stm32f4xx_hal.h"
#include "hardwareSettings.h"

CLedStripDriver::CLedStripDriver(uint16_t NumLeds, DMA_Settings_t DMA_Settings, GPIO_Settings_t GPIO_Settings, USART_TypeDef* UARTN)
{
    m_NumLeds      = NumLeds;
    m_DMA_Ptr[0]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_Ptr[1]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_PtrIndex = 0;
    Set_ComponentPeriod_ms(10);

    m_DMA_Handle.Instance     = DMA_Settings.DMAN_StreamN;
    m_DMA_Handle.Init.Channel = DMA_Settings.DMA_Channel_N;

    m_GPIO = GPIO_Settings;
    m_USART_Handle.Instance = UARTN;

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

uint8_t data = 0x69;
void CLedStripDriver::Execute(void)
{
    if (m_UpdateAvailable == true)
    { // Point DMA to other buffer
        m_DMA_PtrIndex = (m_DMA_PtrIndex xor 1);
        //DMA_MemoryTargetConfig(m_DMA.DMAN_StreamN, *(uint32_t*)m_DMA_Ptr[m_DMA_PtrIndex], DMA_Memory_0);
    }
/*
    HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
    HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

    DMA_Cmd(m_DMA.DMAN_StreamN,ENABLE);
    USART_DMACmd(m_UART.USARTN, USART_DMAReq_Tx, ENABLE);

    m_UpdateAvailable = false;
    */
    HAL_USART_Transmit(&m_USART_Handle, &data, 1, 100);
}

void CLedStripDriver::Initialize(void){}

void CLedStripDriver::Initialize_Hardware(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    // Init GPIO
    InitializeGPIOClock(m_GPIO.GPIOX);
    GPIO_InitStruct.Pin       = m_GPIO.Pin_N;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Alternate = m_GPIO.GPIO_AF;

    HAL_GPIO_Init(m_GPIO.GPIOX, &GPIO_InitStruct);

    // Init USART
    ///@bug Shouldn't know that this is USART2
    __HAL_RCC_USART2_CLK_ENABLE();
    HAL_USART_DeInit(&m_USART_Handle);

    m_USART_Handle.Init.BaudRate     = 2700000; // 2.7MHz
    m_USART_Handle.Init.WordLength   = USART_WORDLENGTH_8B;
    m_USART_Handle.Init.StopBits     = USART_STOPBITS_0_5;
    m_USART_Handle.Init.Parity       = USART_PARITY_NONE;
    m_USART_Handle.Init.Mode         = USART_MODE_TX;
    // Not sure what these 3 do
    m_USART_Handle.Init.CLKPolarity  = USART_POLARITY_HIGH;
    m_USART_Handle.Init.CLKPhase     = USART_PHASE_1EDGE;
    m_USART_Handle.Init.CLKLastBit   = USART_LASTBIT_DISABLE;
//    USART_InitStruct.HwFlowCtl    = UART_HWCONTROL_NONE;
//    USART_InitStruct.OverSampling = UART_OVERSAMPLING_8;

    HAL_USART_Init(&m_USART_Handle);

    // Init DMA
    ///@bug -- abstract this line -- We shouldn't know that it is DMA2
    __HAL_RCC_DMA2_CLK_ENABLE();

//    m_DMA_Handle.Init.Channel             = m_DMA.DMA_Channel_N;
    m_DMA_Handle.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    m_DMA_Handle.Init.PeriphInc           = DMA_PINC_DISABLE;
    m_DMA_Handle.Init.MemInc              = DMA_MINC_ENABLE;
    m_DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    m_DMA_Handle.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    m_DMA_Handle.Init.Mode                = DMA_CIRCULAR;
    m_DMA_Handle.Init.Priority            = DMA_PRIORITY_HIGH;
    m_DMA_Handle.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    m_DMA_Handle.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_1QUARTERFULL;
    m_DMA_Handle.Init.MemBurst            = DMA_MBURST_SINGLE;
    m_DMA_Handle.Init.PeriphBurst         = DMA_PBURST_SINGLE;

    //DMA_InitStructure.BufferSize         = m_NumLeds * 8 + 1;
    //DMA_InitStructure.PeripheralBaseAddr = (uint32_t)(unsigned long int)(&(m_UART.USARTN->DR));
    //DMA_InitStructure.Memory0BaseAddr    =(uint32_t)(unsigned long int)m_DMA_Ptr[m_DMA_PtrIndex];
    HAL_DMA_Init(&m_DMA_Handle);
    //USART_Cmd(m_UART.USARTN, ENABLE);
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
    uint8_t GreenLevel = uint8_t(0.5f + (LedObjArray[LedIndex].Get_Green_PercentOn() / 100.0f * 255));
    uint8_t RedLevel   = uint8_t(0.5f + (LedObjArray[LedIndex].Get_Red_PercentOn()   / 100.0f * 255));
    uint8_t BlueLevel  = uint8_t(0.5f + (LedObjArray[LedIndex].Get_Blue_PercentOn()  / 100.0f * 255));

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

