#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"

CLedBehaviorComp* LedBehavior;

TEST_GROUP(LedBehaviorTests)
{
    void setup()
    {
        mock().disable();
        LedBehavior = new CLedBehaviorComp;
    }
    void teardown()
    {
        delete LedBehavior;
    }
};

TEST(LedBehaviorTests, StatusReturnsActiveAfterConstructor)
{
    CHECK_EQUAL(BEHAVIOR_ACTIVE, LedBehavior->Get_Status());
}

class CLedBehaviorChild : public CLedBehaviorComp
{
    public:
        CLedBehaviorChild()
        {
        }

        void Execute(void)
        {
        }

        void Initialize(void)
        {
        }

        void Force_DoneConditionMet(void)
        {
            m_Status = BEHAVIOR_DONE;
        }
}; // end - class CLedBehaviorChild : public CLedBehaviorComp

TEST(LedBehaviorTests, CompliesWithChildsEndConditionFun)
{
    CLedBehaviorChild BehChild;
    BehChild.Force_DoneConditionMet();

    CHECK_EQUAL(BEHAVIOR_DONE, BehChild.Get_Status());
}

