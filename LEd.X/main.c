/* 
 * File:   main.c
 * Author: Khac
 *
 * Created on March 28, 2020, 10:23 PM
 */
// CONFIG
#include "config.h"

static void initial_gpio(){
    DIR_LED &= ~(1<<LED);
}

void main(){
    initial_gpio();
    while(1){
        _set(PORT_LED,LED);
        delay_ms(1000);
        _clr(PORT_LED,LED);
        delay_ms(1000);
    }
}
