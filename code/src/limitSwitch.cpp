#include "limitSwitch.h"

CLimSwComp::CLimSwComp(CLimSwDriver* limSwDriver, uint8_t Lo_CutOff, uint8_t Hi_Cutoff, uint8_t bufferSize)
{
    m_LimSwDriver = limSwDriver;
    m_Lo_Cutoff   = Lo_CutOff;
    m_Hi_Cutoff   = Hi_Cutoff;
    m_BufferSize  = bufferSize;
    m_LastOutput  = false;
    Initialize();
}

void CLimSwComp::Execute(void)
{
    Filter_Input(m_LimSwDriver->SampleInput());
}

void CLimSwComp::Initialize(void)
{
    m_FilteredInput = 0;
}

bool CLimSwComp::At_Limit(void)
{
    if (m_FilteredInput >= m_Hi_Cutoff) m_LastOutput = true;
    if (m_FilteredInput <= m_Lo_Cutoff) m_LastOutput = false;


    return m_LastOutput;
}

void CLimSwComp::Filter_Input(uint8_t input)
{
    if (input == 0) m_FilteredInput--;
    else            m_FilteredInput++;

    if (m_FilteredInput < 0)            m_FilteredInput = 0;
    if (m_FilteredInput > m_BufferSize) m_FilteredInput = m_BufferSize;

    At_Limit(); // Needed to update the m_LastOutput variable

}

