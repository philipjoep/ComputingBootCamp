# Phil's Notes: ```my_cmake_cpp_project1```

## Intro

Added comments inside the varios `CMakeLists.txt` files.

In `src/mylib/CMakeLists.txt`, see how to switch between STATIC and SHARED libraries.
Start with STATIC set.

Once running `CMake` once, you only need to run `Make` if you change your code.  If you add new folders and/or files, you will need to re-run `CMake`.

## CMake and Make Commands

Make a `build` folder to contain all the build objects and run cmake.

```bash
mkdir build

# change to directory
cd build

# run cmake pointing up one level (will find root level CMakeLists.txt file)
cmake ..
```

There's now a `Makefile` in the `build` folder.

```bash
# call make
make

# run program
./apps/my_program/my_program 
```

To clean, delete the entire `build` folder.

## Dynamic Library (Shared Object)
Switch `src/mylib/CMakeLists.txt` to use SHARED.  Repeat the steps above to run CMake and Make commands.  Within `build/src/mylib` there is now a shared library `libmylib.so`.

Keep in mind that you might still have the `libmylib.so` from the `my_cpp_project` and `LD_LIBRARY_PATH` might still be pointing to the folder containign this shared library.  This will be true if you exported `LD_LIBRARY_PATH` previously and are still using the same terminal.  

You will see an output from running the program:

```bash
# Note the output "(from mylib in non-cmake project)"
$ ./apps/my_program/my_program 

Hello from my_file.cpp (from mylib in non-cmake project)
```
Close and reopen the shell terminal and run application again.  You will see the correct shared library will be found.

```bash
$ ./apps/my_program/my_program 

Hello from my_file.cpp (inside mylib - in my cmake project)
```
