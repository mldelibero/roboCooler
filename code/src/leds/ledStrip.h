#ifndef __LEDSTRIP_H
#define __LEDSTRIP_H
#include "component.h"
#include "ledObj.h"
#include "ledStripDriver.h"
#include "scene.h"

//!< @bug Need to see if I can dynamically allocate m_LedArray in the mcu to remove this define
#define NUM_LEDS    100

class CLedStripComp : public CComponent
{
    public:
        CLedStripComp(CLedStripDriver* LedStripDriver, CScene* FirstScene, CLedObj* LedObjArray);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual uint32_t Get_NumberOfScenes(void);
        virtual void     Add_Scene(CScene* NextScene);

    private:
        CLedStripDriver* m_LedStripDriver;
        uint8_t          m_NumScenes;
        CScene*          m_Scenes[10];
        CLedObj*         m_LedObjArray;
}; // end - class CLedStripComp : public CComponent
#endif // #ifndef __LEDSTRIP_H

