#include <stdint.h>

int main(void);

typedef struct
{
    uint32_t INITIAL_STP_VALUE;
    void*    RESET;
} VECTOR_TABLE_t;

int a = 0;
void __attribute__ ((naked)) reset_handler(void)
{
    a++;
    main();
}

extern uint32_t _stack_base;

__attribute__ ((section(".vector_table")))
VECTOR_TABLE_t vector_table =
{ (uint32_t) &_stack_base
, reset_handler
};


int main(void)
{
    /* int a = 0; */
    /* a++; */
    /* __enable_irq(); */
}
