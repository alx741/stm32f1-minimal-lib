#include "f1.h"
#include <stdbool.h>

void delay(void);
int counter = 5;

int main(void)
{
    RCC_APB2ENR->IOPCEN = true;
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

