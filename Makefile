BUILD_DIR=build
BOOTLOADER=$(BUILD_DIR)/bootloader/bootloader.bin
KERNEL=$(BUILD_DIR)/kernel/kernel.bin
DISK_IMG=$(BUILD_DIR)/disk.img
QEMU_FLAGS=-m 128M
QEMU_DEBUG_FLAGS=-gdb tcp::26000 -S

.PHONY: bootloader kernel bootdisk

default: bootdisk

bootloader:
	make -C bootloader

kernel:
	make -C kernel

bootdisk: bootloader kernel
	dd if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
	dd conv=notrunc if=$(BOOTLOADER) of=$(DISK_IMG) bs=512 count=1 seek=0
	dd conv=notrunc if=$(KERNEL) of=$(DISK_IMG) bs=512 count=12 seek=1

clean:
	rm -rf build/*

run:
	qemu-system-i386 -fda $(DISK_IMG) $(QEMU_FLAGS)

run_debug:
	qemu-system-i386 -fda $(DISK_IMG) $(QEMU_FLAGS) $(QEMU_DEBUG_FLAGS)

hex:
	hexdump -x $(DISK_IMG)

debug:
	gdb -x .gdbinit
