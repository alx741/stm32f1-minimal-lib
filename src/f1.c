#include "f1.h"
#include <stdint.h>

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
