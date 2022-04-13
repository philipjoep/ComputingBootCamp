add_executable(my_program my_program.cpp)

# PRIVATE: Nothing will link against the executible, so use PRIVATE
target_link_libraries(my_program PRIVATE mylib)
