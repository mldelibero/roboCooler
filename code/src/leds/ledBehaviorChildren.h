#ifndef __LEDBEHAVIOR_CHILDREN_H
#define __LEDBEHAVIOR_CHILDREN_H
#include "component.h"
#include "ledBehavior.h"
#include "ledObj.h"

class CLedBeh_Solid : public CLedBehaviorComp
{
    public:
        CLedBeh_Solid(CLedObj ledColor);
        CLedBeh_Solid(uint32_t runTime_ms);

    protected:
        CLedObj m_LedColor;
        virtual void Update_Leds(void);
}; // end - class CLedBeh_Solid : public CLedBehaviorComp
#endif // #ifndef __LEDBEHAVIOR_CHILDREN_H

