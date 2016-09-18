#ifndef __CAPTOUCHMOCK_H
#define __CAPTOUCHMOCK_H
#include "limitSwitch.h"
class CCapTouchMock: public CCapTouchComp
{
    public:
        CCapTouchMock();

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool Get_TouchDetected(void);

        void ForceTouchDetected(void);
        void ForceTouchNotDetected(void);

    private:
        bool m_MockTouchDetected;

};
#endif // #ifndef __CAPTOUCHMOCK_H
