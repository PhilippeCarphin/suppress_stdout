cmake_minimum_required(VERSION 3.13)

project(suppress_stdout C)

include(CTest)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

add_library(my_functions my_functions.c)

add_library(suppressor suppressor.c)

add_executable(main main.c)
target_link_libraries(main PRIVATE my_functions suppressor)

add_test(
    NAME expect_8_words
    COMMAND
        ${CMAKE_SOURCE_DIR}/expect_words.sh ./main 8
)
add_dependencies(check main)
