; Subprogram that reads n sectors from disk

disk_read:
	push bp
	mov bp, sp
	mov bx, [bp+4]	; reading argument to bx register

	mov ah, 0x02	; Read sector from disk code
	mov al, bl 		; N number of sectors to read
	mov dl, 0 		; Drive number (floopy disk = 0)
	mov dh, 0 		; Head number (0 or 1)
	mov ch, 0 		; Cylinder number
	mov cl, 2		; Sector number (indexing goes from 1)

	; Setting ex:bs register pair for address to write to
	mov bx, 0x0
	mov es, bx
	mov bx, KERNEL_ADDR
	int 0x13

	jc disk_error

	; Check if n sectors were read, if not jump to error label
	mov bx, [bp+4]
	cmp al, bl
	jne disk_error

	; If reading was successful, write appropriate message
	push disk_read_msg
	call print_string_rm
	jmp disk_end

disk_error:
	push disk_error_msg
	call print_string_rm

disk_end:
	mov sp, bp
	pop bp			; returning stack pointer to old state
	ret
