#ifndef __LIMITSWITCHMOCK_H
#define __LIMITSWITCHMOCK_H
#include "limitSwitch.h"
#include "LimitSwitchDriver.h"

class CLimSwMock: public CLimSwComp
{
    public:
        CLimSwMock(CLimSwDriver* limSwDriver, uint8_t bufferSize, uint8_t filterCutoff);
        //CLimSwMock(CLimSwDriver* limSwDriver) : CLimSwComp(limSwDriver);

        virtual void Execute(void);
        virtual void Initialize(void);

        virtual bool At_Limit(void);

        void ForceAtLimit(void);
        void ForceNotAtLimit(void);

    private:
        bool m_MockLimitInput;
        CLimSwDriver* m_LimSwDriver;

};
#endif // #ifndef __LIMITSWITCHMOCK_H
