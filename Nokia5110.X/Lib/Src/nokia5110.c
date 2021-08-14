
#include <stdio.h>
#include <string.h>
#include "../Inc/nokia5110.h"
#include "../Inc/font.h"

extern void nokia5110_reset(void){
    RST = 0;
    delay_us(200);
    RST = 1;
}

extern void nokia5110_cmd(uint8_t cmd){
    D_C = 0;
    spi_put(cmd);
}

extern void nokia5110_put(uint8_t data){
    D_C = 1;
    spi_put(data); 
}

extern void nokia5110_puts(uint8_t *data,int len){
    D_C = 1;
    spi_puts(data,len);   
}

extern void nokia5110_image(uint8_t *image){
    D_C = 1;
    spi_puts(image,504);
}

/*
    @para   : int row (0 << row << 6)
    @para   : int col (0 << col << 83)
    @return : void
*/

extern void nokia5110_cursor(int row,int col){
    uint16_t i;
	i = (uint16_t)(row*84 + col);
	if (i > 503)
        return;
    nokia5110_cmd(0x40+(uint8_t)row);
    nokia5110_cmd(0x80+(uint8_t)col);  

}

extern void nokia5110_blank(void){
    nokia5110_cursor(0,0);
    D_C = 1;
    SCE = 0;
    for(int i=0;i<504;i++){
        spi_byte(0x00);
    }
    SCE = 1;
}

extern void nokia5110_init(void){
    DIR_RST = 0;
    DIR_D_C = 0;
    spi_init();
    nokia5110_reset();
    nokia5110_cmd(0x21);
    nokia5110_cmd(0x13);
    nokia5110_cmd(0x07);
    nokia5110_cmd(0xc0);
    nokia5110_cmd(0x20);   
    nokia5110_cmd(0x0c);        
}

extern void nokia5110_5x8_puts(int start_row,int start_col,char *data, enum BACKGROUND bg){
    int i = 0;
    int j = 0;  
    uint8_t buff;
    nokia5110_cursor(start_row,start_col);
    D_C = 1;
    SCE = 0;
    if (bg == NORMAL_BG){
        while(data[i] != 0){
            for(j=0;j<6;j++){
                buff = ASCII[data[i]-0x20][j];
                spi_byte(buff);
            }
            i +=1;
        }       
    }
    else{
        while(data[i] != 0){
            for(j=0;j<6;j++){
                buff = 0xff-ASCII[data[i]-0x20][j];
                spi_byte(buff);
            }
            i +=1;
        }      
    }
    SCE = 1;          
}
