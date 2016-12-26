#ifndef __LEDSTRIP_H
#define __LEDSTRIP_H
#include "component.h"

class CLedStripComp : public CComponent
{
    public:
        CLedStripComp();

        virtual void Execute(void);
        virtual void Initialize(void);
}; // end - class CLedStripComp : public CComponent
#endif // #ifndef __LEDSTRIP_H

