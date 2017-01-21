#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"
#include "ledObj.h"

// -- Defines -------------------------------------------------------------
#define RED_LED_PERCENT_ON   40
#define GREEN_LED_PERCENT_ON 50
#define BLUE_LED_PERCENT_ON  70

#define NUM_LEDS             10
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
// -- Tests ---------------------------------------------------------------
TEST_GROUP(LedBehaviorTests)
{
    void setup()
    {
        mock().disable();
        LedBehavior      = new CLedBehaviorComp;
        LedBehaviorChild = new CLedBehaviorChild;
        LedObjs          = new CLedObj[NUM_LEDS];
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

TEST(LedBehaviorTests, NoBlendingPassesColorsThrough)
{
    LedBehaviorChild->Set_NumLeds(NUM_LEDS);
    LedBehaviorChild->Run(&LedObjs[0]);

    for (int led = 0; led < NUM_LEDS; led++)
    {
        CHECK_EQUAL(RED_LED_PERCENT_ON  , LedObjs[led].Get_Red_PercentOn());
        CHECK_EQUAL(GREEN_LED_PERCENT_ON, LedObjs[led].Get_Green_PercentOn());
        CHECK_EQUAL(BLUE_LED_PERCENT_ON , LedObjs[led].Get_Blue_PercentOn());
    }
}
