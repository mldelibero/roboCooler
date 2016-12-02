#include "limitSwitch.h"

CLimSwComp::CLimSwComp(CLimSwDriver* limSwDriver, uint8_t bufferSize, uint8_t filterCutoff)
{
    m_LimSwDriver  = limSwDriver;
    m_BufferSize   = bufferSize;
    m_FilterCutoff = filterCutoff;
    Initialize();
}

void CLimSwComp::Execute(void)
{
    uint8_t lastInput = m_LimSwDriver->SampleInput();
    Filter_Input(lastInput);
}

void CLimSwComp::Initialize(void)
{
    m_FilteredInput = 0;
}

bool CLimSwComp::At_Limit(void)
{
    if (m_FilteredInput >= m_FilterCutoff) return true;
    else                                   return false;
}

void CLimSwComp::Filter_Input(uint8_t input)
{
    if (input == 0) m_FilteredInput--;
    else            m_FilteredInput++;

    if (m_FilteredInput < 0)            m_FilteredInput = 0;
    if (m_FilteredInput > m_BufferSize) m_FilteredInput = m_BufferSize;
}

