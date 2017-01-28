#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledStripDriver.h"

CLedStripDriver* LedStripDriver;
static uint16_t NumLeds = 0;

TEST_GROUP(LedStripDriverTests)
{
    void setup()
    {
        mock().disable();
        NumLeds = 5;
        LedStripDriver = new CLedStripDriver(NumLeds);
    }
    void teardown()
    {
        delete LedStripDriver;
    }
};

TEST(LedStripDriverTests, FirstTest)
{
}

