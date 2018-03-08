#include "boot.h"
#include "f1.h"
#include <stdbool.h>

void delay(void);

int counter = 5;

int main(void)
{
    uint32_t* rcc_apb2enr = 0x40021000 + 0x18;
    uint32_t* gpio_crh    = 0x40011000 + 0x04;
    uint32_t* gpio_odr    = 0x40011000 + 0x0C;
    uint32_t* gpio_bsrr   = _PORTC + 0x10;

    *rcc_apb2enr |= (1 << 4);

    PORTC->MODE15 = 0b10;
    PORTC->CNF15 = 0b00;

    while (counter != 0)
    {
        PORTC->ODR15 = true;
        delay();
        PORTC->ODR15 = false;
        delay();
        counter--;
    }
}

void delay(void)
{
    for (int i=0; i < 200000; i++);
}

