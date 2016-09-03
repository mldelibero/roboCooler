#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "leds.h"
#include "timer.h"

/*  * List of features needed:
 *  *init calls init_leds
 *  *Does timer driver run out of timers while init is executing?
 *  *LEDs off on startup
 */

static int callOrder = -1;

TEST_GROUP(LedTests)
{
    void setup()
    {
        callOrder = 1;
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedTests)

TEST(LedTests, TestInitCalls)
{
    CLedComp leds;
    mock().expectOneCall("init_ledDriver");
    leds.Initialize();
}

TEST(LedTests, CanSaveLedStates)
{
    CLedComp leds;
    uint8_t ledStates = 0xAA;

    leds.WriteAllLedStates(ledStates);
    CHECK_EQUAL(ledStates, leds.Get_LedStates());
}

TEST(LedTests, RunUpdatesLedStates)
{
    CLedComp leds;
    uint8_t ledStates = 0xAA;
    leds.WriteAllLedStates(ledStates);
    mock().expectOneCall("SetLeds").withParameter("ledValues", ledStates);
    leds.Run();
}

