/**
 ******************************************************************************
 * @file    limSwitchDriverTests.cpp
 * @author  Michael DeLibero
 * @brief   Tests the limit switch driver
 ******************************************************************************
 */
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
//#include <stm32f4xx_hal.h>
#include "limitSwitchDriver.h"

//CLimSwDriver* limSwitch;

//#define TEST_LIMSW_AHB1Periph_GPIOx          RCC_AHB1Periph_GPIOA
//#define TEST_LIMSW_GPIOx                     GPIOA
//#define TEST_LIMSW_GPIO_PIN_X                GPIO_Pin_0

TEST_GROUP(LimSwDriverTests)
{
    void setup()
    {
        mock().enable();
//        limSwitch = new CLimSwDriver(TEST_LIMSW_AHB1Periph_GPIOx, TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X);
    }
    void teardown()
    {
//        delete limSwitch;
        mock().checkExpectations();
        mock().clear();
    }
};
/*
TEST(LimSwDriverTests, InitResetsPeripheral)
{
    mock().expectOneCall("RCC_AHB1PeriphClockCmd");
    mock().expectOneCall("GPIO_StructInit");
    mock().expectOneCall("GPIO_Init");

    limSwitch->Initialize_Hardware();
}

TEST(LimSwDriverTests, SampleCallsGpioReadFunction)
{
    mock().expectOneCall("GPIO_ReadInputDataBit").ignoreOtherParameters();
    limSwitch->SampleInput();
}

TEST(LimSwDriverTests, SampleCallsReturnsCorrectValue)
{
    mock().disable();

    GPIO_SetPinInputValue(TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X, uint8_t(Bit_SET));
    CHECK_EQUAL(Bit_SET, limSwitch->SampleInput());

    GPIO_SetPinInputValue(TEST_LIMSW_GPIOx, TEST_LIMSW_GPIO_PIN_X, uint8_t(Bit_RESET));
    CHECK_EQUAL(Bit_RESET, limSwitch->SampleInput());
}
*/

