#ifndef __LEDSTRIP_H
#define __LEDSTRIP_H
#include "component.h"
#include "ledStripDriver.h"
#include "scene.h"

class CLedStripComp : public CComponent
{
    public:
        CLedStripComp(CLedStripDriver* LedStripDriver, CSceneComp* FirstScene);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
        CLedStripDriver* m_LedStripDriver;
        CSceneComp*      m_FirstScene;
}; // end - class CLedStripComp : public CComponent
#endif // #ifndef __LEDSTRIP_H

