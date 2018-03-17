#include "cmsis.h"
#include "cm3.h"
#include "f1.h"
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


/* ----------------------------------------------
 *   CMSIS
 * ----------------------------------------------
 */

inline void __enable_irq(void)   { __asm__ volatile("CPSIE I\n"); }
inline void __disable_irq(void)  { __asm__ volatile("CPSID I\n"); }
void __enable_fault_irq(void)    { __asm__ volatile("CPSIE F\n"); }
void __disable_fault_irq(void)   { __asm__ volatile("CPSID F\n"); }
void __ISB(void)                 { __asm__ volatile("ISB\n"); }
void __DSB(void)                 { __asm__ volatile("DSB\n"); }
void __DMB(void)                 { __asm__ volatile("DMB\n"); }
void __SEV(void)                 { __asm__ volatile("SEV\n"); }
void __WEF(void)                 { __asm__ volatile("WFE\n"); }
void __WFI(void)                 { __asm__ volatile("WFI\n"); }

void NVIC_EnableIRQ(uint8_t IRQn)
{
    volatile uint32_t* const NVIC_ISER = (void*) _NVIC_ISER;
    *NVIC_ISER |= (1 << IRQn);
}

void NVIC_SetPriority(uint8_t IRQn, uint32_t priority)
{
    volatile uint32_t* const NVIC_IPR = (void*) _NVIC_IPR + (7 * 4);
    *NVIC_IPR |= (1 << 2);
}
