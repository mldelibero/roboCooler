#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"
#include "ledObj.h"

// -- Defines -------------------------------------------------------------
#define RED_LED_PERCENT_ON   40
#define GREEN_LED_PERCENT_ON 50
#define BLUE_LED_PERCENT_ON  70

#define NUM_LEDS             10
// -- Variables -----------------------------------------------------------
CLedObj Off;
CLedObj HalfOn;
CLedObj FullOn;
// -- Class definition ----------------------------------------------------
class CLedBehaviorChild : public CLedBehaviorComp
{
    public:
        CLedBehaviorChild()
        {
            m_LedObj.Set_Red_PercentOn  (RED_LED_PERCENT_ON);
            m_LedObj.Set_Green_PercentOn(GREEN_LED_PERCENT_ON);
            m_LedObj.Set_Blue_PercentOn (BLUE_LED_PERCENT_ON);
        }

        CLedBehaviorChild(CLedObj ledObj)
        {
            m_LedObj = ledObj;
        }

        void Force_DoneConditionMet(void)
        {
            m_Status = BEHAVIOR_DONE;
        }

        CLedObj m_LedObj;

        void Update_Leds(void)
        { // Shows example of how to use this function
            for (uint16_t led = 0; led < m_NumLeds; led++)
            {
                Set_Led(led, m_LedObj);
            }
        }
}; // end - class CLedBehaviorChild : public CLedBehaviorComp

// -- Variables -----------------------------------------------------------
CLedBehaviorComp*  LedBehavior;
CLedBehaviorChild* LedBehaviorChild;
CLedObj*           LedObjs;
// -- Helper Function -----------------------------------------------------
void CheckLeds(uint8_t startIndex, uint8_t endIndex, CLedObj firstObj, CLedObj secondObj, CLedObj thirdObj)
{
    int led = 0;

    for (; led < startIndex; led++)
    {
        CHECK_EQUAL(firstObj.Get_Red_PercentOn()  , LedObjs[led].Get_Red_PercentOn());
        CHECK_EQUAL(firstObj.Get_Green_PercentOn(), LedObjs[led].Get_Green_PercentOn());
        CHECK_EQUAL(firstObj.Get_Blue_PercentOn() , LedObjs[led].Get_Blue_PercentOn());
    }

    for (; led <= endIndex; led++)
    {
        CHECK_EQUAL(secondObj.Get_Red_PercentOn()  , LedObjs[led].Get_Red_PercentOn());
        CHECK_EQUAL(secondObj.Get_Green_PercentOn(), LedObjs[led].Get_Green_PercentOn());
        CHECK_EQUAL(secondObj.Get_Blue_PercentOn() , LedObjs[led].Get_Blue_PercentOn());
    }

    for (; led < NUM_LEDS; led++)
    {
        CHECK_EQUAL(thirdObj.Get_Red_PercentOn()  , LedObjs[led].Get_Red_PercentOn());
        CHECK_EQUAL(thirdObj.Get_Green_PercentOn(), LedObjs[led].Get_Green_PercentOn());
        CHECK_EQUAL(thirdObj.Get_Blue_PercentOn() , LedObjs[led].Get_Blue_PercentOn());
    }
}
// -- Tests ---------------------------------------------------------------
TEST_GROUP(LedBehaviorTests)
{
    void setup()
    {
        mock().disable();
        LedBehavior      = new CLedBehaviorComp;
        LedBehaviorChild = new CLedBehaviorChild;
        LedObjs          = new CLedObj[NUM_LEDS];

        Off.Set_Red_PercentOn(0);
        Off.Set_Green_PercentOn(0);
        Off.Set_Blue_PercentOn(0);

        HalfOn.Set_Red_PercentOn(RED_LED_PERCENT_ON/2);
        HalfOn.Set_Green_PercentOn(GREEN_LED_PERCENT_ON/2);
        HalfOn.Set_Blue_PercentOn(BLUE_LED_PERCENT_ON/2);

        FullOn.Set_Red_PercentOn(RED_LED_PERCENT_ON);
        FullOn.Set_Green_PercentOn(GREEN_LED_PERCENT_ON);
        FullOn.Set_Blue_PercentOn(BLUE_LED_PERCENT_ON);

    }

    void teardown()
    {
        delete LedBehavior;
        delete LedBehaviorChild;
        delete [] LedObjs;
    }
};

TEST(LedBehaviorTests, StatusReturnsActiveAfterConstructor)
{
    CHECK_EQUAL(BEHAVIOR_ACTIVE, LedBehavior->Get_Status());
}

TEST(LedBehaviorTests, ChildClassCompliesWithChildsEndConditionFun)
{
    LedBehaviorChild->Force_DoneConditionMet();
    CHECK_EQUAL(BEHAVIOR_DONE, LedBehaviorChild->Get_Status());
}

TEST(LedBehaviorTests, InitResetsState)
{
    LedBehaviorChild->Force_DoneConditionMet();
    LedBehaviorChild->Initialize();
    CHECK_EQUAL(BEHAVIOR_ACTIVE, LedBehaviorChild->Get_Status());
}

TEST(LedBehaviorTests, BehaviorsAreNotBlendedByDefault)
{
    CHECK_EQUAL(false, LedBehavior->Is_Blended());
}

TEST(LedBehaviorTests, CanControlBehaviorBlending)
{
    LedBehavior->Set_IsBlended();
    CHECK_EQUAL(true, LedBehavior->Is_Blended());

    LedBehavior->Clear_IsBlended();
    CHECK_EQUAL(false, LedBehavior->Is_Blended());
}

TEST(LedBehaviorTests, BothConstructorsActTheSame)
{ /// @bug How do I test this?
}

TEST(LedBehaviorTests, DefaultConstructorRunsForever)
{
    CLedBehaviorComp behavior;
    CHECK_EQUAL(-1, behavior.Get_TimeLeft_ms());
    CHECK_EQUAL(BEHAVIOR_ACTIVE, behavior.Get_Status());
    behavior.Run();
    CHECK_EQUAL(BEHAVIOR_ACTIVE, behavior.Get_Status());
}

TEST(LedBehaviorTests, BaseClassSetsComponentRunPeriod)
{ // All children will adhere to the same rate. May change later
    mock().expectOneCall("CComponent::Set_ComponentPeriod_ms").withParameter("period", BEH_DEF_PER_MS);
}

TEST(LedBehaviorTests, MocksActuallySetComponentRunPeriod)
{
    CHECK_EQUAL(BEH_DEF_PER_MS, LedBehavior->Get_ComponentPeriod_ms());
}

TEST(LedBehaviorTests, TimeLeftDecreasesAfterEachIteration)
{
    int32_t runTime = BEH_DEF_PER_MS * 10;

    CLedBehaviorComp behavior(runTime);
    behavior.Run();

    CHECK_EQUAL(runTime - BEH_DEF_PER_MS, behavior.Get_TimeLeft_ms());
}

TEST(LedBehaviorTests, BehaviorTurnsOffAfterTimeIsExpired)
{
    CLedBehaviorComp behavior(BEH_DEF_PER_MS);
    behavior.Run();
    CHECK_EQUAL(BEHAVIOR_DONE, behavior.Get_Status());
}

TEST(LedBehaviorTests, ReturnsZeroAfterTimeIsExpired)
{
    CLedBehaviorComp behavior(BEH_DEF_PER_MS);
    behavior.Run();
    behavior.Run();
    CHECK_EQUAL(0, behavior.Get_TimeLeft_ms());
}

TEST(LedBehaviorTests, SettingRunTimeToZeroRunsForASingleIteration)
{
    CLedBehaviorComp behavior(0);
    CHECK_EQUAL(BEHAVIOR_ACTIVE, behavior.Get_Status());
    behavior.Run();
    CHECK_EQUAL(BEHAVIOR_DONE, behavior.Get_Status());
}

TEST(LedBehaviorTests, NumLedsDefaultsToZero)
{
    CHECK_EQUAL(0, LedBehavior->Get_NumLeds());
}

TEST(LedBehaviorTests, CanSetNumLeds)
{
    uint16_t numLeds = NUM_LEDS*2;
    LedBehavior->Set_NumLeds(numLeds);
    CHECK_EQUAL(numLeds, LedBehavior->Get_NumLeds());
}

TEST(LedBehaviorTests, BehaviorSetToOperateOnAllLedsByDefault)
{
    LedBehavior->Set_NumLeds(NUM_LEDS);
    CHECK_EQUAL(0         , LedBehavior->Get_FirstLedIndex());
    CHECK_EQUAL(NUM_LEDS-1, LedBehavior->Get_LastLedIndex());
}

TEST(LedBehaviorTests, NoBlendingPassesColorsThrough)
{
    LedBehaviorChild->Set_NumLeds(NUM_LEDS);
    LedBehaviorChild->Clear_IsBlended();
    LedBehaviorChild->Run(&LedObjs[0]);

    CheckLeds(0, NUM_LEDS-1, Off, FullOn, Off);
}

TEST(LedBehaviorTests, CanSetBehaviorToOperateOnPercentageOfLeds)
{
    LedBehavior->Set_NumLeds(NUM_LEDS);
    LedBehavior->Set_StartingPercentage(20);
    LedBehavior->Set_EndingPercentage(80);

    CHECK_EQUAL(1, LedBehavior->Get_FirstLedIndex());
    CHECK_EQUAL(7, LedBehavior->Get_LastLedIndex());
}

TEST(LedBehaviorTests, BehaviorChoosesNearestLedIndexToPercentage)
{
    LedBehavior->Set_NumLeds(NUM_LEDS);

    LedBehavior->Set_StartingPercentage(14);
    CHECK_EQUAL(0, LedBehavior->Get_FirstLedIndex());

    LedBehavior->Set_StartingPercentage(16);
    CHECK_EQUAL(1, LedBehavior->Get_FirstLedIndex());

    LedBehavior->Set_EndingPercentage(34);
    CHECK_EQUAL(2, LedBehavior->Get_LastLedIndex());

    LedBehavior->Set_EndingPercentage(36);
    CHECK_EQUAL(3, LedBehavior->Get_LastLedIndex());
}

TEST(LedBehaviorTests, CannotSetBehaviorToOperateOnMoreThan100PercentOfLeds)
{
    LedBehavior->Set_NumLeds(NUM_LEDS);
    LedBehavior->Set_StartingPercentage(255);
    LedBehavior->Set_EndingPercentage  (255);

    CHECK_EQUAL(9, LedBehavior->Get_FirstLedIndex());
    CHECK_EQUAL(9, LedBehavior->Get_LastLedIndex());
}

TEST(LedBehaviorTests, BehaviorCanOperatesOnOnlyPartOfLeds)
{
    LedBehaviorChild->Set_NumLeds(NUM_LEDS);

    LedBehaviorChild->Set_StartingPercentage(20);
    LedBehaviorChild->Set_EndingPercentage(80);

    LedBehaviorChild->Run(&LedObjs[0]);

    CheckLeds(1, 7, Off, FullOn, Off);
}

TEST(LedBehaviorTests, BeginningEqualToEndOnlyUpdatesOneLed)
{
    LedBehaviorChild->Set_NumLeds(NUM_LEDS);

    LedBehaviorChild->Set_StartingPercentage(50);
    LedBehaviorChild->Set_EndingPercentage(50);

    LedBehaviorChild->Run(&LedObjs[0]);

    CheckLeds(4, 4, Off, FullOn, Off);
}

TEST(LedBehaviorTests, BeginningAfterEndDoesNotUpdateLeds)
{
    LedBehaviorChild->Set_NumLeds(NUM_LEDS);

    LedBehaviorChild->Set_StartingPercentage(80);
    LedBehaviorChild->Set_EndingPercentage(20);
    // Make sure that we aren't being confused by rounding (21 and 20 won't work)
    CHECK(LedBehaviorChild->Get_FirstLedIndex() > LedBehaviorChild->Get_LastLedIndex());

    LedBehaviorChild->Run(&LedObjs[0]);
}

TEST(LedBehaviorTests, CanControlLedForLocalClass)
{
    CLedObj ledObj;
    uint8_t Red   = RED_LED_PERCENT_ON   / 2;
    uint8_t Green = GREEN_LED_PERCENT_ON / 2;
    uint8_t Blue  = BLUE_LED_PERCENT_ON  / 2;

    ledObj.Set_Red_PercentOn  (Red);
    ledObj.Set_Green_PercentOn(Green);
    ledObj.Set_Blue_PercentOn (Blue);

    CLedBehaviorChild firstBehChild(ledObj);
    firstBehChild.Set_NumLeds(NUM_LEDS);
    firstBehChild.Run(&LedObjs[0]);

    CheckLeds(0, NUM_LEDS-1, HalfOn, HalfOn, HalfOn);
}

TEST(LedBehaviorTests, OverwriteBlendingWorks)
{
    // This should overwrite previous
    LedBehaviorChild->Set_NumLeds(NUM_LEDS);
    LedBehaviorChild->Run(&LedObjs[0]);

    CLedObj ledObj;
    uint8_t Red   = RED_LED_PERCENT_ON   / 2;
    uint8_t Green = GREEN_LED_PERCENT_ON / 2;
    uint8_t Blue  = BLUE_LED_PERCENT_ON  / 2;

    ledObj.Set_Red_PercentOn  (Red);
    ledObj.Set_Green_PercentOn(Green);
    ledObj.Set_Blue_PercentOn (Blue);

    CLedBehaviorChild secondBehChild(ledObj);

    secondBehChild.Set_NumLeds(NUM_LEDS);
    secondBehChild.Set_IsBlended();

    secondBehChild.Set_StartingPercentage(20);
    secondBehChild.Set_EndingPercentage(80);

    secondBehChild.Run(&LedObjs[0]);

    CheckLeds(1, 7, FullOn, HalfOn, FullOn);
}
