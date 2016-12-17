#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "CppUTestExt/MockSupport_c.h"

#include "capTouch.h"
#include "capTouchDriverMock.h"


/**
 * * List of tests needed:
 */

CCapTouchDriverMock* CapTouchDriver;
CCapTouchComp*       CapTouch;

TEST_GROUP(CapTouchTests)
{
    void setup()
    {
        mock().disable();
        CapTouchDriver = new CCapTouchDriverMock;
        CapTouch       = new CCapTouchComp(CapTouchDriver);
    }
    void teardown()
    {
        delete CapTouch;
        delete CapTouchDriver;

        mock().checkExpectations();
        mock().clear();
    }
}; // end - TEST_GROUP(CapTouchTests)

TEST(CapTouchTests, PollSensorWhenDataIsReady)
{

    mock().enable();
    CapTouchDriver->Set_MockDataReady();
    mock().expectOneCall("CCapTouchDriver::Is_DataReady");
    mock().expectOneCall("CCapTouchDriver::Read");

    CapTouch->Run();
}

TEST(CapTouchTests, DoesNotPollSensorWhenDataIsNotReady)
{

    mock().enable();
    CapTouchDriver->Clear_MockDataReady();
    mock().expectOneCall("CCapTouchDriver::Is_DataReady");

    CapTouch->Run();
}

TEST(CapTouchTests, ReturnsTouchDetected_IfAppropriate)
{
    CapTouchDriver->Set_MockDataReady();
    CapTouchDriver->Set_MockTouchDetected();
    CapTouch->Run();
    CHECK_EQUAL(true, CapTouch->Is_TouchDetected());
}

TEST(CapTouchTests, DoesNotReturnsTouchDetected_IfNotAppropriate)
{
    CapTouchDriver->Set_MockDataReady();
    CapTouchDriver->Clear_MockTouchDetected();
    CapTouch->Run();
    CHECK_EQUAL(false, CapTouch->Is_TouchDetected());
}

TEST(CapTouchTests, TouchNotDetectedByDefault)
{
    CHECK_EQUAL(false, CapTouch->Is_TouchDetected());
}

TEST(CapTouchTests, TouchNotClearedUntilReadByCustomers)
{
    CapTouchDriver->Set_MockDataReady();

    CapTouchDriver->Set_MockTouchDetected();
    CapTouch->Run();

    CapTouchDriver->Clear_MockTouchDetected();
    CapTouch->Run();

    CHECK_EQUAL(true , CapTouch->Is_TouchDetected());
    CHECK_EQUAL(false, CapTouch->Is_TouchDetected());
}

// capTouch -- set register 5E = 3
// * Combines all 12 electrodes into a single sensor
// ** ECR->ELEPROX_EN = 0X3

