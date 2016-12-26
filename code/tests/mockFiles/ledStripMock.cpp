#include <CppUTestExt/MockSupport.h>
#include "ledStrip.h"

CLedStripComp::CLedStripComp(void)
{
}

void CLedStripComp::Execute(void)
{
    mock().actualCall("CLedStripComp::Execute");
}

void CLedStripComp::Initialize(void)
{
    mock().actualCall("CLedStripComp::Initialize");
}

