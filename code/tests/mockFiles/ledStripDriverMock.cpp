#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStripMock.h"
#include "ledStripDriverMock.h"
#include "ledobj.h"

static uint16_t  Mock_NumLeds = 10;

// --- Mock to compile ledDriverDriver
CLedStripDriver::CLedStripDriver(uint16_t NumLeds)
{
    m_NumLeds     = NumLeds;
}

CLedStripDriver::~CLedStripDriver(void)
{
}

void CLedStripDriver::Initialize_Hardware(void)
{
    mock().actualCall("CLedStripDriver::Initialize_Hardware");
}

void CLedStripDriver::Update(void)
{
    mock().actualCall("CLedStripDriver::Update");
}

// -- Mock that abstracts ledDriverDriver and allows input control
CLedStripDriverMock::CLedStripDriverMock() : CLedStripDriver(Mock_NumLeds)
{
}

CLedStripDriverMock::~CLedStripDriverMock(void)
{
}

void CLedStripDriverMock::Initialize_Hardware(void)
{
    mock().actualCall("CLedStripDriver::Initialize_Hardware");
}

void CLedStripDriverMock::Update(void)
{
    mock().actualCall("CLedStripDriver::Update");
}
