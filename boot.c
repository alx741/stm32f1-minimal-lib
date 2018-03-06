#include "boot.h"
#include <stdint.h>
#include <stdbool.h>

extern uint32_t _stack_base;

void __attribute__((naked)) reset_handler(void)
{
    main();
}

void __attribute__ ((weak)) nmi_handler(void)
{
}

__attribute__ ((section(".vector_table")))
VECTOR_TABLE_t vector_table =
{ (uint32_t) &_stack_base
, reset_handler
, nmi_handler
};
