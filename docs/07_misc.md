# Building

\
In root nsbOS directory there is a file called `Makefile`. This file is run with `make` and tells it how to integrate, build, compile and assemble everything. This file calls other `Makefiles` located in subdirectories where every subdirectory corresponds to one component of this operating system. This means that every component can be build and tested separatly.

In order to build the entire operating system, you can simply run `make` from root direcotry of nsbOS project. What happens in the background is as follows:

- Bootloader gets build
- Kernel gets build
- Shell gets build

After every of these steps, multiple `bin` files get created. Finally, bootloader, kernel and shell binary files are added together to produce final `disk.img` file. This file is a raw binary file and it basically represents our floppy disk which will get loaded into virtual machine. Besides disk image file, there are other object and elf files that get produced during build process. These files are saved in `build/` directory in separate subdirectories.

Building stage will also produce debug files which get stored inside of `debug/` directory.

Additonally, components can separatly be built by calling `make` and passing component name. For example this command will only build shell:
```
	make shell
```

# Running

\
Operating system is intended to run in `qemu` virtual machine to emulate entire environment. Running the OS in virtaul machine can be done by executing following command:
```
	make run
```
This will load `disk.img` as a floppy disk and run virtual machine with some other flags.


# Debugging

\
As mentioned above, building stage will produce some files that are useful for debugging, so these files are passed to the `gdb` debugger. In order to start debugging you should execute following commands:

```
	make run_debug
	make debug
```

The first command will pass OS image to the `qemu` virtual machine and it will wait for the debugger to connect to it. The second command will launch `gdb` and it will connect to previously launched virtual machine.

Debugger configurations are stored in file `.gdbinit`. This file defines how debugger should display information, which debug files to load and some other configurations.

# References and future work

\
The development of an operating system requires a deep understanding of various concepts and techniques. This project produced simple operating system, so there are still opportunities for future development and work. Here are some potential areas of focus for future work:

- Virtual memory
- Processes and threads
- Better security and permissions
- File system
- Better shell for user-space

\
The following references have been really helpful in the creation of this project: \

- OSDev Wiki - _(https://wiki.osdev.org/)_

- Writing a simple operating system from scratch by Nick Blundell - \
  _(https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf)_

- Operating systems: from 0 to 1 - _(https://github.com/tuhdo/os01)_

- The little book about OS development - _(https://littleosbook.github.io/)_

- Writing my own operating system - _(https://dev.to/frosnerd/series/9585)_
