#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "ledStrip.h"
#include "ledStripDriverMock.h"
#include "capTouchMock.h"
#include "limitSwitchMock.h"

/* List of driver features needed:

 * List of features needed:
 *
 * Nice to have features:
 *
 */

CLedStripDriverMock* LedStripDriver;
CCapTouchMock*       CapTouch;
CLimSwMock*          Closed_LimSw;
CLimSwMock*          Opened_LimSw;
CLedStripComp*       LedStrip;

/**
 * @note We are assuming that the timer has expired for all tests
 */
TEST_GROUP(LedStripTests)
{
    void setup()
    {
        LedStripDriver = new CLedStripDriverMock;
        CapTouch       = new CCapTouchMock;
        Closed_LimSw   = new CLimSwMock;
        Opened_LimSw   = new CLimSwMock;
        LedStrip       = new CLedStripComp((CLedStripDriver*)LedStripDriver, (CCapTouchComp*)CapTouch, (CLimSwComp*)Closed_LimSw, (CLimSwComp*)Opened_LimSw);

        mock().enable();
    }
    void teardown()
    {
        delete LedStrip;

        delete LedStripDriver;
        delete CapTouch;
        delete Closed_LimSw;
        delete Opened_LimSw;

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedStripTests)

TEST(LedStripTests, fail)
{
    CHECK(true);
}

