# Not So Big Operating System

This is my take on making simple yet usable and **not so big Operating system**. This operating system is
not meant to be robust and have all advanced components that are present in modern operating systems.
The point of this hobby project is to learn and fully understand low-level operating system events which are mostly taken for granted today. Besides that, this journey required understanding how compiler, linker, build system and debugger work together and can be used to develop software.

## Building and running OS

Thit project uses following things for development and building toolchain:

- `nasm` (Netwide assembler) - assembles bootloader and some parts of kernel code
- `gcc` (GNU compiler collection) - used for compiling most of kernel code and driver code
- `ld` (GNU linker) - combines multiple object files created by assembler and compiler
- `qemu` - emulates x86 architecture (Intel i386)
- `gdb` (GNU debugger) - used for connecting directly to emulator while OS is being executed

## Documentation

Comming soon...

### Progress
- [x] Bootloader
  - [x] Routine for writing to screen
  - [x] Routine for reading disk contents
  - [x] Global descriptor table (GDT)
  - [x] Switching to protected mode and calling kernel code
- [X] Drivers
  - [x] Video driver
  - [X] Keyboard driver
- [ ] Kernel
  - [x] Internal interrupt service routines (ISR)
  - [x] Interrupt request routines (ISQ) and PIC remapping
  - [x] Interrupt descriptor table
  - [ ] ...
- [ ] Other
  - [ ] Implement basic stdio library
  - [ ] Reimplement print_string method
  - [x] Write linker script
  - [ ] Makefiles refactoring
  - [x] Simple user program
