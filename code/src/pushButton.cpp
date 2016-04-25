#include "pushButton.h"
#include "pushButtonDriver.h"
#include "timer.h"

int32_t timer = 0;

void init_PushButton(void)
{
	init_PushButtonDriver();
	timer = AllocateTimer();
	Reset_PushButtonFilters();
}

void Reset_PushButtonFilters(void)
{
}

void Run_PushButtons(void)
{
	IsTimerExpired(timer);
}

motorCmd_t Get_MotorCmd(void)
{
	return MOTOR_STOP;
} // end - motorCmd_t Get_MotorCmd(void)

