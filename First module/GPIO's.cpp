#include "mbed.h"

DigitalOut myled(LED1);
BusOut Puerto(PA_5, PA_6, PA_7, PB_6, PC_7, PA_9, PA_8, PB_10);
uint8_t a=0;
int main() {
    while(1) {
        /*myled = 1; // LED is ON
        wait_ms(1000); // 200 ms
        myled = 0; // LED is OFF
        Puerto=0xFF;
        wait_ms(1000); // 1 sec
        Puerto=0x00;
        wait_ms(1000); // 1 sec*/
        for(a=0;a<256;a++){
            Puerto=a;
            wait_ms(100);
        }
    }
}