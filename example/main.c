#include <f1.h>
#include <rcc.h>
#include <usart.h>
#include <stdbool.h>
#include <stdio.h>

void delay(void);

int main(void)
{
    rcc_setup_in_8mhz_hse_out_72mhz();

    RCC_APB2ENR->IOPCEN = true;
    PORTC->MODE15 = MODE_OUTPUT_50MHZ;
    PORTC->CNF15 = CNF_OUT_PUSH_PULL;

    PORTC->MODE14 = MODE_INPUT;
    PORTC->CNF14 = CNF_IN_PULL_UP_DOWN;

    usart_init_72mhz_9600baud();

    int somechar;
    while (true)
    {
        somechar = getchar();
        if (somechar == 'o')
        {
            PORTC->ODR15 = true;
            printf("on\r\n");
        }
        else
        {
            PORTC->ODR15 = false;
            printf("off\r\n");
        }
    }
}

void delay(void)
{
    for (int i = 0; i < 900000; i++);
}
