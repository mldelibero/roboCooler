#include "lidMotorDriver.h"
#include "lidMotor.h"

CLidMotorComp lidMotor;

CLidMotorComp::CLidMotorComp()
{
}
void CLidMotorComp::Execute(void)
{
}

void CLidMotorComp::Initialize(void)
{
    init_lidMotorDriver();
}

