#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "timer.h"
#include "component.h"

TEST_GROUP(ComponentTests)
{
    void setup()
    {
        mock().disable();
        Init_Timers(); // Resets the timer module
    }
    void teardown()
    {
    }
};

TEST(ComponentTests, ConstructorAllocatesTimer)
{
    CComponent comp;
    CHECK(Get_NumTimersAllocated() > 0);
}

TEST(ComponentTests, TimerIndexIsSaved)
{
    CComponent comp1, comp2;
    CHECK_EQUAL(0, comp1.Get_TimerIndex());
    CHECK_EQUAL(1, comp2.Get_TimerIndex());
}

TEST(ComponentTests, RunOnlyExecutesWhenTimerExpired)
{
    CComponent comp;

    Set_TimerValue(comp.Get_TimerIndex(), 1);
    CHECK_EQUAL(false, comp.Run());

    Set_TimerValue(comp.Get_TimerIndex(), 0);
    CHECK_EQUAL(true, comp.Run());
}

TEST(ComponentTests, TimerAtZeroAfterInitialization)
{
    CComponent comp;
    CHECK_EQUAL(0, Get_TimerValue(comp.Get_TimerIndex()));
}

TEST(ComponentTests, RunResetsTimerOnlyIfExpired)
{
    CComponent comp;
    Set_TimerValue(comp.Get_TimerIndex(), 1);
    comp.Run();
    CHECK_EQUAL(1, Get_TimerValue(comp.Get_TimerIndex()));

    Set_TimerValue(comp.Get_TimerIndex(), 0);
    comp.Run();
    CHECK_EQUAL(comp.Get_TimerResetValue(), Get_TimerValue(comp.Get_TimerIndex()));
}

TEST(ComponentTests, DefaultTimerResetValue_100ms)
{
    CComponent comp;
    CHECK_EQUAL(100, comp.Get_TimerResetValue());
}

TEST(ComponentTests, CanSetTimerResetValue)
{
    CComponent comp(10);
    CHECK_EQUAL(10, comp.Get_TimerResetValue());
}

// Execute function will be overwritten by children
TEST(ComponentTests, BaseExecuteFunRunInBaseClass)
{
    CComponent comp;

    CHECK_EQUAL(false, comp.Has_BaseExFunRun());
    comp.Run();
    CHECK_EQUAL(true, comp.Has_BaseExFunRun());

}

TEST(ComponentTests, InheritedExecuteFunSameAsBaseIfNotUpdated)
{
    class CInheritedComp: public CComponent
    {
        public:
            CInheritedComp() {}
    };

    CInheritedComp comp;

    CHECK_EQUAL(false, comp.Has_BaseExFunRun());
    comp.Run();
    CHECK_EQUAL(true, comp.Has_BaseExFunRun());
}

class CInheritedComp2: public CComponent
{
    public:
        CInheritedComp2();

    private:
        virtual void Execute(void);
};

CInheritedComp2::CInheritedComp2()
{
}

void CInheritedComp2::Execute(void)
{}

TEST(ComponentTests, InheritedExecuteDiffThanAsBaseIfUpdated)
{

    CInheritedComp2 comp;

    CHECK_EQUAL(false, comp.Has_BaseExFunRun());
    comp.Run();
    CHECK_EQUAL(false, comp.Has_BaseExFunRun());
}

TEST(ComponentTests, BaseConstructorRunsInInheritedClass)
{
    CInheritedComp2 comp;
    CHECK_EQUAL(100, comp.Get_TimerResetValue());
}

