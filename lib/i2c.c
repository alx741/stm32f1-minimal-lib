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
    I2C1_CCR->FS = false; // Sm mode
    I2C1_CCR->CCR = 0x28; // 100 Khz
    I2C1_TRISE = 0x9;
    I2C1_CR1->PE = true;  // Enable peripheral
}
