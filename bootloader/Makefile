BUILD_DIR=../build/bootloader
BOOTLOADER_SRCS=bootloader.asm
BOOTLOADER_BIN=bootloader.bin
NASM_FLAGS=-f bin
NASM_MAP_FILE=debug.map

default: $(BUILD_DIR)/$(BOOTLOADER_BIN)

$(BUILD_DIR)/$(BOOTLOADER_BIN): $(BOOTLOADER_SRCS)
	mkdir -p $(BUILD_DIR)
	nasm $< -o $@ $(NASM_FLAGS)
	mv $(NASM_MAP_FILE) $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)