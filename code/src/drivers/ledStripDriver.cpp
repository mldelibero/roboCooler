#include "ledStripDriver.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_usart.h"
#include "hardwareSettings.h"

CLedStripDriver::CLedStripDriver(uint16_t NumLeds, DMA_Settings_t DMA_Settings, GPIO_Settings_t GPIO_Settings, UART_Settings_t UART_Settings)
{
    m_NumLeds     = NumLeds;
    m_DMA_Ptr[0]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_Ptr[1]   = new uint8_t[NumLeds*8+1];
    m_DMA_PtrIndex = 0;
    Set_ComponentPeriod_ms(10);

    m_DMA  = DMA_Settings;
    m_GPIO = GPIO_Settings;
    m_UART = UART_Settings;

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
        DMA_MemoryTargetConfig(m_DMA.DMAN_StreamN, *(uint32_t*)m_DMA_Ptr[m_DMA_PtrIndex], DMA_Memory_0);
    }

    DMA_Cmd(m_DMA.DMAN_StreamN,ENABLE);
    USART_DMACmd(m_UART.USARTN, USART_DMAReq_Tx, ENABLE);

    m_UpdateAvailable = false;
}

void CLedStripDriver::Initialize(void){}

void CLedStripDriver::Initialize_Hardware(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
    DMA_InitTypeDef   DMA_InitStructure;

    // Init Peripheral clocks
    InitializeGPIOClock(m_GPIO.GPIOX);
    RCC_AHB1PeriphClockCmd(m_UART.RCC_APBNPeriph_USARTN, ENABLE);
    RCC_AHB1PeriphClockCmd(LED_AHBxPeriph_DMAx   , ENABLE);

    // Init GPIO
    GPIO_InitStruct.Pin       = m_GPIO.Pin_N;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
    GPIO_InitStruct.Alternate = m_GPIO.GPIO_AF;

    HAL_GPIO_Init(m_GPIO.GPIOX, &GPIO_InitStruct);

    // Init USART
    USART_DeInit(m_UART.USARTN);
    USART_StructInit(&USART_InitStruct);
    USART_OverSampling8Cmd(m_UART.USARTN, ENABLE);

    USART_InitStruct.USART_BaudRate            = 2700000; // 2.7MHz
    USART_InitStruct.USART_WordLength          = USART_WordLength_8b;
    USART_InitStruct.USART_StopBits            = USART_StopBits_0_5;
    USART_InitStruct.USART_Parity              = USART_Parity_No;
    USART_InitStruct.USART_Mode                = USART_Mode_Tx;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

    USART_Init(m_UART.USARTN, &USART_InitStruct);

    // Init DMA
    DMA_InitStructure.DMA_BufferSize         = m_NumLeds * 8 + 1;
    DMA_InitStructure.DMA_FIFOMode           = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold      = DMA_FIFOThreshold_1QuarterFull;
    DMA_InitStructure.DMA_MemoryBurst        = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_Mode               = DMA_Mode_Normal;
    DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(unsigned long int)(&(m_UART.USARTN->DR));
    DMA_InitStructure.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_Priority           = DMA_Priority_High;

    DMA_InitStructure.DMA_Channel            = m_DMA.DMA_Channel_N;
    DMA_InitStructure.DMA_DIR                = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_Memory0BaseAddr    =(uint32_t)(unsigned long int)m_DMA_Ptr[m_DMA_PtrIndex];
    DMA_Init(m_DMA.DMAN_StreamN, &DMA_InitStructure);

    USART_Cmd(m_UART.USARTN, ENABLE);
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

