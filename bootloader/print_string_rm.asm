; Simple subprogram for printing to screen using BIOS calls
; this is indended to be run in 16-bit real mode

print_string_rm:
	push bp			; creating new stack frame
	mov bp, sp
	mov si, [bp+4]	; loading string into si register

	mov ah, 0x0e

print_loop_rm:
	mov al, [si]	; loading one char to al register
	or al, al		; checking if char is null string terminator
	jz print_end_rm
	int 0x10		; calling BIOS interrupt
	inc si			; pointing si register to next char
	jmp print_loop_rm

print_end_rm:
	mov sp, bp
	pop bp			; returning stack pointer to old state
	ret