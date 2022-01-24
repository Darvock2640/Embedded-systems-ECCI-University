#include "mbed.h"

DigitalOut led(PA_5);
Timeout t;

void function_t(void)
{
    led=!led;
    t.attach(&function_t,1);
}

int main()
{
    led=1;
    t.attach(&function_t,5);
    while(1) {

    }
}
