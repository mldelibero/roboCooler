#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "limitSwitch.h"
#include "timer.h"


/**
 * * List of tests needed:
 *  * Integration test makes sure that correct input has been sampled.
 *  * Obj samples input on run
 *  * Obj filters input on run
 *  * obj returns filtered output when querried
 *  * init resets filter
 */

CLimSwComp* limitSwitch;

TEST_GROUP(LimitSwitchTests)
{
    void setup()
    {
        mock().disable();
        Init_Timers();
//        mock().enable();
        limitSwitch = new CLimSwComp;
    }
    void teardown()
    {
        delete limitSwitch;
 //       mock().checkExpectations();
  //      mock().clear();
    }
}; // end - TEST_GROUP(LimitSwitchTests)

TEST(LimitSwitchTests, SamplesInputOnRun)
{
//    mock().expectOneCall("sampleInput");

    Set_TimerValue(limitSwitch->Get_TimerIndex(), 0);
    limitSwitch->Run();
}

