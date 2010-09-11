cmake_minimum_required (VERSION 2.6)
project (examples)

include_directories (../)

#link_directories (../lib)
link_libraries(kdtree)

add_executable(test test.c)
add_executable(test2 test2.c)

