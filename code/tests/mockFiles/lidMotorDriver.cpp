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

