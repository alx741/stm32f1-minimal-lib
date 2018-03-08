#pragma once
#include <stdint.h>

/* ----------------------------------------------
 *   IRQs vector table
 * ----------------------------------------------
 */
typedef struct
{
  // IRQ 0 - 33                    IRQ  34 - 68
    void*  WWDG;                  void*  I2C2_ER;
    void*  PVD;                   void*  SPI1;
    void*  TAMPER;                void*  SPI2;
    void*  RTC;                   void*  USART1;
    void*  FLASH;                 void*  USART2;
    void*  RCC;                   void*  USART3;
    void*  EXTI0;                 void*  EXTI15_10;
    void*  EXTI1;                 void*  RTCALARM;
    void*  EXTI2;                 void*  USBWAKEUP;
    void*  EXTI3;                 void*  TIM8_BRK;
    void*  EXTI4;                 void*  TIM8_UP;
    void*  DMA1_CHANNEL1;         void*  TIM8_TRG_COM;
    void*  DMA1_CHANNEL2;         void*  TIM8_CC;
    void*  DMA1_CHANNEL3;         void*  ADC3;
    void*  DMA1_CHANNEL4;         void*  FSMC;
    void*  DMA1_CHANNEL5;         void*  SDIO;
    void*  DMA1_CHANNEL6;         void*  TIM5;
    void*  DMA1_CHANNEL7;         void*  SPI3;
    void*  ADC1_2;                void*  UART4;
    void*  USB_HP_CAN_TX;         void*  UART5;
    void*  USB_LP_CAN_RX0;        void*  TIM6;
    void*  CAN_RX1;               void*  TIM7;
    void*  CAN_SCE;               void*  DMA2_CHANNEL1;
    void*  EXTI9_5;               void*  DMA2_CHANNEL2;
    void*  TIM1_BRK;              void*  DMA2_CHANNEL3;
    void*  TIM1_UP;               void*  DMA2_CHANNEL4_5;
    void*  TIM1_TRG_COM;          void*  DMA2_CHANNEL5;
    void*  TIM1_CC;               void*  ETH;
    void*  TIM2;                  void*  ETH_WKUP;
    void*  TIM3;                  void*  CAN2_TX;
    void*  TIM4;                  void*  CAN2_RX0;
    void*  I2C1_EV;               void*  CAN2_RX1;
    void*  I2C1_ER;               void*  CAN2_SCE;
    void*  I2C2_EV;               void*  OTG_FS;
} IRQ_VECTOR_TABLE_t;


/* ----------------------------------------------
 *   IRQ handlers
 * ----------------------------------------------
 */
void __attribute__ ((weak)) WWDG_ISR(void);
void __attribute__ ((weak)) PVD_ISR(void);
void __attribute__ ((weak)) TAMPER_ISR(void);
void __attribute__ ((weak)) RTC_ISR(void);
void __attribute__ ((weak)) FLASH_ISR(void);
void __attribute__ ((weak)) RCC_ISR(void);
void __attribute__ ((weak)) EXTI0_ISR(void);
void __attribute__ ((weak)) EXTI1_ISR(void);
void __attribute__ ((weak)) EXTI2_ISR(void);
void __attribute__ ((weak)) EXTI3_ISR(void);
void __attribute__ ((weak)) EXTI4_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL1_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL2_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL3_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL4_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL5_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL6_ISR(void);
void __attribute__ ((weak)) DMA1_CHANNEL7_ISR(void);
void __attribute__ ((weak)) ADC1_2_ISR(void);
void __attribute__ ((weak)) USB_HP_CAN_TX_ISR(void);
void __attribute__ ((weak)) USB_LP_CAN_RX0_ISR(void);
void __attribute__ ((weak)) CAN_RX1_ISR(void);
void __attribute__ ((weak)) CAN_SCE_ISR(void);
void __attribute__ ((weak)) EXTI9_5_ISR(void);
void __attribute__ ((weak)) TIM1_BRK_ISR(void);
void __attribute__ ((weak)) TIM1_UP_ISR(void);
void __attribute__ ((weak)) TIM1_TRG_COM_ISR(void);
void __attribute__ ((weak)) TIM1_CC_ISR(void);
void __attribute__ ((weak)) TIM2_ISR(void);
void __attribute__ ((weak)) TIM3_ISR(void);
void __attribute__ ((weak)) TIM4_ISR(void);
void __attribute__ ((weak)) I2C1_EV_ISR(void);
void __attribute__ ((weak)) I2C1_ER_ISR(void);
void __attribute__ ((weak)) I2C2_EV_ISR(void);
void __attribute__ ((weak)) I2C2_ER_ISR(void);
void __attribute__ ((weak)) SPI1_ISR(void);
void __attribute__ ((weak)) SPI2_ISR(void);
void __attribute__ ((weak)) USART1_ISR(void);
void __attribute__ ((weak)) USART2_ISR(void);
void __attribute__ ((weak)) USART3_ISR(void);
void __attribute__ ((weak)) EXTI15_10_ISR(void);
void __attribute__ ((weak)) RTCALARM_ISR(void);
void __attribute__ ((weak)) USBWAKEUP_ISR(void);
void __attribute__ ((weak)) TIM8_BRK_ISR(void);
void __attribute__ ((weak)) TIM8_UP_ISR(void);
void __attribute__ ((weak)) TIM8_TRG_COM_ISR(void);
void __attribute__ ((weak)) TIM8_CC_ISR(void);
void __attribute__ ((weak)) ADC3_ISR(void);
void __attribute__ ((weak)) FSMC_ISR(void);
void __attribute__ ((weak)) SDIO_ISR(void);
void __attribute__ ((weak)) TIM5_ISR(void);
void __attribute__ ((weak)) SPI3_ISR(void);
void __attribute__ ((weak)) UART4_ISR(void);
void __attribute__ ((weak)) UART5_ISR(void);
void __attribute__ ((weak)) TIM6_ISR(void);
void __attribute__ ((weak)) TIM7_ISR(void);
void __attribute__ ((weak)) DMA2_CHANNEL1_ISR(void);
void __attribute__ ((weak)) DMA2_CHANNEL2_ISR(void);
void __attribute__ ((weak)) DMA2_CHANNEL3_ISR(void);
void __attribute__ ((weak)) DMA2_CHANNEL4_5_ISR(void);
void __attribute__ ((weak)) DMA2_CHANNEL5_ISR(void);
void __attribute__ ((weak)) ETH_ISR(void);
void __attribute__ ((weak)) ETH_WKUP_ISR(void);
void __attribute__ ((weak)) CAN2_TX_ISR(void);
void __attribute__ ((weak)) CAN2_RX0_ISR(void);
void __attribute__ ((weak)) CAN2_RX1_ISR(void);
void __attribute__ ((weak)) CAN2_SCE_ISR(void);
void __attribute__ ((weak)) OTG_FS_ISR(void);


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
