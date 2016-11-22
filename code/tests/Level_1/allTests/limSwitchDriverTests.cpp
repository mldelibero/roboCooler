#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "limitSwitchDriver.h"

CLimSwDriver* limSwitch;

#define TEST_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
#define TEST_LIMSW_GPIOx                     GPIOA
#define TEST_LIMSW_GPIO_PIN_X                GPIO_Pin_0

TEST_GROUP(LimSwDriverTests)
{
    void setup()
    {
        mock().enable();
        limSwitch = new CLimSwDriver(TEST_LIMSW_AHB1Periph_GPIOx, TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X);
    }
    void teardown()
    {
        delete limSwitch;
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(LimSwDriverTests, InitResetsPeripheral)
{
    mock().expectOneCall("RCC_AHB1PeriphClockCmd");
    mock().expectOneCall("GPIO_StructInit");
    mock().expectOneCall("GPIO_Init");

    limSwitch->Initialize_Hardware();
}

TEST(LimSwDriverTests, SampleCallsGpioReadFunction)
{
    mock().expectNCalls(2, "GPIO_ReadInputDataBit").ignoreOtherParameters();
    OpenedLimSwitch_SampleInput();
    ClosedLimSwitch_SampleInput();
}

TEST(LimSwDriverTests, CanWriteMockInput)
{
    mock().disable();

    GPIO_WriteBit(OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X, Bit_RESET);
    GPIO_WriteBit(CLOSE_LIMSW_GPIOx, CLOSE_LIMSW_GPIO_PIN_X, Bit_RESET);
    CHECK_EQUAL(0, OpenedLimSwitch_SampleInput());
    CHECK_EQUAL(0, ClosedLimSwitch_SampleInput());

    GPIO_WriteBit(OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X, Bit_SET);
    GPIO_WriteBit(CLOSE_LIMSW_GPIOx, CLOSE_LIMSW_GPIO_PIN_X, Bit_SET);
    CHECK_EQUAL(1, OpenedLimSwitch_SampleInput());
    CHECK_EQUAL(1, ClosedLimSwitch_SampleInput());
}

