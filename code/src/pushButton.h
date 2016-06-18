#ifndef __PUSHBUTTON_H
#define __PUSHBUTTON_H

void    init_PushButton(void);
uint8_t Get_PbUpStatus(void);
uint8_t Get_PbDnStatus(void);
void    Reset_PushButtonFilters(void);
void    Run_PushButtons(void);

#endif // #ifndef __PUSHBUTTON_H

