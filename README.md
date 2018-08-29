Library for *STM32F1* devices

## Using

Compile the library

    $ make

Copy the content of the `example` directory to your project

    $ cp example/* ~/me/my-project

Configure the parameters in the `Makefile`

* STM32F1LIB_DIR
* SRC_DIR
* BINARY
* LINKER_SCRIPT (for the specific part you're using)


## Implemented

* Low level registers are available in `f1.h` to be used like in `register.bit = value;`
* RCC
* CMSIS (partial)
* USART (works well with *stdio* functions like printf, fgets, etc)
* I2C

### External drivers

* MPU6050
