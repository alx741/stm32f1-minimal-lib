/* Enforce emmition of the vector table. */
/* EXTERN (vector_table) */

/* INPUT(vectors.c) ??? */
/* STARTUP(vectors.c) ??? */

/* Define the entry point of the output file. */
/* ENTRY(reset_handler) */ /* if not present, will use the first byte of .text
*/

SECTIONS
{
	.text :
    {
		*(.vector_table)
		*(.text*)
		/* . = ALIGN(4); */
		*(.rodata*)
		/* . = ALIGN(4); */
	} >FLASH

	/* . = ALIGN(4); */
	/* _etext = .; */

	.data :
    {
		_data_start = .;
		*(.data*)
		. = ALIGN(4);
		_data_end = .;
	} >RAM AT >FLASH
    _data_size = SIZEOF(.data);
	_data_load_start = LOADADDR(.data);

	.bss :
    {
        _bss_start = .;
		*(.bss*)
		*(COMMON)
		/* . = ALIGN(4); */
		_bss_end = .;
	} >RAM
    _bss_size = SIZEOF(.bss);

	/* . = ALIGN(4); */
	/* end = .; */
}

PROVIDE(_stack_base = ORIGIN(RAM) + LENGTH(RAM));
