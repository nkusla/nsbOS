bits 32				; We are expected to run kernel code in 32-bit protected mode
global kernel_init	; This is used as entry point in linking
extern main			; This is used to signal the linker that symbol 'main' exists

section .text

kernel_init:
	call main
	jmp $
