#ifndef __LEDSTRIP_H
#define __LEDSTRIP_H
#include "component.h"
#include "ledStripDriver.h"
#include "scene.h"

#define NUM_LEDS    100

class CLedStripComp : public CComponent
{
    public:
        CLedStripComp(CLedStripDriver* LedStripDriver, CSceneComp* FirstScene);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual uint32_t Get_NumberOfScenes(void);
        virtual void     Add_Scene(CSceneComp* NextScene);

    private:
        CLedStripDriver* m_LedStripDriver;
        uint8_t          m_NumScenes;
        CSceneComp*      m_Scenes[10];
}; // end - class CLedStripComp : public CComponent
#endif // #ifndef __LEDSTRIP_H

