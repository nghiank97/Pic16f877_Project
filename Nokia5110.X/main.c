/* 
 * File:   main.c
 * Author: Khac
 *
 * Created on March 28, 2020, 10:23 PM
 */
// CONFIG
#include "Lib/Inc/config.h"
#include "Lib/Inc/nokia5110.h"

#define UP_BT               RB0
#define DOWN_BT             RB1

#define DIR_UP              TRISB0
#define DIR_DOWN            TRISB1

char* menu[] = {
    " Temperature",
    " Humidity",
    " Both",
    " Battery",
    " Backlight",
    " Contrast"
};


static void gpio_init(void){
    DIR_UP = 1;
    DIR_DOWN = 1;
}

int index_home = 0;

static void set_home_from(void){
    nokia5110_5x8_puts(0,0,menu[0],INVERSE_BG);
    nokia5110_5x8_puts(1,0,menu[1],NORMAL_BG);
    nokia5110_5x8_puts(2,0,menu[2],NORMAL_BG);
    nokia5110_5x8_puts(3,0,menu[3],NORMAL_BG);
    nokia5110_5x8_puts(4,0,menu[4],NORMAL_BG);
    nokia5110_5x8_puts(5,0,menu[5],NORMAL_BG);
}

static void loading_up_form(void){
    switch(index_home){
        case 0:{
            nokia5110_5x8_puts(5,0,menu[5],NORMAL_BG);
            nokia5110_5x8_puts(0,0,menu[0],INVERSE_BG);
            return;
        }
        case 1:{
            nokia5110_5x8_puts(0,0,menu[0],NORMAL_BG);
            nokia5110_5x8_puts(1,0,menu[1],INVERSE_BG);
            return;
        }
        case 2:{
            nokia5110_5x8_puts(1,0,menu[1],NORMAL_BG);
            nokia5110_5x8_puts(2,0,menu[2],INVERSE_BG);
            return;
        }
        case 3:{
            nokia5110_5x8_puts(2,0,menu[2],NORMAL_BG);
            nokia5110_5x8_puts(3,0,menu[3],INVERSE_BG);
            return;
        }
        case 4:{
            nokia5110_5x8_puts(3,0,menu[3],NORMAL_BG);
            nokia5110_5x8_puts(4,0,menu[4],INVERSE_BG);
            return;
        }
        case 5:{
            nokia5110_5x8_puts(4,0,menu[4],NORMAL_BG);
            nokia5110_5x8_puts(5,0,menu[5],INVERSE_BG);
            return;
        }                    
    }
}

static void loading_down_form(void){
    switch(index_home){
        case 0:{
            nokia5110_5x8_puts(1,0,menu[1],NORMAL_BG);
            nokia5110_5x8_puts(0,0,menu[0],INVERSE_BG);
            return;
        }
        case 1:{
            nokia5110_5x8_puts(2,0,menu[2],NORMAL_BG);
            nokia5110_5x8_puts(1,0,menu[1],INVERSE_BG);
            return;
        }
        case 2:{
            nokia5110_5x8_puts(3,0,menu[3],NORMAL_BG);
            nokia5110_5x8_puts(2,0,menu[2],INVERSE_BG);
            return;
        }
        case 3:{
            nokia5110_5x8_puts(4,0,menu[4],NORMAL_BG);
            nokia5110_5x8_puts(3,0,menu[3],INVERSE_BG);
            return;
        }
        case 4:{
            nokia5110_5x8_puts(5,0,menu[5],NORMAL_BG);
            nokia5110_5x8_puts(4,0,menu[4],INVERSE_BG);
            return;
        }
        case 5:{
            nokia5110_5x8_puts(0,0,menu[0],NORMAL_BG);
            nokia5110_5x8_puts(5,0,menu[5],INVERSE_BG);
            return;
        }                    
    }
}

void main(){
    gpio_init();
    nokia5110_init();
    set_home_from();

    while(1){
        if ((UP_BT == 0) && (DOWN_BT == 1)){
            delay_ms(100);
            if ((UP_BT == 0) && (DOWN_BT == 1)){
                index_home+=1;
                if (index_home == 6){
                    index_home = 0;
                }
                loading_up_form();
            }
            continue;
        }
        else if ((UP_BT == 1) && (DOWN_BT == 0)){
            delay_ms(100);
            if ((UP_BT == 1) && (DOWN_BT == 0)){
                index_home-=1;
                if (index_home == -1){
                    index_home = 5;
                }
                loading_down_form();
            }
            continue;
        }
    }
}
