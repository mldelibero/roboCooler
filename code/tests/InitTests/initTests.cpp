#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "init.h"

#include "limitSwitchDriver.h"
#include "capTouchDriver.h"

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
        // Never will get deleted for good in program
        delete Opened_LimSwDriver;
        delete Closed_LimSwDriver;

        mock().checkExpectations();
        mock().clear();
    }
};

TEST(InitTests, ModulesInitialized)
{
    mock().enable();

    mock().expectNCalls(1, "Init_Timers");
    mock().expectNCalls(1, "CLedComp::Initialize");
    mock().expectNCalls(1, "CCapTouchDriver::Initialize_Hardware");
    mock().expectNCalls(1, "CCapTouchComp::Initialize");
    mock().expectNCalls(1, "CLidMotorComp::Initialize");
    mock().expectNCalls(2, "CLimSwDriver::Initialize_Hardware");
    mock().expectNCalls(2, "CLimSwComp::Initialize");
    mock().expectNCalls(1, "CLedStripComp::Initialize");

    init();
}

