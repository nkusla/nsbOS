ENTRY(kernel_init)		# Kenrel entry point (located inside of kernel_init.asm)

SECTIONS {
	. = 0x7e00;		# Kernel code starts after boot sector

	.text : {
		*(.text)
	}

	.data : {
		*(.data)
		*(.rodata)
	}

	. = 0xa000;
}