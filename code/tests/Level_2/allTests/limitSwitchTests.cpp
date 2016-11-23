#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "limitSwitch.h"


/**
 * * List of tests needed:
 *  * Integration test makes sure that correct input has been sampled.
 *  * Obj filters input on run
 *  * obj returns filtered output when querried
 *  * init resets filter
 */

#define TEST_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define TEST_LIMSW_GPIOx                     GPIOA
#define TEST_LIMSW_GPIO_PIN_X                GPIO_Pin_0

CLimSwDriver* limSwDriver;
CLimSwComp*   limSw;

TEST_GROUP(LimitSwitchTests)
{
    void setup()
    {
        mock().disable();
        mock().enable();
        limSwDriver = new CLimSwDriver(TEST_LIMSW_AHB1Periph_GPIOx, TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X);
        limSw       = new CLimSwComp(limSwDriver);
    }
    void teardown()
    {
        delete limSw;
        delete limSwDriver;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LimitSwitchTests)

TEST(LimitSwitchTests, SamplesInputOnRun)
{
//    mock().expectOneCall("GPIO_ReadInputDataBit");
//    limitSwitch->Run();
}

TEST(LimitSwitchTests, FiltersInputOnRun)
{
}

TEST(LimitSwitchTests, ReturnsFilteredInput)
{
}

