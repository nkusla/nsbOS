# Building

\
In root nsbOS directory there is a file called `Makefile`. This file is run with `make` and tells it how to integrate, build, compile and assemble everything. This file calls other `Makefiles` located in subdirectories where every subdirectory corresponds to one component of this operating system. This means that every component can be build and tested separatly.

In order to build the entire operating system, you can simply run `make` from root direcotry of nsbOS project. What happens in the background is as follows:

- Bootloader gets build
- Kernel gets build
- Shell gets build

After every of these steps, multiple `bin` files get created. Finally, bootloader, kernel and shell binary files are added together to produce final `disk.img` file. This file is a raw binary file and it basically represents our floppy disk which will get loaded into virtual machine. Besides disk image file, there are other object and elf files that get produced during build process. These files are saved in `build/` directory in separate subdirectories.

Other components can simply be build by calling `make` and passing component name. For example this command will only build shell:
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