#include "ledObj.h"

CLedObj::CLedObj()
{
    m_Red_PercentOn   = 0;
    m_Green_PercentOn = 0;
    m_Blue_PercentOn  = 0;
}


uint8_t CLedObj::Get_Red_PercentOn(void)
{
    return m_Red_PercentOn;
}

uint8_t CLedObj::Get_Green_PercentOn(void)
{
    return m_Green_PercentOn;
}

uint8_t CLedObj::Get_Blue_PercentOn(void)
{
    return m_Blue_PercentOn;
}

void CLedObj::Set_Red_PercentOn(uint8_t level)
{
    if (level > 100) level = 100;
    m_Red_PercentOn = level;
}

void CLedObj::Set_Green_PercentOn(uint8_t level)
{
    if (level > 100) level = 100;
    m_Green_PercentOn = level;
}

void CLedObj::Set_Blue_PercentOn(uint8_t level)
{
    if (level > 100) level = 100;
    m_Blue_PercentOn = level;
}

void CLedObj::TurnOff(void)
{
    m_Red_PercentOn   = 0;
    m_Green_PercentOn = 0;
    m_Blue_PercentOn  = 0;
}

