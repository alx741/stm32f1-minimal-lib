#include "external/mpu6050.h"
#include "external/mpu6050_registers.h"
#include <i2c.h>
#include <f1.h>
#include <string.h>
#include <stdbool.h>

#define MPU_AD0_LOW_ADDR 0b11010000
#define MPU_AD0_HIGH_ADDR 0b11010010

static const float AFS_SEL_0 = 16384;
static const float AFS_SEL_1 = 8192;
static const float AFS_SEL_2 = 4096;
static const float AFS_SEL_3 = 2048;

static const float FS_SEL_0 = 131;
static const float FS_SEL_1 = 65.5;
static const float FS_SEL_2 = 32.8;
static const float FS_SEL_3 = 16.4;

static const float g = 9.80665;

static uint8_t MPU_ADDR = MPU_AD0_LOW_ADDR;

/* float accel_AFS_factor(void); */
/* float gyro_FS_factor(void); */
/* inline ACCEL_t accel_raw_to_g(const ACCEL_RAW_t *accel_raw); */
/* void gyro_raw_to_dps(GYRO_RAW_t *gyro_raw, GYRO_t *gyro); */

void mpu6050_select_address(bool ad0)
{
    if (ad0)
    {
        MPU_ADDR = MPU_AD0_HIGH_ADDR;
    }
    else
    {
        MPU_ADDR = MPU_AD0_LOW_ADDR;
    }
}

void mpu6050_wake_up(void)
{
    i2c_start();
    i2c_transmit_bytes(MPU_ADDR, (uint8_t[]){0x6B, 0x00}, 2);
    i2c_stop();
}
