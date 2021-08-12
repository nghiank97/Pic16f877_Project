
#include "uart.h"
#include "config.h"

extern void uart_init(enum STATUS intp){  
    TRISC |= (0<<6)|(1<<7);
    SPBRG = BAUD_PRESCALE;
    TXSTA = (1<<SBIT_TXEN);
    RCSTA = (1<<SBIT_SPEN)|(1<<SBIT_CREN);
    if (intp == ENABLE){
        INTCON = (1<<SBIT_GIE)|(1<<SBIT_PIE);
        PIE1 |= (1<<SBIT_TXIE);
    }
}

extern void uart_put(char Data){
    while((PIR1&(1<<SBIT_TXIF)) == 0);
    TXREG = Data;
}

extern void uart_puts(char *Data){
    int local = 0;
    while(Data[local] != 0){
        uart_put(Data[local]);
        local+=1;
    }
}