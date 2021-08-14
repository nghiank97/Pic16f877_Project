#include "../Inc/spi.h"

extern void spi_init(void){
    SCK_DIR = 0;
    SDI_DIR = 1;
    SDO_DIR = 0;
    SS_DIR = 0;

    SSPSTAT = 0x80;
    SSPCON = 0x30;
}

extern void spi_put(uint8_t data){
    SS = 0;
    SSPBUF = data;
    while(BF == 0);
    SS = 1;
}

extern void spi_byte(uint8_t data){
    SSPBUF = data;
    while(BF == 0);
}

extern void spi_puts(uint8_t *data,int len){
    int i = 0;
    SS = 0;
    for(i=0;i<len;i++){
        SSPBUF = data[i];
        while(BF == 0);
    }
    SS = 1;  
}

extern uint8_t spi_get(){
    while(!(SSPSTAT&(1<<BF)));
    return SSPBUF;
}
