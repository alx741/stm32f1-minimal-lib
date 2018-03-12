#pragma once
#include <stdlib.h>
#include <stdint.h>


void i2c_init_100khz(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_transmit_byte(uint8_t data);
uint8_t i2c_receive_byte(void);
void i2c_receive_bytestring(uint8_t *dest, size_t n);
