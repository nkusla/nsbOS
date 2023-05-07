bits 32
extern irq_generic_handler

section .text

irq_interrupt_frame:
	pushad

	call irq_generic_handler

	popad
	add esp, 8
	iret

global irq0
irq0:
	push dword 0
	push dword 32
	jmp irq_interrupt_frame

global irq1
irq1:
	push dword 0
	push dword 33
	jmp irq_interrupt_frame

global irq2
irq2:
	push dword 0
	push dword 34
	jmp irq_interrupt_frame

global irq3
irq3:
	push dword 0
	push dword 35
	jmp irq_interrupt_frame

global irq4
irq4:
	push dword 0
	push dword 36
	jmp irq_interrupt_frame

global irq5
irq5:
	push dword 0
	push dword 37
	jmp irq_interrupt_frame

global irq6
irq6:
	push dword 0
	push dword 38
	jmp irq_interrupt_frame

global irq7
irq7:
	push dword 0
	push dword 39
	jmp irq_interrupt_frame

global irq8
irq8:
	push dword 0
	push dword 40
	jmp irq_interrupt_frame

global irq9
irq9:
	push dword 0
	push dword 41
	jmp irq_interrupt_frame

global irq10
irq10:
	push dword 0
	push dword 42
	jmp irq_interrupt_frame

global irq11
irq11:
	push dword 0
	push dword 43
	jmp irq_interrupt_frame

global irq12
irq12:
	push dword 0
	push dword 44
	jmp irq_interrupt_frame

global irq13
irq13:
	push dword 0
	push dword 45
	jmp irq_interrupt_frame

global irq14
irq14:
	push dword 0
	push dword 46
	jmp irq_interrupt_frame

global irq15
irq15:
	push dword 0
	push dword 47
	jmp irq_interrupt_frame
