# ARM Cortex-M4 Base Project
This project gives a good starting point for developing a bare metal embedded program on the arm cortex m3/m4. 
It uses the gnu c and c++ compiler for building, therefore no expenses are necessary to get it running.

## Toolchain
The following programs are used for development:
* Compiler - [Gcc arm embedded compiler (4.9.3)](https://launchpad.net/gcc-arm-embedded) 
* IDE and Debugger - [Eclipse CDT (Mars - 4.5.0)] (https://www.eclipse.org)  
* Unix tools (make, rm, grep ...) - [Cygwin](https://www.cygwin.com/) or [MinGW - MSYS](https://www.cygwin.com/)
* Documentation - [Doxygen](http://www.stack.nl/~dimitri/doxygen/) 

## Building binaries
The Makefile uses the environment variable **ARM_GCC_PATH** to locate the arm gcc compiler. This variable must be set to the installation
directory of the compiler. On windows this path should not contain any whitespaces. 

To build:
```
set ARM_GCC_PATH=...path-to-buildchain...
make
```

To get further information on the built elf file:
```
make info
```

## Building the documentation
To build the documentation:
```
make doc
```


## Usefull resources
This section lists some usefull resources which I constantly use when working on an cortex m4 target.
### Cortex M4 Technical Reference Manual 
The "Cortex M4 Technical Reference Manual" can be found [here](http://infocenter.arm.com/help/topic/com.arm.doc.ddi0439b/index.html).

Some interesting topics in this manual are:
* [3.3.1. Cortex-M4 instructions](http://infocenter.arm.com/help/topic/com.arm.doc.ddi0439b/CHDDIGAC.html) - Instruction set summary

### Cortex-M4 Devices Generic User Guide
The "Cortex-M4 Devices Generic User Guide" can be found [here](http://infocenter.arm.com/help/topic/com.arm.doc.dui0553a/index.html).

Some interesting topics in this user guide are:
* [2.3.4. Vector table](http://infocenter.arm.com/help/topic/com.arm.doc.dui0553a/BABIFJFG.html) - General description of the vector table.
* [2.3.5. Exception priorities](http://infocenter.arm.com/help/topic/com.arm.doc.dui0553a/BABICDEB.html) - Exception/Interrupt priorities.

### GCC
The "GCC Documentation (4.9.3)" can be found [here](https://gcc.gnu.org/onlinedocs/gcc-4.9.3/gcc/index.html). It is quite usefull as 
reference for the used compiler switches.

For this project the following topics in this documentation are of special interest:
* [3.10 Options That Control Optimization](https://gcc.gnu.org/onlinedocs/gcc-4.9.3/gcc/Optimize-Options.html#Optimize-Options) - Optimization is very important on an embedded targets.
* [3.11 Options Controlling the Preprocessor](https://gcc.gnu.org/onlinedocs/gcc-4.9.3/gcc/Preprocessor-Options.html#Preprocessor-Options) - These are used for automatic dependency generation.

### Make 
The "GNU Make Documentation" can be found [here](http://www.gnu.org/software/make/manual/html_node/index.html).

For this project the following topics in this documentation are of special interest:
* [5.2 Recipe Echoing](http://www.gnu.org/software/make/manual/make.html#Echoing)
* [8.2 Functions for String Substitution and Analysis](http://www.gnu.org/software/make/manual/html_node/Text-Functions.html#Text-Functions)
* [6.3.1 Substitution References](http://www.gnu.org/software/make/manual/html_node/Substitution-Refs.html#Substitution-Refs)
* [8.2 Functions for String Substitution and Analysis](http://www.gnu.org/software/make/manual/html_node/Text-Functions.html#Text-Functions)
* [10.5.3 Automatic Variables](http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)

### Binutils
The "Binutils Documentation" can be found [here](https://sourceware.org/binutils/docs-2.25/binutils/index.html). 

The following tools are especially useful:
* [nm](https://sourceware.org/binutils/docs-2.25/binutils/nm.html#nm) - Lists symbols from object files.
* [objdump](https://sourceware.org/binutils/docs-2.25/binutils/objdump.html#objdump) - Display information from object files.
* [size](https://sourceware.org/binutils/docs-2.25/binutils/size.html#size) - List section sizes.
* [addr2line](https://sourceware.org/binutils/docs-2.25/binutils/addr2line.html#addr2line) -  Translates addresses into file names and line numbers.

#### Assembler - as
The Assembler is part of the binutils package. Its documentation can be found [here](https://sourceware.org/binutils/docs-2.25/as/index.html).

For this project the following topics in this documentation are of special interest:
* [7 Assembler Directives](https://sourceware.org/binutils/docs-2.25/as/Pseudo-Ops.html#Pseudo-Ops)
* [9.4 ARM Dependent Features](https://sourceware.org/binutils/docs-2.25/as/ARM_002dDependent.html#ARM_002dDependent)


#### Linker - ld
The Linker is part of the binutils package. Its documentation can be found [here](https://sourceware.org/binutils/docs-2.25/ld/index.html).

For this project the following topics in this documentation are of special interest:
* [2.1 Command Line Options](https://sourceware.org/binutils/docs-2.25/ld/Options.html#Options)
* [3.3 Simple Linker Script Example](https://sourceware.org/binutils/docs-2.25/ld/Simple-Example.html#Simple-Example)
* [3.4.1 Setting the Entry Point](https://sourceware.org/binutils/docs-2.25/ld/Entry-Point.html#Entry-Point)
* [3.6.4.4 Input Section and Garbage Collection](https://sourceware.org/binutils/docs-2.25/ld/Input-Section-Keep.html#Input-Section-Keep)

### Doxygen
The "Doxygen" documentation can be found [here](http://www.stack.nl/~dimitri/doxygen/index.html).

### Libraries
#### Redhat newlibc
The "newlibc" documentation can be found [here](https://sourceware.org/newlib/libc.html).

For this project the following topics in this documentation are of special interest:
* [12 System Calls](https://sourceware.org/newlib/libc.html#Syscalls)

### Books
This section contains some book I found very helpful when programming on the Cortex M4:
* "Definitive Guide to ARM Cortex-M3 and Cortex-M4 Processors" from Joseph Yiu
* "System Interfaces and Header Issue 4 Version 2" from the open group  
