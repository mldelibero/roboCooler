#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"
#include "LedBehaviorTests.h"
#include "ledObj.h"
// -- Class definition ----------------------------------------------------
class CLedBehaviorChild : public CLedBehaviorComp
{
    public:
        CLedBehaviorChild(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex, CLedObj LedObj) : CLedBehaviorComp(NumLeds, FirstIndex, LastIndex)
        {
            m_LedObj = LedObj;
        }

        void Force_DoneConditionMet(void)
        {
            m_Status = BEHAVIOR_DONE;
        }

        void Update_Leds(void)
        {
            for (uint16_t led = 0; led < m_NumLeds; led++)
            {
                Set_Led(led, m_LedObj);
            }
        }

    private:
        CLedObj m_LedObj;
};

void CheckLeds(uint16_t StartIndex, uint16_t EndIndex, uint16_t NumLeds, CLedObj* OutputLedObj, CLedObj InObj, CLedObj OutObj)
{
    for (int led = 0; led < NumLeds; led++)
    {
        if (((StartIndex <= EndIndex) && (led >= StartIndex && led <= EndIndex))
         || ((StartIndex >  EndIndex) && (led >= StartIndex || led <= EndIndex)))
        {
            CHECK_EQUAL(InObj.Get_Red_PercentOn()  , OutputLedObj[led].Get_Red_PercentOn());
            CHECK_EQUAL(InObj.Get_Green_PercentOn(), OutputLedObj[led].Get_Green_PercentOn());
            CHECK_EQUAL(InObj.Get_Blue_PercentOn() , OutputLedObj[led].Get_Blue_PercentOn());
        }
        else
        {
            CHECK_EQUAL(OutObj.Get_Red_PercentOn()  , OutputLedObj[led].Get_Red_PercentOn());
            CHECK_EQUAL(OutObj.Get_Green_PercentOn(), OutputLedObj[led].Get_Green_PercentOn());
            CHECK_EQUAL(OutObj.Get_Blue_PercentOn() , OutputLedObj[led].Get_Blue_PercentOn());
        }
    }
}

// -- Variables -----------------------------------------------------------
CLedBehaviorComp*  LedBehavior;
CLedBehaviorChild* LedBehaviorChild;
uint16_t FirstIndex = 0;
uint16_t LastIndex  = 0;
uint16_t NumLeds    = 0;
static CLedObj*    LedObjs;

CLedObj Off;
CLedObj OneQuarterOn;
CLedObj HalfOn;
CLedObj ThreeQuartersOn;
CLedObj FullOn;
CLedObj LedColors;
// -- Tests ---------------------------------------------------------------
TEST_GROUP(LedBehaviorTests)
{
    void setup()
    {
        mock().disable();

        // Configure all Led Objects
        Off            .Set_All_PercentOn(  0,   0,   0);
        OneQuarterOn   .Set_All_PercentOn( 25,  25,  25);
        HalfOn         .Set_All_PercentOn( 50,  50,  50);
        ThreeQuartersOn.Set_All_PercentOn( 75,  75,  75);
        FullOn         .Set_All_PercentOn(100, 100, 100);
        LedColors      .Set_All_PercentOn( 20,  40,  60);

        // Configure indices
        NumLeds = NUM_LEDS;
        FirstIndex = 0;
        LastIndex  = uint16_t(NumLeds - 1);

        LedBehavior      = new CLedBehaviorComp (NumLeds, FirstIndex, LastIndex);
        LedBehaviorChild = new CLedBehaviorChild(NumLeds, FirstIndex, LastIndex, LedColors);

        LedObjs          = new CLedObj[NUM_LEDS];
    }

    void teardown()
    {
        delete LedBehavior;
        delete LedBehaviorChild;
        delete [] LedObjs;
    }
}; // end - TEST_GROUP(LedBehaviorTests)

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
    LedBehavior->Set_IsBlended(BEHAVIOR_BLENDING_AVERAGE);
    CHECK_EQUAL(true, LedBehavior->Is_Blended());

    LedBehavior->Clear_IsBlended();
    CHECK_EQUAL(false, LedBehavior->Is_Blended());
}

TEST(LedBehaviorTests, BothConstructorsActTheSame)
{ /// @bug How do I test this?
}

TEST(LedBehaviorTests, DefaultConstructorRunsForever)
{
    CHECK_EQUAL(-1, LedBehavior->Get_TimeLeft_ms());
    CHECK_EQUAL(BEHAVIOR_ACTIVE, LedBehavior->Get_Status());
    LedBehavior->Run();
    CHECK_EQUAL(BEHAVIOR_ACTIVE, LedBehavior->Get_Status());
}

TEST(LedBehaviorTests, BaseClassSetsComponentRunPeriod)
{ // All children will adhere to the same rate. May change later
    mock().expectOneCall("CComponent::Set_ComponentPeriod_ms").withParameter("period", BEH_DEF_PER_MS);
}

TEST(LedBehaviorTests, MocksActuallySetComponentRunPeriod)
{
    CHECK_EQUAL(BEH_DEF_PER_MS, LedBehavior->Get_ComponentPeriod_ms());
}

TEST(LedBehaviorTests, CanSetTimeOutValue)
{
    int32_t runTime = BEH_DEF_PER_MS * 10;
    LedBehavior->Set_TimeoutValue(uint32_t(runTime));

    CHECK_EQUAL(runTime, LedBehavior->Get_TimeLeft_ms());
}

TEST(LedBehaviorTests, TimeLeftDecreasesAfterEachIteration)
{
    int32_t runTime = BEH_DEF_PER_MS * 10;
    LedBehavior->Set_TimeoutValue(uint32_t(runTime));

    LedBehavior->Run();

    CHECK_EQUAL(runTime - BEH_DEF_PER_MS, LedBehavior->Get_TimeLeft_ms());
}

TEST(LedBehaviorTests, BehaviorTurnsOffAfterTimeIsExpired)
{
    int32_t runTime = BEH_DEF_PER_MS;
    LedBehavior->Set_TimeoutValue(runTime);
    LedBehavior->Run();

    CHECK_EQUAL(BEHAVIOR_DONE, LedBehavior->Get_Status());
}

TEST(LedBehaviorTests, ReturnsZeroAfterTimeIsExpired)
{
    LedBehavior->Set_TimeoutValue(0);
    LedBehavior->Run();
    LedBehavior->Run();

    CHECK_EQUAL(0, LedBehavior->Get_TimeLeft_ms());
}

TEST(LedBehaviorTests, SettingRunTimeToZeroRunsForASingleIteration)
{
    LedBehavior->Set_TimeoutValue(0);

    CHECK_EQUAL(BEHAVIOR_ACTIVE, LedBehavior->Get_Status());
    LedBehavior->Run();
    CHECK_EQUAL(BEHAVIOR_DONE  , LedBehavior->Get_Status());
}

TEST(LedBehaviorTests, CanSetNumLedsInConstructor)
{
    CHECK_EQUAL(NumLeds, LedBehavior->Get_NumLeds());
}

TEST(LedBehaviorTests, TestGroupSetsIndices)
{
    CHECK_EQUAL(FirstIndex, LedBehavior->Get_FirstLedIndex());
    CHECK_EQUAL(LastIndex , LedBehavior->Get_LastLedIndex ());
}

TEST(LedBehaviorTests, IndicesOutOfRangeGetTruncatedToMax)
{
    CLedBehaviorComp ledBeh(NUM_LEDS, NUM_LEDS, NUM_LEDS);
    CHECK_EQUAL(NUM_LEDS-1, ledBeh.Get_FirstLedIndex());
    CHECK_EQUAL(NUM_LEDS-1, ledBeh.Get_LastLedIndex ());
}

TEST(LedBehaviorTests, CanChooseIndecesConveringPartOfLedArray)
{
    CLedBehaviorComp ledBeh(10, 2, 8);
    CHECK_EQUAL(2, ledBeh.Get_FirstLedIndex());
    CHECK_EQUAL(8, ledBeh.Get_LastLedIndex ());
}

TEST(LedBehaviorTests, CanChooseInvertedSetOfLeds)
{
    CLedBehaviorComp ledBeh(10, 8, 2);
    CHECK_EQUAL(8, ledBeh.Get_FirstLedIndex());
    CHECK_EQUAL(2, ledBeh.Get_LastLedIndex ());
}

TEST(LedBehaviorTests, BehaviorSetToOperateOnAllLedsByDefault)
{
    CLedBehaviorComp beh(NumLeds);
    CHECK_EQUAL(0         , beh.Get_FirstLedIndex());
    CHECK_EQUAL(NumLeds-1 , beh.Get_LastLedIndex());
}

TEST(LedBehaviorTests, NoBlendingPassesColorsThrough)
{
    LedBehaviorChild->Run(&LedObjs[0]);
    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, LedColors, Off);
}

TEST(LedBehaviorTests, DoesNotUpdateLedsWhenDone)
{
    LedBehaviorChild->Force_DoneConditionMet();
    LedBehaviorChild->Run(&LedObjs[0]);
    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, Off, Off);
}

TEST(LedBehaviorTests, BehaviorCanOperateOnOnlyPartOfLeds)
{
    NumLeds    = 5;
    FirstIndex = 1;
    LastIndex  = 3;

    CLedBehaviorChild beh(NumLeds, FirstIndex, LastIndex, LedColors);
    beh.Run(&LedObjs[0]);

    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, LedColors, Off);
}

TEST(LedBehaviorTests, BeginningEqualToEndOnlyUpdatesOneLed)
{
    uint16_t Index = 2;
    CLedBehaviorChild beh(NumLeds, Index, Index, LedColors);
    beh.Run(&LedObjs[0]);

    CheckLeds(Index, Index, NumLeds, LedObjs, LedColors, Off);
}

TEST(LedBehaviorTests, BeginningAfterEndUpdatesExclusiveSet)
{ // Only allows updates if led <= start or led >= end

    FirstIndex = 3;
    LastIndex  = 1;
    NumLeds    = 5;

    CLedBehaviorChild beh(NumLeds, FirstIndex, LastIndex, LedColors);
    CHECK(beh.Get_FirstLedIndex() > beh.Get_LastLedIndex());
    beh.Run(&LedObjs[0]);

    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, LedColors, Off);
}

TEST(LedBehaviorTests, OverwriteBlendingWorks)
{
    CLedBehaviorChild secondBehChild(NumLeds, FirstIndex, LastIndex, FullOn);

    LedBehaviorChild->Run(&LedObjs[0]);
    secondBehChild.Run(&LedObjs[0]);

    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, FullOn, LedColors);
}

TEST(LedBehaviorTests, AverageBlendingWorks)
{
    CLedBehaviorChild firstBehChild (NumLeds, FirstIndex, LastIndex, FullOn);
    CLedBehaviorChild secondBehChild(NumLeds, FirstIndex, LastIndex, Off);
    secondBehChild.Set_IsBlended(BEHAVIOR_BLENDING_AVERAGE);

    firstBehChild .Run(&LedObjs[0]);
    secondBehChild.Run(&LedObjs[0]);

    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, HalfOn, FullOn);
}

TEST(LedBehaviorTests, AdditionBlendingWorks)
{
    CLedBehaviorChild firstBehChild (NumLeds, FirstIndex, LastIndex, HalfOn);
    CLedBehaviorChild secondBehChild(NumLeds, FirstIndex, LastIndex, OneQuarterOn);
    secondBehChild.Set_IsBlended(BEHAVIOR_BLENDING_ADDITION);

    firstBehChild .Run(&LedObjs[0]);
    secondBehChild.Run(&LedObjs[0]);

    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, ThreeQuartersOn, HalfOn);
}

TEST(LedBehaviorTests, AdditionBlendingCapsAtFullOn)
{
    CLedBehaviorChild firstBehChild (NumLeds, FirstIndex, LastIndex, HalfOn);
    CLedBehaviorChild secondBehChild(NumLeds, FirstIndex, LastIndex, ThreeQuartersOn);
    secondBehChild.Set_IsBlended(BEHAVIOR_BLENDING_ADDITION);

    firstBehChild .Run(&LedObjs[0]);
    secondBehChild.Run(&LedObjs[0]);

    CheckLeds(FirstIndex, LastIndex, NumLeds, LedObjs, FullOn, HalfOn);
}

TEST(LedBehaviorTests, ChildDoesNotHaveDirectAccessToLeds)
{ /// @bug Not sure how to test this
}

