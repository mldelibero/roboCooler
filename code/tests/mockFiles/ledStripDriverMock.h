#ifndef __LED_STRIP_DRIVER_MOCK_H
#define __LED_STRIP_DRIVER_MOCK_H
#include "ledStripDriver.h"
class CLedStripDriverMock : public CLedStripDriver
{
    public:
        CLedStripDriverMock(void);

        ~CLedStripDriverMock(void);

        void Initialize_Hardware(void);
        void Update(CLedObj* LedObjArray);

    private:
};
#endif // #define __LED_STRIP_DRIVER_MOCK_H

