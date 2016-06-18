#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "CppUTestExt/MockSupport_c.h"

#include "pushButton.h"
#include "pushButtonDriver.h"
#include "timer.h"

/*  * List of features needed:

 * Initialize gpio input
 * Create filter for debouncing
 * Create Integration test for input
 * Create user for system
 */

int callOrder = -1;

TEST_GROUP(PushButtonInitTests)
{
    void setup()
    {
        callOrder = 1;
    }
    void teardown()
    {
        init_PushButton();
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(PushButtonInitTests)

TEST(PushButtonInitTests, TestInitCalls)
{
    mock().expectOneCall("RCC_AHB1PeriphClockCmd" ).withCallOrder(callOrder++);
    mock().expectOneCall("RCC_AHB1PeriphClockCmd" ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_StructInit"        ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"              ).withCallOrder(callOrder++);
    mock().expectOneCall("GPIO_Init"              ).withCallOrder(callOrder++);

    mock().expectOneCall("AllocateTimer"          ).withCallOrder(callOrder++);
} // end - TEST(PushButtonInitTests, TestInitCalls)

TEST_GROUP(PushButtonFilterTests)
{
    void setup()
    {
        callOrder = 1;
        mock().clear();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(PushButtonFilterTests)

TEST(PushButtonFilterTests, CanSetMockIOInput)
{
    uint8_t pinValue = 3;

    mock().expectOneCall("GPIO_ReadInputDataBit"  ).withCallOrder(callOrder++).withParameter("GPIOx"   , PBUP_GPIOx).withParameter("GPIO_Pin", PBUP_GPIO_PIN_X);
    mock().expectOneCall("GPIO_ReadInputDataBit"  ).withCallOrder(callOrder++).withParameter("GPIOx"   , PBUP_GPIOx).withParameter("GPIO_Pin", PBUP_GPIO_PIN_X);

    GPIO_SetPinInputValue(0);
    pinValue = GPIO_ReadInputDataBit(PBUP_GPIOx, PBUP_GPIO_PIN_X);
    CHECK_EQUAL(pinValue, 0);

    GPIO_SetPinInputValue(1);
    pinValue = GPIO_ReadInputDataBit(PBUP_GPIOx, PBUP_GPIO_PIN_X);
    CHECK_EQUAL(pinValue, 1);
}

TEST(PushButtonFilterTests, SampleButtonsOnTimeout)
{
    GPIO_SetPinInputValue(0);

    mock().expectOneCall("Set_TimerValue"        ).withCallOrder(callOrder++)
        .withParameter("timerValue", 0);
    Set_TimerValue(0, 0); // Sets all timers to be expired

    mock().expectOneCall("IsTimerExpired"        ).withCallOrder(callOrder++);

    mock().expectOneCall("GPIO_ReadInputDataBit"  ).withCallOrder(callOrder++)
        .withParameter("GPIOx"   , PBUP_GPIOx)
        .withParameter("GPIO_Pin", PBUP_GPIO_PIN_X);

    mock().expectOneCall("GPIO_ReadInputDataBit"  ).withCallOrder(callOrder++)
        .withParameter("GPIOx"   , PBDN_GPIOx)
        .withParameter("GPIO_Pin", PBDN_GPIO_PIN_X);

    Run_PushButtons();
} // end - TEST(PushButtonFilterTests, SampleButtonsOnTimeout)

TEST(PushButtonFilterTests, CanGetSampledInputs)
{
    mock().disable();
    Set_TimerValue(0, 0); // Sets all timers to be expired


    GPIO_SetPinInputValue(0);
    Run_PushButtons();
    mock().enable();
    CHECK_EQUAL(0, Get_PbUpStatus());
    CHECK_EQUAL(0, Get_PbDnStatus());

    GPIO_SetPinInputValue(1);
    mock().disable();
    Run_PushButtons();
    mock().enable();
    CHECK_EQUAL(Get_PbUpStatus(), 1);
    CHECK_EQUAL(Get_PbDnStatus(), 1);
} // end - TEST(PushButtonFilterTests, SampleButtonsOnTimeout)

