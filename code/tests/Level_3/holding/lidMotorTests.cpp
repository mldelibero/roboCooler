#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"
#include "lidMotor.h"
#include "capTouch.h"
#include "capTouchMock.h"
#include "limitSwitchMock.h"
#include "limitSwitchDriverMock.h"

/* List of driver features needed:
 *  *timer off at startup
 *  *Motor stops after a timeout

 * List of features needed:
 *  *Initialize module
 *  *Motor responds to push buttons
 *  *Motor opens and then closes the whole way at initialization
 *  *Error if both limit switches are set at the same time
 *  *Add test for mock limit switch input value is initialized in that test group

 * Nice to have features:
 *  *Motor can open lid a couple inches and then close it after a certain amount of time
 *
 */

CLimSwDriverMock* limSwDriver;

CLimSwMock     Opened_Limit;
CLimSwMock     Closed_Limit;
CCapTouchMock  capTouch;
CLidMotorComp* lidMotorPtr;

/**
 * @note We are assuming that the timer has expired for all tests
 */
TEST_GROUP(LidMotorTests)
{
    void setup()
    {
        limSwDriver = new CLimSwDriverMock();
        lidMotorPtr = new CLidMotorComp(&capTouch, &Closed_Limit, &Opened_Limit);
        mock().enable();
    }
    void teardown()
    {
        delete lidMotorPtr;
        delete limSwDriver;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LidMotorTests)

TEST(LidMotorTests, TestSetupSetsObjectPointers)
{
    POINTERS_EQUAL(&capTouch     , lidMotorPtr->Get_CapSensePtr());
    POINTERS_EQUAL(&Closed_Limit , lidMotorPtr->Get_CloseLimSwPtr());
    POINTERS_EQUAL(&Opened_Limit , lidMotorPtr->Get_OpenLimSwPtr());
}

TEST(LidMotorTests, TestInitCalls)
{
    mock().expectOneCall("init_lidMotorDriver");
    lidMotorPtr->Initialize();
}
TEST(LidMotorTests, InitializesModule) {}

TEST(LidMotorTests, RunPollsLimitSwitches)
{
    mock().expectOneCall("CLimSwComp::At_Limit");
    mock().expectOneCall("CLimSwComp::At_Limit");
    mock().expectOneCall("motorStop");
    mock().ignoreOtherCalls();

    lidMotorPtr->Run();
}

TEST(LidMotorTests, LimitSwitchesControlLidState)
{
    mock().disable();

    Opened_Limit.ForceAtLimit();
    Closed_Limit.ForceNotAtLimit();

    lidMotorPtr->Run();

    CHECK_EQUAL(LID_ATFULLOPEN, lidMotorPtr->Get_State());

    Opened_Limit.ForceNotAtLimit();
    Closed_Limit.ForceAtLimit();

    lidMotorPtr->Run();

    CHECK_EQUAL(LID_ATFULLCLOSE, lidMotorPtr->Get_State());
}

TEST(LidMotorTests, MotorStopIssuedWhenAtLimitSwitch)
{
    Opened_Limit.ForceAtLimit();
    Closed_Limit.ForceNotAtLimit();

    mock().expectOneCall("motorStop");
    mock().ignoreOtherCalls();

    lidMotorPtr->Run();

    Opened_Limit.ForceNotAtLimit();
    Closed_Limit.ForceAtLimit();

    mock().expectOneCall("motorStop");

    lidMotorPtr->Run();
}

TEST(LidMotorTests, MotorStopNotIssuedWhenNotAtLimitSwitch)
{
    Opened_Limit.ForceNotAtLimit();
    Closed_Limit.ForceNotAtLimit();

    mock().expectNCalls(4, "CLimSwComp::At_Limit");
    mock().ignoreOtherCalls();

    lidMotorPtr->Run();

    lidMotorPtr->Run();
}

TEST(LidMotorTests, RunPollsCapSense)
{
    mock().expectNCalls(2,"CLimSwComp::At_Limit");
    mock().expectNCalls(1,"motorStop");
    mock().expectNCalls(1,"lidMotor_Open");

    //The call we actually care about
    mock().expectNCalls(1,"CCapTouchComp::Is_TouchDetected");

    lidMotorPtr->Run();
}

TEST(LidMotorTests, LidOpenIssuedOnCapTouchAndLidClosed)
{
    capTouch.ForceTouchDetected();
    Closed_Limit.ForceAtLimit();
    mock().expectOneCall("lidMotor_Open");
    mock().ignoreOtherCalls();

    lidMotorPtr->Run();
}

TEST(LidMotorTests, LidCloseIssuedOnCapTouchAndLidOpened)
{
    capTouch.ForceTouchDetected();
    Opened_Limit.ForceAtLimit();
    Closed_Limit.ForceNotAtLimit();
    mock().expectOneCall("lidMotor_Close");
    mock().ignoreOtherCalls();

    lidMotorPtr->Run();
}

TEST(LidMotorTests, NoMotorCommandsIssuedWhenNoTouchDetected)
{
    capTouch.ForceTouchNotDetected();

    mock().expectNCalls(0, "lidMotor_Close");
    mock().expectNCalls(0, "lidMotor_Open");
    mock().ignoreOtherCalls();

    Opened_Limit.ForceAtLimit();
    Closed_Limit.ForceNotAtLimit();

    lidMotorPtr->Run();

    Opened_Limit.ForceNotAtLimit();
    Closed_Limit.ForceAtLimit();

    lidMotorPtr->Run();
}

