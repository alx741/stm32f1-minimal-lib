#include <f1.h>
#include <cmsis.h>
#include <rcc.h>
#include <usart.h>
#include <i2c.h>
#include <external/mpu6050.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void delay(void);

volatile float x = 0;
volatile float y = 0;
volatile float z = 0;


void TIM2_ISR(void)
{
    TIM2_SR->UIF = false;
    GYRO_t gyro = mpu6050_read_gyro();
    x += gyro.x / 100;
    y += gyro.y / 100;
    z += gyro.z / 100;
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

    /* int somechar; */
    while (true)
    {
        /* ACCEL_t accel = mpu6050_read_accel(); */
        /* printf("x = %f, y = %f, z = %f\r\n", accel.x, accel.y, accel.z); */

        printf("x = %.1f\ty = %.1f\tz = %.1f\t\r\n", x, y, z);

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
