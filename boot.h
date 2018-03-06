#pragma once

#include <stdint.h>

/* Number of IRQs a device supports */
#ifndef IRQ_N
#define IRQ_N 0
#endif

/* Cortex-M3 vector table */
typedef struct
{
    uint32_t INITIAL_SP_VALUE;
    void*    RESET;
    void*    NMI;
    void*    HARD_FAULT;
    void*    MEMORY_MANAGEMENT_FAULT;
    void*    BUS_FAULT;
    void*    USAGE_FAULT;
    void*    _RESERVED_1[4];
    void*    SVCALL;
    void*    _RESERVED_DEBUG;
    void*    _RESERVED_2;
    void*    PENDSV;
    void*    SYSTICK;
    void*    IRQ[IRQ_N];
} VECTOR_TABLE_t;


/* Exception handlers */
void __attribute__ ((weak)) nmi_handler(void);

extern int main(void);
