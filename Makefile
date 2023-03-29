include Makefile.colors

BUILD_DIR=build
DEBUG_DIR=debug

BOOTLOADER_BIN=$(BUILD_DIR)/bootloader/bootloader.bin
KERNEL_BIN=$(BUILD_DIR)/kernel/kernel.bin
KERNEL_ELF=$(BUILD_DIR)/kernel/kernel.elf
DISK_IMG=$(BUILD_DIR)/disk.img

NUM_SECTORS=30
QEMU_FLAGS=-fda $(DISK_IMG) -m 128M
QEMU_DEBUG_FLAGS=-gdb tcp::26000 -S

.PHONY: bootloader kernel bootdisk debug

default: bootdisk

bootloader:
	@make -C bootloader

kernel:
	@make -C kernel

bootdisk: bootloader kernel
	@echo -e "$(YELLOW)Creating bootable disk image!$(RESET)"
	dd if=/dev/zero of=$(DISK_IMG) bs=512 count=16
	dd conv=notrunc if=$(BOOTLOADER_BIN) of=$(DISK_IMG) bs=512 count=1 seek=0
	dd conv=notrunc if=$(KERNEL_BIN) of=$(DISK_IMG) bs=512 count=$(NUM_SECTORS) seek=1

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
