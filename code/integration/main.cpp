#include "init.h"
#include "timer_Int.h"
#include "pushButton_Int.h"

int main(void)
{
    init_Integration();
    while(1)
    {
        timer_Int();
        pushButtons_Int();
    }
}

