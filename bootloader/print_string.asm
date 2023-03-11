
print_string:
	mov ah, 0x0e

print_loop:
	mov al, [si]
	or al, al
	jz print_end
	int 0x10
	inc si
	jmp print_loop

print_end:
	ret