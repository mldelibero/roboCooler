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
    float level = 10;

    LedObj->Set_Red_PercentOn  (level);
    LedObj->Set_Green_PercentOn(level);
    LedObj->Set_Blue_PercentOn (level);

    CHECK_EQUAL(level, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(level, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(level, LedObj->Get_Blue_PercentOn ());
}

TEST(LedObjTests, TurnOffFunWorks)
{
    float level = 10;

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
    float level = 101;

    LedObj->Set_Red_PercentOn  (level);
    LedObj->Set_Green_PercentOn(level);
    LedObj->Set_Blue_PercentOn (level);

    CHECK_EQUAL(100, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(100, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(100, LedObj->Get_Blue_PercentOn ());
}

TEST(LedObjTests, CanSetAllThreePercentagesAtOnce)
{
    float Red   = 20;
    float Green = 40;
    float Blue  = 60;

    LedObj->Set_All_PercentOn(Red, Green, Blue);

    CHECK_EQUAL(Red  , LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(Green, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(Blue , LedObj->Get_Blue_PercentOn ());
}

TEST(LedObjTests, ObjCeilingsWhenSettingAllThreePercentagesAtOnce)
{
    float level = 110;

    LedObj->Set_All_PercentOn(level, level, level);

    CHECK_EQUAL(100, LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(100, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(100, LedObj->Get_Blue_PercentOn ());
}

float RedPercentOn   = 0;
float GreenPercentOn = 0;
float BluePercentOn  = 0;

TEST_GROUP(LedObjAltConstructorTests)
{
    void setup()
    {
        mock().disable();
        RedPercentOn   = 20;
        GreenPercentOn = 40;
        BluePercentOn  = 60;
        LedObj = new CLedObj(RedPercentOn, GreenPercentOn, BluePercentOn);
    }
    void teardown()
    {
        delete LedObj;
    }
};

TEST(LedObjAltConstructorTests, CanSetValueInConstructor)
{
    CHECK_EQUAL(RedPercentOn  , LedObj->Get_Red_PercentOn  ());
    CHECK_EQUAL(GreenPercentOn, LedObj->Get_Green_PercentOn());
    CHECK_EQUAL(BluePercentOn , LedObj->Get_Blue_PercentOn ());
}

TEST(LedObjAltConstructorTests, ObjCelingsValuesWhenSetInConstructor)
{
    CLedObj obj(110,110,110);
    CHECK_EQUAL(100, obj.Get_Red_PercentOn  ());
    CHECK_EQUAL(100, obj.Get_Green_PercentOn());
    CHECK_EQUAL(100, obj.Get_Blue_PercentOn ());
}

