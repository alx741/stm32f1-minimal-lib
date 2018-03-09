#include "f1.h"
#include <stdbool.h>

void delay(void);
int counter = 5;

void uart_init(void)
{
    RCC_APB2ENR->USART1EN = true; // enable clk
    USART1_CR1->UE = true; // usart enable
    USART1_CR1->M = false; // 8bit word

    USART1_CR1->TE = true; // enable transmitter
    USART1_CR1->RE = true; // enable receiver
}

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

