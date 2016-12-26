#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStripMock.h"
#include "ledStripDriverMock.h"

// --- Mock to compile ledDriverDriver
CLedStripDriver::CLedStripDriver()
{
}

CLedStripDriver::~CLedStripDriver(void)
{
}

void CLedStripDriver::Initialize_Hardware(void)
{
    mock().actualCall("CLedStripDriver::Initialize_Hardware");
}

// -- Mock that abstracts ledDriverDriver and allows input control
CLedStripDriverMock::CLedStripDriverMock() : CLedStripDriver()
{
}

CLedStripDriverMock::~CLedStripDriverMock(void)
{
}

void CLedStripDriverMock::Initialize_Hardware(void)
{
    mock().actualCall("CLedStripDriver::Initialize_Hardware");
}

