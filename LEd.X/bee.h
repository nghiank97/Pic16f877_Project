
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
#define _XTAL_FREQ                          20000000
#endif

#define delay_ms(t)                         __delay_ms(t)
#define delay_us(t)                         __delay_us(t)

#endif

