#include <f1.h>
#include <cmsis.h>
#include <rcc.h>
#include <usart.h>
#include <i2c.h>
#include <external/mpu6050.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void delay(void);

volatile float gx = 0;
volatile float gy = 0;
volatile float gz = 0;
volatile float ax = 0;
volatile float ay = 0;
volatile float az = 0;
volatile float x = 0;
volatile float y = 0;
volatile float z = 0;


void TIM2_ISR(void)
{
    TIM2_SR->UIF = false;
    GYRO_t gyro = mpu6050_read_gyro();
    ACCEL_t accel = mpu6050_read_accel();

    gx += gyro.x / 100;
    gy += gyro.y / 100;
    gz += gyro.z / 100;

    ax = atan2f(accel.y, accel.z) * (180/M_PI);
    ay = atan2f(accel.x, accel.z) * (180/M_PI);

    x = (0.95 * gx) + (0.05 * ax);
    y = (0.95 * gy) + (0.05 * ay);
    z = gz;
}

void setup_timer(void)
{
    __enable_irq();
    NVIC_EnableIRQ(TIM2_IRQ);
    NVIC_SetPriority(TIM2_IRQ, 5);
    RCC_APB1ENR->TIM2EN = true;
    TIM2_CR1->DIR = false; // Upcounter
    *TIM2_CNT = 0;
    *TIM2_PSC = 7200-1; // 10Khz
    *TIM2_ARR = 100-1; // 10ms
    TIM2_DIER->UIE = true; // TIM2 interrupt enable
    TIM2_CR1->CEN = true; // Enable counter
}

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
    mpu6050_wake_up();
    delay(); // Wait mpu6050
    mpu6050_calibrate_gyro();
    delay(); // Wait mpu6050

    setup_timer();

    while (true)
    {
        printf("x = %.1f\ty = %.1f\tz = %.1f\t   \t   \t\r\n", x, y, z);
    }
}

void delay(void)
{
    for (int i = 0; i < 900000; i++);
}
