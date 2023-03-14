; Global Descriptor Table used for memory mapping
; Every descriptor in GDT is 8 bytes large (64 bits)
; Atm code and data segments are overlapping

gdt_start:

; Null descriptor (8 zero bytes)
gdt_null:
	dd 0x0
	dd 0x0

gdt_code:
	dw 0xffff		; Limit			( bits 0-15 )
	dw 0x0			; Base			( bits 16-31 )
	db 0x0			; Base			( bits 32-39 )
	db 0x9a			; Access byte	( bits 40-47 )
	db 0xcf			; Flags ( bits 52-55 ) ; Limit ( bits 48-51 )
	db 0x0			; Base 			( bits 56-63 )

gdt_data:
	dw 0xffff		; Limit			( bits 0-15 )
	dw 0x0			; Base			( bits 16-31 )
	db 0x0			; Base			( bits 32-39 )
	db 0x92			; Access byte	( bits 40-47 )
	db 0xcf			; Flags ( bits 52-55 ) ; Limit ( bits 48-51 )
	db 0x0			; Base 			( bits 56-63 )

gdt_end:

gdt_descriptor:
	dw gdt_start - gdt_end - 1	; Size of GDT (16 bits)
	dd gdt_start				; Address of GDT (32 bits)

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start