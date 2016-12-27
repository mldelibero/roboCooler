#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "scene.h"
#include "ledBehavior.h"
#include "ledObj.h"

const int numLeds = 3;
CLedObj* ledArray[numLeds];
CScene* Scene;

TEST_GROUP(SceneTests)
{
    void setup()
    {
        mock().disable();
        for(int led = 0; led < numLeds; led++)
        {
            ledArray[led] = new CLedObj;
        }
        Scene = new CScene;
    }
    void teardown()
    {
        for(int led = 0; led < numLeds; led++)
        {
            delete ledArray[led];
        }

        delete Scene;

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(SceneTests)

TEST(SceneTests, fail)
{
    CHECK(true);
}

