bits 16
org 7c00h

mov ah, 0x0e
mov si, message

print:
	mov al, [si]
	or al, al
	jz halt
	int 10h
	inc si
	jmp print

halt:
	hlt

message: db "Welcome to nsbOS!", 0

times 510-($-$$) db 0

dw 0xaa55
