#include "limitSwitch.h"

CLimSwComp::CLimSwComp(sampInFun_t sampleIn_fpt)
{
    SampleInput_fpt = sampleIn_fpt;
}

void CLimSwComp::Execute(void)
{
    SampleInput_fpt();
}

void CLimSwComp::Initialize(void)
{
}

bool CLimSwComp::At_Limit(void)
{
    return 0;
}

