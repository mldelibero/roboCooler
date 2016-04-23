#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

//#include "pushButton.h"
#include "pushButtonDriver.h"

/*  * List of features needed:

    * Initialize gpio input
    * Create filter for debouncing
    * Create Integration test for input
    * Create user for system
*/

TEST_GROUP(PushButtonDriverTests)
{
    void setup()
    {}
    void teardown()
    {
        init_PushButtonDriver();
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(PushButtonDriverTests)

TEST(PushButtonDriverTests, TestInitCalls)
{
    int callOrder = 1;

    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("RCC_AHB1PeriphClockCmd").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init").withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init").withCallOrder(callOrder++);

} // end - TEST(PushButtonTests, TestInitCalls)

TEST_GROUP(PushButtonFilterTests)
{
    void setup()
    {}
    void teardown()
    {}
}; // end - TEST_GROUP(PushButtonFilterTests)

TEST(PushButtonFilterTests, fail)
{
    CHECK(false);
}

