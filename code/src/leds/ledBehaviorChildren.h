#ifndef __LEDBEHAVIOR_CHILDREN_H
#define __LEDBEHAVIOR_CHILDREN_H
#include "component.h"
#include "ledBehavior.h"
#include "ledObj.h"

class CLedBeh_Solid : public CLedBehaviorComp
{
    public:
        CLedBeh_Solid(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex, CLedObj LedObj);

    protected:
        CLedObj m_LedObj;
        virtual void Update_Leds(void);
}; // end - class CLedBeh_Solid : public CLedBehaviorComp

class CLedBeh_MovingBand : public CLedBehaviorComp
{
    public:
        CLedBeh_MovingBand(uint16_t NumLeds, uint16_t FirstIndex, uint16_t LastIndex, CLedObj LedObj);

    protected:
        uint16_t m_LedOffset;
        CLedObj  m_LedObj;
        virtual void Update_Leds(void);
}; // end - class CLedBeh_MovingBand : public CLedBehaviorComp
#endif // #ifndef __LEDBEHAVIOR_CHILDREN_H

