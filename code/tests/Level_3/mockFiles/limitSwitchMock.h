#ifndef __LIMITSWITCHMOCK_H
#define __LIMITSWITCHMOCK_H
#include "limitSwitch.h"
#include "LimitSwitchDriverMock.h"

class CLimSwMock: public CLimSwComp
{
    public:
        CLimSwMock(void);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

        void ForceAtLimit(void);
        void ForceNotAtLimit(void);

    private:
        bool m_MockLimitInput;
};
#endif // #ifndef __LIMITSWITCHMOCK_H
