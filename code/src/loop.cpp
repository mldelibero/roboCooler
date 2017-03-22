#include "loop.h"

//#include "capTouch.h"
//#include "limitSwitch.h"
//#include "lidMotor.h"
#include "utils.h"
#include "ledStrip.h"
#include "ledStripDriver.h"

//extern CLimSwComp Opened_Limit;
//extern CLimSwComp Closed_Limit;
//extern CCapTouchComp CapTouch;
//extern CLidMotorComp LidMotor;
extern CLedStripDriver LedStripDriver;
extern CLedStripComp LedStrip;

void loop(void)
{
    WHILE(1)
    {
//        Opened_Limit.Run();
//        Closed_Limit.Run();
//        CapTouch.Run();
//        LidMotor.Run();
        LedStrip.Run();
        LedStripDriver.Run();
    }
}

