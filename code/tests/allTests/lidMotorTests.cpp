#include <CppUTest/TestHarness.h>
//#include <CppUTestExt/MockSupport.h>
//#include "CppUTestExt/MockSupport_c.h"

/* List of driver features needed:
 *  *timer off at startup
 *  *Motor stops after a timeout

 * List of features needed:
 *  *Initialize peripheral and module
 *  *Motor stops if either limit switch is tripped
 *  *Motor opens lid if down LS is active and cap sense is tripped
 *  *Motor opens and then closes the whole way at initialization

 * Nice to have features:
 *  *Motor can open lid a couple inches and then close it after a certain amount of time
 *
 */

TEST_GROUP(LidMotorTests)
{
    void setup()
    {
//        mock().disable();
//        Init_Timers();
//        mock().enable();
    }
    void teardown()
    {
//        mock().checkExpectations();
//        mock().clear();
    }
}; // end - TEST_GROUP(LidMotorTests)

TEST(LidMotorTests, TestInitCalls)
{
}

