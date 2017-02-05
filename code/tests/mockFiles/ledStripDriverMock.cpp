#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStripMock.h"
#include "ledStripDriverMock.h"
#include "ledobj.h"

static uint16_t        Mock_NumLeds = 10;
static DMA_Settings_t  Mock_DMA_Settings;
static GPIO_Settings_t Mock_GPIO_Settings;
static UART_Settings_t Mock_UART_Settings;

// --- Mock to compile ledDriverDriver
CLedStripDriver::CLedStripDriver(uint16_t NumLeds, DMA_Settings_t DMA_Settings, GPIO_Settings_t GPIO_Settings, UART_Settings_t UART_Settings)
{
    m_NumLeds     = NumLeds;

    if (DMA_Settings.DMA_Channel_N         ) return;
    if (GPIO_Settings.PinSourceN           ) return;
    if (UART_Settings.RCC_APBNPeriph_USARTN) return;
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
CLedStripDriverMock::CLedStripDriverMock() : CLedStripDriver(Mock_NumLeds, Mock_DMA_Settings, Mock_GPIO_Settings, Mock_UART_Settings)
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
