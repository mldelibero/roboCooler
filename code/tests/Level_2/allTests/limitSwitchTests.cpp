#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "limitSwitch.h"
#include "timer.h"


/**
 * * List of tests needed:
 *  * Integration test makes sure that correct input has been sampled.
 *  * Obj filters input on run
 *  * obj returns filtered output when querried
 *  * init resets filter
 */

CLimSwComp* limitSwitch;

uint8_t SampleLimitSwitchInput(void);
uint8_t SampleLimitSwitchInput(void)
{
    mock().actualCall("SampleLimitSwitchInput");
    return 0;
}

TEST_GROUP(LimitSwitchTests)
{
    void setup()
    {
        mock().disable();
        Init_Timers();
        mock().enable();
        limitSwitch = new CLimSwComp(&SampleLimitSwitchInput);
    }
    void teardown()
    {
        delete limitSwitch;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LimitSwitchTests)

TEST(LimitSwitchTests, SamplesInputOnRun)
{
    mock().expectOneCall("SampleLimitSwitchInput");

    Set_TimerValue(limitSwitch->Get_TimerIndex(), 0);
    limitSwitch->Run();
}

TEST(LimitSwitchTests, FiltersInputOnRun)
{
    mock().expectOneCall("SampleLimitSwitchInput");

    Set_TimerValue(limitSwitch->Get_TimerIndex(), 0);
    limitSwitch->Run();
}

