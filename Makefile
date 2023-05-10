include Makefile.colors

BUILD_DIR=build
DEBUG_DIR=debug

BOOTLOADER_BIN=$(BUILD_DIR)/bootloader/bootloader.bin
KERNEL_BIN=$(BUILD_DIR)/kernel/kernel.bin
KERNEL_ELF=$(BUILD_DIR)/kernel/kernel.elf
SHELL_BIN=$(BUILD_DIR)/shell/shell.bin
DISK_IMG=$(BUILD_DIR)/disk.img

KERNEL_NUM_SECTORS=14
SHELL_NUM_SECTORS=4
QEMU_FLAGS=-fda $(DISK_IMG) -m 128M
QEMU_DEBUG_FLAGS=-gdb tcp::26000 -S

.PHONY: bootloader kernel bootdisk debug shell

default: bootdisk

bootloader:
	@make -C bootloader

kernel:
	@make -C kernel

shell:
	@make -C shell

bootdisk: bootloader kernel shell
	@echo -e "$(YELLOW)Creating bootable disk image!$(RESET)"
	dd if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
	dd conv=notrunc if=$(BOOTLOADER_BIN) of=$(DISK_IMG) bs=512 count=1 seek=0
	dd conv=notrunc if=$(KERNEL_BIN) of=$(DISK_IMG) bs=512 count=$(KERNEL_NUM_SECTORS) seek=1
	dd conv=notrunc if=$(SHELL_BIN) of=$(DISK_IMG) bs=512 count=$(SHELL_NUM_SECTORS) seek=15

run:
	@qemu-system-i386 $(QEMU_FLAGS)

run_debug:
	@qemu-system-i386 $(QEMU_FLAGS) $(QEMU_DEBUG_FLAGS)

debug:
	@gdb -x .gdbinit

disk_inspect:
	@hexdump -C $(DISK_IMG)

kernel_inspect:
	@objdump -S $(KERNEL_ELF)

clean:
	rm -rf $(BUILD_DIR)/* $(DEBUG_DIR)/*
