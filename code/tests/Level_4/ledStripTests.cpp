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

/**
 * @note We are assuming that the timer has expired for all tests
 */
TEST_GROUP(LedStripTests)
{
    void setup()
    {
        LedStripDriver = new CLedStripDriverMock;
        FirstScene     = new CSceneMock;
        LedStrip       = new CLedStripComp((CLedStripDriver*)LedStripDriver, (CSceneComp*)FirstScene);

        mock().enable();
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

TEST(LedStripTests, fail)
{
    CHECK(true);
}

