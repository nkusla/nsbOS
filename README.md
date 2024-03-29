# Not so big Operating System

This is my take on making simple yet usable and **not so big Operating system**. This operating system is
not meant to be robust and have all advanced components that are present in modern operating systems.
The point of this hobby project is to learn and fully understand low-level operating system events which are mostly taken for granted today. Besides that, this journey required understanding how compiler, linker, build system and debugger work together and can be used to develop software.

\
![Hello friend message](docs/images/hello_friend_message.png)

## Required tools and installation

This project uses following things for development and building toolchain:

- `nasm` (Netwide assembler) - assembles bootloader and some parts of kernel code (x86 intel syntax)
- `gcc` (GNU compiler collection) - used for compiling most of kernel code and device driver code
- `ld` (GNU linker) - combines multiple object files created by assembler and compiler
- `gdb` (GNU debugger) - used for connecting directly to emulator while OS is being executed
- `objdump` - used for examening object and elf file formats
- `make` - used for running scripts for building and automatization
- `qemu` - emulates x86 architecture (Intel i386)

Most of these tools come pre-installed on all Linux distros. Installation on Arch-based distros:
```
sudo pacman -S binutils nasm gcc gdb make qemu-desktop
```

## Building and running OS

Enter project directory and run following command to build and run OS in qemu:

```
make
make run
```

## Documentation

Full documentation is located in directory `docs/`. Chapters are divided into separate md files. In order to generate one pdf file from multiple md files, some other packages must be installed by running this command:

```
sudo pacman -S pandoc texlive-core
```

Final pdf file can be then generated by running this command:

```
make docs
```

Documentation can be viewed at the following link: [nsbOS-manual](./docs/nsbOS-manual.pdf)