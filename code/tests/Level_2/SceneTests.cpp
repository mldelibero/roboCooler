#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "scene.h"
#include "ledBehavior.h"

TEST_GROUP(SceneTests)
{
    void setup()
    {
        mock().disable();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(SceneTests)

TEST(SceneTests, fail)
{
    CHECK(true);
}

