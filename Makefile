SRC_DIR = ./lib
INC_DIR = ./include
OBJECTS=$(foreach c_file, $(shell find $(SRC_DIR) -type f -name '*.c'), $(c_file:.c=.o))

libstm32f1.a: $(OBJECTS)
	arm-none-eabi-ar -crs $@ $^

%.o: %.c
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -c -I $(INC_DIR) $^ -o $@

clean:
	rm -f $(OBJECTS) libstm32f1.a
