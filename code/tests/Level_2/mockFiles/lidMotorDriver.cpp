#include <CppUTestExt/MockSupport.h>
#include "lidMotorDriver.h"

void init_lidMotorDriver(void)
{
    mock().actualCall("init_lidMotorDriver");
}

void motorStop(void)
{
    mock().actualCall("motorStop");
}

void lidMotor_Open(void)
{
    mock().actualCall("lidMotor_Open");
}

void lidMotor_Close(void)
{
    mock().actualCall("lidMotor_Close");
}
