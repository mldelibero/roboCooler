#include "loop.h"

#include "capTouch.h"
#include "limitSwitch.h"
#include "lidMotor.h"
#include "utils.h"
#include "ledStrip.h"
#include "ledStripDriver.h"

extern "C" {
#include "Board_LED.h"                  // ::Board Support:LED
}
#include "cmsis_os.h"

extern CLimSwComp Opened_Limit;
extern CLimSwComp Closed_Limit;
extern CCapTouchComp CapTouch;
extern CLidMotorComp LidMotor;
extern CLedStripDriver LedStripDriver;
extern CLedStripComp LedStrip;

void loop(void)
{
    uint32_t led_cnt = LED_GetCount();
    uint32_t led_num = 0;
//    WHILE(1)
    while(1)
    {
        //        Opened_Limit.Run();
        //        Closed_Limit.Run();
        //        CapTouch.Run();
        //        LidMotor.Run();
        //        LedStrip.Run();
        //        LedStripDriver.Run();

        osDelay(500);                           /* Wait 500ms                     */
        LED_On(led_num);                    // Turn specified LED on
        osDelay(500);                           /* Wait 500ms                     */
        LED_Off(led_num);                   // Turn specified LED off

        led_num = ++led_num % led_cnt;                          // Change LED number
    }
}

