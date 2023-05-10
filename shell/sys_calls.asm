bits 32
global write
global read

write:
	push ebp
	mov ebp, esp
	push ebx

	mov eax, 4
	mov ebx, 1
	mov ecx, [ebp+8]
	mov edx, [ebp+12]
	int 0x80

	pop ebx
	mov esp, ebp
	pop ebp
	ret

read:
	push ebp
	mov ebp, esp
	push ebx
	push esi

	mov eax, 3
	mov ebx, 0
	mov ecx, [ebp+8]
	mov edx, [ebp+12]
	mov esi, [ebp+16]
	int 0x80

	pop esi
	pop ebx
	mov esp, ebp
	pop ebp
	ret
