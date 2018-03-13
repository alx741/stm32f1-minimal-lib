#pragma once
#include <stdlib.h>
#include <stdint.h>

void i2c_init_100khz(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_transmit_bytes(uint8_t addr, uint8_t *src, size_t n);
void i2c_receive_bytes(uint8_t addr, uint8_t *dest, size_t n);
