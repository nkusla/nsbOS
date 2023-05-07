; Implementation of software interrupt routines

bits 32
extern sys_call_handler

global sir128
sir128:
	push dword 0
	push dword 128
	pushad

	call sys_call_handler

	popad
	add esp, 8
	iret