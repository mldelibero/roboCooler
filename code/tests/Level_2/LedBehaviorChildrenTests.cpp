#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"
#include "ledBehaviorChildren.h"
#include "LedBehaviorTests.h"

CLedBeh_Solid*  SolidColorBehavior;
CLedObj         LedColor;
static CLedObj  Off;
static CLedObj* LedObjs;

TEST_GROUP(SolidColorTests)
{
    void setup()
    {
        mock().disable();
        LedColor.Set_Red_PercentOn  (20);
        LedColor.Set_Green_PercentOn(60);
        LedColor.Set_Blue_PercentOn (80);

        SolidColorBehavior = new CLedBeh_Solid(LedColor);
        LedObjs          = new CLedObj[NUM_LEDS];
    }

    void teardown()
    {
        delete SolidColorBehavior;
        delete [] LedObjs;
    }
}; // end - TEST_GROUP(SolidColorTests)

TEST(SolidColorTests, AllLedsTurnOnToSpecificColor)
{
    SolidColorBehavior->Set_NumLeds(NUM_LEDS);
    SolidColorBehavior->Run(&LedObjs[0]);
    CheckLeds(0, NUM_LEDS-1, LedObjs, Off, LedColor, Off);
}

