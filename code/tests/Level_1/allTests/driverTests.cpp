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
        void init_hardware(void);
};

void init_hardware(void)
{
}

TEST(DriverTests, canInheritFrom)
{
}

