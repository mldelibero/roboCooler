#include "ledBehavior.h"
#include "ledObj.h"

CLedBehaviorComp::CLedBehaviorComp(uint16_t NumLeds)
{
    Initialize();
    m_NumLeds = NumLeds;
    m_FirstLedIndex = 0;
    m_LastLedIndex  = uint16_t(m_NumLeds-1);
}

CLedBehaviorComp::CLedBehaviorComp(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex)
{
    Initialize();
    m_NumLeds       = NumLeds;

    m_FirstLedIndex = (FirstIndex < m_NumLeds) ? FirstIndex : uint16_t(m_NumLeds - 1);
    m_LastLedIndex  = (LastIndex  < m_NumLeds) ? LastIndex  : uint16_t(m_NumLeds - 1);

    if (m_FirstLedIndex > m_LastLedIndex) m_IndicesWrap = true;
} // end -- Constructor

void CLedBehaviorComp::Execute(void)
{
    if (m_Status == BEHAVIOR_DONE) return;

    Update_Leds();

    if (m_RunForever == true);
    else
    {
        m_TimeLeft_ms -= Get_ComponentPeriod_ms();
        if (m_TimeLeft_ms <= 0)
        {
            m_Status = BEHAVIOR_DONE;
            m_TimeLeft_ms = 0;
        }
    }
}

void CLedBehaviorComp::Initialize(void)
{
    Set_ComponentPeriod_ms(BEH_DEF_PER_MS);

    m_BlendingType  = BEHAVIOR_BLENDING_NONE;
    m_IndicesWrap   = false;
    m_RunForever    = true;
    m_Status        = BEHAVIOR_ACTIVE;
    m_TimeLeft_ms   = -1;
}

void CLedBehaviorComp::Clear_IsBlended(void)
{
    m_BlendingType = BEHAVIOR_BLENDING_NONE;
}

uint16_t CLedBehaviorComp::Get_FirstLedIndex(void)
{
    return m_FirstLedIndex;
}

uint16_t CLedBehaviorComp::Get_LastLedIndex(void)
{
    return m_LastLedIndex;
}

uint16_t CLedBehaviorComp::Get_NumLeds(void)
{
    return m_NumLeds;
}

Led_Behavior_t CLedBehaviorComp::Get_Status(void)
{
    return m_Status;
}

int32_t CLedBehaviorComp::Get_TimeLeft_ms(void)
{
    return m_TimeLeft_ms;
}

bool CLedBehaviorComp::Is_Blended(void)
{ // If true -- will blend with the previous behavior
    return (m_BlendingType == BEHAVIOR_BLENDING_NONE) ? false : true;
}

void CLedBehaviorComp::Set_IsBlended(Led_BehaviorBlending_t BlendingType)
{
    m_BlendingType = BlendingType;
}

void CLedBehaviorComp::Set_Led(uint16_t led, CLedObj LedValue)
{
    // Don't operate if indexes were set incorrectly
    if ((m_IndicesWrap == false) && (led < Get_FirstLedIndex() || led > Get_LastLedIndex())) return;
    if ((m_IndicesWrap == true ) && (led < Get_FirstLedIndex() && led > Get_LastLedIndex())) return;

    CLedObj* LedArray = (CLedObj*)(m_Target_p);
    if (LedArray == NULL) return;

    if (m_BlendingType == BEHAVIOR_BLENDING_NONE)
    {
        LedArray[led] = LedValue;
    }

    else if (m_BlendingType == BEHAVIOR_BLENDING_AVERAGE)
    {
        uint8_t RedValue   = uint8_t(float(LedArray[led].Get_Red_PercentOn()   + LedValue.Get_Red_PercentOn  ())/2);
        uint8_t GreenValue = uint8_t(float(LedArray[led].Get_Green_PercentOn() + LedValue.Get_Green_PercentOn())/2);
        uint8_t BlueValue  = uint8_t(float(LedArray[led].Get_Blue_PercentOn()  + LedValue.Get_Blue_PercentOn ())/2);

        LedArray[led].Set_Red_PercentOn(RedValue);
        LedArray[led].Set_Green_PercentOn(GreenValue);
        LedArray[led].Set_Blue_PercentOn(BlueValue);
    }

    else if (m_BlendingType == BEHAVIOR_BLENDING_ADDITION)
    {
        uint8_t RedValue   = uint8_t(LedArray[led].Get_Red_PercentOn()   + LedValue.Get_Red_PercentOn());
        uint8_t GreenValue = uint8_t(LedArray[led].Get_Green_PercentOn() + LedValue.Get_Green_PercentOn());
        uint8_t BlueValue  = uint8_t(LedArray[led].Get_Blue_PercentOn()  + LedValue.Get_Blue_PercentOn());

        LedArray[led].Set_Red_PercentOn(RedValue);
        LedArray[led].Set_Green_PercentOn(GreenValue);
        LedArray[led].Set_Blue_PercentOn(BlueValue);
    }
}

void CLedBehaviorComp::Set_TimeoutValue(uint32_t RunTime_ms)
{
    m_RunForever  = false;
    m_TimeLeft_ms = RunTime_ms;
}

void CLedBehaviorComp::Update_Leds(void)
{ // Shows example of how to use this function
    CLedObj ledObj;

    for (uint16_t led = 0; led < m_NumLeds; led++)
    {
        Set_Led(led, ledObj);
    }
}

