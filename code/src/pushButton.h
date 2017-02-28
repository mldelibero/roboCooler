#ifndef __PUSHBUTTON_H
#define __PUSHBUTTON_H
#include <stm32f4xx.h>

void          init_PushButton(void);
GPIO_PinState Get_PbDnStatus(void);
GPIO_PinState Get_PbUpStatus(void);
void          Reset_PushButtonFilters(void);
void          Run_PushButtons(void);

#endif // #ifndef __PUSHBUTTON_H

