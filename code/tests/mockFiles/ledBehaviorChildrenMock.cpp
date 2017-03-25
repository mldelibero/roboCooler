#include <CppUTestExt/MockSupport.h>

#include "ledBehavior.h"
#include "ledBehaviorChildren.h"
#include "ledBehaviorChildrenMock.h"
#include "ledObj.h"

static uint16_t Mock_NumLeds    = 10;
static uint16_t Mock_FirstIndex = 0;
static uint16_t Mock_LastIndex  = 9;
static CLedObj  Mock_LedObj;

//--- Compile mock version
CLedBeh_Solid::CLedBeh_Solid(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex, CLedObj LedObj) : CLedBehaviorComp(NumLeds, FirstIndex, LastIndex)
{
    if (NumLeds)                    return;
    if (FirstIndex)                 return;
    if (LastIndex)                  return;
    if (LedObj.Get_Red_PercentOn()) return;
}

void CLedBeh_Solid::Update_Leds(void) {}

//--- Compile abstract mock version with output control
CLedBeh_SolidMock::CLedBeh_SolidMock(void) : CLedBehaviorComp(Mock_NumLeds, Mock_FirstIndex, Mock_LastIndex)
{
}

void CLedBeh_SolidMock::Update_Leds(void) {}

