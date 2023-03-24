BUILD_DIR=../build/kernel
DRIVERS_BUILD_DIR=../build/drivers
DRIVERS_DIR=../drivers

DRIVERS_SRC:=$(wildcard $(DRIVERS_DIR)/*.c)
DRIVERS_OBJS:=$(patsubst $(DRIVERS_DIR)/%.c, $(DRIVERS_BUILD_DIR)/%.o, $(DRIVERS_SRC))

KERNEL_SRC:=$(wildcard *.c)
KERNEL_OBJS:=$(patsubst %.c, $(BUILD_DIR)/%.o, $(KERNEL_SRC))
KERNEL_BIN=$(BUILD_DIR)/kernel.bin

KERNEL_LOAD_ADDR=0x7e00
GCC_FLAGS=-c -m32 -fno-PIC -fno-stack-protector
NASM_FLAGS=-f elf32
LD_FLAGS=-m elf_i386 --oformat binary -Ttext $(KERNEL_LOAD_ADDR)

.PHONY: kernel drivers

default: kernel drivers

drivers: $(DRIVERS_SRC)
	mkdir -p $(DRIVERS_BUILD_DIR)
	gcc $^ $(GCC_FLAGS)
	mv *.o $(DRIVERS_BUILD_DIR)

kernel: $(KERNEL_SRC) drivers
	mkdir -p $(BUILD_DIR)
	gcc $(KERNEL_SRC) -o $(KERNEL_OBJS) $(GCC_FLAGS)
	nasm kernel_start.asm -o $(BUILD_DIR)/kernel_start.o $(NASM_FLAGS)
	ld $(BUILD_DIR)/kernel_start.o $(DRIVERS_OBJS) $(KERNEL_OBJS) -o $(KERNEL_BIN) $(LD_FLAGS)

clean:
	rm -rf $(BUILD_DIR) $(DRIVERS_BUILD_DIR)