#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "leds.h"
#include "ledDriver.h"
#include "timer.h"

/*  * List of features needed:
 *  *LEDs off on startup
 *  *LED timer is allocated after init
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
        init_leds();
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedTests)

TEST(LedTests, TestInitCalls)
{
    mock().expectOneCall("AllocateTimer"          );
} // end - TEST(PushButtonInitTests, TestInitCalls)

