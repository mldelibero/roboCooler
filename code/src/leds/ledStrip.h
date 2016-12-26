#ifndef __LEDSTRIP_H
#define __LEDSTRIP_H
#include "component.h"
#include "capTouch.h"
#include "limitSwitch.h"

class CLedStripComp : public CComponent
{
    public:
        CLedStripComp(CCapTouchComp* CapTouch, CLimSwComp* Closed_LimSw, CLimSwComp* Opened_LimSw);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        CCapTouchComp* m_CapTouch;
        CLimSwComp*    m_Closed_LimSw;
        CLimSwComp*    m_Opened_LimSw;
}; // end - class CLedStripComp : public CComponent
#endif // #ifndef __LEDSTRIP_H

