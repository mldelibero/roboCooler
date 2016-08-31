#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include "leds.h"

#include "timer.h"


void init_leds(void)
{
    static int32_t led_timer = -1;
    led_timer = AllocateTimer();
    Set_TimerValue(led_timer, LED_TIMER_RESET);
}

