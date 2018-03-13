#pragma once
#include "mpu6050_registers.h"
#include <stdint.h>
#include <stdbool.h>

/* MPU6050 boots up in sleep mode. All registers, except for PWR_MGMT_1 and
 * WHO_I_AM, will have a reset value of 0x00, until the device wakes up.
 *
 * Booting, resetting and waking up operations can take up to 100ms. Make sure
 * to give the device some time.
 */

/**
 * Accelerometer measurements in gravities (g)
 */
typedef struct
{
    float x, y, z;
} ACCEL_t;

/**
 * Gyroscope measurements in degrees per second (dps)
 */
typedef struct
{
    float x, y, z;
} GYRO_t;

void mpu6050_select_address(bool ad0);
void mpu6050_wake_up(void);
uint8_t mpu6050_read_register(uint8_t reg);
ACCEL_t mpu6050_read_accel(void);
GYRO_t mpu6050_read_gyro(void);
float mpu6050_read_temp(void);

/**
 * Convert Accelerometer measurements from gravities (g)
 * to meters per second (mps) and back
 */
void accel_g_to_mps(ACCEL_t *accel);
void accel_mps_to_g(ACCEL_t *accel);
