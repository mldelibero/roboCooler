#include "capTouch.h"
#include "ledDriver.h"
//#include "limitSwitch.h"
#include "lidMotor.h"
//#include "utils.h"
#include "ledStrip.h"
#include "ledStripDriver.h"
#include "timer.h"

extern "C" {
#include "Board_LED.h"                  // ::Board Support:LED
}

//extern CLimSwComp Opened_Limit;
//extern CLimSwComp Closed_Limit;
extern CCapTouchComp CapTouch;
extern CLidMotorComp LidMotor;
extern CLedStripDriver LedStripDriver;
extern CLedStripComp LedStrip;

void loop(void)
{
    uint32_t led_cnt = LED_GetCount();
    uint32_t led_num = 0;
    int32_t timer = AllocateTimer();
    bool on = false;
    //    WHILE(1)
    while(1)
    {
        HAL_GPIO_TogglePin(LOOP_INT_GPIOx, LOOP_GPIO_PIN_X);
        //        Opened_Limit.Run();
        //        Closed_Limit.Run();
        CapTouch.Run();
        LidMotor.Run();
        LedStrip.Run();
        LedStripDriver.Run();

        if (IsTimerExpired(timer) == true)
        {
            Set_TimerValue(timer, 500);

            if (on == true)
            {
                LED_Off(led_num);                   // Turn specified LED off
                led_num = ++led_num % led_cnt;      // Change LED number
                on = false;
            }
            else
            {
                LED_On(led_num);                    // Turn specified LED on
                on = true;
            }
        }
    } // end - WHILE(1)
}

