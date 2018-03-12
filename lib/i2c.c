#include "i2c.h"
#include "f1.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum I2C_MODE_t {I2C_RECEIVE, I2C_TRANSMIT} I2C_MODE;

inline void i2c_init_100khz(void)
{
    I2C1_CR1->PE = false; // Disable peripheral
    I2C1_CR2->FREQ = 8;   // 8 MHz
    I2C1_CCR->FS = false; // standard mode (sm)
    I2C1_CCR->CCR = 0x28; // 100 Khz
    I2C1_TRISE = 0x9;
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
    volatile uint16_t dummy;

    switch (mode)
    {
        case I2C_RECEIVE:
            I2C1_DR = addr | 0x01;
            break;
        case I2C_TRANSMIT:
            I2C1_DR = addr | 0x00;
            break;
    }
    while (! I2C1_SR1->ADDR);

    dummy = (uint16_t) *I2C_SR1;
    dummy = (uint16_t) *I2C_SR2;
}

inline void i2c_transmit_byte(uint8_t data)
{
    I2C1_DR = data;
    while (! I2C1_SR1->TXE);
}

inline uint8_t i2c_receive_byte(void)
{
    I2C_CR2.ACK = false;
    i2c_stop();
    while (! I2C1_SR1->RXNE);
    return I2C1_DR;
}
