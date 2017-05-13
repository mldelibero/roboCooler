#include <stm32f4xx_hal.h>
//#include "capTouch.h"
//#include "capTouchDriver.h"
#include "leds.h"
//#include "lidMotor.h"
//#include "limitSwitch.h"
//#include "limitSwitchDriver.h"
#include "ledBehaviorChildren.h"
#include "ledStrip.h"
#include "ledStripDriver.h"
#include "roboCooler.h"
#include "scene.h"
#include "timer.h"
//extern "C" {
//#include "Board_LED.h"                  // ::Board Support:LED
//}

CLedComp leds;
CLedObj  LedObjArray[NUM_LEDS];
CLedObj  LedsAt50Percent(50,50,50);

CLedBeh_Solid   SolidLedStrip(NUM_LEDS, 0, NUM_LEDS-1, LedsAt50Percent);

DMA_Settings_t  DMA_Settings  = {USARTx_TX_DMA_CHANNEL, USARTx_TX_DMA_STREAM};
GPIO_Settings_t GPIO_Settings = {LED_GPIOX, LED_GPIO_AF, LED_GPIO_PIN_N};
CLedStripDriver LedStripDriver(NUM_LEDS, DMA_Settings, GPIO_Settings, LED_USARTN);

CSceneOn        FirstScene(NUM_LEDS);
CLedStripComp   LedStrip(&LedStripDriver, &FirstScene, LedObjArray);

//CCapTouchDriver CapTouchDriver(
//        CAP_SCL_GPIOx, CAP_SCL_GPIO_PIN_x,
//        CAP_SDA_GPIOx, CAP_SDA_GPIO_PIN_x,
//        CAP_IRQ_GPIOx, CAP_IRQ_GPIO_PIN_x,
//        CAP_GPIO_AF, CAP_I2Cx);
//
//CCapTouchComp CapTouch(&CapTouchDriver);

//CLimSwDriver Opened_LimSwDriver(OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);
//CLimSwDriver Closed_LimSwDriver(OPEN_LIMSW_GPIOx, OPEN_LIMSW_GPIO_PIN_X);

//CLimSwComp Opened_Limit(&Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);
//CLimSwComp Closed_Limit(&Opened_LimSwDriver, LIM_SW_LO_CUTOFF, LIM_SW_Hi_CUTOFF, LIM_SW_BUFFER_SIZE);

//CLidMotorComp LidMotor(&CapTouch, &Closed_Limit, &Opened_Limit);

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct;
    RCC_ClkInitTypeDef RCC_ClkInitStruct;

    // Enable Power Control clock
    __HAL_RCC_PWR_CLK_ENABLE();

    /* The voltage scaling allows optimizing the power consumption when the
       device is clocked below the maximum system frequency (see datasheet). */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 4;
    //RCC_OscInitStruct.PLL.PLLN = 84;
    RCC_OscInitStruct.PLL.PLLN = 168;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    // RCC_OscInitStruct.PLL.PLLQ = 4;
    RCC_OscInitStruct.PLL.PLLQ = 7;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
       clocks dividers */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
        |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    //  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    //RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    //  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

    // Configure the Systick interrupt time
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    // Configure the Systick
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

    // SysTick_IRQn interrupt configuration
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void HAL_MspInit(void)
{
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);

    /* System interrupt init*/
    /* MemoryManagement_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
    /* BusFault_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
    /* UsageFault_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
    /* SVCall_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(SVCall_IRQn, 0, 0);
    /* DebugMonitor_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DebugMonitor_IRQn, 0, 0);
    /* PendSV_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(PendSV_IRQn, 0, 0);
    /* SysTick_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void init(void)
{
    HAL_Init();
    SystemClock_Config();

    //  LED_Initialize();
    Init_Timers();

    FirstScene.Add_Behavior(&SolidLedStrip);

    leds.Initialize();
    LedStripDriver.Initialize_Hardware();
    LedStripDriver.Initialize();
    LedStrip.Initialize();

    //    LidMotor.Initialize();

    //    CapTouchDriver.Initialize_Hardware();
    //    CapTouch.Initialize();

    //    Closed_LimSwDriver.Initialize_Hardware();
    //    Closed_LimSwDriver.Initialize_Hardware();

    //    Opened_Limit.Initialize();
    //    Closed_Limit.Initialize();
}

/**
 * @brief User implementations of USART initialization functions
 */
//void HAL_USART_MspInit(USART_HandleTypeDef* husart)
//{
 //   if(husart->Instance==LedStripDriver.Get_UsartN()) LedStripDriver.HAL_USART_MspInit();
//}

