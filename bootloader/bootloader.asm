bits 16
org 0x7c00

STACK_BASE_ADDR equ 0x8000

; Setting up stack registers
mov bp, STACK_BASE_ADDR
mov sp, bp

; Clearing screen
mov ah, 0
mov al, 3
int 0x10

; Printing welcome message
mov si, welcome_message
call print_string
jmp $

; Includes
%include "print_string.asm"

welcome_message: db "Welcome to nsbOS!", 0

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55
