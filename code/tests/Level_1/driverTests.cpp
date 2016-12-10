#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

TEST_GROUP(DriverTests)
{
    void setup()
    {
        mock().disable();
    }
    void teardown()
    {
    }
};

class childDriver
{
    public:
        childDriver(void);
        void Initialize_Hardware(void);
};

void Initialize_Hardware(void)
{
}

TEST(DriverTests, canInheritFrom)
{
}

