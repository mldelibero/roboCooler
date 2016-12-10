#include "loop.h"

#include "capTouch.h"
#include "limitSwitch.h"
#include "utils.h"

extern CLimSwComp Opened_Limit;
extern CLimSwComp Closed_Limit;
extern CCapTouchComp CapTouch;

void loop(void)
{
    WHILE(1)
    {
        Opened_Limit.Run();
        Closed_Limit.Run();

        CapTouch.Run();
    }
}

