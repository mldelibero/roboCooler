#ifndef __LED_STRIP_DRIVER_H
#define __LED_STRIP_DRIVER_H
#include "CDriver.h"

class CLedStripDriver : CDriver
{
    public:
        CLedStripDriver();
        virtual ~CLedStripDriver(void);

        void Initialize_Hardware(void);

    protected:
}; // end -- class CLedStripDriver

#endif //#ifndef __LED_STRIP_DRIVER_H

