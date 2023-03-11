; Indication that we are running in 16-bit real mode
bits 16

; This is the address where bootloader gets stored in memory by BIOS.
; Every label address is caculated relative to this address.
org 0x7c00

STACK_BASE_ADDR equ 0x8000

; Setting up stack registers
mov bp, STACK_BASE_ADDR
mov sp, bp

; Clearing screen (BIOS routine)
mov ah, 0
mov al, 3
int 0x10

; Printing welcome message
push welcome_message	; Passing message address as parameter to subprogram
call print_string
jmp $

; Includes
%include "print_string.asm"

welcome_message: db "Welcome to nsbOS!", 0

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55
