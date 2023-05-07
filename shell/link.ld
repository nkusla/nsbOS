ENTRY(main)

SECTIONS {
	. = 0x9e00;

	.text : {
		*(.text)
	}

	.data : {
		*(.data)
		*(.rodata)
	}
}