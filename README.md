# Introduction
This project should give a good starting point to develop a bare metal embedded program with gcc. 
The target architecture of this project is the cortex m4 from arm, but the project can easily be adapted to 
other architectures as well.

# Toolchain
The [GCC ARM Embedded](https://launchpad.net/gcc-arm-embedded) compiler (4.9.3) is used to compile this project. 

# GCC
The gcc manual can be found [here](https://gcc.gnu.org/onlinedocs/gcc-4.9.3/gcc/index.html#toc_Top). Its quite usefull as 
reference for the used compiler switched.

Some interesting topics in this manual are:
* [Preprocessor Options](https://gcc.gnu.org/onlinedocs/gcc-4.9.3/gcc/Preprocessor-Options.html#Preprocessor-Options) - This is used for automatic dependency generation.

# Makefile 
The gnu make manual can be found [here](http://www.gnu.org/software/make/manual/html_node/index.html).

The following links represent shortcuts to important concepts which are used in the Makefile of this project:
* [Recipe Echoing](http://www.gnu.org/software/make/manual/make.html#Echoing)
* [Automatic Variables](http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)
* [Functions for String Substitution and Analysis](http://www.gnu.org/software/make/manual/html_node/Text-Functions.html#Text-Functions)
* [Substitution References](http://www.gnu.org/software/make/manual/html_node/Substitution-Refs.html#Substitution-Refs)