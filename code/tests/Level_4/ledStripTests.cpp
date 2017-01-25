#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStrip.h"
#include "ledStripDriverMock.h"
#include "sceneMock.h"

CLedStripDriverMock* LedStripDriver;
CSceneMock*          FirstScene;

CLedStripComp*       LedStrip;
CLedObj              LedObjArray[NUM_LEDS];
//-----------------------------------------------------------------------------
TEST_GROUP(LedStripTests)
{
    void setup()
    {
        mock().disable();
        LedStripDriver = new CLedStripDriverMock;
        FirstScene     = new CSceneMock;
        LedStrip       = new CLedStripComp((CLedStripDriver*)LedStripDriver, (CScene*)FirstScene, LedObjArray);
    }

    void teardown()
    {
        delete LedStrip;
        delete FirstScene;

        delete LedStripDriver;

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedStripTests)

// Testing SceneMock class
TEST(LedStripTests, SceneNotRunAfterConstructor)
{
    CHECK_EQUAL(false, FirstScene->HasBeenPlayed());
}

TEST(LedStripTests, SceneIndicatesRunAfterBeingRun)
{
    FirstScene->Play();
    CHECK_EQUAL(true, FirstScene->HasBeenPlayed());
}

TEST(LedStripTests, SceneIndicatesNotRunAfterSecondAsk)
{
    FirstScene->Play();
    FirstScene->HasBeenPlayed();

    CHECK_EQUAL(false, FirstScene->HasBeenPlayed());
}

//-----------------------------------------------------------------------------
TEST(LedStripTests, ConstructorSetsTimeoutToZero)
{
    mock().enable();
    mock().expectOneCall("CComponent::Constructor").withParameter("resetValue", 0);
    mock().ignoreOtherCalls();

    CLedStripComp LedStripComp((CLedStripDriver*)LedStripDriver, (CScene*)FirstScene, LedObjArray);
}

TEST(LedStripTests, RunExecutesFirstSceneAndLedStripDriver)
{
    mock().enable();

    mock().expectOneCall("CScene::Play"           ).withCallOrder(1).withParameter("LedObjArray", LedObjArray).onObject(FirstScene);
    mock().expectOneCall("CLedStripDriver::Update").withCallOrder(2);
    LedStrip->Run();
}

TEST(LedStripTests, ReturnsCorrectNumberOfScenesAfterConstructor)
{
    CHECK_EQUAL(1, LedStrip->Get_NumberOfScenes());
}

TEST(LedStripTests, CanAddScene)
{
    CSceneMock SecondScene;

    LedStrip->Add_Scene(&SecondScene);
    CHECK_EQUAL(2, LedStrip->Get_NumberOfScenes());
}

TEST(LedStripTests, MultipleTestsRunIfAdded)
{
    CSceneMock SecondScene;

    mock().enable();
    mock().expectOneCall("CScene::Play").onObject(FirstScene).ignoreOtherParameters();
    mock().expectOneCall("CScene::Play").onObject(&SecondScene).ignoreOtherParameters();
    mock().ignoreOtherCalls();

    LedStrip->Add_Scene(&SecondScene);
    LedStrip->Run();
}

TEST(LedStripTests, BasicOverRunProtection)
{
    CSceneMock AddtionalScene;
    for (int scene = 1; scene <= 10; scene++)
    {
        LedStrip->Add_Scene(&AddtionalScene);
    }

    CHECK_EQUAL(10, LedStrip->Get_NumberOfScenes());
}

