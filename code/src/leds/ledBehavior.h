#ifndef __LEDBEHAVIOR_H
#define __LEDBEHAVIOR_H
#include "component.h"
#include "ledBehavior.h"

class CLedBehaviorComp : public CComponent
{
    public:
        CLedBehaviorComp(void);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
}; // end - class CLedBehaviorComp : public CComponent
#endif // #ifndef __LEDBEHAVIOR_H

