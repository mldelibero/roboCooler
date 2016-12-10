#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "init.h"

#include "limitSwitchDriver.h"

int32_t timer = -1;

extern CLimSwDriver* Opened_LimSwDriver;
extern CLimSwDriver* Closed_LimSwDriver;

TEST_GROUP(InitTests)
{
    void setup()
    {
        mock().enable();
    }
    void teardown()
    {
        delete Opened_LimSwDriver; // Never will get deleted for good in program
        delete Closed_LimSwDriver; // Never will get deleted for good in program

        mock().checkExpectations();
        mock().clear();
    }
};

TEST(InitTests, ModulesInitialized)
{
    mock().enable();

    mock().expectOneCall("Init_Timers");
    mock().expectOneCall("CLedComp::Initialize");
    mock().expectOneCall("CLidMotorComp::Initialize");
    mock().expectNCalls(2, "CLimSwDriver::Initialize_Hardware");
    mock().expectNCalls(2, "CLimSwComp::Initialize");

    init();
}

