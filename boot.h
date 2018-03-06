#pragma once

#include <stdint.h>

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
} VECTOR_TABLE_t;

/* Exception handlers
 *
 * All handlers, except RESET, NMI, SYSTICK and IRQs, will halt
 * the processor by default
 */
void __attribute__((naked)) RESET_HANDLER(void);
void __attribute__ ((weak)) NMI_HANDLER(void);
void __attribute__ ((weak)) HARD_FAULT_HANDLER(void);
void __attribute__ ((weak)) MEMORY_MANAGEMENT_FAULT_HANDLER(void);
void __attribute__ ((weak)) BUS_FAULT_HANDLER(void);
void __attribute__ ((weak)) USAGE_FAULT_HANDLER(void);
void __attribute__ ((weak)) SVCALL_HANDLER(void);
void __attribute__ ((weak)) PENDSV_HANDLER(void);
void __attribute__ ((weak)) SYSTICK_HANDLER(void);

extern int main(void);
