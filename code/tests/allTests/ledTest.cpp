#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "leds.h"
#include "ledDriver.h"
#include "timer.h"

/*  * List of features needed:
 *  *Test that correct timer is set at init
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
        init_leds();
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedTests)

TEST(LedTests, TestInitCalls)
{
    mock().expectOneCall("AllocateTimer"          );
    mock().expectOneCall("Set_TimerValue"        )
        .withParameter("timerValue", LED_TIMER_RESET);
} // end - TEST(PushButtonInitTests, TestInitCalls)

