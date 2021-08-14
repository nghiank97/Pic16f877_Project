
#ifndef SPI_H_
#define SPI_H_
#include "config.h"

#define SCK             RC3 //Serial Clock
#define SDI             RC4 //Serial Data In
#define SD0             RC5 //Serial Data Out
#define SS              RA5 //Slave Select: Not used in this application
#define SCK_DIR         TRISC3
#define SDI_DIR         TRISC4
#define SDO_DIR         TRISC5
#define SS_DIR          TRISA5

extern void spi_byte(uint8_t data);
extern void spi_init(void);
extern void spi_put(uint8_t data);
extern void spi_puts(uint8_t *data,int len);
extern uint8_t spi_get(void);

#endif