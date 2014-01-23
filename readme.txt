MMMMMMMMMMMMMMMMMMMMMdyo//hMMMMMMMMMMMMM
MMMMds+/:::/+shNMMms/::::::+dMMMMMMMMMMM
MMh/:::::::::::hMy::::::/+syhNNNMMMMMMMM
Mo:::::/sss+::hNo:::::+hmho/-..-:+ymMMMM
h:::::dMMMMMmdMo::::/dNo.           :hMM
o::::oMMMMMMMMs::::/mm-    `.::-.     oM
h:::::dNMMMMmo::::/mm.    -hNMMMmo     h
Mo:::::+syso/::::/mm-    :NMMMMMMM-    +
MMh/:::::::::::/sNd.    -NdNMMMMMd`    s
MMMNds+/////+ohmd/`    -Nh`.+sso:`    :N
MMMMMMMNNNmhys/.`     /Ny`          `oNM
MMMMMMMMMMMh-      `:hMMd+-.    `./smMMM
MMMMMMMMMMMMNs``-/smMMMMMMNNmmmmNNMMMMMM
MMMMMMMMMMMMMMNNNMMMMMMMMMMMMMMMMMMMMMMM
MMMMSENSEPOSTMMMMMMMSENSEPOSTMMMMMMMMMMM 


You've been called into ACME Banks global headquarters to investigate a breach. It appears Evilgroup has managed to breach a server and deploy their own executable on it (EvilGroupVM.exe). The executable is a piece of software that accepts bytecode files and executes them, similar in approach to how the Java Virtual Machine functions. Using this technique, Evilgroup hopes they can evade detecion by antivirus software. Their OPSEC failure meant that both the virtual machine executable and several bytecode files were left behind after the cleanup script ran and it's your job to work out the instruction set of EvilGroupVM.exe.

Disclaimer: When using the term "virtual machine" we mean something like the Java Virtual Machine. A software based architecture that you can write programs for. This particular architecture, EvilGroupVM.exe, has nine instructions whose operation code (opcode) you need to find through binary reverse engineering.

The tools you will require are:

- A Hex editor (any will do)
- A disassembler, IDA (the free version for Windows will work if you don't have a registered copy) 
- A debugger, Olly or WinDBG on Windows, Gnu GDB or EDB on Linux https://www.gnu.org/software/gdb/

Basic Usage: Unzip the reverseme folder, open a command line and cd to it. Depending on operating system, type

Windows: EvilGroupVM.exe <BytecodeFile>
Ubuntu Linux: ./EvilGroupVM <BytecodeFile>

For example, to run the helloworld bytecode file on Windows, you would type:

EvilGroupVM.exe helloworld

IMPORTANT: Note that the EvilGroupVM.exe architecture has debugging capabilities enabled. This means, it has one instruction that shows you the thread context of a binary when it is hit. Once you start developing your own bytecode binaries, it is possible to debug them (but you need to find the debug instruction/opcode first).

The outcome of this exercise should include the following key structures in your report:

1: A description of the binary file format. For example 
	a. What does the bytecode file header look like? 
	b. What determines where execution will start once the bytecode is loaded in the VM? 
	c. Does the architecture contain other parts of memory (like a stack) where it can store data and operate on them? 

2: The instruction set including their impact on the runtime memory
	a. Find all instructions that the EvilGroupVM.exe accepts
	b. Analyze each of them and understand how they make changes to the runtime memory of the bytecodes thread

3: Write a proof of concept self modifying bytecode file that prints your name to the screen. The binary must be self modifying, that is, you may not use the "print_char" instruction directly, rather, the binary must modify itself if it wants to make use of "print_char".

4: This one is the advanced challenge. If you have the ability and time, send us back a C-file that, when compiled, will give an almost exact match compared to EvilGroupVM (Ubuntu Linux) or EvilGroupVM.exe (Windows). Focus to get pointer arithmetic and data structures correctly.

