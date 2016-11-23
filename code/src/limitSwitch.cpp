#include "limitSwitch.h"

CLimSwComp::CLimSwComp(CLimSwDriver* limSwDriver)
{
    m_LimSwDriver = limSwDriver;
}

void CLimSwComp::Execute(void)
{
}

void CLimSwComp::Initialize(void)
{
}

bool CLimSwComp::At_Limit(void)
{
    return 0;
}

