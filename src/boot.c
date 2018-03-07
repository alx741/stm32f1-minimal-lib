#include "boot.h"
#include "f1.h"
#include <stdint.h>
#include <stdbool.h>

extern uint32_t _stack_base;

__attribute__ ((section(".VECTOR_TABLE")))
VECTOR_TABLE_t VECTOR_TABLE =
    { (uint32_t) &_stack_base
    , RESET_HANDLER
    , NMI_HANDLER
    , HARD_FAULT_HANDLER
    , MEMORY_MANAGEMENT_FAULT_HANDLER
    , BUS_FAULT_HANDLER
    , USAGE_FAULT_HANDLER
    , 0 // Reserved
    , 0
    , 0
    , 0
    , SVCALL_HANDLER
    , 0 // Reserved
    , 0
    , PENDSV_HANDLER
    , SYSTICK_HANDLER
    };

void __attribute__((naked)) RESET_HANDLER(void)
{
    main();
}

void HARD_FAULT_HANDLER(void)
{
    while(1); // Halt
}

void MEMORY_MANAGEMENT_FAULT_HANDLER(void)
{
    HARD_FAULT_HANDLER();
}

void BUS_FAULT_HANDLER(void)
{
    HARD_FAULT_HANDLER();
}

void USAGE_FAULT_HANDLER(void)
{
    HARD_FAULT_HANDLER();
}

void SVCALL_HANDLER(void)
{
    HARD_FAULT_HANDLER();
}

void PENDSV_HANDLER(void)
{
    HARD_FAULT_HANDLER();
}
