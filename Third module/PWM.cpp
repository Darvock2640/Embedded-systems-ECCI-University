#include "mbed.h"

DigitalOut  led(PA_5);
DigitalIn   boton(PC_13);
PwmOut      PWM1(PA_8);

int main()
{
    PWM1.period_us(666);
    PWM1=0;

    while(1) {
        if(boton==0) {
            PWM1=0.25;
            led=1;
        } else {
            led=0;
            PWM1=0;
        }
    }
}