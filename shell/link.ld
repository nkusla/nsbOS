ENTRY(main)

SECTIONS {
	. = 0x9a00;

	.text : {
		*(.text)
	}

	.data : {
		*(.data)
		*(.rodata)
	}
}