#include <CppUTestExt/MockSupport.h>

int32_t AllocateTimer(void)
{
    mock().actualCall("AllocateTimer");
	return 1;
} // end - int32_t AllocateTimer(void)

bool IsTimerExpired(int32_t timer)
{
	mock().actualCall("IsTimerExpired");
	if(timer){}
	return false;
}
