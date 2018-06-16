#pragma once
#include <stdint.h>

/* ----------------------------------------------
 *   IRS handlers
 * ----------------------------------------------
 */

// Enable IRQs with CMSIS functions and enable peripheral interrupts
//
//     __enable_irq();
//     NVIC_EnableIRQ(TIM2_IRQ);
//     ...
//     TIM2_DIER->UIE = true;
//
//
// Handle ISRs in your own code
//
//     void TIM2_ISR(void)
//     {
//         // do something here
//     }
//
#define _weak_  void __attribute__ ((weak, isr("IRQ")))
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
 *   IRQs
 * ----------------------------------------------
 */

#define   WWDG_IRQ              0
#define   PVD_IRQ               1
#define   TAMPER_IRQ            2
#define   RTC_IRQ               3
#define   FLASH_IRQ             4
#define   RCC_IRQ               5
#define   EXTI0_IRQ             6
#define   EXTI1_IRQ             7
#define   EXTI2_IRQ             8
#define   EXTI3_IRQ             9
#define   EXTI4_IRQ             10
#define   DMA1_CHANNEL1_IRQ     11
#define   DMA1_CHANNEL2_IRQ     12
#define   DMA1_CHANNEL3_IRQ     13
#define   DMA1_CHANNEL4_IRQ     14
#define   DMA1_CHANNEL5_IRQ     15
#define   DMA1_CHANNEL6_IRQ     16
#define   DMA1_CHANNEL7_IRQ     17
#define   ADC1_2_IRQ            18
#define   USB_HP_CAN_TX_IRQ     19
#define   USB_LP_CAN_RX0_IRQ    20
#define   CAN_RX1_IRQ           21
#define   CAN_SCE_IRQ           22
#define   EXTI9_5_IRQ           23
#define   TIM1_BRK_IRQ          24
#define   TIM1_UP_IRQ           25
#define   TIM1_TRG_COM_IRQ      26
#define   TIM1_CC_IRQ           27
#define   TIM2_IRQ              28
#define   TIM3_IRQ              29
#define   TIM4_IRQ              30
#define   I2C1_EV_IRQ           31
#define   I2C1_ER_IRQ           32
#define   I2C2_EV_IRQ           33
#define   I2C2_ER_IRQ           34
#define   SPI1_IRQ              35
#define   SPI2_IRQ              36
#define   USART1_IRQ            37
#define   USART2_IRQ            38
#define   USART3_IRQ            39
#define   EXTI15_10_IRQ         40
#define   RTCALARM_IRQ          41
#define   USBWAKEUP_IRQ         42
#define   TIM8_BRK_IRQ          43
#define   TIM8_UP_IRQ           44
#define   TIM8_TRG_COM_IRQ      45
#define   TIM8_CC_IRQ           46
#define   ADC3_IRQ              47
#define   FSMC_IRQ              48
#define   SDIO_IRQ              49
#define   TIM5_IRQ              50
#define   SPI3_IRQ              51
#define   UART4_IRQ             52
#define   UART5_IRQ             53
#define   TIM6_IRQ              54
#define   TIM7_IRQ              55
#define   DMA2_CHANNEL1_IRQ     56
#define   DMA2_CHANNEL2_IRQ     57
#define   DMA2_CHANNEL3_IRQ     58
#define   DMA2_CHANNEL4_5_IRQ   59
#define   DMA2_CHANNEL5_IRQ     60
#define   ETH_IRQ               61
#define   ETH_WKUP_IRQ          62
#define   CAN2_TX_IRQ           63
#define   CAN2_RX0_IRQ          64
#define   CAN2_RX1_IRQ          65
#define   CAN2_SCE_IRQ          66
#define   OTG_FS_IRQ            67


/* ----------------------------------------------
 *   APB Memory Map
 * ----------------------------------------------
 */
#define _TIM2            0x40000000
#define _TIM3            0x40000400
#define _TIM4            0x40000800
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
 *   Embedded Flash Memory
 * --------------------------------------------------------------
 */

typedef struct
{
    unsigned LATENCY : 3;
    unsigned HLFCYA  : 1;
    unsigned PRFTBE  : 1;
    unsigned PRFTBS  : 1;
    unsigned         : 26;
} FLASH_ACR_t;

static volatile FLASH_ACR_t*  const FLASH_ACR = (void*) _FLASH_INTERFACE;


/* --------------------------------------------------------------
 *   Reset and Clock Control (RCC)
 * --------------------------------------------------------------
 */

typedef struct
{
    unsigned HSION   : 1;
    unsigned HSIRDY  : 1;
    unsigned         : 1;
    unsigned HSITRIM : 5;
    unsigned HSICAL  : 8;
    unsigned HSEON   : 1;
    unsigned HSERDY  : 1;
    unsigned HSEBYP  : 1;
    unsigned CSSON   : 1;
    unsigned         : 4;
    unsigned PLLON   : 1;
    unsigned PLLRDY  : 1;
    unsigned         : 6;
} RCC_CR_t;

typedef struct
{
    unsigned SW       : 2;
    unsigned SWS      : 2;
    unsigned HPRE     : 4;
    unsigned PPRE1    : 3;
    unsigned PPRE2    : 3;
    unsigned ADCPRE   : 2;
    unsigned PLLSRC   : 1;
    unsigned PLLXTPRE : 1;
    unsigned PLLMUL   : 4;
    unsigned USBPRE   : 1;
    unsigned          : 1;
    unsigned MCO      : 3;
    unsigned          : 5;
} RCC_CFGR_t;

typedef struct
{
    unsigned LSIRDYF  : 1;
    unsigned LSERDYF  : 1;
    unsigned HSIRDYF  : 1;
    unsigned HSERDYF  : 1;
    unsigned PLLRDYF  : 1;
    unsigned          : 2;
    unsigned CSSF     : 1;
    unsigned LSIRDYIE : 1;
    unsigned LSERDYIE : 1;
    unsigned HSIRDYIE : 1;
    unsigned HSERDYIE : 1;
    unsigned PLLRDYIE : 1;
    unsigned          : 3;
    unsigned LSIRDYC  : 1;
    unsigned LSERDYC  : 1;
    unsigned HSIRDYC  : 1;
    unsigned HSERDYC  : 1;
    unsigned PLLRDYC  : 1;
    unsigned          : 2;
    unsigned CSSC     : 1;
    unsigned          : 8;
} RCC_CIR_t;

typedef struct
{
    unsigned AFIORST   : 1;
    unsigned           : 1;
    unsigned IOPARST   : 1;
    unsigned IOPBRST   : 1;
    unsigned IOPCRST   : 1;
    unsigned IOPDRST   : 1;
    unsigned IOPERST   : 1;
    unsigned IOPFRST   : 1;
    unsigned IOPGRST   : 1;
    unsigned ADC1RST   : 1;
    unsigned ADC2RST   : 1;
    unsigned TIM1RST   : 1;
    unsigned SPI1RST   : 1;
    unsigned TIM8RST   : 1;
    unsigned USART1RST : 1;
    unsigned ADC3RST   : 1;
    unsigned           : 3;
    unsigned TIM9RST   : 1;
    unsigned TIM10RST  : 1;
    unsigned TIM11RST  : 1;
    unsigned           : 10;
} RCC_APB2RSTR_t;

typedef struct
{
    unsigned TIM2RST   : 1;
    unsigned TIM3RST   : 1;
    unsigned TIM4RST   : 1;
    unsigned TIM5RST   : 1;
    unsigned TIM6RST   : 1;
    unsigned TIM7RST   : 1;
    unsigned TIM12RST  : 1;
    unsigned TIM13RST  : 1;
    unsigned TIM14RST  : 1;
    unsigned           : 2;
    unsigned WWDGRST   : 1;
    unsigned           : 2;
    unsigned SPI2RST   : 1;
    unsigned SPI3RST   : 1;
    unsigned           : 1;
    unsigned USART2RST : 1;
    unsigned USART3RST : 1;
    unsigned USART4RST : 1;
    unsigned USART5RST : 1;
    unsigned I2C1RST   : 1;
    unsigned I2C2RST   : 1;
    unsigned USBRST    : 1;
    unsigned           : 1;
    unsigned CANRST    : 1;
    unsigned           : 1;
    unsigned BKPRST    : 1;
    unsigned PWRRST    : 1;
    unsigned DACRST    : 1;
    unsigned           : 2;
} RCC_APB1RSTR_t;

typedef struct
{
    unsigned DMA1EN  : 1;
    unsigned DMA2EN  : 1;
    unsigned SRAMEN  : 1;
    unsigned         : 1;
    unsigned FLITFEN : 1;
    unsigned         : 1;
    unsigned CRCEN   : 1;
    unsigned         : 1;
    unsigned FSMCEN  : 1;
    unsigned         : 1;
    unsigned SDIOEN  : 1;
    unsigned         : 21;
} RCC_AHBENR_t;

typedef struct
{
    unsigned AFIOEN   : 1;
    unsigned          : 1;
    unsigned IOPAEN   : 1;
    unsigned IOPBEN   : 1;
    unsigned IOPCEN   : 1;
    unsigned IOPDEN   : 1;
    unsigned IOPEEN   : 1;
    unsigned IOPFEN   : 1;
    unsigned IOPGEN   : 1;
    unsigned ADC1EN   : 1;
    unsigned ADC2EN   : 1;
    unsigned TIM1EN   : 1;
    unsigned SPI1EN   : 1;
    unsigned TIM8EN   : 1;
    unsigned USART1EN : 1;
    unsigned ADC3EN   : 1;
    unsigned          : 3;
    unsigned TIM9EN   : 1;
    unsigned TIM10EN  : 1;
    unsigned TIM11EN  : 1;
    unsigned          : 10;
} RCC_APB2ENR_t;

typedef struct
{
    unsigned TIM2EN    : 1;
    unsigned TIM3EN    : 1;
    unsigned TIM4EN    : 1;
    unsigned TIM5EN    : 1;
    unsigned TIM6EN    : 1;
    unsigned TIM7EN    : 1;
    unsigned TIM12EN   : 1;
    unsigned TIM13EN   : 1;
    unsigned TIM14EN   : 1;
    unsigned           : 2;
    unsigned WWDGEN    : 1;
    unsigned           : 2;
    unsigned SPI2EN    : 1;
    unsigned SPI3EN    : 1;
    unsigned           : 1;
    unsigned USART2EN  : 1;
    unsigned USART3EN  : 1;
    unsigned USART4EN  : 1;
    unsigned USART5EN  : 1;
    unsigned I2C1EN    : 1;
    unsigned I2C2EN    : 1;
    unsigned USBEN     : 1;
    unsigned           : 1;
    unsigned CANEN     : 1;
    unsigned           : 1;
    unsigned BKPEN     : 1;
    unsigned PWREN     : 1;
    unsigned DACEN     : 1;
    unsigned           : 2;
} RCC_APB1ENR_t;

typedef struct
{
    unsigned LSEON  : 1;
    unsigned LSERDY : 1;
    unsigned LSEBYP : 1;
    unsigned        : 5;
    unsigned RTCSEL : 2;
    unsigned        : 5;
    unsigned RTCEN  : 1;
    unsigned BDRST  : 1;
    unsigned        : 15;
} RCC_BDCR_t;

typedef struct
{
    unsigned LSION    : 1;
    unsigned LSIRDY   : 1;
    unsigned          : 22;
    unsigned RMVF     : 1;
    unsigned          : 1;
    unsigned PINRSTF  : 1;
    unsigned PORRSTF  : 1;
    unsigned SFTRSTF  : 1;
    unsigned IWDGRSTF : 1;
    unsigned WWDGRSTF : 1;
    unsigned LPWRRSTF : 1;
} RCC_CSR_t;

static volatile RCC_CR_t*       const RCC_CR       = (void*) _RCC + 0x00;
static volatile RCC_CFGR_t*     const RCC_CFGR     = (void*) _RCC + 0x04;
static volatile RCC_CIR_t*      const RCC_CIR      = (void*) _RCC + 0x08;
static volatile RCC_APB2RSTR_t* const RCC_APB2RSTR = (void*) _RCC + 0x0C;
static volatile RCC_APB1RSTR_t* const RCC_APB1RSTR = (void*) _RCC + 0x10;
static volatile RCC_AHBENR_t*   const RCC_AHBENR   = (void*) _RCC + 0x14;
static volatile RCC_APB2ENR_t*  const RCC_APB2ENR  = (void*) _RCC + 0x18;
static volatile RCC_APB1ENR_t*  const RCC_APB1ENR  = (void*) _RCC + 0x1C;
static volatile RCC_BDCR_t*     const RCC_BDCR     = (void*) _RCC + 0x20;
static volatile RCC_CSR_t*      const RCC_CSR      = (void*) _RCC + 0x24;


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


/* ------------------------------------------------------------------
 *   General-purpose timers (TIM2 to TIM5)
 * ------------------------------------------------------------------
 */

typedef struct
{
    unsigned CEN  : 1;
    unsigned UDIS : 1;
    unsigned URS  : 1;
    unsigned OPM  : 1;
    unsigned DIR  : 1;
    unsigned CMS  : 2;
    unsigned ARPE : 1;
    unsigned CKD  : 2;
    unsigned      : 6;
} TIM_CR1_t;

typedef struct
{
    unsigned      : 3;
    unsigned CCDS : 1;
    unsigned MMS  : 3;
    unsigned TI1S : 1;
    unsigned      : 8;
} TIM_CR2_t;

typedef struct
{
    unsigned SMS  : 3;
    unsigned      : 1;
    unsigned TS   : 3;
    unsigned MSM  : 1;
    unsigned ETF  : 4;
    unsigned ETPS : 2;
    unsigned ECE  : 1;
    unsigned ETP  : 1;
} TIM_SMCR_t;

typedef struct
{
    unsigned UIE   : 1;
    unsigned CC1IE : 1;
    unsigned CC2IE : 1;
    unsigned CC3IE : 1;
    unsigned CC4IE : 1;
    unsigned       : 1;
    unsigned TIE   : 1;
    unsigned       : 1;
    unsigned UDE   : 1;
    unsigned CC1DE : 1;
    unsigned CC2DE : 1;
    unsigned CC3DE : 1;
    unsigned CC4DE : 1;
    unsigned       : 1;
    unsigned TDE   : 1;
    unsigned       : 1;
} TIM_DIER_t;

typedef struct
{
    unsigned UIF   : 1;
    unsigned CC1IF : 1;
    unsigned CC2IF : 1;
    unsigned CC3IF : 1;
    unsigned CC4IF : 1;
    unsigned       : 1;
    unsigned TIF   : 1;
    unsigned       : 2;
    unsigned CC1OF : 1;
    unsigned CC2OF : 1;
    unsigned CC3OF : 1;
    unsigned CC4OF : 1;
    unsigned       : 3;
} TIM_SR_t;

typedef struct
{
    unsigned UG   : 1;
    unsigned CC1G : 1;
    unsigned CC2G : 1;
    unsigned CC3G : 1;
    unsigned CC4G : 1;
    unsigned      : 1;
    unsigned TG   : 1;
    unsigned      : 9;
} TIM_EGR_t;

typedef struct
{
    unsigned CC1S : 2;
    union
    {
        struct
        {
            unsigned OC1FE : 1;
            unsigned OC1PE : 1;
        };
        struct
        {
            unsigned IC1PSC : 2;
        };
    };
    union
    {
        struct
        {
            unsigned OC1M : 3;
            unsigned OC1CE : 1;
        };
        struct
        {
            unsigned IC1F : 4;
        };
    };
    unsigned CC2S : 2;
    union
    {
        struct
        {
            unsigned OC2FE : 1;
            unsigned OC2PE : 1;
        };
        struct
        {
            unsigned IC2PSC : 2;
        };
    };
    union
    {
        struct
        {
            unsigned OC2M : 3;
            unsigned OC2CE : 1;
        };
        struct
        {
            unsigned IC2F : 4;
        };
    };
} TIM_CCMR1_t;

typedef struct
{
    unsigned CC3S : 2;
    union
    {
        struct
        {
            unsigned OC3FE : 1;
            unsigned OC3PE : 1;
        };
        struct
        {
            unsigned IC3PSC : 2;
        };
    };
    union
    {
        struct
        {
            unsigned OC3M : 3;
            unsigned OC3CE : 1;
        };
        struct
        {
            unsigned IC3F : 4;
        };
    };
    unsigned CC4S : 2;
    union
    {
        struct
        {
            unsigned OC4FE : 1;
            unsigned OC4PE : 1;
        };
        struct
        {
            unsigned IC4PSC : 2;
        };
    };
    union
    {
        struct
        {
            unsigned OC4M : 3;
            unsigned OC4CE : 1;
        };
        struct
        {
            unsigned IC4F : 4;
        };
    };
} TIM_CCMR2_t;

typedef struct
{
    unsigned CC1E : 1;
    unsigned CC1P : 1;
    unsigned      : 2;
    unsigned CC2E : 1;
    unsigned CC2P : 1;
    unsigned      : 2;
    unsigned CC3E : 1;
    unsigned CC3P : 1;
    unsigned      : 2;
    unsigned CC4E : 1;
    unsigned CC4P : 1;
    unsigned      : 2;
} TIM_CCER_t;

typedef struct
{
    unsigned DBA : 5;
    unsigned     : 3;
    unsigned DBL : 5;
    unsigned     : 3;
} TIM_DCR_t;

static volatile TIM_CR1_t*   const TIM2_CR1   = (void*) _TIM2 + 0x00;
static volatile TIM_CR2_t*   const TIM2_CR2   = (void*) _TIM2 + 0x04;
static volatile TIM_SMCR_t*  const TIM2_SMCR  = (void*) _TIM2 + 0x08;
static volatile TIM_DIER_t*  const TIM2_DIER  = (void*) _TIM2 + 0x0C;
static volatile TIM_SR_t*    const TIM2_SR    = (void*) _TIM2 + 0x10;
static volatile TIM_EGR_t*   const TIM2_EGR   = (void*) _TIM2 + 0x14;
static volatile TIM_CCMR1_t* const TIM2_CCMR1 = (void*) _TIM2 + 0x18;
static volatile TIM_CCMR2_t* const TIM2_CCMR2 = (void*) _TIM2 + 0x1C;
static volatile TIM_CCER_t*  const TIM2_CCER  = (void*) _TIM2 + 0x20;
static volatile uint16_t*    const TIM2_CNT   = (void*) _TIM2 + 0x24;
static volatile uint16_t*    const TIM2_PSC   = (void*) _TIM2 + 0x28;
static volatile uint16_t*    const TIM2_ARR   = (void*) _TIM2 + 0x2C;
static volatile uint16_t*    const TIM2_CCR1  = (void*) _TIM2 + 0x34;
static volatile uint16_t*    const TIM2_CCR2  = (void*) _TIM2 + 0x38;
static volatile uint16_t*    const TIM2_CCR3  = (void*) _TIM2 + 0x3C;
static volatile uint16_t*    const TIM2_CCR4  = (void*) _TIM2 + 0x40;
static volatile TIM_DCR_t*   const TIM2_DCR   = (void*) _TIM2 + 0x48;
static volatile uint16_t*    const TIM2_DMAR  = (void*) _TIM2 + 0x4C;


/* ------------------------------------------------------------------
 *   Inter-integrated circuit interface (I2C)
 * ------------------------------------------------------------------
 */

typedef struct
{
    unsigned PE        : 1;
    unsigned SMBUS     : 1;
    unsigned           : 1;
    unsigned SMBTYPE   : 1;
    unsigned ENARP     : 1;
    unsigned ENPEC     : 1;
    unsigned ENGC      : 1;
    unsigned NOSTRETCH : 1;
    unsigned START     : 1;
    unsigned STOP      : 1;
    unsigned ACK       : 1;
    unsigned POS       : 1;
    unsigned PEC       : 1;
    unsigned ALERT     : 1;
    unsigned           : 1;
    unsigned SWRST     : 1;
} I2C_CR1_t;

typedef struct
{
    unsigned FREQ    : 6;
    unsigned         : 2;
    unsigned ITERREN : 1;
    unsigned ITEVTEN : 1;
    unsigned ITBUFEN : 1;
    unsigned DMAEN   : 1;
    unsigned LAST    : 1;
    unsigned         : 3;
} I2C_CR2_t;

typedef struct
{
    unsigned ADD0    : 1;
    unsigned ADD     : 9;
    unsigned         : 5;
    unsigned ADDMODE : 1;
} I2C_OAR1_t;

typedef struct
{
    unsigned ENDUAL : 1;
    unsigned ADD2   : 7;
    unsigned        : 8;
} I2C_OAR2_t;

typedef struct
{
    unsigned SB       : 1;
    unsigned ADDR     : 1;
    unsigned BTF      : 1;
    unsigned ADD10    : 1;
    unsigned STOPF    : 1;
    unsigned          : 1;
    unsigned RXNE     : 1;
    unsigned TXE      : 1;
    unsigned BERR     : 1;
    unsigned ARLO     : 1;
    unsigned AF       : 1;
    unsigned OVR      : 1;
    unsigned PECERR   : 1;
    unsigned          : 1;
    unsigned TIMEOUT  : 1;
    unsigned SMBALERT : 1;
} I2C_SR1_t;

typedef struct
{
    unsigned MSL        : 1;
    unsigned BUSY       : 1;
    unsigned TRA        : 1;
    unsigned            : 1;
    unsigned GENCALL    : 1;
    unsigned SMBDEFAULT : 1;
    unsigned SMBHOST    : 1;
    unsigned DUALF      : 1;
    unsigned PEC        : 8;
} I2C_SR2_t;

typedef struct
{
    unsigned CCR  : 12;
    unsigned      : 2;
    unsigned DUTY : 1;
    unsigned FS   : 1;
} I2C_CCR_t;

static volatile I2C_CR1_t*  const    I2C1_CR1   = (void*) _I2C1 + 0x00;
static volatile I2C_CR2_t*  const    I2C1_CR2   = (void*) _I2C1 + 0x04;
static volatile I2C_OAR1_t* const    I2C1_OAR1  = (void*) _I2C1 + 0x08;
static volatile I2C_OAR2_t* const    I2C1_OAR2  = (void*) _I2C1 + 0x0C;
static volatile uint8_t*    const    I2C1_DR    = (void*) _I2C1 + 0x10;
static volatile I2C_SR1_t*  const    I2C1_SR1   = (void*) _I2C1 + 0x14;
static volatile I2C_SR2_t*  const    I2C1_SR2   = (void*) _I2C1 + 0x18;
static volatile I2C_CCR_t*  const    I2C1_CCR   = (void*) _I2C1 + 0x1C;
static volatile uint8_t*    const    I2C1_TRISE = (void*) _I2C1 + 0x20;

static volatile I2C_CR1_t*  const I2C2_CR1   = (void*) _I2C2 + 0x00;
static volatile I2C_CR2_t*  const I2C2_CR2   = (void*) _I2C2 + 0x04;
static volatile I2C_OAR1_t* const I2C2_OAR1  = (void*) _I2C2 + 0x08;
static volatile I2C_OAR2_t* const I2C2_OAR2  = (void*) _I2C2 + 0x0C;
static volatile uint8_t*    const I2C2_DR    = (void*) _I2C2 + 0x10;
static volatile I2C_SR1_t*  const I2C2_SR1   = (void*) _I2C2 + 0x14;
static volatile I2C_SR2_t*  const I2C2_SR2   = (void*) _I2C2 + 0x18;
static volatile I2C_CCR_t*  const I2C2_CCR   = (void*) _I2C2 + 0x1C;
static volatile uint8_t*    const I2C2_TRISE = (void*) _I2C2 + 0x20;


/* ------------------------------------------------------------------
 *   Universal synchronous asynchronous receiver transmitter (USART)
 * ------------------------------------------------------------------
 */

typedef struct
{
    unsigned PE   : 1;
    unsigned FE   : 1;
    unsigned NE   : 1;
    unsigned ORE  : 1;
    unsigned IDLE : 1;
    unsigned RXNE : 1;
    unsigned TC   : 1;
    unsigned TXE  : 1;
    unsigned LBD  : 1;
    unsigned CTS  : 1;
    unsigned      : 22;
} USART_SR_t;

typedef struct
{
    unsigned DR : 9;
    unsigned    : 23;
} USART_DR_t;

typedef struct
{
    unsigned DIV_FRACTION : 4;
    unsigned DIV_MANTISSA : 12;
    unsigned              : 16;
} USART_BRR_t;

typedef struct
{
    unsigned SBK    : 1;
    unsigned RWU    : 1;
    unsigned RE     : 1;
    unsigned TE     : 1;
    unsigned IDLEIE : 1;
    unsigned RXNEIE : 1;
    unsigned TCIE   : 1;
    unsigned TXEIE  : 1;
    unsigned PEIE   : 1;
    unsigned PS     : 1;
    unsigned PCE    : 1;
    unsigned WAKE   : 1;
    unsigned M      : 1;
    unsigned UE     : 1;
    unsigned        : 2;
    unsigned        : 16;
} USART_CR1_t;

typedef struct
{
    unsigned ADD   : 4;
    unsigned       : 1;
    unsigned LBDL  : 1;
    unsigned LBDIE : 1;
    unsigned       : 1;
    unsigned LBCL  : 1;
    unsigned CPHA  : 1;
    unsigned CPOL  : 1;
    unsigned CKLEN : 1;
    unsigned STOP  : 2;
    unsigned LINEN : 1;
    unsigned       : 17;
} USART_CR2_t;

typedef struct
{
    unsigned EIE   : 1;
    unsigned IREN  : 1;
    unsigned IRLP  : 1;
    unsigned HDSEL : 1;
    unsigned NACK  : 1;
    unsigned SCEN  : 1;
    unsigned DMAR  : 1;
    unsigned DMAT  : 1;
    unsigned RTSE  : 1;
    unsigned CTSE  : 1;
    unsigned CTSIE : 1;
    unsigned       : 21;
} USART_CR3_t;

typedef struct
{
    unsigned PSC : 8;
    unsigned GT  : 8;
    unsigned     : 16;
} USART_GTPR_t;

static volatile USART_SR_t*   const USART1_SR   = (void*) _USART1 + 0x00;
static volatile USART_DR_t*   const USART1_DR   = (void*) _USART1 + 0x04;
static volatile USART_BRR_t*  const USART1_BRR  = (void*) _USART1 + 0x08;
static volatile USART_CR1_t*  const USART1_CR1  = (void*) _USART1 + 0x0C;
static volatile USART_CR2_t*  const USART1_CR2  = (void*) _USART1 + 0x10;
static volatile USART_CR3_t*  const USART1_CR3  = (void*) _USART1 + 0x14;
static volatile USART_GTPR_t* const USART1_GTPR = (void*) _USART1 + 0x18;

static volatile USART_SR_t*   const USART2_SR   = (void*) _USART2 + 0x00;
static volatile USART_DR_t*   const USART2_DR   = (void*) _USART2 + 0x04;
static volatile USART_BRR_t*  const USART2_BRR  = (void*) _USART2 + 0x08;
static volatile USART_CR1_t*  const USART2_CR1  = (void*) _USART2 + 0x0C;
static volatile USART_CR2_t*  const USART2_CR2  = (void*) _USART2 + 0x10;
static volatile USART_CR3_t*  const USART2_CR3  = (void*) _USART2 + 0x14;
static volatile USART_GTPR_t* const USART2_GTPR = (void*) _USART2 + 0x18;

static volatile USART_SR_t*   const USART3_SR   = (void*) _USART3 + 0x00;
static volatile USART_DR_t*   const USART3_DR   = (void*) _USART3 + 0x04;
static volatile USART_BRR_t*  const USART3_BRR  = (void*) _USART3 + 0x08;
static volatile USART_CR1_t*  const USART3_CR1  = (void*) _USART3 + 0x0C;
static volatile USART_CR2_t*  const USART3_CR2  = (void*) _USART3 + 0x10;
static volatile USART_CR3_t*  const USART3_CR3  = (void*) _USART3 + 0x14;
static volatile USART_GTPR_t* const USART3_GTPR = (void*) _USART3 + 0x18;
