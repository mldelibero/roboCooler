#include "ledStripDriver.h"
#include "hardwareSettings.h"

CLedStripDriver::CLedStripDriver(uint16_t NumLeds, ARM_DRIVER_USART* Driver_USARTn)
{
    m_NumLeds      = NumLeds;
    m_DMA_Ptr[0]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_Ptr[1]   = new uint8_t[m_NumLeds*8+1];
    m_DMA_PtrIndex = 0;
    Set_ComponentPeriod_ms(10);

    m_Driver_USARTn = Driver_USARTn;

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

    m_Driver_USARTn->Send(m_DMA_Ptr[m_DMA_PtrIndex], m_NumLeds * 8 + 1);
}

void CLedStripDriver::Initialize(void){}

void CLedStripDriver::Initialize_Hardware(void)
{
    m_Driver_USARTn->Initialize(NULL);
    m_Driver_USARTn->PowerControl(ARM_POWER_FULL);
    m_Driver_USARTn->Control(
            ARM_USART_MODE_ASYNCHRONOUS |
            ARM_USART_DATA_BITS_8       |
            ARM_USART_PARITY_NONE       |
            ARM_USART_STOP_BITS_0_5, 2700000
            );
    m_Driver_USARTn->Control(ARM_USART_CONTROL_TX, 1); // Enable Transmitter
    m_Driver_USARTn->Control(ARM_USART_CONTROL_RX, 0); // Disable Receiver

    /*
    m_USART_Handle.Init.BaudRate     = 2650000; // Shouldn't need to do this.
    __HAL_RCC_DMA2_CLK_ENABLE();
    HAL_NVIC_SetPriority(DMA2_Stream6_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA2_Stream6_IRQn);
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

