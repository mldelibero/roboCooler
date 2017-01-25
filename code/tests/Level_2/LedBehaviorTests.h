#ifndef __LEDBEHAVIORTESTS_H
#define __LEDBEHAVIORTESTS_H
#include "ledObj.h"
#define NUM_LEDS             5
void CheckLeds(uint16_t StartIndex, uint16_t EndIndex, CLedObj* OutLedObj, CLedObj FirstObj, CLedObj SecondObj, CLedObj ThirdObj);
void CheckLeds_Exclusive(uint16_t StartIndex, uint16_t EndIndex, CLedObj* OutLedObj, CLedObj FirstObj, CLedObj SecondObj, CLedObj ThirdObj);
#endif //#ifndef __LEDBEHAVIORTESTS_H

