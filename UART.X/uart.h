
#ifndef UART_H_
#define UART_H_
#include "config.h"

#define ENABLE_TRANSMIT()                       {PIE1 |= (1<<SBIT_TXIE);}
#define DISENABLE_TRANSMIT()                    {PIE1 &= ~(1<<SBIT_TXIE);}

extern void uart_init(enum STATUS intp);
extern void uart_put(char Data);
extern void uart_puts(char *Data);

#endif

