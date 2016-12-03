#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "limitSwitch.h"
#include "limitSwitchDriverMock.h"


/**
 * * List of tests needed:
 *  * Integration test makes sure that correct input has been sampled.
 *  * Obj filters input on run
 *  * obj returns filtered output when querried
 *  * init resets filter
 *
 *  * Add hysteresis on the filter
 */

#define TEST_BUFFER_SIZE        5
#define TEST_BUFFER_CUTOFF      3

CLimSwDriverMock* limSwDriver;
CLimSwComp*       limSw;

TEST_GROUP(LimitSwitchTests)
{
    void setup()
    {
        mock().disable();
        mock().enable();
        limSwDriver = new CLimSwDriverMock();
        limSw       = new CLimSwComp(limSwDriver, TEST_BUFFER_SIZE, TEST_BUFFER_CUTOFF);
    }
    void teardown()
    {
        delete limSw;
        delete limSwDriver;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LimitSwitchTests)

TEST(LimitSwitchTests, SamplesInputOnRun)
{
    mock().expectOneCall("CLimSwDriver::SampleInput");
    limSw->Run();
}

TEST(LimitSwitchTests, FiltersInputOnRun)
{
    mock().disable();

    CHECK_EQUAL(false, limSw->At_Limit());
    limSwDriver->Set_MockInput();

    for (int cnt = 1; cnt < TEST_BUFFER_CUTOFF; cnt++)
    { // Run 1 less than cutoff
        limSw->Run();
    }

    CHECK_EQUAL(false, limSw->At_Limit());
    limSw->Run(); // 7th
    CHECK_EQUAL(true, limSw->At_Limit());
}

TEST(LimitSwitchTests, BufferSizeIsRespected)
{
    mock().disable();
    limSwDriver->Set_MockInput();
    for(int cnt = 1; cnt <= TEST_BUFFER_SIZE + 2; cnt++)
    { // Overrun buffer size
        limSw->Run();
    }

    limSwDriver->Clear_MockInput();
    //for(int cnt = 10; cnt > 7; cnt--)
    for(int cnt = TEST_BUFFER_SIZE; cnt > TEST_BUFFER_CUTOFF; cnt--)
    { // Dip to just above the cutoff
        limSw->Run();
    }

    CHECK_EQUAL(true, limSw->At_Limit());
    limSw->Run();
    CHECK_EQUAL(false, limSw->At_Limit());
}

