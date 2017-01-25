#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledBehaviorMock.h"
#include "ledObj.h"
#include "scene.h"
// ----------------------------------------------------------------------------
#define NUM_BEHAVIORS   3
#define NUM_LEDOBJS     3
static uint16_t NumLeds = 0;
CLedBehaviorMock* behavior[NUM_BEHAVIORS];

CLedObj* LedObjArray[NUM_LEDOBJS];
CScene*  Scene;

// ----------------------------------------------------------------------------
TEST_GROUP(SceneTests)
{
    void setup()
    {
        mock().disable();
        NumLeds = 5;

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            behavior[b] = new CLedBehaviorMock;
        }

        Scene      = new CScene(NumLeds);
    }

    void teardown()
    {
        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            delete behavior[b];
        }

        delete Scene;

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
    Scene->Play(LedObjArray[0]);
}

// ----------------------------------------------------------------------------
class CChildScene : public CScene
{
    public:
        CChildScene(uint16_t myNumLeds) : CScene(myNumLeds)
        {
        }

        void Force_StopCondition(bool forceTo)
        {
            Led_Behavior_t beh = (forceTo == true) ? BEHAVIOR_DONE : BEHAVIOR_ACTIVE;

            for (int b = 0; b < m_NumBehaviors; b++)
            {
                ((CLedBehaviorMock*)(m_Behaviors[b]))->Force_State(beh);
            }
        }

        virtual bool Is_StartTriggerMet(void)
        {
            return true;
        }
        virtual bool Is_StopTriggerMet(void)
        {
            return CScene::Is_StopTriggerMet();
        }
};

CChildScene* ChildScene;
// ----------------------------------------------------------------------------

TEST_GROUP(ChildSceneTests)
{
    void setup()
    {
        mock().disable();
        NumLeds = 5;

        ChildScene = new CChildScene(NumLeds);

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            behavior[b] = new CLedBehaviorMock;
            ChildScene->Add_Behavior(behavior[b]);
        }
    }

    void teardown()
    {
        mock().checkExpectations();
        mock().clear();

        delete ChildScene;

        for (int b = 0; b < NUM_BEHAVIORS; b++)
        {
            delete behavior[b];
        }
    }
}; // end - TEST_GROUP(ChildSceneTests)


TEST(ChildSceneTests, ChildObjStartTriggerIsSetByDefault)
{
    CHECK_EQUAL(true, ChildScene->Is_StartTriggerMet());
}

TEST(ChildSceneTests, ChildObjStopTriggerIsNotSetByDefault)
{
    CHECK_EQUAL(false, ChildScene->Is_StopTriggerMet());
}

TEST(ChildSceneTests, CanForceStopTrigger)
{
    ChildScene->Force_StopCondition(true);
    CHECK_EQUAL(true, ChildScene->Is_StopTriggerMet());

    ChildScene->Force_StopCondition(false);
    CHECK_EQUAL(false, ChildScene->Is_StopTriggerMet());
}

TEST(ChildSceneTests, StartResetsAllBehaviors)
{ // This assumes that the stop condition has been cleared
    mock().enable();
    for (int b = 0; b < NUM_BEHAVIORS; b++)
    {
        mock().expectOneCall("CLedBehaviorComp::Initialize").onObject(behavior[b]);
    }

    mock().ignoreOtherCalls();
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, RepeatedStartConditionDoesNotReinitialize)
{
    ChildScene->Play(LedObjArray[0]);
    mock().enable();

    mock().expectNCalls(0, "CLedBehaviorComp::Initialize");
    mock().ignoreOtherCalls();
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, StopTriggerOverridesStartTrigger)
{ // Failing will call mock function CLedBehaviorComp::Initialize
    mock().enable();
    ChildScene->Force_StopCondition(true);
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, StopTriggerOverridesStartTrigger2)
{ // Failing will call mock function CLedBehaviorComp::Initialize
    ChildScene->Play(LedObjArray[0]);
    ChildScene->Play(LedObjArray[0]);

    mock().enable();
    ChildScene->Force_StopCondition(true);
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, SceneReinitializesAfterStopTriggerClears)
{
    ChildScene->Play(LedObjArray[0]);

    mock().enable();
    ChildScene->Force_StopCondition(true);
    ChildScene->Play(LedObjArray[0]);

    ChildScene->Force_StopCondition(false);
    for (int b = 0; b < NUM_BEHAVIORS; b++)
    {
        mock().expectOneCall("CLedBehaviorComp::Initialize").onObject(behavior[b]);
    }
    mock().ignoreOtherCalls();
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, SceneCallsBehaviorWithLedObjArrayPointer)
{ // Only calls the first behavior
    ChildScene->Play(LedObjArray[0]); // Call first to reset scene

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).withParameter("LedObjArray", LedObjArray[0]);

    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, ScenePlaysNextBehaviorWhenCurrentOneFinished)
{
    ChildScene->Play(LedObjArray[0]); // Call first to reset scene

    behavior[0]->Force_State(BEHAVIOR_DONE);

    mock().enable();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[1]).ignoreOtherParameters();
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, SceneCallsconsecutiveBlendedBehaviors)
{
    ChildScene->Play(LedObjArray[0]); // Resets all behaviors

    mock().enable();

    behavior[1]->Force_Blended(true);
    behavior[2]->Force_Blended(true);
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).ignoreOtherParameters();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[1]).ignoreOtherParameters();
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[2]).ignoreOtherParameters();
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, SceneDoesnotBlendNonConsecutiveBlendedBehaviors)
{
    ChildScene->Play(LedObjArray[0]); // Resets all behaviors

    mock().enable();

    behavior[1]->Force_Blended(false);
    behavior[2]->Force_Blended(true);
    mock().expectOneCall("CLedBehaviorComp::Execute").onObject(behavior[0]).ignoreOtherParameters();
    ChildScene->Play(LedObjArray[0]);
}

TEST(ChildSceneTests, NoBehaviorsRunIfTheyAreAllFinished)
{ // Failing will call a behavior mock function
// This also tests that the scene does not reinitialize on a repeated start condition
    ChildScene->Play(LedObjArray[0]); // Call first to reset scene

    for (int b = 0; b < NUM_BEHAVIORS; b++)
    {
        behavior[b]->Force_State(BEHAVIOR_DONE);
    }

    mock().enable();
    ChildScene->Play(LedObjArray[0]);
}

