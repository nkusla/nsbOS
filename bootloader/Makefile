BUILD_DIR=../build/bootloader
BOOTLOADER_SRCS=bootloader.asm
BOOTLOADER_OBJ=bootloader.o
NASM_FLAGS=-g -f bin
NASM_MAP_FILE=debug.map

all: $(BUILD_DIR)/$(BOOTLOADER_OBJ)

$(BUILD_DIR)/$(BOOTLOADER_OBJ): $(BOOTLOADER_SRCS)
	mkdir -p $(BUILD_DIR)
	nasm $< -o $@ $(NASM_FLAGS)
	mv $(NASM_MAP_FILE) $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)