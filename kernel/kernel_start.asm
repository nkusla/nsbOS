bits 32		; We are expected to run kernel code in 32-bit protected mode
extern main	; This is used to signal the linked that symbol 'main' exists

call main
jmp $