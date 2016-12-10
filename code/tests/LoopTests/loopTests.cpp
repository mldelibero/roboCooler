#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "loop.h"

TEST_GROUP(LoopTests)
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
}; // end -- TEST_GROUP(LoopTests)

TEST(LoopTests, ModulesInitialized)
{
    loop();
}

