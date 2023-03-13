; Indication that we are running in 16-bit real mode
bits 16

; This is the address where bootloader gets stored in memory by BIOS.
; Every label address is caculated relative to this address.
org 0x7c00

STACK_BASE_ADDR equ 0x8400

; Setting up stack registers
mov bp, STACK_BASE_ADDR
mov sp, bp

; Clearing screen (BIOS routine)
mov ah, 0
mov al, 3
int 0x10

; Printing welcome message
push welcome_msg	; Passing message address as parameter to subprogram
call print_string
pop ax				; Popping arguments from stack

; Reading other sectors from disk
push 0x0001			; Number of sectors to read
call disk_read
pop ax

jmp $				; Infinite loop

; Including subprograms
%include "print_string.asm"
%include "disk_read.asm"

; Data
%include "data.asm"

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55

; Additional sector
times 512 db 0xda
