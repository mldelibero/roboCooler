#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStripMock.h"
#include "ledStripDriverMock.h"
#include "ledobj.h"

static uint32_t            Mock_DMA_Channel_X;
static uint32_t            Mock_DMA_FLAG_TCIFX;
static DMA_Stream_TypeDef* Mock_DMAX_StreamX;
static uint16_t            Mock_NumLeds = 10;
static uint32_t            Mock_RCC_AHB1Periph_DMAX;

// --- Mock to compile ledDriverDriver
CLedStripDriver::CLedStripDriver(uint16_t NumLeds, uint32_t RCC_AHB1Periph_DMAX, uint32_t DMA_Channel_X, DMA_Stream_TypeDef* DMAX_StreamX, uint32_t DMA_FLAG_TCIFX)
{
    m_NumLeds     = NumLeds;

    if (RCC_AHB1Periph_DMAX) return;
    if (DMA_Channel_X      ) return;
    if (DMAX_StreamX       ) return;
    if (DMA_FLAG_TCIFX     ) return;
}

CLedStripDriver::~CLedStripDriver(void)
{
}

void CLedStripDriver::Initialize_Hardware(void)
{
    mock().actualCall("CLedStripDriver::Initialize_Hardware");
}

void CLedStripDriver::Update(CLedObj* LedObjArray)
{
    mock().actualCall("CLedStripDriver::Update");
    if (LedObjArray == NULL) return;
}

void CLedStripDriver::Execute(void)
{
    mock().actualCall("CLedStripDriver::Execute");
}
void CLedStripDriver::Initialize(void)
{
    mock().actualCall("CLedStripDriver::Initialize");
}

// -- Mock that abstracts ledDriverDriver and allows input control
CLedStripDriverMock::CLedStripDriverMock() : CLedStripDriver(Mock_NumLeds, Mock_RCC_AHB1Periph_DMAX, Mock_DMA_Channel_X, Mock_DMAX_StreamX, Mock_DMA_FLAG_TCIFX)
{
}

CLedStripDriverMock::~CLedStripDriverMock(void)
{
}

void CLedStripDriverMock::Initialize_Hardware(void)
{
    mock().actualCall("CLedStripDriver::Initialize_Hardware");
}

void CLedStripDriverMock::Update(CLedObj* LedObjArray)
{
    mock().actualCall("CLedStripDriver::Update");
    if (LedObjArray == NULL) return;
}
