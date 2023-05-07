bits 32
global printf_string

printf_string:
	push ebp
	mov ebp, esp
	push ebx
	push esi

	mov ebx, [ebp+8]
	mov esi, 0

	count:
	cmp byte [ebx], 0
	je sys_call_write
	inc esi
	inc ebx
	jmp count

	sys_call_write:
	mov eax, 4
	mov ebx, 1
	mov ecx, [ebp+8]
	mov edx, esi
	int 0x80

	pop esi
	pop ebx

	mov esp, ebp
	pop ebp
	ret