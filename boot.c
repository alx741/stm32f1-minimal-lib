#include <stdint.h>
#include <stdbool.h>

extern uint32_t _stack_base;
void delay(void);
int main(void);

typedef struct
{
    uint32_t INITIAL_STP_VALUE;
    void*    RESET;
} VECTOR_TABLE_t;

__attribute__ ((section(".vector_table")))
VECTOR_TABLE_t vector_table =
{ (uint32_t) &_stack_base
, reset_handler
};

int main(void)
{
    uint32_t* rcc_apb2enr = 0x40021000 + 0x18;
    uint32_t* gpio_crh    = 0x40011000 + 0x04;
    uint32_t* gpio_odr    = 0x40011000 + 0x0C;

    *rcc_apb2enr |= (1 << 4);

    *gpio_crh &= ~(1 << 28);
    *gpio_crh |= (1 << 29);
    *gpio_crh &= ~(1 << 30);
    *gpio_crh &= ~(1 << 31);

    while (1)
    {
        *gpio_odr |= (1 << 15);
        delay();
        *gpio_odr &= ~(1 << 15);
        delay();
    }
}

void delay(void)
{
    for (int i=0; i < 500000; i++);
}

void __attribute__ ((naked)) reset_handler(void)
{
    main();
}
