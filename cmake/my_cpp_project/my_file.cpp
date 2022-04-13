#include <iostream>

void file_hello()
{
  // Original
  // std::cout << "Hello from my_file.cpp" << std::endl;

  // For example building libraries
  std::cout << "Hello from my_file.cpp (from mylib in non-cmake project)" << std::endl;
}
