#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledStripDriver.h"

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
}

