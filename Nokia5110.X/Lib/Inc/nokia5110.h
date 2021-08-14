
#ifndef NOKIA5110_H_
#define NOKIA5110_H_
#include "config.h"
#include "spi.h"

enum COMMAND{
    INVERSE_BACKGROUND = 0x0D
};

enum SIGNAL{
    OFF_PIXEL = 0,
    ON_PIXEL = 1
};

enum BACKGROUND{
    INVERSE_BG = 0,
    NORMAL_BG = 1
};

extern void nokia5110_cmd(uint8_t cmd);
extern void nokia5110_put(uint8_t data);
extern void nokia5110_puts(uint8_t *data,int len);
extern void nokia5110_blank(void);
extern void nokia5110_image(uint8_t *image);
extern void nokia5110_cursor(int row,int col);
extern void nokia5110_init(void);

extern void nokia5110_5x8_puts(int start_row,int start_col,char *data, enum BACKGROUND bg);

#endif
