#ifndef __CAPTOUCHMOCK_H
#define __CAPTOUCHMOCK_H
#include "capTouch.h"
class CCapTouchMock: public CCapTouchComp
{
    public:
        CCapTouchMock();

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool Is_TouchDetected(void);

        void ForceTouchDetected(void);
        void ForceTouchNotDetected(void);

    private:
        bool m_Mock_TouchDetected;

};
#endif // #ifndef __CAPTOUCHMOCK_H
