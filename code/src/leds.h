#ifndef __LEDS_H
#define __LEDS_H
#include <stm32f4xx.h>
#include "timerDriver.h"

#define LED_TIMER_RESET     TIMER_FREQ / 30 // 30Hz

void init_leds(void);

#endif // #ifndef __LEDS_H

