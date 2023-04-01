include ../Makefile.colors

BUILD_DIR=../build/kernel
DEBUG_DIR=../debug
DRIVERS_BUILD_DIR=../build/drivers
DRIVERS_DIR=../drivers

DRIVERS_SRC:=$(wildcard $(DRIVERS_DIR)/*.c)
DRIVERS_OBJS:=$(patsubst $(DRIVERS_DIR)/%.c, $(DRIVERS_BUILD_DIR)/%.o, $(DRIVERS_SRC))

KERNEL_SRC:=$(wildcard *.c)
KERNEL_OBJS:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(KERNEL_SRC))

KERNEL_ASM:=$(filter-out kernel_init.asm, $(wildcard *.asm))
KERNEL_ASM_OBJS:=$(patsubst %.asm, $(BUILD_DIR)/%.o, $(KERNEL_ASM))

KERNEL_ELF=$(BUILD_DIR)/kernel.elf
KERNEL_BIN=$(BUILD_DIR)/kernel.bin
KERNEL_DEBUG=$(DEBUG_DIR)/kernel.dbg

KERNEL_LOAD_ADDR=0x7e00
DATA_LOAD_ADDR=0x8500
GCC_FLAGS=-g -c -m32 -fno-pic -ffreestanding -fno-stack-protector
NASM_FLAGS=-g -f elf32
LD_FLAGS=-m elf_i386 --oformat elf32-i386 -Ttext $(KERNEL_LOAD_ADDR) -Tdata $(DATA_LOAD_ADDR)

.PHONY: kernel drivers

default: kernel drivers

drivers: $(DRIVERS_SRC)
	@echo -e "$(YELLOW)Building drivers source code!$(RESET)"
	@mkdir -p $(DRIVERS_BUILD_DIR)
	gcc $^ $(GCC_FLAGS)
	mv *.o $(DRIVERS_BUILD_DIR)

kernel: $(KERNEL_SRC) drivers
	@echo -e "$(YELLOW)Building kernel source code!$(RESET)"
	@mkdir -p $(BUILD_DIR)
	gcc $(KERNEL_SRC) $(GCC_FLAGS)
	nasm kernel_init.asm -o $(BUILD_DIR)/kernel_init.o $(NASM_FLAGS)
	nasm $(KERNEL_ASM) $(NASM_FLAGS)
	mv *.o $(BUILD_DIR)
	ld $(BUILD_DIR)/kernel_init.o $(KERNEL_ASM_OBJS) $(DRIVERS_OBJS) $(KERNEL_OBJS) -o $(KERNEL_ELF) $(LD_FLAGS)
	objcopy -O binary $(KERNEL_ELF) $(KERNEL_BIN)
	objcopy --only-keep-debug $(KERNEL_ELF) $(KERNEL_DEBUG)

test:
	echo $(KERNEL_ASM)

clean:
	rm -rf $(BUILD_DIR) $(DRIVERS_BUILD_DIR)
