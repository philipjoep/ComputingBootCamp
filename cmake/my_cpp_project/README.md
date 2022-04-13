#Phil's Notes

Steps to build:
1) Pre-processor
2) Compiler (source to assembly)
3) Assembler (assembly to binary)
4) Linker

To look at pre-processor effects on source files:
```
gcc -E -P main.cpp     >> main.i
gcc -E -P my_file.cpp  >> my_file.i
```

To see the assembly code in *.s files:
```
gcc -S main.cpp
gcc -S my_file.cpp
```

Call sssembler on assembly file to create object (binary) files
```
as -o main.o     main.s
as -o my_file.o  my_file.s
```

