# Drivers

\
To interact with physical devices such as the monitor, keyboard, and mouse, they need to be mapped to specific addresses in the I/O address space. The `x86` instruction set provides two useful functions, namely `in` and `out`, which enable the CPU to read data from I/O-mapped addresses and store that data in registers. These low-level functions are used for direct communication with the hardware.

## Video driver

\
The video memory is memory-mapped starting from address `0xb8000`. For simplicity, the screen resolution is set to 25x80, which corresponds to the basic VGA mode called `text mode 0`. In this mode, we can only write colored text to the screen. Each character displayed on the screen is represented by 2 bytes. The first byte represents the ASCII value of the character, while the second byte represents the background and foreground colors. Following table shows how background and foreground colors are encoded in color byte:

|	 Bit	|  7  | 654	|  3  | 210 |
|   :---:	|:---:|:---:|:---:|:---:|
|	Color	| background bright bit | background | foreground bright bit | foreground |


Following table shows how each color is encoded with 3 bits:

|	Value	|	Color	|
|	:---:	|	:---:	|
|	 000	|	Black	|
|	 001	|	Blue	|
|	 010	|	Green	|
|	 011	|	Cyan	|
|	 100	|	Red	|
|	 101	|	Meganta	|
|	 110	|	Brown	|
|	 111	|	Light Gray	|

## Keyboard driver

\
The keyboard driver implemented in this project is designed for keyboards that use the PS/2 port for communication. The keyboard data register is mapped to the I/O address `0x60`. When a key is pressed on the keyboard, the corresponding scancode is stored in this data register. The driver reads the scancode from the address, parses it, stores it in the keyboard buffer, and displays it on the screen.

<div style="page-break-after: always; visibility: hidden">\pagebreak</div>
