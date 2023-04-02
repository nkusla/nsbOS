# Not So Big Operating System

This is my take on making simple yet usable and **not so big Operaing system**. This operating system is
not meant to be robust and have all advanced components that are present in modern operating systems.
The point of this hobby project is to learn and fully understand low-level operating system events which are mostly taken for granted today. Besides that, this journey required understanding how compiler, linker, build system and debugger work together and can be used to develop software.

### Documentation

Comming soon...

### Progress
- [x] Bootloader
  - [x] Routine for writing to screen
  - [x] Routine for reading disk contents
  - [x] Global descriptor table (GDT)
  - [x] Switching to protected mode and calling kernel code
- [ ] Drivers
  - [x] Video driver
  - [ ] Keyboard driver
- [ ] Kernel
  - [x] Internal interrupt service routines (ISR)
  - [x] Interrupt request routines (ISQ) and PIC remapping
  - [x] Interrupt descriptor table
  - [ ] ...
- [ ] Other
  - [ ] Implement basic string library
  - [ ] Reimplement print_string method
  - [ ] Makefiles refactoring