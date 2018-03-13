#include <f1.h>
#include <rcc.h>
#include <usart.h>
#include <i2c.h>
#include <external/mpu6050.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void delay(void);

int main(void)
{
    rcc_setup_in_8mhz_hse_out_72mhz();

    RCC_APB2ENR->IOPCEN = true;
    PORTC->MODE15 = MODE_OUTPUT_50MHZ;
    PORTC->CNF15 = CNF_OUT_PUSH_PULL;

    PORTC->MODE14 = MODE_INPUT;
    PORTC->CNF14 = CNF_IN_PULL_UP_DOWN;

    usart_init_72mhz_9600baud();
    i2c_init_100khz();

    delay(); // Wait mpu6050

    // Wake mpu6050 up
    mpu6050_wake_up();

    /* int somechar; */
    while (true)
    {
        delay();

        ACCEL_t accel = mpu6050_read_accel();
        printf("x = %f, y = %f, z = %f\r\n", accel.x, accel.y, accel.z);

        /* GYRO_t gyro = mpu6050_read_gyro(); */
        /* printf("x = %f, y = %f, z = %f\r\n", gyro.x, gyro.y, gyro.z); */

        /* float temp = mpu6050_read_temp(); */
        /* printf("temp = %f\r\n", temp); */

        /* somechar = getchar(); */
        /* if (somechar == 'o') */
        /* { */
        /*     PORTC->ODR15 = true; */
        /*     printf("on\r\n"); */
        /* } */
        /* else */
        /* { */
        /*     PORTC->ODR15 = false; */
        /*     printf("off\r\n"); */
        /* } */
    }
}

void delay(void)
{
    for (int i = 0; i < 900000; i++);
}
