BUILD_DIR=build
BOOTLOADER=$(BUILD_DIR)/bootloader/bootloader.o
DISK_IMG=$(BUILD_DIR)/disk.img
QEMU_FLAGS=-m 128M
QEMU_DEBUG_FLAGS=-gdb tcp::26000 -S

.PHONY: bootdisk bootloader

default: bootdisk

bootloader:
	make -C bootloader

bootdisk: bootloader
	dd if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
	dd conv=notrunc if=$(BOOTLOADER) of=$(DISK_IMG) bs=512 count=2 seek=0

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
