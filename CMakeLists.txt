cmake_minimum_required(VERSION 3.13)

project(suppress_stdout C)

add_library(my_functions my_functions.c)

add_executable(main main.c)
target_link_libraries(main PRIVATE my_functions)

add_custom_target(run COMMAND ./main DEPENDS main)

