#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//#include "lidMotorMock.h"
#include "ledStrip.h"

/* List of driver features needed:

 * List of features needed:
 *
 * Nice to have features:
 *
 */

//CLidMotorMock* lidMotorPtr;
CLedStripComp* ledStrip;

/**
 * @note We are assuming that the timer has expired for all tests
 */
TEST_GROUP(LedStripTests)
{
    void setup()
    {
        //lidMotorPtr = new CLidMotorMock();
        ledStrip    = new CLedStripComp();
        mock().enable();
    }
    void teardown()
    {
//        delete lidMotorPtr;
        delete ledStrip;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedStripTests)

TEST(LedStripTests, fail)
{
    CHECK(true);
}

