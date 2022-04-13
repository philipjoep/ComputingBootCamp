#Phil's Notes

Steps to build:
1) Pre-processor
2) Compiler (source to assembly)
3) Assembler (assembly to binary)
4) Linker

To look at pre-processor effects on source files:
```bash
gcc -E -P main.cpp     >> main.i
gcc -E -P my_file.cpp  >> my_file.i
```

To see the assembly code in *.s files:
```bash
gcc -S main.cpp
gcc -S my_file.cpp
```

Call sssembler on assembly file to create object (binary) files
```bash
as -o main.o     main.s
as -o my_file.o  my_file.s
```
To list all the symbols in the object file:
```bash
nm main.o
```

Link object files to make the application program:
```bash
g++ -o my_program   main.o   my_file.o
```

Or there's a shorter way to do everything above:
```bash
# Need g++ because of iostream
g++ -o my_program main.cpp my_file.cpp
```
The problem doing it this way is every file is compiled each time, even if most of them have not changed.

You can use static libraries to build code once.
* But downside is that there is a copy of the static library in every executible that uses it; make the file larger.
* Also, if not careful, could have executibles that use different versions of the same lib.

```bash
# create object file of source file used for library
g++ -c my_file.cpp

#use archive
# https://man7.org/linux/man-pages/man1/ar.1.html
# r: replacement
# v: verbose
# s: add index to file
ar rvs mylib.a my_file.o
```

```bash
# Compile program with static library
g++ -o my_program main.cpp mylib.a
```

Could use a dynamic libray (shared objects) instead:

PIC stands for "Position Independent Code".

To quote man gcc:

    If supported for the target machine, emit position-independent code, suitable for dynamic linking and avoiding any limit on the size of the global offset table. This option makes a difference on AArch64, m68k, PowerPC and SPARC.

Use this when building shared objects (*.so) on those mentioned architectures.

```bash
# Created the object file
# -fpic: create "position independent code"
g++ -c -fpic my_file.cpp

# Create the shared object file for the "mylib" library
# Always prefixed with "lib" and ends with ".so"
g++ --shared -o libmylib.so my_file.o

# Link to program (this will produce a linking error)
# -l to link shared object by the name without the prefixed "lib" or postfix ".so"
#   You can put a space after -l but not required. Same as -lmylib
g++ -o my_program main.cpp -l mylib

# This also produces an error when trying to run the program.
g++ -o my_program -L/home/pi/dev_workspace/ComputingBootCamp/cmake/my_cpp_project main.cpp -l mylib

# This environment variable needs to have the path to the shared library
echo $LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/home/pi/dev_workspace/ComputingBootCamp/cmake/my_cpp_project:$LD_LIBRARY_PATH

# Now you can run my_program
./my_program
```
