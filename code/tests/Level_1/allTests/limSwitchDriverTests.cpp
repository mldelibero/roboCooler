#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_gpio.h>
#include "limitSwitchDriver.h"

/**
 * * List of tests needed:
 * *
 * * Init sets up peripheral
 * * Can mock set/clear the switch input
 * * Returns mocked setting
 * * return 0 by default (before run)
 * * Integration test makes sure that correct input has been sampled.
 *  * Obj samples input on run
 *  * Obj filters input on run
 *  * obj returns filtered output when querried
 *  * init resets filter
 */

TEST_GROUP(LimSwDriverTests)
{
    void setup()
    {
        mock().enable();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(LimSwDriverTests, InitResetsPeripheral)
{
    mock().disable();
    init_LimSwDriver();
}

TEST(LimSwDriverTests, SampleCallsGpioReadFunction)
{
    mock().expectNCalls(2, "GPIO_ReadInputDataBit").ignoreOtherParameters();
    OpenedLimSwitch_SampleInput();
    ClosedLimSwitch_SampleInput();
}

