#ifndef __LED_STRIP_DRIVER_H
#define __LED_STRIP_DRIVER_H
#include "CDriver.h"
#include "ledObj.h"

class CLedStripDriver : CDriver
{
    public:
        CLedStripDriver(CLedObj* LedObjArray, uint16_t NumLeds);
        virtual ~CLedStripDriver(void);

        void Initialize_Hardware(void);
        void Update(void);

    protected:
        CLedObj* m_LedObjArray;
        uint16_t m_NumLeds;
}; // end -- class CLedStripDriver

#endif //#ifndef __LED_STRIP_DRIVER_H

