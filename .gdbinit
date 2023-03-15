# Breakpoints
b *0x7c00

# Main configuration
set architecture i386
set disassembly-flavor intel
target remote localhost:26000
layout asm
layout reg
