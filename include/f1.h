#pragma once
#include <stdint.h>

/* ----------------------------------------------
 *   IRQ handlers
 * ----------------------------------------------
 */
#define _weak_  void __attribute__ ((weak))
_weak_     WWDG_ISR(void),                     I2C2_ER_ISR(void);
_weak_     PVD_ISR(void),                      SPI1_ISR(void);
_weak_     TAMPER_ISR(void),                   SPI2_ISR(void);
_weak_     RTC_ISR(void),                      USART1_ISR(void);
_weak_     FLASH_ISR(void),                    USART2_ISR(void);
_weak_     RCC_ISR(void),                      USART3_ISR(void);
_weak_     EXTI0_ISR(void),                    EXTI15_10_ISR(void);
_weak_     EXTI1_ISR(void),                    RTCALARM_ISR(void);
_weak_     EXTI2_ISR(void),                    USBWAKEUP_ISR(void);
_weak_     EXTI3_ISR(void),                    TIM8_BRK_ISR(void);
_weak_     EXTI4_ISR(void),                    TIM8_UP_ISR(void);
_weak_     DMA1_CHANNEL1_ISR(void),            TIM8_TRG_COM_ISR(void);
_weak_     DMA1_CHANNEL2_ISR(void),            TIM8_CC_ISR(void);
_weak_     DMA1_CHANNEL3_ISR(void),            ADC3_ISR(void);
_weak_     DMA1_CHANNEL4_ISR(void),            FSMC_ISR(void);
_weak_     DMA1_CHANNEL5_ISR(void),            SDIO_ISR(void);
_weak_     DMA1_CHANNEL6_ISR(void),            TIM5_ISR(void);
_weak_     DMA1_CHANNEL7_ISR(void),            SPI3_ISR(void);
_weak_     ADC1_2_ISR(void),                   UART4_ISR(void);
_weak_     USB_HP_CAN_TX_ISR(void),            UART5_ISR(void);
_weak_     USB_LP_CAN_RX0_ISR(void),           TIM6_ISR(void);
_weak_     CAN_RX1_ISR(void),                  TIM7_ISR(void);
_weak_     CAN_SCE_ISR(void),                  DMA2_CHANNEL1_ISR(void);
_weak_     EXTI9_5_ISR(void),                  DMA2_CHANNEL2_ISR(void);
_weak_     TIM1_BRK_ISR(void),                 DMA2_CHANNEL3_ISR(void);
_weak_     TIM1_UP_ISR(void),                  DMA2_CHANNEL4_5_ISR(void);
_weak_     TIM1_TRG_COM_ISR(void),             DMA2_CHANNEL5_ISR(void);
_weak_     TIM1_CC_ISR(void),                  ETH_ISR(void);
_weak_     TIM2_ISR(void),                     ETH_WKUP_ISR(void);
_weak_     TIM3_ISR(void),                     CAN2_TX_ISR(void);
_weak_     TIM4_ISR(void),                     CAN2_RX0_ISR(void);
_weak_     I2C1_EV_ISR(void),                  CAN2_RX1_ISR(void);
_weak_     I2C1_ER_ISR(void),                  CAN2_SCE_ISR(void);
_weak_     I2C2_EV_ISR(void),                  OTG_FS_ISR(void);


/* ----------------------------------------------
 *   APB Memory Map
 * ----------------------------------------------
 */
#define _TIM2            0x40000000
#define _TIM3            0x40004000
#define _TIM4            0x40008000
#define _RTC             0x40002800
#define _WWDG            0x40002C00
#define _IWDG            0x40003000
#define _SPI2            0x40003800
#define _USART2          0x40004400
#define _USART3          0x40004800
#define _I2C1            0x40005400
#define _I2C2            0x40005800
#define _USB_REGISTERS   0x40005C00
#define _USB_CAN_SRAM    0x40006000
#define _BXCAN           0x40006400
#define _BKP             0x40006C00
#define _PWR             0x40007000
#define _AFIO            0x40010000
#define _EXTI            0x40010400
#define _PORTA           0x40010800
#define _PORTB           0x40010C00
#define _PORTC           0x40011000
#define _PORTD           0x40011400
#define _PORTE           0x40011800
#define _ADC1            0x40012400
#define _ADC2            0x40012800
#define _TIM1            0x40012C00
#define _CPI1            0x40013000
#define _USART1          0x40013800
#define _DMA             0x40020000
#define _RCC             0x40021000
#define _FLASH_INTERFACE 0x40022000
#define _CRC             0x40023000


/* --------------------------------------------------------------
 *   General purpose and alternate function I/O (GPIO and AFIOs)
 * --------------------------------------------------------------
 */

// Available modes (MODEy)
#define    MODE_INPUT           0b00
#define    MODE_OUTPUT_2MHZ     0b10
#define    MODE_OUTPUT_10MHZ    0b01
#define    MODE_OUTPUT_50MHZ    0b11

// Available configurations (CNFy)
#define   CNF_IN_ANALOG             0b00
#define   CNF_IN_FLOATING           0b01
#define   CNF_IN_PULL_UP_DOWN       0b10
#define   CNF_OUT_PUSH_PULL         0b00
#define   CNF_OUT_OPEN_DRAIN        0b01
#define   CNF_ALTERNATE_PUSH_PULL   0b10
#define   CNF_ALTERNATE_OPEN_DRAIN  0b11

typedef struct
{
    union
    {
        uint32_t CRL;
        struct
        {
            unsigned MODE0 : 2;
            unsigned CNF0  : 2;
            unsigned MODE1 : 2;
            unsigned CNF1  : 2;
            unsigned MODE2 : 2;
            unsigned CNF2  : 2;
            unsigned MODE3 : 2;
            unsigned CNF3  : 2;
            unsigned MODE4 : 2;
            unsigned CNF4  : 2;
            unsigned MODE5 : 2;
            unsigned CNF5  : 2;
            unsigned MODE6 : 2;
            unsigned CNF6  : 2;
            unsigned MODE7 : 2;
            unsigned CNF7  : 2;
        };
    };

    union
    {
        uint32_t CRH;
        struct
        {
            unsigned MODE8  : 2;
            unsigned CNF8   : 2;
            unsigned MODE9  : 2;
            unsigned CNF9   : 2;
            unsigned MODE10 : 2;
            unsigned CNF10  : 2;
            unsigned MODE11 : 2;
            unsigned CNF11  : 2;
            unsigned MODE12 : 2;
            unsigned CNF12  : 2;
            unsigned MODE13 : 2;
            unsigned CNF13  : 2;
            unsigned MODE14 : 2;
            unsigned CNF14  : 2;
            unsigned MODE15 : 2;
            unsigned CNF15  : 2;
        };
    };

    union
    {
        uint32_t IDR;
        struct
        {
            unsigned IDR0  : 1;
            unsigned IDR1  : 1;
            unsigned IDR2  : 1;
            unsigned IDR3  : 1;
            unsigned IDR4  : 1;
            unsigned IDR5  : 1;
            unsigned IDR6  : 1;
            unsigned IDR7  : 1;
            unsigned IDR8  : 1;
            unsigned IDR9  : 1;
            unsigned IDR10 : 1;
            unsigned IDR11 : 1;
            unsigned IDR12 : 1;
            unsigned IDR13 : 1;
            unsigned IDR14 : 1;
            unsigned IDR15 : 1;
            unsigned       : 16;
        };
    };

    union
    {
        uint32_t ODR;
        struct
        {
            unsigned ODR0  : 1;
            unsigned ODR1  : 1;
            unsigned ODR2  : 1;
            unsigned ODR3  : 1;
            unsigned ODR4  : 1;
            unsigned ODR5  : 1;
            unsigned ODR6  : 1;
            unsigned ODR7  : 1;
            unsigned ODR8  : 1;
            unsigned ODR9  : 1;
            unsigned ODR10 : 1;
            unsigned ODR11 : 1;
            unsigned ODR12 : 1;
            unsigned ODR13 : 1;
            unsigned ODR14 : 1;
            unsigned ODR15 : 1;
            unsigned       : 16;
        };
    };

    uint32_t BSRR;
    uint32_t BRR;

    union
    {
        uint32_t LCKR;
        struct
        {
            unsigned LCK0  : 1;
            unsigned LCK1  : 1;
            unsigned LCK2  : 1;
            unsigned LCK3  : 1;
            unsigned LCK4  : 1;
            unsigned LCK5  : 1;
            unsigned LCK6  : 1;
            unsigned LCK7  : 1;
            unsigned LCK8  : 1;
            unsigned LCK9  : 1;
            unsigned LCK10 : 1;
            unsigned LCK11 : 1;
            unsigned LCK12 : 1;
            unsigned LCK13 : 1;
            unsigned LCK14 : 1;
            unsigned LCK15 : 1;
            unsigned LCKK  : 1;
            unsigned       : 15;
        };
    };
} GPIO_PORT_t;

static volatile GPIO_PORT_t* const PORTA = (void*) _PORTA;
static volatile GPIO_PORT_t* const PORTB = (void*) _PORTB;
static volatile GPIO_PORT_t* const PORTC = (void*) _PORTC;
static volatile GPIO_PORT_t* const PORTD = (void*) _PORTD;
static volatile GPIO_PORT_t* const PORTE = (void*) _PORTE;
