#include "ledObj.h"

CLedObj::CLedObj()
{
    m_Red_PercentOn   = 0;
    m_Green_PercentOn = 0;
    m_Blue_PercentOn  = 0;
}

CLedObj::CLedObj(float RedPercentOn, float GreenPercentOn, float BluePercentOn)
{
    Set_Red_PercentOn(RedPercentOn);
    Set_Green_PercentOn(GreenPercentOn);
    Set_Blue_PercentOn(BluePercentOn);
}

float CLedObj::Get_Red_PercentOn(void)
{
    return m_Red_PercentOn;
}

float CLedObj::Get_Green_PercentOn(void)
{
    return m_Green_PercentOn;
}

float CLedObj::Get_Blue_PercentOn(void)
{
    return m_Blue_PercentOn;
}

void CLedObj::Set_Red_PercentOn(float level)
{
    if (level > 100) level = 100;
    m_Red_PercentOn = level;
}

void CLedObj::Set_Green_PercentOn(float level)
{
    if (level > 100) level = 100;
    m_Green_PercentOn = level;
}

void CLedObj::Set_Blue_PercentOn(float level)
{
    if (level > 100) level = 100;
    m_Blue_PercentOn = level;
}

void CLedObj::Set_All_PercentOn(float RedPercentOn, float GreenPercentOn, float BluePercentOn)
{
    Set_Red_PercentOn(RedPercentOn);
    Set_Green_PercentOn(GreenPercentOn);
    Set_Blue_PercentOn(BluePercentOn);
}

void CLedObj::TurnOff(void)
{
    m_Red_PercentOn   = 0;
    m_Green_PercentOn = 0;
    m_Blue_PercentOn  = 0;
}

