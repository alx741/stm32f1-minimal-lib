STM32F1LIB_DIR = ..
STM32F1LIB_INCLUDE_DIR = $(STM32F1LIB_DIR)/include
STM32F1LIB_LINKER_DIR = $(STM32F1LIB_DIR)/linker

SRC_DIR = .
BINARY = main
LINKER_SCRIPT = stm32f103x8.ld
OBJECTS=$(foreach c_file, $(wildcard $(SRC_DIR)/*.c), $(c_file:.c=.o))

$(BINARY).bin: $(BINARY).elf
	arm-none-eabi-objcopy -O binary $^ $@

$(BINARY).elf: $(OBJECTS)
	arm-none-eabi-gcc -Wl,--gc-sections -L$(STM32F1LIB_DIR) -L$(STM32F1LIB_LINKER_DIR) -lstm32f1 -T$(STM32F1LIB_LINKER_DIR)/$(LINKER_SCRIPT) $^ -o $@

%.o: %.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c -nostdlib -I$(STM32F1LIB_INCLUDE_DIR) $^ -o $@

burn: $(BINARY).bin
	st-flash write $< 0x8000000

clean:
	rm -f $(OBJECTS) $(BINARY).elf $(BINARY).bin
