bits 16
org 0x7c00

mov ah, 0x0e
mov si, message

print:
	mov al, [si]
	or al, al
	jz end
	int 0x10
	inc si
	jmp print

end:
	hlt

message: db "Welcome to nsbOS!", 0

times 510-($-$$) db 0

dw 0xaa55
