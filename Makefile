BUILD_DIR=build
BOOTLOADER=$(BUILD_DIR)/bootloader/bootloader.o
DISK_IMG=$(BUILD_DIR)/disk.img

.PHONY: bootdisk bootloader

default: bootdisk

bootloader:
	make -C bootloader

bootdisk: bootloader
	dd if=/dev/zero of=$(DISK_IMG) bs=512 count=2880
	dd conv=notrunc if=$(BOOTLOADER) of=$(DISK_IMG) bs=512 count=1 seek=0

clean:
	rm -rf build/*
