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

typedef enum
{
    BEHAVIOR_BLENDING_NONE    = 0,
    BEHAVIOR_BLENDING_AVERAGE,
    BEHAVIOR_BLENDING_ADDITION
} Led_BehaviorBlending_t;

class CLedBehaviorComp : public CComponent
{
    public:
        CLedBehaviorComp(uint16_t NumLeds);
        CLedBehaviorComp(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex);

        virtual void Execute(void);
        virtual void Initialize(void);

        void           Clear_IsBlended(void);
        uint16_t       Get_FirstLedIndex(void);
        uint16_t       Get_LastLedIndex(void);
        uint16_t       Get_NumLeds(void);
        Led_Behavior_t Get_Status(void);
        int32_t        Get_TimeLeft_ms(void);
        virtual bool   Is_Blended(void);
        void           Set_IsBlended(Led_BehaviorBlending_t BlendingType);
        void           Set_TimeoutValue(uint32_t RunTime_ms);

    private:
        Led_BehaviorBlending_t m_BlendingType;
        bool                   m_RunForever;
        int32_t                m_TimeLeft_ms;

    protected:
        void         Set_Led(uint16_t led, CLedObj LedValue);
        virtual void Update_Leds(void);

        uint16_t       m_FirstLedIndex;
        bool           m_IndicesWrap;
        uint16_t       m_LastLedIndex;
        uint16_t       m_NumLeds;
        Led_Behavior_t m_Status;
}; // end - class CLedBehaviorComp : public CComponent
#endif // #ifndef __LEDBEHAVIOR_H
