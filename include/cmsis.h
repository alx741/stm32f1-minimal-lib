#pragma once
#include <stdint.h>

/* ----------------------------------------------
 *   CMSIS - Cortex-M3 instructions
 * ----------------------------------------------
 */

void __enable_irq(void);
void __disable_irq(void);
void __enable_fault_irq(void);
void __disable_fault_irq(void);
void __ISB(void);
void __DSB(void);
void __DMB(void);
/* uint32_t __REV(uint32_t value); */
/* uint32_t __REV16(uint32_t value); */
/* uint32_t __REVSH(uint32_t value); */
/* uint32_t __RBIT(uint32_t value); */
void __SEV(void);
void __WEF(void);
void __WFI(void);


/* ----------------------------------------------
 *   CMSIS - Cortex-M3 instructions
 * ----------------------------------------------
 */

void NVIC_EnableIRQ(uint8_t IRQn);
void NVIC_DisableIRQ(uint8_t IRQn);
void NVIC_SetPendingIRQ(uint8_t IRQn);
void NVIC_ClearPendingIRQ(uint8_t IRQn);
uint32_t NVIC_GetPendingIRQ(uint8_t IRQn);
void NVIC_SetPriority(uint8_t IRQn, uint32_t priority);
uint32_t NVIC_GetPriority(uint8_t IRQn);
