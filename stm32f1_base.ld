EXTERN (vector_table)
ENTRY  (reset_handler)
/* INPUT(vectors.c)     should??? */
/* STARTUP(vectors.c)   should??? */

SECTIONS
{
	.text :
    {
		*(.vector_table)
		*(.text*)
		*(.rodata*)
	} >FLASH

	.data :
    {
		_data_start = .;
		*(.data*)
		_data_end = .;
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
