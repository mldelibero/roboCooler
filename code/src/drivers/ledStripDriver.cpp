#include "ledStripDriver.h"
#include "stm32f4xx_hal.h"
#include "hardwareSettings.h"

USART_HandleTypeDef husart6;
DMA_HandleTypeDef hdma_usart6_tx;
uint8_t data[] = {0x7E, 0x69};

#define LED_USART_Pin GPIO_PIN_6
#define LED_USART_GPIO_Port GPIOC

CLedStripDriver::CLedStripDriver(uint16_t NumLeds, DMA_Settings_t DMA_Settings, GPIO_Settings_t GPIO_Settings, USART_TypeDef* USARTN)
{
    m_NumLeds      = NumLeds;
    m_DMA_Ptr[0]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_Ptr[1]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_PtrIndex = 0;
    Set_ComponentPeriod_ms(10);

    m_DMA_Handle.Instance     = DMA_Settings.DMAN_StreamN;
    m_DMA_Handle.Init.Channel = DMA_Settings.DMA_Channel_N;

    m_GPIO = GPIO_Settings;
    m_USART_Handle.Instance = USARTN;

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
    }

    m_UpdateAvailable = false;

    // Fix to enable multiple msgs to be transmitted
    USART_HandleTypeDef* husart = (USART_HandleTypeDef* )((DMA_HandleTypeDef* )(&hdma_usart6_tx))->Parent;
    husart->State=HAL_USART_STATE_READY; 

    //DMA_MemoryTargetConfig(m_DMA.DMAN_StreamN, *(uint32_t*)m_DMA_Ptr[m_DMA_PtrIndex], DMA_Memory_0);
    //HAL_USART_Transmit_DMA(&huart6,&data[0],sizeof(data));
    HAL_USART_Transmit_DMA(&husart6,m_DMA_Ptr[m_DMA_PtrIndex],m_NumLeds * 8 + 1);
}

void CLedStripDriver::Initialize(void){}

void CLedStripDriver::Initialize_Hardware(void)
{
    /* DMA controller clock enable */
    __HAL_RCC_DMA2_CLK_ENABLE();

    /* DMA interrupt init */
    /* DMA2_Stream6_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);

    husart6.Instance          = USART6;
    husart6.Init.BaudRate     = 2700000;
    husart6.Init.BaudRate     = 2650000; // Shouldn't need to do this.
    husart6.Init.WordLength   = USART_WORDLENGTH_8B;
    husart6.Init.StopBits     = USART_STOPBITS_0_5;
    husart6.Init.Parity       = USART_PARITY_NONE;
    husart6.Init.Mode         = USART_MODE_TX;
    //husart6.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    //husart6.Init.OverSampling = UART_OVERSAMPLING_8;
    if (HAL_USART_Init(&husart6) != HAL_OK)
    {
        //        Error_Handler();
    }
}

USART_TypeDef* CLedStripDriver::Get_UsartN(void)
{
    return m_USART_Handle.Instance;
}

void CLedStripDriver::HAL_USART_MspInit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    __HAL_RCC_USART6_CLK_ENABLE();
//#define ret(n) n
 //   #define USART_CLK_ENABLE(USARTN)  __HAL_RCC_## USARTN## _CLK_ENABLE();
//#define USART_CLK_ENABLE(USARTN)  __HAL_RCC_## ret(USARTN)## _CLK_ENABLE();

//    USART_CLK_ENABLE(m_USART.Instance);
    //USART_CLK_ENABLE(USART6);

    GPIO_InitStruct.Pin       = m_GPIO.Pin_N;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    //GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
//    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = m_GPIO.GPIO_AF;

    //InitializeGPIOClock(m_GPIO.GPIOX);
    HAL_GPIO_Init(m_GPIO.GPIOX, &GPIO_InitStruct);

    /* Peripheral DMA init*/
    hdma_usart6_tx.Instance                 = DMA2_Stream6;
    hdma_usart6_tx.Init.Channel             = DMA_CHANNEL_5;
    hdma_usart6_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_usart6_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart6_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart6_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart6_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart6_tx.Init.Mode                = DMA_NORMAL;
    hdma_usart6_tx.Init.Priority            = DMA_PRIORITY_LOW;
    hdma_usart6_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart6_tx) != HAL_OK)
    {
        //          Error_Handler();
    }

    __HAL_LINKDMA(&husart6,hdmatx,hdma_usart6_tx);
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

void tempfun(void)
{
    /*
       GPIO_InitTypeDef  GPIO_InitStruct;

    // INitialize DMA clock
    __HAL_RCC_DMA2_CLK_ENABLE();

    // UART prep
    m_UART_Handle.Instance = USART6;

    m_UART_Handle.Init.BaudRate     = 2700000;
    m_UART_Handle.Init.WordLength   = UART_WORDLENGTH_8B;
    m_UART_Handle.Init.StopBits     = UART_STOPBITS_1;
    m_UART_Handle.Init.Parity       = UART_PARITY_NONE;
    m_UART_Handle.Init.Mode         = UART_MODE_TX;
    m_UART_Handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    m_UART_Handle.Init.OverSampling = UART_OVERSAMPLING_8;

    // USART clock enable
    __HAL_RCC_USART6_CLK_ENABLE():

    // Init USART
    ///@bug Shouldn't know that this is USART6
    //__HAL_RCC_USART6_CLK_ENABLE();
    //HAL_USART_DeInit(&m_USART_Handle);
    HAL_UART_DeInit(m_UART_Handle);

    m_USART_Handle.Init.BaudRate     = 2700000; // 2.7MHz
    m_USART_Handle.Init.WordLength   = USART_WORDLENGTH_8B;
    m_USART_Handle.Init.StopBits     = USART_STOPBITS_0_5;
    m_USART_Handle.Init.Parity       = USART_PARITY_NONE;
    m_USART_Handle.Init.Mode         = USART_MODE_TX;
    // Not sure what these 3 do
    m_USART_Handle.Init.CLKPolarity  = USART_POLARITY_HIGH;
    m_USART_Handle.Init.CLKPhase     = USART_PHASE_1EDGE;
    m_USART_Handle.Init.CLKLastBit   = USART_LASTBIT_DISABLE;
    //    m_USART_Handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    //    m_USART_Handle.Init.OverSampling = UART_OVERSAMPLING_8;
    */

    //HAL_HalfDuplex_Init(&m_UART_Handle);

    // Init DMA
    ///@bug -- abstract this line -- We shouldn't know that it is DMA2
    //    __HAL_RCC_DMA2_CLK_ENABLE();

//    m_DMA_Handle.Init.Channel             = m_DMA.DMA_Channel_N;
//    m_DMA_Handle.Init.Direction           = DMA_MEMORY_TO_PERIPH;
//    m_DMA_Handle.Init.PeriphInc           = DMA_PINC_DISABLE;
//    m_DMA_Handle.Init.MemInc              = DMA_MINC_ENABLE;
//    m_DMA_Handle.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
//    m_DMA_Handle.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
//    m_DMA_Handle.Init.Mode                = DMA_CIRCULAR;
//    m_DMA_Handle.Init.Priority            = DMA_PRIORITY_HIGH;
//    m_DMA_Handle.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
//    m_DMA_Handle.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_1QUARTERFULL;
//    m_DMA_Handle.Init.MemBurst            = DMA_MBURST_SINGLE;
//    m_DMA_Handle.Init.PeriphBurst         = DMA_PBURST_SINGLE;
//
   //DMA_InitStructure.BufferSize         = m_NumLeds * 8 + 1;
   //DMA_InitStructure.PeripheralBaseAddr = (uint32_t)(unsigned long int)(&(m_UART.USARTN->DR));
   //DMA_InitStructure.Memory0BaseAddr    =(uint32_t)(unsigned long int)m_DMA_Ptr[m_DMA_PtrIndex];
//    HAL_DMA_Init(&m_DMA_Handle);

//    HAL_USART_Init(&m_USART_Handle);
}

/**
* @brief This function handles DMA2 stream6 global interrupt.
*/
//void DMA2_Stream6_IRQHandler(void)
//{
//  HAL_DMA_IRQHandler(&hdma_usart6_tx);
//}
