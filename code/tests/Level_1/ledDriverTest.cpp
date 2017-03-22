#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledDriver.h"

TEST_GROUP(LedDriverTests)
{
    void setup()
    {
        init_ledDriver();
        mock().disable();
    }
    void teardown()
    {
    }
};

TEST(LedDriverTests, CanSetAndClearAllLEDs)
{
    SetLeds(0xFF);
    CHECK_EQUAL(Get_LedStates(), 0XFF);

    SetLeds(0);
    CHECK_EQUAL(Get_LedStates(), 0);
}

TEST(LedDriverTests, CanSetLedsIndividually)
{
    for (int leds = 1; leds < 0xFF;)
    {
        SetLeds(uint8_t(leds));
        CHECK_EQUAL(leds, Get_LedStates());
        leds = (leds << 1) + 1;
    }
}

TEST(LedDriverTests, CanClearLedsIndividually)
{
    for (int leds = 0XFF; leds > 0; leds = leds >> 1)
    {
        SetLeds(uint8_t(leds));
        CHECK_EQUAL(leds, Get_LedStates());
    }
}

