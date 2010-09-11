cmake_minimum_required (VERSION 2.8.2)
project (examples)

include_directories (../include)

link_libraries(kdtree)

add_executable(test test.c)
add_executable(test2 test2.c)
add_executable(test3 test3.c)

