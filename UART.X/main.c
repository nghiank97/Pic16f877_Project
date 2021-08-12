/* 
 * File:   main.c
 * Author: Khac
 *
 * Created on March 28, 2020, 10:23 PM
 */

#include "config.h"
#include "uart.h"

int start = 0;
char frame[5] = {'n', 'g', 'h', 'i', 'a'};

void __interrupt() auto_transmit(void){
    if ((PIR1&(1<<SBIT_TXIF)) == (1<<SBIT_TXIF)){
        TXREG = frame[start];
        start+=1;
        if (start == 5){
            DISENABLE_TRANSMIT();
            start = 0;
        }
    }
}

void main(){
    uart_init(ENABLE);
    while(1){
    }
}

