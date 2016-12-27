#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "ledObj.h"

CLedObj* LedObj;

TEST_GROUP(LedObjTests)
{
    void setup()
    {
        mock().disable();
        LedObj = new CLedObj;
    }
    void teardown()
    {
        delete LedObj;
    }
};

TEST(LedObjTests, RgbLevelsClearedAfterConstructor)
{
    CHECK_EQUAL(0, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(0, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(0, LedObj->Get_Blue_PercentOn ());
}

TEST(LedObjTests, CanSetRgbLevels)
{
    uint8_t level = 10;

    LedObj->Set_Red_PercentOn  (level);
    LedObj->Set_Green_PercentOn(level);
    LedObj->Set_Blue_PercentOn (level);

    CHECK_EQUAL(level, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(level, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(level, LedObj->Get_Blue_PercentOn ());
}

TEST(LedObjTests, TurnOffFunWorks)
{
    uint8_t level = 10;

    LedObj->Set_Red_PercentOn  (level);
    LedObj->Set_Green_PercentOn(level);
    LedObj->Set_Blue_PercentOn (level);

    LedObj->TurnOff();

    CHECK_EQUAL(0, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(0, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(0, LedObj->Get_Blue_PercentOn ());

    LedObj->TurnOff();
}

TEST(LedObjTests, CannotSetAbove100Percent)
{
    uint8_t level = 101;

    LedObj->Set_Red_PercentOn  (level);
    LedObj->Set_Green_PercentOn(level);
    LedObj->Set_Blue_PercentOn (level);

    CHECK_EQUAL(100, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(100, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(100, LedObj->Get_Blue_PercentOn ());
}

