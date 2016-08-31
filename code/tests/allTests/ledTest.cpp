#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "leds.h"
#include "ledDriver.h"
#include "timer.h"
#include "timer_mock.h"

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
        Reset_timerMock();
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
    int32_t timer = 4;
    Set_TimerToAllocate(timer);

    mock().expectOneCall("init_ledDriver"        );
    mock().expectOneCall("AllocateTimer"         );
    mock().expectOneCall("Set_TimerValue"        )
        .withParameter("timer"     , timer)
        .withParameter("timerValue", LED_TIMER_RESET);

    init_leds();
} // end - TEST(PushButtonInitTests, TestInitCalls)

