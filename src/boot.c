#include "boot.h"
#include "f1.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Linker script symbols */
extern uint32_t _stack_base, _data_start, _data_load_start, _data_size,
       _bss_start, _bss_size, _data_end;

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
    /* Initialize .data in RAM */
	uint32_t *data_src = &_data_load_start;
	uint32_t *data_dst = &_data_start;
    size_t data_size = (size_t) &_data_size;
    while (data_size--)
    {
        *data_dst++ = *data_src++;
    }

    /* Initialize .rodata in RAM */

    /* User program entry point */
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
