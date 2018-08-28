#include "usart.h"
#include "f1.h"
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void usart_init_72mhz_9600baud(void)
{
    // USART1 PORTA pins
    RCC_APB2ENR->IOPAEN = true;
    PORTA->MODE9 = MODE_OUTPUT_50MHZ;
    PORTA->CNF9 = CNF_ALTERNATE_PUSH_PULL;
    PORTA->MODE10 = MODE_INPUT;
    PORTA->CNF10 = CNF_IN_PULL_UP_DOWN;

    RCC_APB2ENR->USART1EN = true;
    USART1_CR1->UE = true;
    USART1_CR1->M = false; // 8bit word

    // 9600 Bauds with 72Mhz Master clock
    // Div = 72000000/(16 * 9600) = 468.75
    USART1_BRR->DIV_FRACTION = 12; // 16*0.75 = 12
    USART1_BRR->DIV_MANTISSA = 468;

    USART1_CR1->RE = true;
    USART1_CR1->TE = true;
}

int _read(int file, char *ptr, int len)
{
    int i;
    int c;
	if (file == STDIN_FILENO)
    {
        while (! USART1_SR->RXNE);
        c = USART1_DR->DR;
        ptr[0] = 0x000000FF & c;
        return 1;
	}

	errno = EIO;
	return -1;
}

int _write(int file, char *ptr, int len)
{
    int i;
	if (file == STDOUT_FILENO)
    {
		for (i = 0; i<len; i++)
        {
            USART1_DR->DR = ptr[i];
            while (! USART1_SR->TXE);
        }
		return i;
	}

	errno = EIO;
	return -1;
}
