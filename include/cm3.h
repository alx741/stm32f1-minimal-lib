#pragma once
#include <stdint.h>

/* ----------------------------------------------
 *   CM3 Memory Map
 * ----------------------------------------------
 */
#define _CM3_INTERNAL   0xE0000000


/* ----------------------------------------------
 *   Nested Vector Interrupt Controller (NVIC)
 * ----------------------------------------------
 */

typedef struct
{
    unsigned INTLINESNUM : 4;
    unsigned             : 28;
} NVIC_ICTR_t;

static volatile NVIC_ICTR_t* const NVIC_ICTR = (void*) _CM3_INTERNAL + 0xE004;
#define _NVIC_ISER (_CM3_INTERNAL + 0xE100)
#define _NVIC_ICER (_CM3_INTERNAL + 0xE180)
#define _NVIC_ISPR (_CM3_INTERNAL + 0xE200)
#define _NVIC_ICPR (_CM3_INTERNAL + 0xE280)
#define _NVIC_IABR (_CM3_INTERNAL + 0xE300)
#define _NVIC_IPR  (_CM3_INTERNAL + 0xE400)
#define _NVIC_STIR (_CM3_INTERNAL + 0xEF00)
