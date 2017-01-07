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
            m_StopTrigger = false;
        }

        virtual bool Is_StopTriggerMet(void)
        {
            return m_StopTrigger;
        }

        void Force_StopCondition(bool forceTo)
        {
            m_StopTrigger = forceTo;
        }

    private:
        virtual bool Is_StartTriggerMet(void)
        { // Should cause the class to always run
            return true;
        }

        bool m_StopTrigger;
}; // end - class CSceneChild : public CScene
// ----------------------------------------------------------------------------
const int numLeds = 3;
#define NUM_BEHAVIORS   3
CLedObj* ledObjArray[numLeds];
CScene* Scene;
CChildScene* ChildScene;
CLedBehaviorMock* behavior[NUM_BEHAVIORS];

TEST_GROUP(SceneTests)
{
    void setup()
    {
        mock().disable();

        for(int led = 0; led < numLeds; led++)
        {
            ledObjArray[led] = new CLedObj;
        }
        Scene      = new CScene;

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            behavior[b] = new CLedBehaviorMock;
        }
    }

    void teardown()
    {
        for(int led = 0; led < numLeds; led++)
        {
            delete ledObjArray[led];
        }

        delete Scene;

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            delete behavior[b];
        }

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
    Scene->Play(ledObjArray[0]);
}

TEST(SceneTests, SetsNumLedsToNominalWhenAddingBehavior)
{
    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",0).onObject(behavior[0]);
    mock().expectOneCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",0).onObject(behavior[1]);
    Scene->Add_Behavior(behavior[0]);
    Scene->Add_Behavior(behavior[1]);
}

TEST(SceneTests, SetsNumLedsToUpdatedWhenAddingBehavior)
{
    Scene->Set_NumLeds(50);
    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",50).onObject(behavior[0]);
    mock().expectOneCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",50).onObject(behavior[1]);
    Scene->Add_Behavior(behavior[0]);
    Scene->Add_Behavior(behavior[1]);
}

TEST(SceneTests, SetsAllBehaviorsWhenOwnsNumLedsUpdated)
{
    Scene->Add_Behavior(behavior[0]);
    Scene->Add_Behavior(behavior[1]);

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",51).onObject(behavior[0]);
    mock().expectOneCall("CLedBehaviorComp::Set_NumLeds").withParameter("numLeds",51).onObject(behavior[1]);

    Scene->Set_NumLeds(51);
}


TEST_GROUP(ChildSceneTests)
{
    void setup()
    {
        mock().disable();

        for(int led = 0; led < numLeds; led++)
        {
            ledObjArray[led] = new CLedObj;
        }

        behavior[0] = new CLedBehaviorMock;
        behavior[1] = new CLedBehaviorMock;
        behavior[2] = new CLedBehaviorMock;

        ChildScene = new CChildScene;

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            ChildScene->Add_Behavior(behavior[b]);
        }
    }

    void teardown()
    {
        for(int led = 0; led < numLeds; led++)
        {
            delete ledObjArray[led];
        }

        delete ChildScene;

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            delete behavior[b];
        }

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(ChildSceneTests)

TEST(ChildSceneTests, SceneCallsBehaviorWithLedObjArrayPointer)
{
    ChildScene->Play(ledObjArray[0]); // Call first to reset scene

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).withParameter("LedObjArray", ledObjArray[0]);

    ChildScene->Play(ledObjArray[0]);
}

TEST(ChildSceneTests, SceneOnlyCallsActiveBehavior)
{
    ChildScene->Play(ledObjArray[0]); // Call first to reset scene

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).ignoreOtherParameters();

    ChildScene->Play(ledObjArray[0]);
}

TEST(ChildSceneTests, ScenePlaysNextBehaviorWhenCurrentOneFinished)
{
    ChildScene->Play(ledObjArray[0]); // Call first to reset scene

    behavior[0]->Force_State(BEHAVIOR_DONE);

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[1]).ignoreOtherParameters();
    ChildScene->Play(ledObjArray[0]);
}

TEST(ChildSceneTests, StartResetsAllBehaviors)
{
    for (int b = 0; b < NUM_BEHAVIORS; b++)
    {
        behavior[b]->Force_State(BEHAVIOR_DONE);
    }

    mock().enable();
    for (int b = 0; b < NUM_BEHAVIORS; b++)
    {
        mock().expectOneCall("CLedBehaviorComp::Initialize").onObject(behavior[b]);
    }

    ChildScene->Play(ledObjArray[0]);
}

TEST(ChildSceneTests, NoBehaviorsRunIfTheyAreAllFinished)
{ // Failing will call a behavior mock function
// This also tests that the scene does not reinitialize on a repeated start condition
    ChildScene->Play(ledObjArray[0]); // Call first to reset scene

    for (int b = 0; b < NUM_BEHAVIORS; b++)
    {
        behavior[b]->Force_State(BEHAVIOR_DONE);
    }

    mock().enable();
    ChildScene->Play(ledObjArray[0]);
}

TEST(ChildSceneTests, MockObjStopStateFunWorks)
{ // Failing will call a behavior mock function
    ChildScene->Force_StopCondition(true);
    mock().enable();
    ChildScene->Play(ledObjArray[0]); // Should override start trigger
}

TEST(ChildSceneTests, SceneCallsconsecutiveBlendedBehaviors)
{
    ChildScene->Play(ledObjArray[0]); // Resets all behaviors

    mock().enable();

    behavior[1]->Force_Blended(true);
    behavior[2]->Force_Blended(true);
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).ignoreOtherParameters();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[1]).ignoreOtherParameters();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[2]).ignoreOtherParameters();
    ChildScene->Play(ledObjArray[0]);
}

TEST(ChildSceneTests, SceneDoesnotBlendNonConsecutiveBlendedBehaviors)
{
    ChildScene->Play(ledObjArray[0]); // Resets all behaviors

    mock().enable();

    behavior[1]->Force_Blended(false);
    behavior[2]->Force_Blended(true);
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).ignoreOtherParameters();
    ChildScene->Play(ledObjArray[0]);
}


/*
 * Functionality:
 * Should stay in finished state after all behaviors are completed
 * Should have a watchdog timeout in case a behavior never ends. -- Will need an override for other projects
 *
 */

