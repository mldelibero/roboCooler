#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"
#include "lidMotor.h"
#include "timer.h"
#include "limitSwitch.h"
#include "limitSwitchDriver.h"
#include "limitSwitchMock.h"

/* List of driver features needed:
 *  *timer off at startup
 *  *Motor stops after a timeout

 * List of features needed:
 *  *Initialize module
 *  *Motor stops if either limit switch is tripped
 *  *Motor opens lid if down LS is active and cap sense is tripped
 *  *Motor opens and then closes the whole way at initialization
 *  *Error if both limit switches are set at the same time
 *  *Add test for mock limit switch input value is initialized in that test group

 * Nice to have features:
 *  *Motor can open lid a couple inches and then close it after a certain amount of time
 *
 */

CLimSwMock Opened_Limit, Closed_Limit;
CLidMotorComp* lidMotorPtr;

TEST_GROUP(LidMotorTests)
{
    void setup()
    {
        lidMotorPtr = new CLidMotorComp(&Opened_Limit, &Closed_Limit);

        mock().disable();
        Init_Timers();
        mock().enable();
    }
    void teardown()
    {
        delete lidMotorPtr;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LidMotorTests)

TEST(LidMotorTests, TestSetupSetsLimitSwitchPointers)
{
    POINTERS_EQUAL(&Opened_Limit, lidMotorPtr->Get_OpenLimSwPtr());
    POINTERS_EQUAL(&Closed_Limit, lidMotorPtr->Get_CloseLimSwPtr());
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

    Set_TimerValue(lidMotorPtr->Get_TimerIndex(), 0);
    lidMotorPtr->Run();
}

TEST(LidMotorTests, LimitSwitchesControlLidState)
{
    mock().disable();

    Opened_Limit.ForceAtLimit();
    Closed_Limit.ForceNotAtLimit();

    Set_TimerValue(lidMotorPtr->Get_TimerIndex(), 0);
    lidMotorPtr->Run();

    CHECK_EQUAL(LID_ATFULLOPEN, lidMotorPtr->Get_State());

    Opened_Limit.ForceNotAtLimit();
    Closed_Limit.ForceAtLimit();

    Set_TimerValue(lidMotorPtr->Get_TimerIndex(), 0);
    lidMotorPtr->Run();

    CHECK_EQUAL(LID_ATFULLCLOSE, lidMotorPtr->Get_State());
}

