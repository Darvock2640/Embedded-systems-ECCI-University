#include "mbed.h"
#include "stdio.h"

//------------------------------------
// Hyperterminal configuration
// 9600 bauds, 8-bit data, no parity
//------------------------------------

void write_usart(int tam);

//Serial pc(PA_0, PA_1); //tx,rx
Serial pc(USBTX, USBRX); //tx,rx
DigitalOut myled(LED1);

char dato=0;
char buffer_usart[100];

int main()
{
    //int i = 1;
    pc.baud(9600);
    pc.printf("Hello World !\n\r\r ");
    while(1) {
        //wait(1);
        if(pc.readable()) {
            dato=pc.getc();
            myled = !myled;
            if(dato=='A') {
                pc.printf("primero\n\r");
            }
            if(dato=='B') {
                pc.printf("Segundo\n\r");
            }
            if(dato=='C') {
                pc.printf("tercero\n\r");
            }
        }

        //pc.printf("This program runs since %d seconds.\n \r", i++);

    }
}