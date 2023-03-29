include ../Makefile.colors

BUILD_DIR=../build/bootloader
DEBUG_DIR=../debug
BOOTLOADER_SRCS=bootloader.asm
BOOTLOADER_BIN=bootloader.bin
NASM_FLAGS=-f bin
NASM_MAP_FILE=bootloader.map

default: $(BUILD_DIR)/$(BOOTLOADER_BIN)

$(BUILD_DIR)/$(BOOTLOADER_BIN): $(BOOTLOADER_SRCS)
	@echo -e "$(YELLOW)Building bootloader source code!$(RESET)"
	@mkdir -p $(BUILD_DIR)
	nasm $< -o $@ $(NASM_FLAGS)
	@mkdir -p $(DEBUG_DIR)
	mv $(NASM_MAP_FILE) $(DEBUG_DIR)

clean:
	rm -rf $(BUILD_DIR) $(DEBUG_DIR)/$(NASM_MAP_FILE)