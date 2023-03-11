BUILD_DIR=../build/bootloader
BOOTLOADER_SRCS := $(wildcard *.asm)
BOOTLOADER_OBJS := $(patsubst %.asm, $(BUILD_DIR)/%.o, $(BOOTLOADER_SRCS))
NASM_FLAGS=-g -f bin

all: $(BOOTLOADER_OBJS)

$(BOOTLOADER_OBJS): $(BOOTLOADER_SRCS)
	mkdir -p $(BUILD_DIR)
	nasm $< -o $@ $(NASM_FLAGS)

clean:
	rm -rf $(BUILD_DIR)