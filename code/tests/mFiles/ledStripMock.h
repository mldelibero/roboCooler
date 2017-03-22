#ifndef __LEDSTRIPMOCK_H
#define __LEDSTRIPMOCK_H
#include "ledStrip.h"

class CLedStripMock : public CLedStripComp
{
    public:
        CLedStripMock(void);

        virtual void Execute(void);
        virtual void Initialize(void);

    private:
};
#endif // #define __LEDSTRIPMOCK_H

