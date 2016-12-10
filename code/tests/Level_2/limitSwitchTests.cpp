#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "limitSwitch.h"
#include "limitSwitchDriverMock.h"


/**
 * * List of tests needed:
 *  * Integration test makes sure that correct input has been sampled.
 */

#define TEST_BUFFER_SIZE      10
#define TEST_BUFFER_HI_CUTOFF 7
#define TEST_BUFFER_LO_CUTOFF 3

CLimSwDriverMock* limSwDriver;
CLimSwComp*       limSw;

TEST_GROUP(LimitSwitchTests)
{
    void setup()
    {
        mock().enable();
        limSwDriver = new CLimSwDriverMock();
        limSw       = new CLimSwComp(limSwDriver, TEST_BUFFER_LO_CUTOFF, TEST_BUFFER_HI_CUTOFF, TEST_BUFFER_SIZE);
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

    for (int cnt = 1; cnt < TEST_BUFFER_HI_CUTOFF; cnt++)
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
    for(int cnt = TEST_BUFFER_SIZE; cnt >= TEST_BUFFER_LO_CUTOFF + 2; cnt--)
    { // Dip to just above the cutoff
        limSw->Run();
    }

    CHECK_EQUAL(true, limSw->At_Limit());
    limSw->Run();
    CHECK_EQUAL(false, limSw->At_Limit());
}

TEST(LimitSwitchTests, InitResetsObject)
{
    mock().disable();

    limSwDriver->Set_MockInput();
    for(int cnt = 1; cnt <= TEST_BUFFER_HI_CUTOFF; cnt++)
    {
        limSw->Run();
    }

    CHECK_EQUAL(true, limSw->At_Limit());

    limSw->Initialize();

    for(int cnt = 1; cnt <= TEST_BUFFER_LO_CUTOFF; cnt++)
    { // Puts the buffer inbetween cutoffs to test hysteresis reset
        limSw->Run();
    }

    CHECK_EQUAL(false, limSw->At_Limit());
}

