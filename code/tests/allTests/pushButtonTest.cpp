#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "pushButton.h"
#include "pushButtonDriver.h"

/*  * List of features needed:

    * Initialize gpio input
    * Create filter for debouncing
    * Create Integration test for input
    * Create user for system
*/

TEST_GROUP(PushButtonInitTests)
{
    void setup()
    {}
    void teardown()
    {
        init_PushButton();
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(PushButtonInitTests)

TEST(PushButtonInitTests, TestInitCalls)
{
    int callOrder = 1;

    mock().expectOneCall("RCC_AHB1PeriphClockCmd" ).withCallOrder(callOrder++);
    mock().expectOneCall("RCC_AHB1PeriphClockCmd" ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"		  ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"			  ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"			  ).withCallOrder(callOrder++);

    mock().expectOneCall("AllocateTimer"		  ).withCallOrder(callOrder++);
} // end - TEST(PushButtonInitTests, TestInitCalls)

TEST_GROUP(PushButtonFilterTests)
{
    void setup()
    {
	}
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
	}
}; // end - TEST_GROUP(PushButtonFilterTests)

TEST(PushButtonFilterTests, MotorCmdStopInitially)
{
	CHECK(Get_MotorCmd() == MOTOR_STOP);
}

TEST(PushButtonFilterTests, OnlySamplesButtonsOnTimeOut)
{
    mock().expectOneCall("IsTimerExpired"		  );
	Run_PushButtons();
}

