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
 *
 *  * Add hysteresis on the filter
 *  * mock hw driver needs to have a settable input
 */

#define TEST_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define TEST_LIMSW_GPIOx                     GPIOA
#define TEST_LIMSW_GPIO_PIN_X                GPIO_Pin_0

#define TEST_BUFFER_SIZE                     5
#define TEST_BUFFER_CUTOFF                   3

CLimSwDriver* limSwDriver;
CLimSwComp*   limSw;

TEST_GROUP(LimitSwitchTests)
{
    void setup()
    {
        mock().disable();
        mock().enable();
        limSwDriver = new CLimSwDriver(TEST_LIMSW_AHB1Periph_GPIOx, TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X);
        limSw       = new CLimSwComp(limSwDriver, TEST_BUFFER_SIZE, TEST_BUFFER_CUTOFF);
    }
    void teardown()
    {
        delete limSw;
        delete limSwDriver;
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LimitSwitchTests)
/*
TEST(LimitSwitchTests, SamplesInputOnRun)
{
    mock().expectOneCall("CLimSwDriver::SampleInput");
    limSw->Run();
}

TEST(LimitSwitchTests, FiltersInputOnRun)
{
    mock().disable();

    CHECK_EQUAL(false, limSw->At_Limit());
    GPIO_WriteBit(TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X, Bit_SET);

    for (int cnt = 1; cnt <= 6; cnt++)
    { // Run 1 less than cutoff
        limSw->Run();
    }

    CHECK_EQUAL(false, limSw->At_Limit());
    limSw->Run(); // 7th
    CHECK_EQUAL(true, limSw->At_Limit());
}
*/
TEST(LimitSwitchTests, BufferSizeIsRespected)
{
    mock().disable();
    GPIO_WriteBit(TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X, Bit_SET);
    for(int cnt = 1; cnt <= TEST_BUFFER_SIZE + 2; cnt++)
    { // Overrun buffer size
        limSw->Run();
    }

    GPIO_SetPinInputValue(TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X, 0);
    //for(int cnt = 10; cnt > 7; cnt--)
    for(int cnt = TEST_BUFFER_SIZE; cnt > TEST_BUFFER_CUTOFF; cnt--)
    { // Dip to just above the cutoff
        limSw->Run();
    }

    CHECK_EQUAL(true, limSw->At_Limit());
    limSw->Run();
    CHECK_EQUAL(false, limSw->At_Limit());
}

