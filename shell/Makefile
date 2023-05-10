include ../Makefile.colors

BUILD_DIR=../build/shell
DEBUG_DIR=../debug

SHELL_ELF=$(BUILD_DIR)/shell.elf
SHELL_BIN=$(BUILD_DIR)/shell.bin
SHELL_DEBUG=$(DEBUG_DIR)/shell.dbg

GCC_WARNINGS=-Wno-incompatible-pointer-types
GCC_FLAGS=-g -c -m32 -march=i386 -O0 -fno-pic -ffreestanding -fno-stack-protector $(GCC_WARNINGS)
NASM_FLAGS=-g -f elf32
LD_FLAGS=-m elf_i386 --oformat elf32-i386
LD_SCRIPT=link.ld

default: shell

shell:
	@mkdir -p $(BUILD_DIR)
	gcc shell.c stdio.c $(GCC_FLAGS)
	nasm sys_calls.asm $(NASM_FLAGS)
	mv *.o $(BUILD_DIR)
	ld -T $(LD_SCRIPT) $(BUILD_DIR)/shell.o $(BUILD_DIR)/sys_calls.o $(BUILD_DIR)/stdio.o  -o $(SHELL_ELF) $(LD_FLAGS)
	objcopy -O binary $(SHELL_ELF) $(SHELL_BIN)
	objcopy --only-keep-debug $(SHELL_ELF) $(SHELL_DEBUG)

clean:
	rm -rf $(BUILD_DIR)