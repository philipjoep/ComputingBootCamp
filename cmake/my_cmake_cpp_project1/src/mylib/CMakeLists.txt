# Create Header file list, though not needed to create the library, it is needed for IDEs 
set(HEADER_LIST "${MyCmakeProject_SOURCE_DIR}/include/mylib/my_file.hpp")

# For static library
#add_library(mylib STATIC my_file.cpp ${HEADER_LIST})

#for dynamic library
add_library(mylib SHARED my_file.cpp ${HEADER_LIST})

# PUBLIC|PRIVATE|INTERFACE
# PUBLIC:       My own object (target), mylib, and anything that uses mylib will need these headers.
# PRIVATE:      My own object (target), mylib, will need these headers, but anything using mylib won't need the headers.
# INTERFACE:    My own object (target), mylib, will NOT need these headers, but anything using mylib WILL need the headers.
target_include_directories(mylib PUBLIC ../../include)


