; Implementation of first 32 interrupts (exceptions) which are reserved by x86 arch

bits 32
extern isr_generic_handler

section .text

isr_interrupt_frame:
	pushad

	call isr_generic_handler

	popad
	add esp, 8
	iret

; Division Error
global isr0
isr0:
	push dword 0
	push dword 0
	jmp isr_interrupt_frame

; Debug
global isr1
isr1:
	push dword 0
	push dword 1
	jmp isr_interrupt_frame

; NMI
global isr2
isr2:
	push dword 0
	push dword 2
	jmp isr_interrupt_frame

; Breakpoint
global isr3
isr3:
	push dword 0
	push dword 3
	jmp isr_interrupt_frame

; Overflow
global isr4
isr4:
	push dword 0
	push dword 4
	jmp isr_interrupt_frame

; Bound Range Exceeded
global isr5
isr5:
	push dword 0
	push dword 5
	jmp isr_interrupt_frame

; Invalid Opcode
global isr6
isr6:
	push dword 0
	push dword 6
	jmp isr_interrupt_frame

; Device Not Available
global isr7
isr7:
	push dword 0
	push dword 7
	jmp isr_interrupt_frame

; Double Fault
global isr8
isr8:
	; Error code pushed by CPU
	push dword 8
	jmp isr_interrupt_frame

; Coprocessor Segment Overrun
global isr9
isr9:
	push dword 0
	push dword 9
	jmp isr_interrupt_frame

; Invalid TSS
global isr10
isr10:
	; Error code pushed by CPU
	push dword 10
	jmp isr_interrupt_frame

; Segment Not Present
global isr11
isr11:
	; Error code pushed by CPU
	push dword 11
	jmp isr_interrupt_frame

; Stack-Segment Fault
global isr12
isr12:
	; Error code pushed by CPU
	push dword 12
	jmp isr_interrupt_frame

; General Protection Fault
global isr13
isr13:
	; Error code pushed by CPU
	push dword 13
	jmp isr_interrupt_frame

; Page Fault
global isr14
isr14:
	; Error code pushed by CPU
	push dword 14
	jmp isr_interrupt_frame

; Reserved
global isr15
isr15:
	push dword 0
	push dword 15
	jmp isr_interrupt_frame

; x87 Floating Point Exception
global isr16
isr16:
	push dword 0
	push dword 16
	jmp isr_interrupt_frame

; Alignment Check
global isr17
isr17:
	; Error code pushed by CPU
	push dword 17
	jmp isr_interrupt_frame

; Machine Check
global isr18
isr18:
	push dword 0
	push dword 18
	jmp isr_interrupt_frame

; SIMD Floating-Point Exception
global isr19
isr19:
	push dword 0
	push dword 19
	jmp isr_interrupt_frame

; Virtualization Exception
global isr20
isr20:
	push dword 0
	push dword 20
	jmp isr_interrupt_frame

; Control Protection Exception
global isr21
isr21:
	; Error code pushed by CPU
	push dword 21
	jmp isr_interrupt_frame

; Reserved
global isr22
isr22:
	push dword 0
	push dword 22
	jmp isr_interrupt_frame

; Reserved
global isr23
isr23:
	push dword 0
	push dword 23
	jmp isr_interrupt_frame

; Reserved
global isr24
isr24:
	push dword 0
	push dword 24
	jmp isr_interrupt_frame

; Reserved
global isr25
isr25:
	push dword 0
	push dword 25
	jmp isr_interrupt_frame

; Reserved
global isr26
isr26:
	push dword 0
	push dword 26
	jmp isr_interrupt_frame

; Reserved
global isr27
isr27:
	push dword 0
	push dword 27
	jmp isr_interrupt_frame

; Hypervisor Injection Exception
global isr28
isr28:
	push dword 0
	push dword 28
	jmp isr_interrupt_frame

; VMM Communication Exception
global isr29
isr29:
	; Error code pushed by CPU
	push dword 29
	jmp isr_interrupt_frame

; Security Exception
global isr30
isr30:
	; Error code pushed by CPU
	push dword 30
	jmp isr_interrupt_frame

; Reserved
global isr31
isr31:
	push dword 0
	push dword 31
	jmp isr_interrupt_frame
