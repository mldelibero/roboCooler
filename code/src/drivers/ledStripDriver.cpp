#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledStripDriver.h"

CLedStripDriver::CLedStripDriver(uint16_t NumLeds)
{
    m_NumLeds     = NumLeds;
}

CLedStripDriver::~CLedStripDriver(void)
{
}

void CLedStripDriver::Initialize_Hardware(void)
{
}

