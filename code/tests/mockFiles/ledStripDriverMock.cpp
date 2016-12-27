#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStripMock.h"
#include "ledStripDriverMock.h"
#include "ledobj.h"

CLedObj*  Mock_LedObjArray;
static uint16_t  Mock_NumLeds;

// --- Mock to compile ledDriverDriver
CLedStripDriver::CLedStripDriver(CLedObj* LedObjArray, uint16_t NumLeds)
{
    m_LedObjArray = LedObjArray;
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
CLedStripDriverMock::CLedStripDriverMock() : CLedStripDriver(Mock_LedObjArray, Mock_NumLeds)
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
