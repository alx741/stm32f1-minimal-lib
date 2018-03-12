#include "i2c.h"
#include "f1.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum I2C_MODE_t {I2C_RECEIVE, I2C_TRANSMIT} I2C_MODE;

inline void i2c_init_100khz(void)
{
    // Enable clock and configure pins
    RCC_APB2ENR->IOPBEN = true;
    RCC_APB1ENR->I2C1EN = true;
    PORTB->MODE6 = MODE_OUTPUT_50MHZ;
    PORTB->CNF6 = CNF_ALTERNATE_OPEN_DRAIN;
    PORTB->MODE7 = MODE_OUTPUT_50MHZ;
    PORTB->CNF7 = CNF_ALTERNATE_OPEN_DRAIN;

    I2C1_CR1->PE = false; // Disable peripheral
    I2C1_CR2->FREQ = 8;   // 8 MHz
    I2C1_CCR->FS = false; // standard mode (sm)
    I2C1_CCR->CCR = 0x28; // 100 Khz
    *I2C1_TRISE = 0x09;
    I2C1_CR1->PE = true;  // Enable peripheral
}

inline void i2c_start(void)
{
    I2C1_CR1->START = true;
    while (! I2C1_SR1->SB);
}

inline void i2c_stop(void)
{
    I2C1_CR1->STOP = true;
    while (I2C1_SR2->MSL);
}

void i2c_slave_select(uint8_t addr, I2C_MODE mode)
{
    volatile uint8_t dummy;
    dummy = (uint8_t) I2C1_SR1->ADDR;

    switch (mode)
    {
        case I2C_RECEIVE:
            *I2C1_DR = addr | 0x01;
            break;
        case I2C_TRANSMIT:
            *I2C1_DR = addr | 0x00;
            break;
    }
    while (! I2C1_SR1->ADDR);

    dummy = (uint8_t) I2C1_SR1->ADDR;
    dummy = (uint8_t) I2C1_SR2->BUSY;
}

void i2c_transmit_byte(uint8_t addr, uint8_t data)
{
    i2c_slave_select(addr, I2C_TRANSMIT);
    *I2C1_DR = data;
    while (! I2C1_SR1->TXE);
}

uint8_t i2c_receive_byte(uint8_t addr)
{
    i2c_slave_select(addr, I2C_RECEIVE);
    I2C1_CR1->ACK = false;
    i2c_stop();
    while (! I2C1_SR1->RXNE);
    return *I2C1_DR;
}
