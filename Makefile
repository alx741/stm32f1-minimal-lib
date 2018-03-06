SRC_DIR = .
BINARY = main
OBJECTS=$(foreach c_file, $(wildcard $(SRC_DIR)/*.c), $(c_file:.c=.o))

$(BINARY).bin: $(BINARY).elf
	arm-none-eabi-objcopy -O binary $? $@

$(BINARY).elf: $(OBJECTS)
	arm-none-eabi-gcc -Wl,--gc-sections -nostdlib -T stm32f103x8.ld $? -o $@

%.o: %.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c -nostdlib $? -o $@

burn: $(BINARY).bin
	st-flash write $< 0x8000000

clean:
	rm -f $(OBJECTS) $(BINARY).elf $(BINARY).bin
