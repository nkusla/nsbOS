; Creates file which is used for debugging
[map all bootloader.map]

; Indication that we are running in 16-bit real mode
bits 16

; This is the address where bootloader gets stored in memory by BIOS.
; Every label address is caculated relative to this address.
org 0x7c00

; Constants
STACK_BASE_ADDR equ 0x7c00
KERNEL_LOAD_ADDR equ 0x7e00
NUM_SECTORS equ 18

; Setting up stack registers
mov bp, STACK_BASE_ADDR
mov sp, bp

; Clearing screen (BIOS routine)
mov ah, 0
mov al, 3
int 0x10

; Printing welcome message
push welcome_msg		; Passing message address as parameter to subprogram
call print_string_rm

; Reading other sectors from disk and wiritng to memory
push word NUM_SECTORS	; Number of sectors to read
call disk_read

; Protected mode message
push switching_to_pm_msg
call print_string_rm

; Switching to protected 32-bit mode
call switch_to_pm

; Includes (real mode)
%include "print_string_rm.asm"
%include "disk_read.asm"
%include "gdt.asm"
%include "data.asm"

; Includes (protected mode)
%include "switch_to_pm.asm"

kernel_start:
	jmp KERNEL_LOAD_ADDR	; calling kernel code

; Padding and magic number
times 510-($-$$) db 0
dw 0xaa55

; Additional sector
; times 512 db 0xda
