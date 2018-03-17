#pragma once
#include <stdint.h>

void __enable_irq(void);
void __disable_irq(void);

void NVIC_EnableIRQ(uint8_t IRQn);
void NVIC_DisableIRQ(uint8_t IRQn);
void NVIC_SetPendingIRQ(uint8_t IRQn);
void NVIC_ClearPendingIRQ(uint8_t IRQn);
uint32_t NVIC_GetPendingIRQ(uint8_t IRQn);
void NVIC_SetPriority(uint8_t IRQn, uint32_t priority);
uint32_t NVIC_GetPriority(uint8_t IRQn);
