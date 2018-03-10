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

    usart_init_72mhz_9600baud();

    int somechar;
    int a = 1234;
    float b = 234.23;
    while (true)
    {
        /* somechar = getchar(); */
        /* if (somechar == 'a') */
        /* { */
        /*     PORTC->ODR15 = true; */
        /*     putchar('x'); */
        /* } */
        /* else */
        /* { */
        /*     PORTC->ODR15 = false; */
        /* } */

        /* PORTC->ODR15 = true; */
        /* delay(); */
        /* PORTC->ODR15 = false; */
        /* delay(); */
        /* putchar('x'); */
        printf("a = %d, b = %f\r\n", a, b);
    }

}

void delay(void)
{
    for (int i = 0; i < 900000; i++);
}
