#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledBehavior.h"

// -- Class definition ----------------------------------------------------
class CLedBehaviorChild : public CLedBehaviorComp
{
    public:
        CLedBehaviorChild()
        {
        }

        void Execute(void)
        {
        }

        void Force_DoneConditionMet(void)
        {
            m_Status = BEHAVIOR_DONE;
        }
}; // end - class CLedBehaviorChild : public CLedBehaviorComp

// -- Variables -----------------------------------------------------------
CLedBehaviorComp*  LedBehavior;
CLedBehaviorChild* LedBehaviorChild;

// -- Tests ---------------------------------------------------------------
TEST_GROUP(LedBehaviorTests)
{
    void setup()
    {
        mock().disable();
        LedBehavior      = new CLedBehaviorComp;
        LedBehaviorChild = new CLedBehaviorChild;

    }
    void teardown()
    {
        delete LedBehavior;
        delete LedBehaviorChild;
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

/*
 * Necessary Tests:
 *
 * Is_blended fun
 */

