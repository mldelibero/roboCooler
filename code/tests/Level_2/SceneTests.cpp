#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "scene.h"
#include "ledBehavior.h"
#include "ledBehaviorMock.h"
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

/*
 * Functionality:
 * Can Add behaviors
 * Can't add too many behaviors
 * Starting should reset all behavior states
 * Should not reinitalize on a repeated start condition
 *
 * Children should set up a boolean return fun that indicates the start/hard stop criteria
 * Hard stop should move system to not running
 * Should only execute behaviors when running
 *
 * Should only execute the consecutive behaviors when current behavior is completed or if next behavior is blended
 * Should stay in finished state after all behaviors are completed
 * Should have a watchdog timeout in case a behavior never ends. -- Will need an override for other projects
 *
 */

TEST(SceneTests, NotRunningAfterConstructor)
{
    CHECK_EQUAL(false, Scene->Is_Running());
}

TEST(SceneTests, DefaultStartTriggerImplementationReturnsFalse)
{
    CHECK_EQUAL(false, Scene->Is_StartTriggerMet());
}

TEST(SceneTests, CanAddBehavior)
{
    CLedBehaviorComp behavior;
    CHECK_EQUAL(true, Scene->Add_Behavior(&behavior));
}

TEST(SceneTests, SceneLimitsNumberOfBehaviorsThatCanBeAdded)
{
    CLedBehaviorComp behavior;

    for (int beh = 1; beh < MAX_BEHAVIORS; beh++)
    {
        Scene->Add_Behavior(&behavior);
    }
    CHECK_EQUAL(true , Scene->Add_Behavior(&behavior));
    CHECK_EQUAL(false, Scene->Add_Behavior(&behavior));
}

TEST(SceneTests, SceneOnlyCallsActiveBehavior)
{
    CLedBehaviorMock b[2];

    Scene->Add_Behavior(&b[0]);
    Scene->Add_Behavior(&b[1]);

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(&b[0]);

    Scene->Play(ledArray[0], numLeds);
}

TEST(SceneTests, ScenePlaysNextBehaviorWhenCurrentOneFinished)
{
    CLedBehaviorMock b[2];

    Scene->Add_Behavior(&b[0]);
    Scene->Add_Behavior(&b[1]);

    b[0].Force_State(BEHAVIOR_DONE);

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(&b[1]);
    Scene->Play(ledArray[0], numLeds);
}

class CSceneChild : public CScene
{
    public:
        CSceneChild();
}; // end - class CSceneChild : public CScene

CSceneChild::CSceneChild(void)
{
}

