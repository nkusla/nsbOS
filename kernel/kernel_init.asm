bits 32		; We are expected to run kernel code in 32-bit protected mode
extern main	; This is used to signal the linker that symbol 'main' exists

section .text

kernel_init:
	call main
	jmp $