#ifndef __CAP_TOUCH_DRIVER_MOCK_H
#define __CAP_TOUCH_DRIVER_MOCK_H

#include "capTouchDriver.h"
class CCapTouchDriverMock : public CCapTouchDriver
{
    public:
        CCapTouchDriverMock(void);
        ~CCapTouchDriverMock(void);

        void Initialize_Hardware(void);

        void Clear_MockDataReady(void);
        void Set_MockDataReady(void);
        bool Is_DataReady(void);

        void Clear_MockTouchDetected(void);
        void Set_MockTouchDetected(void);
        uint16_t ReadFromDevice(void);

    private:
        BitAction m_MockInputValue;
        bool m_Mock_DataReady;
        bool m_Mock_TouchDetected;
};
#endif // #ifndef __CAP_TOUCH_DRIVER_MOCK_H

