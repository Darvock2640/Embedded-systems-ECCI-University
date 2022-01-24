//..................librerias......................................................................................
#include "mbed.h"
#include <stdio.h>
#include <string.h>

//..............variables globales y prototipos de funcion.........................................................
char buffer[40];
unsigned int num=0;

void ini_LCD(void);
void enable(void);
void dato_LCD(unsigned char dato);
void ins_LCD(unsigned char dato);
void write_LCD(unsigned char tam);

DigitalOut EN(PB_13);
DigitalOut RW(PB_14);
DigitalOut RS(PB_15);
DigitalIn B(PC_13);

BusOut data_bus(PB_1, PB_2, PB_12, PA_11, PA_12, PC_5, PC_6, PC_8);

//..............codigo principal................................................................

int main() {
//.........................conf perifericos.................................................
/*
    RS=1;
    RW=0;
    EN=1;
    data_bus=0b10101100;
*/
    ini_LCD(); //inicializa la LCD
    
    sprintf(buffer,"0 para todos"); 
    write_LCD(strlen(buffer));
    
    ins_LCD(192);
    
    sprintf(buffer,"menos para Perendejo");
    write_LCD(strlen(buffer));

    wait_ms(2000);
    ins_LCD(1);
    
    //.........................bucle.............................................................    
    while (1) {
        wait_ms(250);
        ins_LCD(1);
        num++;
        sprintf(buffer,"Num: %u",num);
        write_LCD(strlen(buffer)); 
    }
}

//......................funciones............................................................

//...................ini_LCD....................................
void ini_LCD (void)
{
    wait_ms(20);            // delay 20 ms
    data_bus=0x30;          // VALOR DE INICIALIZACION
    enable();

    wait_ms(5);             // delay 5 ms
    data_bus=0x30;          // VALOR DE INICIALIZACION
    enable();

    wait_ms(1);             // delay 1 ms
    data_bus=0x30;          // VALOR DE INICIALIZACION
    enable();

    data_bus=0b00111000;    // Function set 8 bits - 2 lineas - 5*8
    enable();

    data_bus=0b00001000;    // display off
    enable();

    data_bus=0b00000001;    // display clear
    enable();

    data_bus=0b00000110;    // entry mode set - incrementa la posicion del cursor
    enable();

    data_bus=0b00001110;    // display on/off control - LCD on - cursor on - blink off
    enable();
}

//...................enable....................................
void enable (void)
{
    EN=1;                   // enable en alto
    wait_ms(1);
    EN=0;                   // enable en bajo
}

//...................dato....................................
void dato_LCD(unsigned char dato)
{
    RW=0;                   //R/W en 0
    RS=1;                   //RS en 1 (envia dato)
    data_bus=dato;          //dato a publicar 
    enable();
    wait_ms(2);             //tiempo de ejecucion
}

//...................instruccion..................................
void ins_LCD(unsigned char dato)
{
    RW=0;                  //R/W en 0
    RS=0;                  //RS en 0 (envia instruccion)
    data_bus=dato;         //dato a publicar 
    enable();
    wait_ms(2);            //tiempo de ejecucion
}
void write_LCD(unsigned char tam){
    
    unsigned char i;
    
    for(i=0;i<tam;i++){
        dato_LCD(buffer[i]);
    }
}