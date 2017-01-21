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
        mock().checkExpectations();
        mock().clear();
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
    CHECK_EQUAL(comp.Get_ComponentPeriod_ms(), Get_TimerValue(comp.Get_TimerIndex()));
}

TEST(ComponentTests, DefaultTimerResetValue_100ms)
{
    CComponent comp;
    CHECK_EQUAL(100, comp.Get_ComponentPeriod_ms());
}

TEST(ComponentTests, CanSetTimerResetValue)
{
    CComponent comp(10);
    CHECK_EQUAL(10, comp.Get_ComponentPeriod_ms());
}

class CInheritedComp: public CComponent
{
    public:
        CInheritedComp()
        {
            m_ExecuteRun = false;
            Initialize();
        }

        void* Get_Target_p(void)
        {
            return m_Target_p;
        }

        bool m_ExecuteRun;
        bool m_Initalized;

    private:
        virtual void Execute(void)
        {
            m_ExecuteRun = true;
            mock().actualCall("CInheritedComp::Execute").withParameter("m_Target_p", m_Target_p);
        }

        virtual void Initialize(void)
        {
            m_Initalized = true;
        }
};

TEST(ComponentTests, BaseConstructorRunsInInheritedClass)
{
    CInheritedComp comp;
    CHECK_EQUAL(100, comp.Get_ComponentPeriod_ms());
}

TEST(ComponentTests, RunCallsExecuteFun)
{
    CInheritedComp comp;
    comp.Run();
    CHECK(comp.m_ExecuteRun);
}

TEST(ComponentTests, RunWithPointerPassesItToExecute)
{
    CInheritedComp comp;
    uint32_t var = 0;

    mock().enable();
    mock().expectOneCall("CInheritedComp::Execute").withParameter("m_Target_p", &var);
    comp.Run((void*)(&var));
}

TEST(ComponentTests, RunWithPointerNullsPointerAfterRunning)
{
    CInheritedComp comp;
    uint32_t var = 0;
    comp.Run((void*)(&var));

    POINTERS_EQUAL(NULL, comp.Get_Target_p());
}

TEST(ComponentTests, RunWithPointerOnlyExecutesWhenTimerExpired)
{
    CComponent comp;
    uint32_t var = 0;

    Set_TimerValue(comp.Get_TimerIndex(), 1);
    CHECK_EQUAL(false, comp.Run((void*)&var));

    Set_TimerValue(comp.Get_TimerIndex(), 0);
    CHECK_EQUAL(true, comp.Run((void*)&var));
}

TEST(ComponentTests, RunWithPointerResetsTimerOnlyIfExpired)
{
    CComponent comp;
    uint32_t var = 0;

    Set_TimerValue(comp.Get_TimerIndex(), 1);
    comp.Run((void*)&var);
    CHECK_EQUAL(1, Get_TimerValue(comp.Get_TimerIndex()));

    Set_TimerValue(comp.Get_TimerIndex(), 0);
    comp.Run((void*)&var);
    CHECK_EQUAL(comp.Get_ComponentPeriod_ms(), Get_TimerValue(comp.Get_TimerIndex()));
}

