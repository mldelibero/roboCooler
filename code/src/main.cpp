#include "stm32f4xx.h"
#include "init.h"
#include "loop.h"

int main(void)
{
    init();
    loop();
    while(1);
}
