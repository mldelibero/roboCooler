#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "init.h"

int32_t timer = -1;

TEST_GROUP(InitTests)
{
    void setup()
    {
        mock().enable();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(InitTests, ModulesInitialized)
{
    mock().expectOneCall("CLedComp::Initialize");
    mock().expectOneCall("CLidMotorComp::Initialize");
    mock().expectOneCall("Init_Timers");
    init();
}

