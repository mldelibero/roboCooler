#include <CppUTestExt/MockSupport.h>
#include "lidMotor.h"

volatile CLidMotorComp lidMotor;

CLidMotorComp::CLidMotorComp()
{
}

void CLidMotorComp::Initialize(void)
{
    mock().actualCall("CLidMotorComp::Initialize");
}

void CLidMotorComp::Execute(void)
{
}
