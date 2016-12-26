#ifndef __LEDSTRIP_H
#define __LEDSTRIP_H
#include "component.h"
#include "capTouch.h"
#include "ledStripDriver.h"
#include "limitSwitch.h"

class CLedStripComp : public CComponent
{
    public:
        CLedStripComp(CLedStripDriver* LedStripDriver,  CCapTouchComp* CapTouch, CLimSwComp* Closed_LimSw, CLimSwComp* Opened_LimSw);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        CLedStripDriver* m_LedStripDriver;
        CCapTouchComp*   m_CapTouch;
        CLimSwComp*      m_Closed_LimSw;
        CLimSwComp*      m_Opened_LimSw;
}; // end - class CLedStripComp : public CComponent
#endif // #ifndef __LEDSTRIP_H

