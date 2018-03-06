boot.bin: boot.elf
	arm-none-eabi-objcopy -O binary boot.elf boot.bin

boot.elf: boot.o
	arm-none-eabi-gcc -Wl,--gc-sections -nostdlib -T stm32f103x8.ld boot.o -o boot.elf

boot.o: boot.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c -nostdlib boot.c -o boot.o

burn: boot.bin
	st-flash write $< 0x8000000

clean:
	rm -f boot.o boot.elf boot.bin
