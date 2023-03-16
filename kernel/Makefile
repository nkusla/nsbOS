BUILD_DIR=../build/kernel
KERNEL_SRC=kernel.c
KERNEL_BIN=kernel.bin
KERNEL_OBJ=kernel.o
OFFSET_ADDR=0x7400
GCC_FLAGS=-ffreestanding
LD_FLAGS=--oformat binary -Ttext $(OFFSET_ADDR)

all: $(BUILD_DIR)/$(KERNEL_OBJ)

$(BUILD_DIR)/$(KERNEL_OBJ): $(KERNEL_SRC)
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $(BUILD_DIR)/$(KERNEL_BIN) $(GCC_FLAGS)
	ld $(BUILD_DIR)/$(KERNEL_BIN) -o $@ $(LD_FLAGS)

clean:
	rm -rf $(BUILD_DIR)