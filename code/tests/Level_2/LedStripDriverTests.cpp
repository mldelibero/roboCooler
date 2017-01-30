#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledStripDriver.h"
#include "stm32f4xx.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_rcc.h"

// ------------------------------------------------------------------------
uint32_t myRCC_AHB1Periph_DMAX     = RCC_AHB1Periph_DMA1;
uint32_t myDMA_Channel_X           = DMA_Channel_4;
DMA_Stream_TypeDef* myDMAX_StreamX = DMA2_Stream6;
uint32_t myDMA_FLAG_TCIFX          = DMA_FLAG_TCIF6;
//
// -- Accessor Class ------------------------------------------------------
class CLedStripDriverChild : CLedStripDriver
{
    public:
        CLedStripDriverChild(uint16_t NumLeds, uint32_t RCC_AHB1Periph_DMAX, uint32_t DMA_Channel_X, DMA_Stream_TypeDef* DMAX_StreamX, uint32_t DMA_FLAG_TCIFX) : CLedStripDriver(NumLeds, RCC_AHB1Periph_DMAX, DMA_Channel_X, DMAX_StreamX, DMA_FLAG_TCIFX) {}

        ~CLedStripDriverChild(void) {}

        uint8_t* Get_CurrentDmaPtr(void)
        {
            return m_DMA_Ptr[m_DMA_PtrIndex];
        }

        uint8_t* Get_DmaPopPointer(void)
        { // Returns the pointer to which you are populating data
            return m_DMA_Ptr[m_DMA_PtrIndex xor 1];
        }

        int32_t Get_Period_ms(void)
        {
            return Get_ComponentPeriod_ms();
        }
}; // end - class CLedStripDriverChild : CLedStripDriver
// ------------------------------------------------------------------------
CLedStripDriverChild* LedStripDriver;
CLedObj*              LedObjArray;
static uint16_t       NumLeds = 0;
// ------------------------------------------------------------------------
TEST_GROUP(LedStripDriverTests)
{
    void setup()
    {
        mock().disable();
        NumLeds = 2;

        myRCC_AHB1Periph_DMAX = RCC_AHB1Periph_DMA1;
        myDMA_Channel_X       = DMA_Channel_4;
        myDMAX_StreamX        = DMA2_Stream6;
        myDMA_FLAG_TCIFX      = DMA_FLAG_TCIF6;

        LedStripDriver = new CLedStripDriverChild(NumLeds, myRCC_AHB1Periph_DMAX, myDMA_Channel_X, myDMAX_StreamX, myDMA_FLAG_TCIFX);
        LedObjArray    = new CLedObj[NumLeds];
    }

    void teardown()
    {
        delete LedStripDriver;
        delete [] LedObjArray;
    }
};

TEST(LedStripDriverTests, ZeroAndOneDefinesAreCorrect)
{ // This is pivital to the process
    CHECK_EQUAL(0x06, BIT_LOW);
    CHECK_EQUAL(0x04, BIT_HI);
}

TEST(LedStripDriverTests, DMAPointerStaysTheSameIfLedStripIsTheSame)
{
    uint8_t* DmaPtr = LedStripDriver->Get_CurrentDmaPtr();
    ((CComponent*)(LedStripDriver))->Run();
    POINTERS_EQUAL(DmaPtr, LedStripDriver->Get_CurrentDmaPtr());
}

TEST(LedStripDriverTests, DMAPointerUpdatesAfterNewInformationUpdated)
{
    uint8_t* DmaPtr1 = NULL;
    uint8_t* DmaPtr2 = NULL;

    DmaPtr1 = LedStripDriver->Get_CurrentDmaPtr();
    ((CLedStripDriver*)(LedStripDriver))->Update(LedObjArray);
    POINTERS_EQUAL(DmaPtr1, LedStripDriver->Get_CurrentDmaPtr());

    ((CComponent*)(LedStripDriver))->Run();
    DmaPtr2 = LedStripDriver->Get_CurrentDmaPtr();

    long unsigned int a = reinterpret_cast<uintptr_t>(DmaPtr1);
    long unsigned int b = reinterpret_cast<uintptr_t>(DmaPtr2);
    CHECK_FALSE(a == b);
}

TEST(LedStripDriverTests, DMATriggeredAt100Hz)
{
    CHECK_EQUAL(10, LedStripDriver->Get_Period_ms());
}

TEST(LedStripDriverTests, DMALengthSetProperly)
{
    /// @bug Not checking LED Strip Driver DMA length setting
}

TEST(LedStripDriverTests, AllLEDBitsInDoubleBufferInitializedToBIT_LOW)
{
    uint8_t* EncodedData = LedStripDriver->Get_DmaPopPointer();

    for (uint8_t led = 0; led < NumLeds*8+1; led++)
    {
        CHECK_EQUAL(219, EncodedData[led]);
    }
}

TEST(LedStripDriverTests, AllLedBitsCanBeSetAndReset)
{ // Set and Reset all bits for an LED and check all 8 bytes of encoded data
// See LedEncoding.xlsx for calculations on this
    LedObjArray[0].Set_Green_PercentOn(6.64f);
    LedObjArray[0].Set_Red_PercentOn  (38.67f);
    LedObjArray[0].Set_Blue_PercentOn (37.11f);

    ((CLedStripDriver*)(LedStripDriver))->Update(LedObjArray);

    uint8_t* EncodedData = LedStripDriver->Get_DmaPopPointer();

// See LedEncoding.xlsx for calculations on this
    CHECK_EQUAL(219, EncodedData[0]);
    CHECK_EQUAL(218, EncodedData[1]);
    CHECK_EQUAL(211, EncodedData[2]);
    CHECK_EQUAL(210, EncodedData[3]);
    CHECK_EQUAL(155, EncodedData[4]);
    CHECK_EQUAL(154, EncodedData[5]);
    CHECK_EQUAL(147, EncodedData[6]);
    CHECK_EQUAL(146, EncodedData[7]);

    LedObjArray[0].Set_Green_PercentOn(93.33f);
    LedObjArray[0].Set_Red_PercentOn  (61.18f);
    LedObjArray[0].Set_Blue_PercentOn (62.75f);

    ((CLedStripDriver*)(LedStripDriver))->Update(LedObjArray);

// See LedEncoding.xlsx for calculations on this
    CHECK_EQUAL(146, EncodedData[0]);
    CHECK_EQUAL(147, EncodedData[1]);
    CHECK_EQUAL(154, EncodedData[2]);
    CHECK_EQUAL(155, EncodedData[3]);
    CHECK_EQUAL(210, EncodedData[4]);
    CHECK_EQUAL(211, EncodedData[5]);
    CHECK_EQUAL(218, EncodedData[6]);
    CHECK_EQUAL(219, EncodedData[7]);
}

TEST(LedStripDriverTests, ResetCommandIsAtTheEndOfTheStrip)
{
    uint8_t* EncodedData = LedStripDriver->Get_DmaPopPointer();
    ((CLedStripDriver*)(LedStripDriver))->Update(LedObjArray);

// See LedEncoding.xlsx for calculations on this
    CHECK_EQUAL(219, EncodedData[NumLeds * 8]);
}

TEST(LedStripDriverTests, MultipleLedsCanBeUsed)
{ // check setting two LEDs to different values
// See LedEncoding.xlsx for calculations on this
    LedObjArray[0].Set_Green_PercentOn(6.64f);
    LedObjArray[0].Set_Red_PercentOn  (38.67f);
    LedObjArray[0].Set_Blue_PercentOn (37.11f);

    ((CLedStripDriver*)(LedStripDriver))->Update(LedObjArray);

    uint8_t* EncodedData = LedStripDriver->Get_DmaPopPointer();

// See LedEncoding.xlsx for calculations on this
    CHECK_EQUAL(219, EncodedData[0]);
    CHECK_EQUAL(218, EncodedData[1]);
    CHECK_EQUAL(211, EncodedData[2]);
    CHECK_EQUAL(210, EncodedData[3]);
    CHECK_EQUAL(155, EncodedData[4]);
    CHECK_EQUAL(154, EncodedData[5]);
    CHECK_EQUAL(147, EncodedData[6]);
    CHECK_EQUAL(146, EncodedData[7]);

    LedObjArray[1].Set_Green_PercentOn(93.33f);
    LedObjArray[1].Set_Red_PercentOn  (61.18f);
    LedObjArray[1].Set_Blue_PercentOn (62.75f);

    ((CLedStripDriver*)(LedStripDriver))->Update(LedObjArray);

// See LedEncoding.xlsx for calculations on this
    CHECK_EQUAL(146, EncodedData[8]);
    CHECK_EQUAL(147, EncodedData[9]);
    CHECK_EQUAL(154, EncodedData[10]);
    CHECK_EQUAL(155, EncodedData[11]);
    CHECK_EQUAL(210, EncodedData[12]);
    CHECK_EQUAL(211, EncodedData[13]);
    CHECK_EQUAL(218, EncodedData[14]);
    CHECK_EQUAL(219, EncodedData[15]);
}

