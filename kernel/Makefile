BUILD_DIR=../build/kernel
KERNEL_SRC=kernel.c
KERNEL_BIN=kernel.bin
KERNEL_OBJ=kernel.o
KERNEL_LOAD_ADDR=0x7400
GCC_FLAGS=-fno-PIC -m32 -c -ffreestanding
NASM_FLAG=-f elf32
LD_FLAGS=-m elf_i386 --oformat binary -Ttext $(KERNEL_LOAD_ADDR)

all: $(BUILD_DIR)/$(KERNEL_BIN)

$(BUILD_DIR)/$(KERNEL_BIN): $(KERNEL_SRC)
	mkdir -p $(BUILD_DIR)
	gcc $< -o $(BUILD_DIR)/$(KERNEL_OBJ) $(GCC_FLAGS)
	nasm kernel_start.asm -o $(BUILD_DIR)/kernel_start.o $(NASM_FLAG)
	ld $(BUILD_DIR)/kernel_start.o $(BUILD_DIR)/$(KERNEL_OBJ) -o $@ $(LD_FLAGS)

clean:
	rm -rf $(BUILD_DIR)