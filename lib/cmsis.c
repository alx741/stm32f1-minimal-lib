#include "cmsis.h"
#include "f1.h"
#include <stdint.h>
#include <stdbool.h>

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


inline static void set_nvic_bit(uint32_t base, uint8_t bit)
{
    volatile uint32_t* const reg = (void*) base + ((bit / 32) * 4);
    *reg |= (1 << bit % 32);
}

inline void NVIC_EnableIRQ(uint8_t IRQn)
{
    set_nvic_bit(_NVIC_ISER, IRQn);
}

inline void NVIC_DisableIRQ(uint8_t IRQn)
{
    set_nvic_bit(_NVIC_ICER, IRQn);
}

inline void NVIC_SetPendingIRQ(uint8_t IRQn)
{
    set_nvic_bit(_NVIC_ISPR, IRQn);
}

inline void NVIC_ClearPendingIRQ(uint8_t IRQn)
{
    set_nvic_bit(_NVIC_ICPR, IRQn);
}

inline uint32_t NVIC_GetPendingIRQ(uint8_t IRQn)
{
    volatile uint32_t* const NVIC_ISPR = (void*) _NVIC_ISPR + ((IRQn / 32) * 4);
    return *NVIC_ISPR & (1 << IRQn % 32);
}

void NVIC_SetPriority(uint8_t IRQn, uint32_t priority)
{
    volatile uint32_t* const NVIC_IPR = (void*) _NVIC_IPR + ((IRQn / 4) * 4);
    uint8_t prio = (uint8_t) priority << 4; // STM32F1 uses only the high nibble
    *NVIC_IPR |= (prio << ((IRQn % 4) * 8));
}

uint32_t NVIC_GetPriority(uint8_t IRQn)
{
    volatile uint32_t* const NVIC_IPR = (void*) _NVIC_IPR + ((IRQn / 4) * 4);
    uint8_t offset = (IRQn % 4) * 8;
    return (*NVIC_IPR & (0xFF << offset)) >> offset + 4; // STM32F1 uses only the high nibble
}
