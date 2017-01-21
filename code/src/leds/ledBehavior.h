#ifndef __LEDBEHAVIOR_H
#define __LEDBEHAVIOR_H
#include "component.h"
#include "ledBehavior.h"
#include "ledObj.h"

typedef enum
{
    BEHAVIOR_ACTIVE = 0,
    BEHAVIOR_DONE
} Led_Behavior_t;

class CLedBehaviorComp : public CComponent
{
    public:
        CLedBehaviorComp(void);

        virtual void Execute(void);
        virtual void Initialize(void);

        Led_Behavior_t Get_Status(void);
        void         Set_NumLeds(uint16_t numLeds);

        virtual bool Is_Blended(void);
        void         Set_IsBlended(void);
        void         Clear_IsBlended(void);

    protected:
        bool           m_IsBlended;
        CLedObj*       m_LedArray;
        Led_Behavior_t m_Status;

}; // end - class CLedBehaviorComp : public CComponent
#endif // #ifndef __LEDBEHAVIOR_H

