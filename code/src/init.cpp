#include "init.h"

#include <stm32f4xx_hal.h>
//#include "capTouchDriver.h"
#include "leds.h"
//#include "lidMotor.h"
//#include "limitSwitch.h"
//#include "limitSwitchDriver.h"
//#include "ledBehaviorChildren.h"
//#include "ledStrip.h"
//#include "ledStripDriver.h"
//#include "roboCooler.h"
//#include "scene.h"
#include "timer.h"
//
CLedComp leds;
//CLedObj  LedObjArray[NUM_LEDS];
//CLedObj  LedsAt50Percent(50,50,50);
//
//CLedBeh_Solid   SolidLedStrip(NUM_LEDS, 0, NUM_LEDS-1, LedsAt50Percent);
//
//DMA_Settings_t  DMA_Settings  = {USARTx_TX_DMA_CHANNEL,USARTx_TX_DMA_STREAM};
//GPIO_Settings_t GPIO_Settings = {LED_GPIOX, LED_GPIO_AF, LED_GPIO_PIN_N};
//CLedStripDriver LedStripDriver(NUM_LEDS, DMA_Settings, GPIO_Settings, LED_USARTN);
//
//CSceneOn        FirstScene(NUM_LEDS);
//CLedStripComp   LedStrip(&LedStripDriver, &FirstScene, LedObjArray);
//
//CCapTouchDriver CapTouchDriver(
//        CAP_SCL_GPIOx, CAP_SCL_GPIO_PIN_x,
//        CAP_SDA_GPIOx, CAP_SDA_GPIO_PIN_x,
//        CAP_IRQ_GPIOx, CAP_IRQ_GPIO_PIN_x,
//        CAP_GPIO_AF, CAP_APBxPeriph_I2Cx, CAP_I2Cx);
//
//CCapTouchComp CapTouch(&CapTouchDriver);
//
//CLimSwDriver Opened_LimSwDriver(OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);
//CLimSwDriver Closed_LimSwDriver(OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);
//
//CLimSwComp Opened_Limit(&Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);
//CLimSwComp Closed_Limit(&Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);
//
//CLidMotorComp LidMotor(&CapTouch, &Closed_Limit, &Opened_Limit);
//
void init(void)
{
    HAL_Init();
    Init_Timers();
//
//    FirstScene.Add_Behavior(&SolidLedStrip);
//
    leds.Initialize();
//    LedStripDriver.Initialize_Hardware();
//    LedStripDriver.Initialize();
//    LedStrip.Initialize();
//
//    LidMotor.Initialize();
//
//    CapTouchDriver.Initialize_Hardware();
//    CapTouch.Initialize();
//
//    Closed_LimSwDriver.Initialize_Hardware();
//    Closed_LimSwDriver.Initialize_Hardware();
//
//    Opened_Limit.Initialize();
//    Closed_Limit.Initialize();
}

