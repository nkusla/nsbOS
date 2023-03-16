; Routne that switches CPU from 16-bit real mode
; to 32-bit protected mode

switch_to_pm:
	cli	; Clearing interrupts flag

	; Passing GDT descriptor to CPU
	lgdt [gdt_descriptor]

	; Setting proteced mode bit in control register 0
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax

	; Forcing CPU to flush instruction pipeline and
	; setting up cs register
	jmp CODE_SEG:init_pm

bits 32

init_pm:
	; Initializing segment registers
	mov ax, DATA_SEG
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	; Restarting stack pointers
	mov ebp, STACK_BASE_ADDR
	mov esp, ebp

	jmp END
