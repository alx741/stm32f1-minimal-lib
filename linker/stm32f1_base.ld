ENTRY  (RESET_HANDLER)
EXTERN (VECTOR_TABLE)
EXTERN (IRQ_VECTOR_TABLE)

SECTIONS
{
	.text :
    {
		*(.VECTOR_TABLE)
		*(.IRQ_VECTOR_TABLE)
		*(.text*)
		*(.rodata*)
	} >FLASH

	.data :
    {
		_data_start = .;
		*(.data*)
	} >RAM AT >FLASH
    _data_size = SIZEOF(.data);
	_data_load_start = LOADADDR(.data);

	.bss :
    {
        _bss_start = .;
		*(.bss*)
		*(COMMON)
        _bss_end = .;
	} >RAM
    _bss_size = SIZEOF(.bss);
}

PROVIDE(_stack_base = ORIGIN(RAM) + LENGTH(RAM));
