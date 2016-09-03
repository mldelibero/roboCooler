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

