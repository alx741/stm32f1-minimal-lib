#include "rcc.h"
#include "f1.h"
#include <stdbool.h>

void rcc_setup_in_8mhz_hse_out_72mhz(void)
{
    // Turn HSE on
    RCC_CR->HSEON = true;
    while (! RCC_CR->HSERDY);

    // Configure buses clocks
    RCC_CFGR->HPRE = 0x00;
    RCC_CFGR->PPRE1 = 0b100;
    RCC_CFGR->PPRE2 = 0b000;
    FLASH_ACR->LATENCY = 0b010;

    RCC_CFGR->PLLSRC = true;    // Use HSE as PLL input
    RCC_CFGR->PLLXTPRE = false; // HSE not divided
    RCC_CFGR->PLLMUL = 0b0111;  // 8Mhz * 9 = 72Mhz
    RCC_CR->PLLON = true;       // Turn PLL on
    while (! RCC_CR->PLLRDY);   // Wait PLL to be ready
    RCC_CFGR->SW = 0b10;        // Use PLL as system clock
    while (RCC_CFGR->SWS != 0b10);
}
