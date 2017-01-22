#ifndef __LEDBEHAVIOR_H
#define __LEDBEHAVIOR_H
#include "component.h"
#include "ledBehavior.h"
#include "ledObj.h"

#define BEH_DEF_PER_MS  50 // 20Hz

typedef enum
{
    BEHAVIOR_ACTIVE = 0,
    BEHAVIOR_DONE
} Led_Behavior_t;

class CLedBehaviorComp : public CComponent
{
    public:
        CLedBehaviorComp(void);
        CLedBehaviorComp(uint32_t runTime_ms);

        virtual void Execute(void);
        virtual void Initialize(void);

        uint16_t       Get_NumLeds(void);
        Led_Behavior_t Get_Status(void);
        int32_t        Get_TimeLeft_ms(void);
        void           Set_NumLeds(uint16_t numLeds);

        virtual bool Is_Blended(void);
        void         Set_IsBlended(void);
        void         Clear_IsBlended(void);

        uint16_t     Get_FirstLedIndex(void);
        uint16_t     Get_LastLedIndex(void);
        void         Set_StartingPercentage(uint8_t startingPercentage);
        void         Set_EndingPercentage(uint8_t endingPercentage);

    protected:
        virtual void Update_Leds(void);
        void Set_Led(uint16_t led, CLedObj LedValue);

        uint8_t        m_EndingPercentage;
        bool           m_IsBlended;
        Led_Behavior_t m_Status;
        uint16_t       m_NumLeds;
        uint8_t        m_StartingPercentage;

    private:
        uint16_t RoundPercentageToIndex(float value);

        bool     m_RunForever;
        int32_t  m_RunTime_ms;
}; // end - class CLedBehaviorComp : public CComponent
#endif // #ifndef __LEDBEHAVIOR_H

