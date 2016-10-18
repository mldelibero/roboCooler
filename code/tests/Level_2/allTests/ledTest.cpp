#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "leds.h"

/*  * List of features needed:
 *  *init calls init_leds
 *  *Does timer driver run out of timers while init is executing?
 *  *LEDs off on startup
 */

TEST_GROUP(LedTests)
{
    void setup()
    {
        mock().disable();
        mock().enable();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedTests)

TEST(LedTests, TestInitCalls)
{
    CLedComp leds;
    mock().expectOneCall("init_ledDriver");
    leds.Initialize();
}

TEST(LedTests, CanSaveLedStates)
{
    CLedComp leds;
    uint8_t ledStates = 0xAA;

    leds.WriteAllLedStates(ledStates);
    CHECK_EQUAL(ledStates, leds.Get_LedStates());
}

TEST(LedTests, RunUpdatesLedStates)
{
    CLedComp leds;
    uint8_t ledStates = 0xAA;
    leds.WriteAllLedStates(ledStates);
    mock().expectOneCall("SetLeds").withParameter("ledValues", ledStates);
    leds.BypassBootSequence();
    leds.Run();
}

TEST(LedTests, ResetFreqGreater10Hz)
{
    CLedComp leds;
    CHECK(leds.Get_TimerResetValue() < 100); // < 100ms
}

TEST_GROUP(LedBootTests)
{
    void setup()
    {
        mock().disable();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(LedBootTests)

TEST(LedBootTests, BootModeEnabledAfterInit)
{
    CLedComp leds;
    CHECK(leds.Is_InBootMode());
}

TEST(LedBootTests, BootIntervalGreaterThanZero)
{
    CLedComp leds;
    CHECK(leds.Get_BootPeriod() > 0);
}

TEST(LedBootTests, BootModeDisabledOnlyAfterElapsedRuns)
{
    CLedComp leds;
    for (int32_t run = 0; run < leds.Get_TotalRunsInBoot()-1; run++)
    {
        leds.Run();
    }
    // Should be true right before the last run
    CHECK_EQUAL(true, leds.Is_InBootMode());

    // Will be false after last run
    leds.Run();
    CHECK_EQUAL(false, leds.Is_InBootMode());
}

TEST(LedBootTests, DoesNotSetNormalLedsStatesInBootMode)
{
    mock().enable();
    mock().expectOneCall("SetLeds").withParameter("ledValues", 1);

    CLedComp leds;
    leds.WriteAllLedStates(0xAA);
    leds.Run();
}

TEST(LedBootTests, SetsLedBootStates)
{
    CLedComp leds;
    uint8_t normalLedsState = 0xAA;
    leds.WriteAllLedStates(normalLedsState); // Will not be called during boot state
    mock().enable();

    // Check first call is to boot sequence
    mock().expectOneCall("SetLeds").withParameter("ledValues", 0x1);
    leds.Run();

    // Ignore for rest of boot sequence calls
    mock().expectNCalls(leds.Get_TotalRunsInBoot(), "SetLeds").ignoreOtherParameters();
    for(int32_t run = 0; run < leds.Get_TotalRunsInBoot(); run++)
    {
        leds.Run();
    }

    // Check that the next call is the normal sequence call value
    mock().expectOneCall("SetLeds").withParameter("ledValues", normalLedsState);
    leds.Run();
}

/*
 * @brief   This checks that the leds turn on in sequence
 */
TEST(LedBootTests, UpdatesLedsCorrectlyInBootMode)
{
    CLedComp leds;
    leds.WriteAllLedStates(0xAA);

    uint8_t expected_bootLeds = 0;
    uint8_t actual_bootLeds   = 0;

    for(int32_t run = 1; run < leds.Get_TotalRunsInBoot(); run++)
    {
        leds.Run();
        actual_bootLeds = leds.Get_BootLedStates();
        if (actual_bootLeds != expected_bootLeds)
        { // 1 3 7 F 1F 3F 7F FF
        if (expected_bootLeds == 0xFF)
        {
            expected_bootLeds = 0;
        }
        else
        {
            expected_bootLeds = uint8_t(expected_bootLeds*2 + 1); // bit shifts to the left
        }
            CHECK_EQUAL(expected_bootLeds, actual_bootLeds);
        }
    }
} // end - TEST(LedBootTests, UpdatesLedsCorrectlyInBootMode)

