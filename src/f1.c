#include "f1.h"
#include <stdint.h>

/* IRQs vector table
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


__attribute__ ((section(".IRQ_VECTOR_TABLE")))
IRQ_VECTOR_TABLE_t IRQ_VECTOR_TABLE =
    { WWDG_ISR               , I2C2_ER_ISR
    , PVD_ISR                , SPI1_ISR
    , TAMPER_ISR             , SPI2_ISR
    , RTC_ISR                , USART1_ISR
    , FLASH_ISR              , USART2_ISR
    , RCC_ISR                , USART3_ISR
    , EXTI0_ISR              , EXTI15_10_ISR
    , EXTI1_ISR              , RTCALARM_ISR
    , EXTI2_ISR              , USBWAKEUP_ISR
    , EXTI3_ISR              , TIM8_BRK_ISR
    , EXTI4_ISR              , TIM8_UP_ISR
    , DMA1_CHANNEL1_ISR      , TIM8_TRG_COM_ISR
    , DMA1_CHANNEL2_ISR      , TIM8_CC_ISR
    , DMA1_CHANNEL3_ISR      , ADC3_ISR
    , DMA1_CHANNEL4_ISR      , FSMC_ISR
    , DMA1_CHANNEL5_ISR      , SDIO_ISR
    , DMA1_CHANNEL6_ISR      , TIM5_ISR
    , DMA1_CHANNEL7_ISR      , SPI3_ISR
    , ADC1_2_ISR             , UART4_ISR
    , USB_HP_CAN_TX_ISR      , UART5_ISR
    , USB_LP_CAN_RX0_ISR     , TIM6_ISR
    , CAN_RX1_ISR            , TIM7_ISR
    , CAN_SCE_ISR            , DMA2_CHANNEL1_ISR
    , EXTI9_5_ISR            , DMA2_CHANNEL2_ISR
    , TIM1_BRK_ISR           , DMA2_CHANNEL3_ISR
    , TIM1_UP_ISR            , DMA2_CHANNEL4_5_ISR
    , TIM1_TRG_COM_ISR       , DMA2_CHANNEL5_ISR
    , TIM1_CC_ISR            , ETH_ISR
    , TIM2_ISR               , ETH_WKUP_ISR
    , TIM3_ISR               , CAN2_TX_ISR
    , TIM4_ISR               , CAN2_RX0_ISR
    , I2C1_EV_ISR            , CAN2_RX1_ISR
    , I2C1_ER_ISR            , CAN2_SCE_ISR
    , I2C2_EV_ISR            , OTG_FS_ISR
    };
