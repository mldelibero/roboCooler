#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStrip.h"
#include "ledStripDriverMock.h"
#include "sceneMock.h"

/* List of driver features needed:

 * List of features needed:
 *
 * Nice to have features:
 *
 */

CLedStripDriverMock* LedStripDriver;
CSceneMock*          FirstScene;

CLedStripComp*       LedStrip;

//-----------------------------------------------------------------------------
TEST_GROUP(SceneMockTests)
{
    void setup()
    {
        FirstScene     = new CSceneMock;
        mock().disable();
    }
    void teardown()
    {
        delete FirstScene;
    }
}; // end - TEST_GROUP(SceneMockTests)

TEST(SceneMockTests, SceneNotRunAfterConstructor)
{
    CHECK_EQUAL(false, FirstScene->HasBeenRun());
}

TEST(SceneMockTests, SceneIndicatesRunAfterBeingRun)
{
    FirstScene->Run();
    CHECK_EQUAL(true, FirstScene->HasBeenRun());
}

TEST(SceneMockTests, SceneIndicatesNotRunAfterSecondAsk)
{
    FirstScene->Run();
    FirstScene->HasBeenRun();

    CHECK_EQUAL(false, FirstScene->HasBeenRun());
}


//-----------------------------------------------------------------------------
TEST_GROUP(LedStripTests)
{
    void setup()
    {
        LedStripDriver = new CLedStripDriverMock;
        FirstScene     = new CSceneMock;
        LedStrip       = new CLedStripComp((CLedStripDriver*)LedStripDriver, (CSceneComp*)FirstScene);

        mock().disable();
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

TEST(LedStripTests, RunExecutesFirstSceneAndLedStripDriver)
{
    mock().enable();

    mock().expectOneCall("CSceneComp::Execute"    ).withCallOrder(1);
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
    LedStrip->Add_Scene(&SecondScene);
    LedStrip->Run();

    CHECK_EQUAL(true, FirstScene->HasBeenRun());
    CHECK_EQUAL(true, SecondScene.HasBeenRun());
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

