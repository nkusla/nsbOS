; Simple subprogram for printing to screen using BIOS calls

print_string:
	push bp			; creating new stack frame
	mov bp, sp
	mov si, [bp+4]	; loading string into si register

	mov ah, 0x0e

print_loop:
	mov al, [si]	; loading one char to al register
	or al, al		; checking if char is null string terminator
	jz print_end
	int 0x10		; calling BIOS interrupt
	inc si			; pointing si register to next char
	jmp print_loop

print_end:
	mov sp, bp
	pop bp			; returning stack pointer to old state
	ret