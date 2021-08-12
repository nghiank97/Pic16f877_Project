
#ifndef BEE_H_
#define	BEE_H_

typedef   signed            char            int8_t;
typedef   signed            int             int16_t;
typedef   signed long       int             int32_t;
typedef   unsigned          char            uint8_t;
typedef   unsigned 			int		        uint16_t;
typedef   unsigned long		int		        uint32_t;
typedef   float						        float32_t;

#define _bv(PIN)                            (1<<PIN)
#define _set(PORT,PIN)                      (PORT |= _bv(PIN))
#define _clr(PORT,PIN)                      (PORT &= ~_bv(PIN))
#define _write(PORT,PIN,S)                  (S==1 ? _set(PORT,PIN): _clr(PORT,PIN))  
#define _read(PORT,PIN)                     ((PORT&_bv(PIN))==0x00 ? 0:1)
#define _toggle(PORT,PIN)                   ((PORT) ^=_bv(PIN))


#pragma config FOSC                         = HS            
#pragma config WDTE                         = OFF           
#pragma config PWRTE                        = OFF           
#pragma config BOREN                        = ON            
#pragma config LVP                          = OFF           
#pragma config CPD                          = OFF           
#pragma config WRT                          = OFF           
#pragma config CP                           = OFF
#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ                          16000000
#endif

enum STATUS{
    ENABLE = 1,
    DISENABLE = 0
};

#define F_CPU                               _XTAL_FREQ

#define delay_ms(t)                         __delay_ms(t)
#define delay_us(t)                         __delay_us(t)            

/* UART */
#define SBIT_TXEN                           5
#define SBIT_SPEN                           7
#define SBIT_CREN                           4

#define SBIT_TXIF                           4
/* PIE1 register */

#define SBIT_TXIE                           4
/* INTCON register */

#define SBIT_GIE                            7
#define SBIT_PIE                            6

#define ENABLE_INTERRUPT()                  {INTCON |= (1<<SBIT_GIE);}
#define DISENABLE_INTERRUPT()               {INTCON &= ~(1<<SBIT_GIE);}

#endif

