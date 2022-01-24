#include "mbed.h"

DigitalOut led(PA_5);
InterruptIn button(PC_13);

void function_button(void)
{
    led=!led;

}

int main()
{
    button.fall(&function_button);
    while(1) {

    }
}
