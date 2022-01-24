#include "mbed.h"

AnalogIn ain(PA_0);

float volt=0;

int main() {
    while(1) {
       volt=ain;
    }
}
