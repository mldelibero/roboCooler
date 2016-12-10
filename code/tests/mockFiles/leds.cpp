#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "leds.h"

CLedComp::CLedComp()
{

}

void CLedComp::Execute(void)
{
    mock().actualCall("CLedComp:Execute");
}

void CLedComp::Initialize(void)
{
    mock().actualCall("CLedComp:Initialize");
}

void CLedComp::BypassBootSequence(void)
{
    mock().actualCall("CLedComp::BypassBootSequence");
}

bool CLedComp::Is_InBootMode(void)
{
    mock().actualCall("CLedComp::Is_InBootMode");
    return false;
}

uint8_t CLedComp::Get_BootLedStates(void)
{
    mock().actualCall("CLedComp::Get_BootLedStates");
    return 0;
}

int32_t CLedComp::Get_BootPeriod(void)
{
    mock().actualCall("CLedComp::Get_BootPeriod");
    return 0;
}

uint8_t CLedComp::Get_LedStates(void)
{
    mock().actualCall("CLedComp::Get_LedStates");
    return 0;
}

int32_t CLedComp::Get_TotalRunsInBoot(void)
{
    mock().actualCall("CLedComp::Get_TotalRunsInBoot");
    return 0;
}

void CLedComp::WriteAllLedStates(uint8_t ledStates)
{
    mock().actualCall("CLedComp::WriteAllLedStates");
    if (ledStates) return;
}

