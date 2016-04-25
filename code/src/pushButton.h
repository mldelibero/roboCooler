#ifndef __PUSHBUTTON_H
#define __PUSHBUTTON_H
typedef enum my_motorCmd
{
    MOTOR_STOP = 0,
    MOTOR_FWD  = 1,
    MOTOR_REV  = 2,
    MOTOR_NO_CMD
} motorCmd_t;

void init_PushButton(void);
void Reset_PushButtonFilters(void);
void Run_PushButtons(void);
motorCmd_t Get_MotorCmd(void);

#endif // #ifndef __PUSHBUTTON_H
