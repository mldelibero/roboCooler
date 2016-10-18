#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "limitSwitch.h"


/**
 * * List of tests needed:
 *  * Integration test makes sure that correct input has been sampled.
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
        mock().enable();
        limitSwitch = new CLimSwComp();
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
//    mock().expectOneCall("GPIO_ReadInputDataBit");
//    limitSwitch->Run();
}

TEST(LimitSwitchTests, FiltersInputOnRun)
{
}

