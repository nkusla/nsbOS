# Debug symbols
add-symbol-file debug/kernel.dbg
add-symbol-file debug/shell.dbg

# Breakpoints
#b *0x7c00
#b *0x7d2b
b shell.c:4

# Main configuration
set architecture i386
set disassembly-flavor intel
target remote localhost:26000

# TUI layout
tui new-layout asm {-horizontal asm 2 regs 1} 2 status 0 cmd 1
tui new-layout src {-horizontal src 2 asm 1} 2 status 0 cmd 1
layout src
