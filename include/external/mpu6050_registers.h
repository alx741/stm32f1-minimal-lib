#pragma once
#include <stdint.h>

/* ----------------------------------------------
 *   Power Management
 * ----------------------------------------------
 */

#define PWR_MGMT_1   0x6B

typedef struct
{
    unsigned              : 3;
    unsigned TEMP_DIS     : 1;
    unsigned              : 1;
    unsigned CYCLE        : 1;
    unsigned SLEEP        : 1;
    unsigned DEVICE_RESET : 1;
} PWR_MGMT_1_t;


/* ----------------------------------------------
 *   Accelerometer
 * ----------------------------------------------
 */

#define ACCEL          0x3B
#define ACCEL_CONFIG   0x1C

typedef struct
{
    int16_t X, Y, Z;
} ACCEL_RAW_t;


typedef struct
{
    unsigned         : 3;
    unsigned AFS_SEL : 2;
    unsigned ZA_ST   : 1;
    unsigned YA_ST   : 1;
    unsigned XA_ST   : 1;
} ACCEL_CONFIG_t;


/* ----------------------------------------------
 *   Gyroscope
 * ----------------------------------------------
 */

#define GYRO          0x43
#define GYRO_CONFIG   0x1B

typedef struct
{
    int16_t X, Y, Z;
} GYRO_RAW_t;

typedef struct
{
    unsigned         : 3;
    unsigned FS_SEL  : 2;
    unsigned ZG_ST   : 1;
    unsigned YG_ST   : 1;
    unsigned XG_ST   : 1;
} GYRO_CONFIG_t;



/* ----------------------------------------------
 *   Temperature
 * ----------------------------------------------
 */

#define TEMP   0x41
typedef int16_t  TEMP_RAW_t;


/* ----------------------------------------------
 *   Who Am I
 * ----------------------------------------------
 */

#define WHO_AM_I   0x75
typedef uint8_t  WHO_AM_I_t;
