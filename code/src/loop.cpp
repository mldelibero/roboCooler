#include "loop.h"
#include "limitSwitch.h"
#include "utils.h"

extern CLimSwComp Opened_Limit;
extern CLimSwComp Closed_Limit;

void loop(void)
{
    WHILE(1)
    {
        Opened_Limit.Run();
        Closed_Limit.Run();
    }
}

