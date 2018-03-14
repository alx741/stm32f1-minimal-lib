#include "external/mpu6050.h"
#include "external/mpu6050_registers.h"
#include <i2c.h>
#include <f1.h>
#include <string.h>
#include <stdbool.h>

#define MPU_AD0_LOW_ADDR 0b11010000
#define MPU_AD0_HIGH_ADDR 0b11010010

typedef struct
{
    uint8_t XH;
    uint8_t XL;
    uint8_t YH;
    uint8_t YL;
    uint8_t ZH;
    uint8_t ZL;
} DATA_POINT_t;

typedef struct
{
    int32_t X, Y, Z;
} GYRO_OFFSET_t;

ACCEL_t accel_raw_to_g(const ACCEL_RAW_t *accel_raw);
GYRO_t gyro_raw_to_dps(const GYRO_RAW_t *gyro_raw);
void gyro_apply_offset(GYRO_RAW_t *gyro);
float accel_AFS_factor(void);
float gyro_FS_factor(void);

// Accelerometer range scales
static const float AFS_SEL_0 = 16384;
static const float AFS_SEL_1 = 8192;
static const float AFS_SEL_2 = 4096;
static const float AFS_SEL_3 = 2048;

// Gyroscope range scales
static const float FS_SEL_0 = 131;
static const float FS_SEL_1 = 65.5;
static const float FS_SEL_2 = 32.8;
static const float FS_SEL_3 = 16.4;

// Calibration
static const int GYRO_CALIBRATION_SAMPLES = 200;
GYRO_OFFSET_t GYRO_OFFSET = {0};

// Physical constants
static const float g = 9.80665;

// MPU selected address
static uint8_t MPU_ADDR = MPU_AD0_LOW_ADDR;


inline void mpu6050_select_address(bool ad0)
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

inline void mpu6050_wake_up(void)
{
    i2c_start();
    i2c_transmit_bytes(MPU_ADDR, (uint8_t[]){PWR_MGMT_1_REG, 0x00}, 2);
    i2c_stop();
}

uint8_t mpu6050_read_register(uint8_t reg_address)
{
    uint8_t result;
    i2c_start();
    i2c_transmit_bytes(MPU_ADDR, &reg_address, 1);
    i2c_start();
    i2c_receive_bytes(MPU_ADDR, &result, 1);
    return result;
}

ACCEL_t mpu6050_read_accel(void)
{
    DATA_POINT_t data_point;
    ACCEL_RAW_t accel_raw;
    ACCEL_t accel;
    i2c_start();
    i2c_transmit_bytes(MPU_ADDR, (uint8_t[]){ACCEL_REG}, 1);
    i2c_start();
    i2c_receive_bytes(MPU_ADDR, (void*) &data_point, 6);
    accel_raw.X = data_point.XH << 8 | data_point.XL;
    accel_raw.Y = data_point.YH << 8 | data_point.YL;
    accel_raw.Z = data_point.ZH << 8 | data_point.ZL;
    return accel_raw_to_g(&accel_raw);
}

GYRO_RAW_t mpu6050_read_gyro_raw(void)
{
    DATA_POINT_t data_point;
    GYRO_RAW_t gyro_raw;
    i2c_start();
    i2c_transmit_bytes(MPU_ADDR, (uint8_t[]){GYRO_REG}, 1);
    i2c_start();
    i2c_receive_bytes(MPU_ADDR, (void*) &data_point, 6);
    gyro_raw.X = data_point.XH << 8 | data_point.XL;
    gyro_raw.Y = data_point.YH << 8 | data_point.YL;
    gyro_raw.Z = data_point.ZH << 8 | data_point.ZL;
    return gyro_raw;
}

GYRO_t mpu6050_read_gyro(void)
{
    GYRO_RAW_t gyro_raw = mpu6050_read_gyro_raw();
    gyro_apply_offset(&gyro_raw);
    return gyro_raw_to_dps(&gyro_raw);
}

void gyro_apply_offset(GYRO_RAW_t *gyro)
{
    if (GYRO_OFFSET.X == 0) { return; } // Not calibrated yet
    gyro->X -= GYRO_OFFSET.X;
    gyro->Y -= GYRO_OFFSET.Y;
    gyro->Z -= GYRO_OFFSET.Z;
}

void mpu6050_calibrate_gyro(void)
{
    GYRO_RAW_t gyro_sample;
    for (int i = 0; i < GYRO_CALIBRATION_SAMPLES; i++)
    {
        gyro_sample = mpu6050_read_gyro_raw();
        GYRO_OFFSET.X += gyro_sample.X;
        GYRO_OFFSET.Y += gyro_sample.Y;
        GYRO_OFFSET.Z += gyro_sample.Z;
    }
    GYRO_OFFSET.X /= GYRO_CALIBRATION_SAMPLES;
    GYRO_OFFSET.Y /= GYRO_CALIBRATION_SAMPLES;
    GYRO_OFFSET.Z /= GYRO_CALIBRATION_SAMPLES;
}

float mpu6050_read_temp(void)
{
    DATA_POINT_t data_point;
    TEMP_RAW_t temp_raw;
    i2c_start();
    i2c_transmit_bytes(MPU_ADDR, (uint8_t[]){TEMP_REG}, 1);
    i2c_start();
    i2c_receive_bytes(MPU_ADDR, (void*) &data_point, 2);
    temp_raw = data_point.XH << 8 | data_point.XL;
    return (float) temp_raw/340 + 36.53;
}

ACCEL_t accel_raw_to_g(const ACCEL_RAW_t *accel_raw)
{
    ACCEL_t accel;
    float scaling_factor = accel_AFS_factor();
    accel.x = accel_raw->X / scaling_factor;
    accel.y = accel_raw->Y / scaling_factor;
    accel.z = accel_raw->Z / scaling_factor;
    return accel;
}

GYRO_t gyro_raw_to_dps(const GYRO_RAW_t *gyro_raw)
{
    GYRO_t gyro;
    float scaling_factor = gyro_FS_factor();
    gyro.x = gyro_raw->X / scaling_factor;
    gyro.y = gyro_raw->Y / scaling_factor;
    gyro.z = gyro_raw->Z / scaling_factor;
    return gyro;
}

float accel_AFS_factor(void)
{
    ACCEL_CONFIG_t accel_config;
    uint8_t accel_config_byte = mpu6050_read_register(ACCEL_CONFIG_REG);
    memcpy(&accel_config, &accel_config_byte, 1);
    switch (accel_config.AFS_SEL)
    {
        case 0:
            return AFS_SEL_0;
            break;
        case 1:
            return AFS_SEL_1;
            break;
        case 2:
            return AFS_SEL_2;
            break;
        case 3:
            return AFS_SEL_3;
            break;
    }
    return 0;
}

float gyro_FS_factor(void)
{
    GYRO_CONFIG_t gyro_config;
    uint8_t gyro_config_byte = mpu6050_read_register(GYRO_CONFIG_REG);
    memcpy(&gyro_config, &gyro_config_byte, 1);
    switch (gyro_config.FS_SEL)
    {
        case 0:
            return FS_SEL_0;
            break;
        case 1:
            return FS_SEL_1;
            break;
        case 2:
            return FS_SEL_2;
            break;
        case 3:
            return FS_SEL_3;
            break;
    }
    return 0;
}
