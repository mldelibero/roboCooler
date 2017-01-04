#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "scene.h"
#include "ledBehavior.h"
#include "ledBehaviorMock.h"
#include "ledObj.h"

// Support Classes ------------------------------------------------------------

class CChildScene : public CScene
{
    public:
        CChildScene()
        {
        }

    private:
        virtual bool Is_StartTriggerMet(void)
        { // Should cause the class to always run
            return true;
        }
}; // end - class CSceneChild : public CScene
// ----------------------------------------------------------------------------
const int numLeds = 3;
CLedObj* ledArray[numLeds];
CScene* Scene;
CChildScene* ChildScene;
CLedBehaviorMock* behavior[2];

TEST_GROUP(SceneTests)
{
    void setup()
    {
        mock().disable();

        for(int led = 0; led < numLeds; led++)
        {
            ledArray[led] = new CLedObj;
        }
        Scene      = new CScene;
        behavior[0] = new CLedBehaviorMock;
        behavior[1] = new CLedBehaviorMock;
    }

    void teardown()
    {
        for(int led = 0; led < numLeds; led++)
        {
            delete ledArray[led];
        }

        delete Scene;
        delete behavior[0];
        delete behavior[1];

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(SceneTests)

TEST(SceneTests, CanAddBehavior)
{
    CHECK_EQUAL(true, Scene->Add_Behavior(behavior[0]));
}

TEST(SceneTests, SceneLimitsNumberOfBehaviorsThatCanBeAdded)
{
    for (int beh = 1; beh < MAX_BEHAVIORS; beh++)
    {
        Scene->Add_Behavior(behavior[0]);
    }
    CHECK_EQUAL(true , Scene->Add_Behavior(behavior[0]));
    CHECK_EQUAL(false, Scene->Add_Behavior(behavior[0]));
}

TEST(SceneTests, BaseClassDoesNotCallBehaviors)
{ // This will call CLedBehaviorComp::Execute when failing
    Scene->Add_Behavior(behavior[0]);

    mock().enable();
    Scene->Play(ledArray[0], numLeds);
}


TEST_GROUP(ChildSceneTests)
{
    void setup()
    {
        mock().disable();

        for(int led = 0; led < numLeds; led++)
        {
            ledArray[led] = new CLedObj;
        }

        behavior[0] = new CLedBehaviorMock;
        behavior[1] = new CLedBehaviorMock;

        ChildScene = new CChildScene;
        ChildScene->Add_Behavior(behavior[0]);
        ChildScene->Add_Behavior(behavior[1]);
    }

    void teardown()
    {
        for(int led = 0; led < numLeds; led++)
        {
            delete ledArray[led];
        }

        delete ChildScene;
        delete behavior[0];
        delete behavior[1];

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(ChildSceneTests)

TEST(ChildSceneTests, SceneOnlyCallsActiveBehavior)
{
    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]);

    ChildScene->Play(ledArray[0], numLeds);
}

TEST(ChildSceneTests, ScenePlaysNextBehaviorWhenCurrentOneFinished)
{
    behavior[0]->Force_State(BEHAVIOR_DONE);

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[1]);
    ChildScene->Play(ledArray[0], numLeds);
}

TEST(ChildSceneTests, NoBehaviorsRunIfTheyAreAllFinished)
{
    behavior[0]->Force_State(BEHAVIOR_DONE);
    behavior[1]->Force_State(BEHAVIOR_DONE);

    mock().enable();
    ChildScene->Play(ledArray[0], numLeds);
}

/*
 * Functionality:
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

