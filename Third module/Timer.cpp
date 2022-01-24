#include "mbed.h"
 
Timer t;
 
int main() {
    t.start();
    printf("Hello World!\n\r");
    wait_ms(50);
    t.stop();
    printf("The time taken was %i uS seconds\n\r", t.read_us());
}