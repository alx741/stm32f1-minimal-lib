SRC_DIR = ./src
INC_DIR = ./include
OBJECTS=$(foreach c_file, $(wildcard $(SRC_DIR)/*.c), $(c_file:.c=.o))

libstm32f1.a: $(OBJECTS)
	arm-none-eabi-ar -crs $@ $^

%.o: %.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c -nostdlib -I $(INC_DIR) $^ -o $@

clean:
	rm -f $(OBJECTS) libstm32f1.a
