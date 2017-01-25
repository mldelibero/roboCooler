#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"
#include "ledBehaviorChildren.h"
#include "LedBehaviorTests.h"

// -- Variables -----------------------------------------------------------
CLedBeh_Solid*      SolidColorBehavior;
CLedBeh_MovingBand* MovingBandBehavior;
CLedBeh_Solid*      TurnOffAllLeds;


static CLedObj  Off;
static CLedObj  LedColors;
static CLedObj* LedObjs;

static uint16_t FirstIndex = 0;
static uint16_t LastIndex  = 0;
static uint16_t NumLeds    = 0;
// -- Tests ---------------------------------------------------------------

TEST_GROUP(SolidColorTests)
{
    void setup()
    {
        mock().disable();
        LedColors.Set_All_PercentOn(20,40,60);
        Off      .Set_All_PercentOn(  0,   0,   0);

        // Configure indices
        NumLeds = NUM_LEDS;
        FirstIndex = 0;
        LastIndex  = uint16_t(NumLeds - 1);

        SolidColorBehavior = new CLedBeh_Solid(NumLeds, FirstIndex, LastIndex, LedColors);
        LedObjs            = new CLedObj[NUM_LEDS];
   }

    void teardown()
    {
        delete SolidColorBehavior;
        delete [] LedObjs;
    }
}; // end - TEST_GROUP(SolidColorTests)

TEST(SolidColorTests, AllLedsTurnOnToSpecificColor)
{
    SolidColorBehavior->Run(&LedObjs[0]);
    CheckLeds(FirstIndex, LastIndex, LedObjs, Off, LedColors, Off);
}

// -- Moving LED band tests -----------------------------------------------
TEST_GROUP(MovingBandTests)
{
    void setup()
    {
        mock().disable();

        LedColors.Set_All_PercentOn(20,40,60);

        // Configure indices
        NumLeds    = 5;
        FirstIndex = 1;
        LastIndex  = 3;

        TurnOffAllLeds     = new CLedBeh_Solid     (NumLeds, FirstIndex, LastIndex, Off);
        MovingBandBehavior = new CLedBeh_MovingBand(NumLeds, FirstIndex, LastIndex, LedColors);
        LedObjs            = new CLedObj[NUM_LEDS];
    }

    void teardown()
    {
        delete TurnOffAllLeds;
        delete MovingBandBehavior;
        delete [] LedObjs;
    }
}; // end - TEST_GROUP(MovingBandTests)

TEST(MovingBandTests, FirstRunTurnsOnCorrectNumberOfLeds)
{
    MovingBandBehavior->Run(&LedObjs[0]);
    CheckLeds(FirstIndex, LastIndex, LedObjs, Off, LedColors, Off);
}


TEST(MovingBandTests, BandMovesEachIterationIfNoSubIterationSet)
{
    MovingBandBehavior->Run(&LedObjs[0]);
    TurnOffAllLeds    ->Run(&LedObjs[0]);
    MovingBandBehavior->Run(&LedObjs[0]);

    FirstIndex++;
    LastIndex++;

    CheckLeds(FirstIndex, LastIndex, LedObjs, Off, LedColors, Off);
}

TEST(MovingBandTests, BandWrapsAroundEndpoint)
{
}

TEST(MovingBandTests, BandStaysStillWhenInbetweenSubIterations)
{
}

TEST(MovingBandTests, BandMovesEachSubIteration)
{
}

