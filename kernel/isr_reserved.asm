; Implementation of first 32 interrupts (exceptions) which are reserved by x86 arch

bits 32
extern interrupt_generic_handler

interrupt_frame:
	pushad

	call interrupt_generic_handler

	popad
	add esp, 8
	iret

; Division Error
global isr0
isr0:
	push byte 0
	push byte 0
	jmp interrupt_frame

; Debug
global isr1
isr1:
	push byte 0
	push byte 1
	jmp interrupt_frame

; NMI
global isr2
isr2:
	push byte 0
	push byte 2
	jmp interrupt_frame

; Breakpoint
global isr3
isr3:
	push byte 0
	push byte 3
	jmp interrupt_frame

; Overflow
global isr4
isr4:
	push byte 0
	push byte 4
	jmp interrupt_frame

; Bound Range Exceeded
global isr5
isr5:
	push byte 0
	push byte 5
	jmp interrupt_frame

; Invalid Opcode
global isr6
isr6:
	push byte 0
	push byte 6
	jmp interrupt_frame

; Device Not Available
global isr7
isr7:
	push byte 0
	push byte 7
	jmp interrupt_frame

; Double Fault
global isr8
isr8:
	; Error code pushed by CPU
	push byte 8
	jmp interrupt_frame

; Coprocessor Segment Overrun
global isr9
isr9:
	push byte 0
	push byte 9
	jmp interrupt_frame

; Invalid TSS
global isr10
isr10:
	; Error code pushed by CPU
	push byte 10
	jmp interrupt_frame

; Segment Not Present
global isr11
isr11:
	; Error code pushed by CPU
	push byte 11
	jmp interrupt_frame

; Stack-Segment Fault
global isr12
isr12:
	; Error code pushed by CPU
	push byte 12
	jmp interrupt_frame

; General Protection Fault
global isr13
isr13:
	; Error code pushed by CPU
	push byte 13
	jmp interrupt_frame

; Page Fault
global isr14
isr14:
	; Error code pushed by CPU
	push byte 14
	jmp interrupt_frame

; Reserved
global isr15
isr15:
	push byte 0
	push byte 15
	jmp interrupt_frame

; x87 Floating Point Exception
global isr16
isr16:
	push byte 0
	push byte 16
	jmp interrupt_frame

; Alignment Check
global isr17
isr17:
	; Error code pushed by CPU
	push byte 17
	jmp interrupt_frame

; Machine Check
global isr18
isr18:
	push byte 0
	push byte 18
	jmp interrupt_frame

; SIMD Floating-Point Exception
global isr19
isr19:
	push byte 0
	push byte 19
	jmp interrupt_frame

; Virtualization Exception
global isr20
isr20:
	push byte 0
	push byte 20
	jmp interrupt_frame

; Control Protection Exception
global isr21
isr21:
	; Error code pushed by CPU
	push byte 21
	jmp interrupt_frame

; Reserved
global isr22
isr22:
	push byte 0
	push byte 22
	jmp interrupt_frame

; Reserved
global isr23
isr23:
	push byte 0
	push byte 23
	jmp interrupt_frame

; Reserved
global isr24
isr24:
	push byte 0
	push byte 24
	jmp interrupt_frame

; Reserved
global isr25
isr25:
	push byte 0
	push byte 25
	jmp interrupt_frame

; Reserved
global isr26
isr26:
	push byte 0
	push byte 26
	jmp interrupt_frame

; Reserved
global isr27
isr27:
	push byte 0
	push byte 27
	jmp interrupt_frame

; Hypervisor Injection Exception
global isr28
isr28:
	push byte 0
	push byte 28
	jmp interrupt_frame

; VMM Communication Exception
global isr29
isr29:
	; Error code pushed by CPU
	push byte 29
	jmp interrupt_frame

; Security Exception
global isr30
isr30:
	; Error code pushed by CPU
	push byte 30
	jmp interrupt_frame

; Reserved
global isr31
isr31:
	push byte 0
	push byte 31
	jmp interrupt_frame
