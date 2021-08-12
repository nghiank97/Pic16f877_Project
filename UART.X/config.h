
#ifndef CONFIG_H_
#define	CONFIG_H_

#include "bee.h"

#define BAUD_RATE                                   9600
#define BAUD_PRESCALE                               (uint16_t)((F_CPU/64/BAUD_RATE) - 1)

#endif

